# CSCI350P3

usc email 1: asarun@usc.edu

usc email 2: mbawa@usc.edu

Description:

- This project extends xv6 with a three-level Multi Feedback Queue (MFQ) scheduler with priority boost (aging), and adds getpinfo() system call to print each process's scheduling record.

How to compile:

- Installed Docker and set up (cloned the cs350-docker helper repo https://github.com/camerondurham/cs350-docker)
- Updated run script to ensure work variable reflects path
- Run ./run.sh and ./run.shell to start the docker environment
- Change directory to the xv6 project folder
- Run make clean and make to clean and compile

How to run:

- Inside xv6 folder (in shell), run make qemu-nox to start the simulator
- Run test1 to see mixed CPU and IO intensive workload
- Run test2 to see priority boosting of long running processes
- Run test3 to see process stay in the highest priority queue

Notes:

- To exit out of the shell, press Ctrl-a and then x
- To exit out of the docker environment, type exit in the Docker shell
- Test outputs included in the workload.pdf for reference
