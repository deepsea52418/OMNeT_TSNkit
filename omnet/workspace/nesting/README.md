# NeSTiNg - Network Simulator for Time-sensitive Networking

NeSTiNg is a simulation model for Time-sensitive Networking (TSN) using the OMNeT++ discrete event simulation framework.
Our model uses the [INET framework](https://inet.omnetpp.org/) and enhances it by TSN-capable components.
The model was initially developed by a group of students during a curricular project and is continously extended at the [Distributed Systems group of IPVS, University of Stuttgart](https://www.ipvs.uni-stuttgart.de/departments/vs/)

## Contact
### Gitter
We founded a Gitter community to ease the communication:
https://gitter.im/ipvs-nesting/community

### Mail
+ [David Hellmanns](https://www.ipvs.uni-stuttgart.de/institute/team/Hellmanns/)
+ [Jonathan Falk](https://www.ipvs.uni-stuttgart.de/institute/team/Falk-00005/)

## Compatibility

The current version of the NeSTiNg simulation framework has been tested with OMNeT++ version 5.5.1 and INET version 4.1.2 under Linux.

## Getting Started

+ Follow the instructions at [https://omnetpp.org/](https://omnetpp.org/) to download and install OMNeT++ version 5.5.1
+ Make sure OMNeT++ is in your `PATH` by changing into the OMNeT++ directory and sourcing the `setenv` script.
+ `cd` into an arbitrarily named, preferably empty `<workspace>` directory.
+ Clone this repository, i.e.

```
  $ git clone https://gitlab.com/ipvs/nesting.git
```

+ Download and unpack INET version 4.1.2 or clone the INET repository and checkout tag `v4.1.2`, i.e.

```
  $ git clone https://github.com/inet-framework/inet.git
  $ git checkout -b v4.1.2 v4.1.2
```
  or alternatively with a space-saving one-liner:
```
  $ git clone --branch v4.1.2 --depth 1 https://github.com/inet-framework/inet.git
```

+ Your directory should now look like this:

```
  <workspace>
  ├── nesting
  └── inet
```

### Importing and building from the OMNeT++ IDE

+ Start the OMNeT++ IDE, either from your desktop environment or by calling `omnetpp` from the terminal.
+ Set your previously chosen `<workspace>` directory as the workspace and launch the IDE.
+ Import both `nesting` and `inet` into your workspace:
	- Select `File -> Import...` from the menu.
	- Select `General -> Existing Projects into Workspace` and click `Next >`.
	- Under `Select root directory:`, choose the `<workspace>` directory.
	- Both project folders should now appear and be checked under `Projects`.
	- Click `Finish` and wait for the indexer to complete.
+ Build both INET and NeSTiNg by right-clicking on the corresponding project folder and selecting `Build Project`.
  (You can switch between the `release` and `debug` configuration in the same context menu under `Build Configurations -> Set Active`)
+ You can now run the supplied example simulation:
	- Navigate into `nesting > simulations` in the project explorer.
	- Right-click `example.ini` and choose `Run As` (or `Debug As` depending on the build configuration) `OMNeT++ Simulation`.
	- After a possible build step you will be presented with a graphical interface showing the simulation model.

### Building from the terminal

If you want to use NeSTiNg without the IDE or using OMNeT++ core, you can also build INET and NeSTiNg and run simulations from the terminal. (By default, the release versions of both projects will be built. To build the debug version, call `MODE=debug make` instead of `make` below. NeSTiNg requires the INET library to be built with the same configuration.)

+ To build INET:

```
  $ cd inet
  $ make makefiles
  $ make
```

+ To build NeSTiNg (both the library and the simulation executable):

```
  $ cd ../nesting
  $ make makefiles
  $ make
```

+ To run the example simulation, change to the `nesting/simulations` directory and call one of the following

```
  $ ./runsim example.ini                # run simulation without graphical interface (release)
  $ ./runsim-qt example.ini             # run simulation with the Qt interface (release)
  $ MODE=debug ./runsim example.ini     # run simulation without graphical interface (debug)
  $ MODE=debug ./runsim-qt example.ini  # run simulation with the Qt interface (debug)
```

## Citation

If you use NeSTiNg in your research, please include the following reference in your publication:

> J. Falk, D. Hellmanns, B. Carabelli _et al._ “NeSTiNg: Simulating IEEE Time-sensitive Networking (TSN) in OMNeT++”. In: _Proceedings of the 2019 International Conference on Networked Systems (NetSys)_. Garching b. München, Germany, Mar. 2019.

The author's version can be retrieved [here](ftp://ftp.informatik.uni-stuttgart.de/pub/library/ncstrl.ustuttgart_fi/INPROC-2019-04/INPROC-2019-04.pdf).

### bibtex entry
```
@inproceedings {nesting_2019,
    author = {Jonathan Falk and David Hellmanns and Ben Carabelli and Naresh Nayak and Frank D{\"u}rr and Stephan Kehrer and Kurt Rothermel},
    title = {{NeSTiNg}: Simulating {IEEE} Time-sensitive Networking ({TSN}) in {OMNeT}++},
    booktitle = {Proceedings of the 2019 International Conference on Networked Systems (NetSys)},
    address = {Garching b. M{\"u}nchen, Germany},
    month = mar,
    year = {2019},
} 
```

## Related Projects
### [Automated TSN configuration Plugin](https://gitlab.com/Scipsybee/automated-tsn-configuration-plugin)
A modular framework to automate offline scheduling in TSN networks to facilitate the design time and pre-simulation automated network configurations as well as interpretation of the simulations, based on NeSTiNg TSN simulation tool in OMNeT++

## Contribution
Institute of Parallel and Distributed Systems  
University of Stuttgart  
https://www.ipvs.uni-stuttgart.de/departments/vs/
