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
//Importing library used for exit() method
#include <cstdlib>

#include "ErrorChecker.h"

//using standard library
using namespace std;

//Error checker constructor
ErrorChecker::ErrorChecker(){

}

//Error checker destructor
ErrorChecker::~ErrorChecker(){
	cout<<"Error checker destroyed sucessfully..."<<endl;
}
//Function to check the argument number, it must be 3;
void
ErrorChecker::Error_ArgumentNumberCheck(int numberOfArguments){
	if(numberOfArguments != 3){
		cout <<"-------------------------Error-------------------------"<<endl;
		cout <<"Argument number need to be 3" << endl;
		cout <<"Try execute the file using the command"<<endl;
		cout <<"./buffer <time for sleep> <number of producer threads> <number of consumer threads>"<<endl;
		cout <<"----------------------------------------------------------------------"<<endl;
		exit(0);
	}
}

//Warning for high sleep time
void
ErrorChecker::Warning_HighValueOfSleepTime(int sleepTime){
	if(sleepTime > 100){
		cout <<"-------------------------Warning-------------------------"<<endl;
		cout <<"High values of sleep time can make the program executes slowly and you will have to wait much" << endl;
		cout <<"----------------------------------------------------------------------"<<endl;
	}
}

//Warning for high value of consumer threads
void
ErrorChecker::Warning_HighNumberOfConsumerThreads(int numberOfConsumerThreads){
	if(numberOfConsumerThreads > 20){
		cout <<"-------------------------Warning-------------------------"<<endl;
		cout <<"Number of Consumers too high, may cause consumers to wait too much" << endl;
		cout <<"----------------------------------------------------------------------"<<endl;
	}
}

//Warning for high value of producer threads
void
ErrorChecker::Warning_HighNumberOfProducerThreads(int numberOfProducerThreads){
	if(numberOfProducerThreads > 20){
		cout <<"-------------------------Warning-------------------------"<<endl;
		cout <<"Number of Producers too high, may cause producers to wait too much" << endl;
		cout <<"----------------------------------------------------------------------"<<endl;
		exit(0);
	}
}