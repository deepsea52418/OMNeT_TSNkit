# OMNeT_TSNkit

## Introduction

This project addresses the scheduling and simulation challenges in Time-Sensitive Networks (TSN), utilizing [TSNkit](https://github.com/ChuanyuXue/tsnkit) to generate network scheduling schemes. The simulation is conducted using the NeSTiNg framework, allowing the verification of scheduling schemes. A [video link](https://space.bilibili.com/35942145) is available for the project.

The primary goal of this project is to promote the TSNkit tool and OMNeT++ simulation software, facilitating a quick introduction to TSN. Moreover, it aims to make the replication of classic TSN algorithms from research papers more accessible.

> OMNeT++ supports various simulation frameworks. It is recommended to choose an appropriate framework based on simulation goals. This project uses the NeSTiNg framework as an example.
> 
> TSNkit supports multiple algorithms, with this project demonstrating the SMT-NW (No-wait Packet Scheduling for IEEE Time-sensitive Networks) algorithm. For more algorithms, refer to [this link](https://tsnkit.readthedocs.io/en/latest/schedule.html).

## Project Requirements
+ [Ubuntu 18.04](https://releases.ubuntu.com/18.04/)
+ [OMNeT++ 5.6.1](https://github.com/omnetpp/omnetpp/releases/tag/omnetpp-5.6.1)
+ [INET Framework 4.1.2](https://github.com/inet-framework/inet/releases/tag/v4.1.2)
+ [NeSTiNg](https://gitlab.com/ipvs/nesting)&nbsp;&nbsp;&nbsp;&nbsp;![Commit](https://img.shields.io/badge/commit-b7f1df09-blue)
+ [TSNkit](https://github.com/ChuanyuXue/tsnkit)&nbsp;&nbsp;&nbsp;&nbsp;![Commit](https://img.shields.io/badge/commit-1ae494b-blue)
+ Refer to the respective project Readme files for other dependency environments.

## Code Explanation

1. **Network Topology:**
   ``` mermaid
   graph LR
       Client1[Client1]
       Client2[Client2]
       Client3[Client3]
       TSNSwitch1[TSNSwitch1]
       TSNSwitch2[TSNSwitch2]
       Server1[Server1]
       Server2[Server2]
       Server3[Server3]
       Client1 --- TSNSwitch1
       Client2 --- TSNSwitch1
       Client3 --- TSNSwitch1
       TSNSwitch1 --- TSNSwitch2
       TSNSwitch2 --- Server1
       TSNSwitch2 --- Server2
       TSNSwitch2 --- Server3

2. **Flow Information**

| FlowID | Src | Dst | Size | Period    | Deadline | Jitter   |
|--------|-----|-----|------|-----------|----------|----------|
| 0      | 1   | 5   | 500B | 500000ns  | 408400ns | 408400ns |
| 1      | 2   | 6   | 1200B| 1000000ns | 408400ns | 408400ns |
| 2      | 3   | 7   | 200B | 200000ns  | 408400ns | 408400ns |

3. **File Directory**
```
.
├── omnet
│   └── workspace
│       └── nesting
│           └── teach
│               ├── xml
│               │   ├── teach_gcl.xml (Simulated GCL Information)
│               │   └── teach_Routing.xml (Simulated Routing Information)
│               ├── _example_teach.ini (Simulated Network Configuration)
│               └── teach.ned (Simulated Network Topology)
└── TSNkit
    └── data
        │  
        ├── input
        │    └── example
        │       ├──  example_net.csv  (Network Topology)
        │       └──  example_task.csv (FLOW Information)
        │        
        │          
        └─ output
            └── example
                 ├── example-DELAY.csv     (Flow Delay Information)
                 ├── example-GCL.csv       (GCL Information)
                 ├── example-OFFSET.csv    (Flow Send Offset)
                 ├── example-QUEUE.csv     (Flow Priority Information)
                 └──  example-ROUTE.csv     (Flow Priority Information)

```
## Usage

#### Installation
1. Download and install Ubuntu 18.04, and install OMNeT++ 5.6.1.
2. Navigate to the OMNeT++ directory: `cd [path to your OMNeT++]`.
3. `git clone https://gitee.com/deepsea52418/omnet_tsnkit.git`.
4. `cd OMNET_TSNKIT`.
5. Install and compile INET Framework, specific instructions can be found [here](https://github.com/inet-framework/inet/blob/master/INSTALL.md).
6. Install and compile NeSTiNg, specific instructions can be found [here](https://gitlab.com/ipvs/nesting/-/blob/master/README.md).
7. Install TSNkit, specific instructions can be found [here](https://github.com/ChuanyuXue/tsnkit/blob/main/README.md).

#### Solve using Scheduling Algorithm
1. `cd TSNkit/src`
2. Use `python -m  tsnkit.models.smt_nw  ../data/input/example/example_task.csv  ../data/input/example/example_net.csv  ../data/output/example` for solving, This command loads the network information (net.csv) and flow information (task.csv) in data/input/example for solution
3. Upon completion, you can find the generated scheduling result files (GCL.csv, OFFSET.csv, etc.) in the "../data/output/example/".

#### Run Simulation
1. Open OMNeT++.
2. Choose OMNET_TSNKIT\omnet\workspace as the OMNeT++ workspace.
3. Select nesting\teach\\_example_teach.ini, right-click, and choose `Run As` to execute.

## Tips
>
>The SMT-NW algorithm achieves no-wait transmission of flows by specifying the offset time for flow transmission. In this process, there is no involvement of flow priority-related issues; therefore, all flow priorities are set to 0.
>
>According to the definition in the `nesting\src\nesting\ieee8021q\queue\QueuingFrames.h` code, with 8 available queues, flows with priority 0 are mapped to Queueing module's queue 1 for transmission.
>
>In the NeSTiNg simulation framework, by default, the oscillator submodule frequency of simulation node modules is set to 1MHz, and simulation time precision is 1μs. To enhance simulation accuracy, in this project, the oscillator module frequency is specified as 1GHz, resulting in a simulation time precision of 1ns.
>
>In the NeSTiNg simulation framework, the default data frame format specified by the 802.3 protocol is used, where the complete data frame size equals the application layer data + preamble (8B) + destination address (6B) + source address (6B) + vlanTag (4B) + length (2B) + CRC (4B).
>
>Currently, frame spacing issues are not considered in TSNkit. You need to modify the `INTERFRAME_GAP_BITS` parameter in the `\inet\src\inet\linklayer\ethernet\Ethernet.h` file from 96 to 0.
>
>The calculation of delay in TSNKit subtracts the transmission delay of the source end, and does not subtract the offset, while the calculation of delay in OMNeT starts from the source device starting to send the first bit, which means that the delay in tsnkit The output minus the offset, plus the transmission delay at the source end, is the delay that should appear in OMNeT.

## Contribution

If you have any comments or suggestions for this project, feel free to submit an issue on the project page. Thank you for your participation and feedback!

## Acknowledgments

+ [Chuang Li](https://github.com/chaungLi)
+ [Callin](https://github.com/lxacc)
+ Contributors to OMNeT++, INET Framework, NeSTiNg, and TSNkit projects


