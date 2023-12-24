Getting Started Guide for Linux
===============================

Introduction
------------

This document contains instructions for installing and configuring the Network Simulator for Time-sensitive Networking (NeSTiNg). It is designed to get newcomers up and running quickly. The document describes how to compile and run NeSTiNg in a Linux environment, without going deeply into detail.

Compatibility
-------------

The current version of the NeSTiNg simulation framework has been tested with

* OMNeT++ v5.5.1
* INET v4.1.2.

Building NeSTiNg from source
----------------------------

* Follow the instructions at https://omnetpp.org/ to download and install OMNeT++
* The official `Install Guide <https://omnetpp.org/doc/omnetpp/InstallGuide.pdf>`_ might provide userful information on building and installing OMNeT++.
* ``cd`` into your OMNeT++ ``<workspace>`` directory.

Next download and unpack INET version 4.1.2 or clone the INET repository and checkout tag ``v4.1.2``, i.e.

.. code-block:: console

    $ git clone https://github.com/inet-framework/inet.git
    $ git checkout -b v4.1.2 v4.1.2

Then clone the NeSTiNg repository

.. code-block:: console

    $ git clone https://gitlab.com/ipvs/nesting.git

Your directory should now look like this::

    <workspace>
    ├── nesting
    └── inet


Importing and building from the OMNeT++ IDE
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Start the OMNeT++ IDE, either from your desktop environment or by calling ``omnetpp`` from the terminal.
* Set your previously chosen ``<workspace>`` directory as the workspace and launch the IDE.
* Import both ``nesting`` and ``inet`` into your workspace:

	* Select ``File -> Import...`` from the menu.
	* Select ``General -> Existing Projects into Workspace`` and click ``Next >``.
	* Under ``Select root directory:``, choose the ``<workspace>`` directory.
	* Both project folders should now appear and be checked under ``Projects``.
	* Click ``Finish`` and wait for the indexer to complete.

* Build both INET and NeSTiNg by right-clicking on the corresponding project folder and selecting ``Build Project``.
  (You can switch between the ``release`` and ``debug`` configuration in the same context menu under ``Build Configurations -> Set Active``)
* You can now run the supplied example simulation:

	* Navigate into ``nesting > simulations`` in the project explorer.
	* Right-click ``example.ini`` and choose ``Run As`` (or ``Debug As`` depending on the build configuration) ``OMNeT++ Simulation``.
	* After a possible build step you will be presented with a graphical interface showing the simulation model.

Building from the terminal
^^^^^^^^^^^^^^^^^^^^^^^^^^

If you want to use NeSTiNg without the IDE or using OMNeT++ core, you can also build INET and NeSTiNg and run simulations from the terminal. (By default, the release versions of both projects will be built. To build the debug version, call ``MODE=debug make`` instead of ``make`` below. NeSTiNg requires the INET library to be built with the same configuration.)

To build INET:

.. code-block:: console

    $ cd inet
    $ make makefiles
    $ make

To build NeSTiNg (both the library and the simulation executable):

.. code-block:: console

    $ cd ../nesting
    $ make makefiles
    $ make

To run the example simulation, change to the ``nesting/simulations`` directory and call one of the following

.. code-block:: console

    $ ./runsim example.ini                # run simulation without graphical interface (release)
    $ ./runsim-qt example.ini             # run simulation with the Qt interface (release)
    $ MODE=debug ./runsim example.ini     # run simulation without graphical interface (debug)
    $ MODE=debug ./runsim-qt example.ini  # run simulation with the Qt interface (debug)

Running NeSTiNg from container
------------------------------

If you're only interested in using NeSTiNg modules to run simulations, but aren't interested in modifying the code base, you can simply pull the latest container image:

.. code-block:: console

    $ docker pull registry.gitlab.com/ipvs/nesting:latest

In the next step you have to run the continer

.. code-block:: console

    $ xhost +
    $ docker run -it -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --device /dev/dri/ registry.gitlab.com/ipvs/nesting:latest

From inside the container you can now start the Omnet++ IDE

.. code-block:: console

    $ omnetpp

