/*
------------------------------------------------------------------------------------------------------------------------
AUCKLAND UNIVERSITY OF TECHNOLOGY

CODE DEVELOPED BY: ALESSANDRO CAETANO BELTRÃO
STUDENT ID: 14851449
SEMESTER 02 OF  2014
PAPER: OPERATING SYSTEMS
CODE LICENSED UNDER GNU GPL 2.0
CAN BE ALSO FOUND IN: https://github.com/AlessandroCaetano/OS-Assignment

FEEL FREE TO FORK AND PULL THIS PROJECT FROM MY REPOSITORY AND SEND ANY CONTRIBUTION THAT YOU WANT

------------------------------------------------------------------------------------------------------------------------
*/

//Importing default input/output library
#include <iostream>
//Necessary for using threads
#include <thread>
//Used for vector class
#include <vector>
//Used for time manipulation
#include <chrono>
//Used for mutex lock
#include <mutex>

//Including custom class
#include "ErrorChecker.h"
#include "Buffer.h"


//using standard library
using namespace std;

//Initializing Custom Buffer Class
Buffer buffer;

//Initializing Custom Error checker Class
ErrorChecker error;

//Initializing mutex lock
mutex locker;

//Producer Method
void
*produce(){
	unique_lock<mutex> lck(locker);
	//Initializing random seed
	srand(time(NULL));

	//Random time to Sleep
	int timeToSleep = rand()%10 + 1;

	//variable of random item
	int producedItem;
	//Printing current thread id
	cout << "Producer thread number: "<< this_thread::get_id() <<" starting to run..." << endl;
	lck.unlock();

	while(true){
		//Sleep time to give other threads a chance to take the processor
		this_thread::sleep_for(chrono::seconds(timeToSleep));
		//Locking critical session
		unique_lock<mutex> lck(locker);
		//Producing random item
		producedItem = (rand() + 1);
		if(buffer.Insert_Item(producedItem) == 0)
			cout << "Producer thread number: "<< this_thread::get_id() <<" inserted item sucesfully"<< endl;

		//SHow updated buffer
		buffer.Show_Itens();
		//Unlock critical section
		lck.unlock();
	}
}

//Consumer method
void
*consume(){
	//Creating unique lock
	unique_lock<mutex> lck(locker);
	//Initializing random seed
	srand(time(NULL));

	//Random time to Sleep
	int timeToSleep = rand()%10 + 1;

	//Consumed item
	int consumedItem;
	//Printing current thread id
	cout << "Consumer thread number: "<< this_thread::get_id() <<" starting to run..." << endl;
	lck.unlock();

	while(true){
		//Sleep time to give other threads a chance to take the processor
		this_thread::sleep_for(chrono::seconds(timeToSleep));

		//Locking critical consumer section
		unique_lock<mutex> lck(locker);

		//Consuming item from buffer
		consumedItem = (rand()%5);
		if(buffer.Remove_Item(&consumedItem) == 0)
			cout << "Consumer thread number: "<< this_thread::get_id() <<" consumed item sucesfully"<< endl;
		else
			cout << "Could not remove item" << endl;

		//SHow updated buffer
		buffer.Show_Itens();
		//Unlock critical section
		lck.unlock();
	}
}

//Main method
int
main(int argc, char *argv[]){


	//Creating vector for Producers
	vector<thread> producerVector;

	//Creating vector for Consumers
	vector<thread> consumerVector;

	//Getting number of arguments
	int numberOfArguments = argc-1;

	//Check argument numbers
	error.Error_ArgumentNumberCheck(numberOfArguments);

	//Parsing parameters from command line
	int sleepTime 		= atoi(argv[1]);
	int numberOfProducers 	= atoi(argv[2]);
	int numberOfConsumers 	= atoi(argv[3]);


	//Custom warning Checks
	error.Warning_HighValueOfSleepTime(sleepTime);
	error.Warning_HighNumberOfProducerThreads(numberOfProducers);
	error.Warning_HighNumberOfConsumerThreads(numberOfConsumers);


	//Creating Producer Threads
	for(int i = 0; i < numberOfProducers; i++)
		producerVector.push_back(thread(produce));

	//Creating Consumer Threads
	for(int i = 0; i < numberOfConsumers; i++){
		consumerVector.push_back(thread(consume));
	}
	//Main thread sleeping
	this_thread::sleep_for(chrono::seconds(sleepTime));


	//Waiting for consumers and producers threads to end and join
	for(auto& consumerThread:consumerVector) consumerThread.join();
	for(auto& producerThread:producerVector) producerThread.join();

	//End of the program
	return 0;
}
