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

//Defining error type
#ifndef ERRORCHECKER_H_
#define ERRORCHECKER_H_

//Including default input/output library
#include <iostream>

//using standard library
using namespace std;


class ErrorChecker{

public:
	ErrorChecker();
	~ErrorChecker();
	void Error_ArgumentNumberCheck(int numberOfArguments);
	void Warning_HighValueOfSleepTime(int sleepTime);
	void Warning_HighNumberOfConsumerThreads(int numberOfConsumerThreads);
	void Warning_HighNumberOfProducerThreads(int numberOfProducerThreads);

};
#endif /* ERRORCHECKER_H_ */