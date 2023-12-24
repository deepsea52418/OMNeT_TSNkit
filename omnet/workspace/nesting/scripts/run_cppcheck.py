import sys
import os
import subprocess
import json
import hashlib
import re

for env_var in ["NESTING", "OMNETPP", "INET"]:
    if env_var not in os.environ:
        print("Environment variale ${} not defined!".format(env_var), file=sys.stderr)
        sys.exit(1)

# Read environment variables
omnetpp = os.environ["OMNETPP"]
nesting = os.environ["NESTING"]
inet = os.environ["INET"]

# Path to cppcheck report that shall be generated
cppcheck_report_path = "cppcheck_report.json" if len(sys.argv) <= 1 else str(sys.argv[1])

run_cppcheck_cmd = [
    'cppcheck',
    '--std=c++11',
    '--suppress=*:*omnetpp*',
    '--suppress=*:*inet*',
    '--suppress=*:*_m.cc',
    '--suppress=*:*_m.h',
    '--enable=all',
    '-DNDEBUG',
    '-I', '{}/include'.format(omnetpp),
    '-I', '{}/src'.format(inet),
    '-I', '{}/src'.format(nesting),
    '{}/src'.format(nesting),
    '--template={"type": "issue","description": "{message}","check_name": "{id}","location": {"path": "{file}","lines": {"begin": "{line}"}}, "severity": "{severity}", "fingerprint": ""}'
]

# Run cppcheck
print("Cppcheck run command: ", " ".join(run_cppcheck_cmd))
output = subprocess.run(run_cppcheck_cmd, check=True, encoding='utf-8', stdout=sys.stdout, stderr=subprocess.PIPE)

# Create json output file conform to gitlabs code quality report format.
# For more information see https://docs.gitlab.com/ee/user/project/merge_requests/code_quality.html#implementing-a-custom-tool
cppcheck_report = []
id = 1
for line in output.stderr.split('\n'):
    if line != '':
        try:
            issue = json.loads(line)
        except json.decoder.JSONDecodeError as err:
            print("Failed to parse JSON: ", line)
            raise err
        if issue['severity'] == 'information':
            print(issue, file=sys.stderr)
            continue
        else:
            # Use system independent relative paths to source files
            match = re.search('.*/(src/nesting/.*)', issue['location']['path'])
            issue['location']['path'] = match.group(1)
            
            # Add an id
            issue['id'] = id
            id += 1

            # Calculate sha1 fingerprints for issues
            fingerprint = "{}:{}:{}".format(
                    issue['description'],
                    issue['location']['path'],
                    issue['location']['lines']['begin']
            ).encode('utf-8')
            issue['fingerprint'] = hashlib.sha1(fingerprint).hexdigest()
            cppcheck_report.append(issue)

# Print status
print('Cppcheck found {} issues.'.format(id - 1))

# Write report to file
with open(cppcheck_report_path, 'w') as f:
    f.write(json.dumps(cppcheck_report, indent=4))

print('Wrote report to {}'.format(cppcheck_report_path))