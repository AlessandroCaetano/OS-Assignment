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

//Defining buffer type
#ifndef BUFFER_H_
#define BUFFER_H_

//Including default input/output library
#include <iostream>

//using standard library
using namespace std;


class Buffer{

public:
	Buffer();
	~Buffer();
	int Insert_Item(int item);
	int Remove_Item(int* item);
	int Get_Item(int item);
	void Show_Itens();


private:
	static const int BUFFER_SIZE = 5 ;
	static const int size = BUFFER_SIZE;
	int buffer_itens[BUFFER_SIZE];
};
#endif /* BUFFER_H_ */