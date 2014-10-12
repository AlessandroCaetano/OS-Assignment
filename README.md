OS-Assignment
=============

Operating Systems Assignment for Auckland Univesity of Technology

Student Name: Alessandro CAetano Beltrao
Student ID: 14851449
Public Repository with the code: https://github.com/AlessandroCaetano/OS-Assignment
Link to download the project: https://github.com/AlessandroCaetano/OS-Assignment


1- How to Run

	On terminal use the commands:

		$ ./buffer <sleep time for main> <number of producer threads> <number of consumer threads>

2- How to compile

	2.1 Using makefile:

		$ cd .../assignment
		$ make

	2.2 Compiling manually:

		g++ -g -O2 -c -w -Wall -ansi -pedantic -I. -pthread -lm -std=c++11 main.cpp -o main.o
		g++ -g -O2 -c -w -Wall -ansi -pedantic -I. -pthread -lm -std=c++11 Buffer.cpp -o Buffer.o
		g++ -g -O2 -c -w -Wall -ansi -pedantic -I. -pthread -lm -std=c++11 ErrorChecker.cpp -o ErrorChecker.o
		g++ -w -Wall -ansi -pedantic -I. -pthread -lm -std=c++11 main.o Buffer.o ErrorChecker.o -o buffer
		rm -f *.o all

3- File Explanation

	2.1- Buffer: Custom class to receive itens from threads, acts like a shared memory;

	2.2- ErrorChecker: Class with custom warnings and errors;

	2.3- main: Main class, here the buffer is created alongside with the producer and consumer threads, all of the threads are synchronized using the mutex class;

	2.4- Makefile: File to make easier to compile the source code, to use it just type make on the terminal inside de folder with the code;


4- Running Sample

	Producer thread number: 139950298552064 starting to run...
	Producer thread number: 139950290159360 starting to run...
	Producer thread number: 139950281766656 starting to run...
	Producer thread number: 139950273373952 starting to run...
	Producer thread number: 139950264981248 starting to run...
	Producer thread number: 139950256588544 starting to run...
	Consumer thread number: 139950248195840 starting to run...
	Consumer thread number: 139950239803136 starting to run...
	Consumer thread number: 139950231410432 starting to run...
	Consumer thread number: 139950223017728 starting to run...
	Consumer thread number: 139950214625024 starting to run...
	Consumer thread number: 139950206232320 starting to run...
	Producer thread number: 139950298552064 inserted item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  0
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  0
	Producer thread number: 139950281766656 inserted item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  0
	Producer thread number: 139950273373952 inserted item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  800370706
	Buffer item on position 3:  1854941880
	Buffer item on position 4:  0
	Buffer item on position 5:  0
	Producer thread number: 139950264981248 inserted item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  800370706
	Buffer item on position 3:  1854941880
	Buffer item on position 4:  613145739
	Buffer item on position 5:  0
	Producer thread number: 139950256588544 inserted item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  800370706
	Buffer item on position 3:  1854941880
	Buffer item on position 4:  613145739
	Buffer item on position 5:  1220814424
	Consumer thread number: 139950248195840 consumed item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  613145739
	Buffer item on position 5:  1220814424
	Consumer thread number: 139950239803136 consumed item sucesfully
	Buffer item on position 1:  770797756
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  1220814424
	Consumer thread number: 139950231410432 consumed item sucesfully
	Buffer item on position 1:  0
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  1220814424
	Producer thread number: 139950290159360 inserted item sucesfully
	Buffer item on position 1:  161304356
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  1220814424
	Consumer thread number: 139950223017728 consumed item sucesfully
	Buffer item on position 1:  0
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  1220814424
	Consumer thread number: 139950206232320 consumed item sucesfully
	Buffer item on position 1:  0
	Buffer item on position 2:  800370706
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  1220814424
	Consumer thread number: 139950214625024 consumed item sucesfully
	Buffer item on position 1:  0
	Buffer item on position 2:  0
	Buffer item on position 3:  0
	Buffer item on position 4:  0
	Buffer item on position 5:  1220814424


5- Running Analysis

	On my point of view the software is running correctly, the buffer type is being acessed by both producer and consumer threads, each time one of the threads create a item, represented by a random integer type different than zero and put it inside the buffer, and after that any other thread can assume the cpu and try to produce or take one of the itens out of the buffer. This code is using mutex to prevent the threads to be taken out durint the access of the buffer.

6- Developer System Specs

	VMWare Workstation 10 Virtual Machine
	OS: Open Suse 13
	RAM: 2Gb
	Processor: Intel Core i7 - 3630QM
	Compiler Version: G++ 4.8
	Language Used: C++ 11
