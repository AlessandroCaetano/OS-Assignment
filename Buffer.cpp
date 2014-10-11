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

//Including default input/output library
#include <iostream>

//Including custom buffer definition
#include "Buffer.h"

//Using standard library
using namespace std;

//Constructor initializing buffer with value 0
Buffer::Buffer(){
	for(int i = 0; i < this->size; i++)
		buffer_itens[i] = 0;
}

//Destructor Method;
Buffer::~Buffer(){
	cout << "Buffer destroyed --- Run to the Hills" <<endl;
}

//Method for item insertion
int
Buffer::Insert_Item(int item){
	for(int i = 0; i < this->size; i++){
			if(this->buffer_itens[i] != 0)
				continue;
			else{
				this->buffer_itens[i] = item;
				return 0;
			}
		}
	cerr << "Could not insert item" <<endl;
	return -1;
}

//Method for Removing Itens
int
Buffer::Remove_Item(int *item){

	if(*item >= 0 && *item < 5)
	{
		this->buffer_itens[*item] = 0;
		return 0;
	}

	cerr << "This item couldn't be removed"<< endl;
	return -1;

}

//Method for Recovering Itens
int
Buffer::Get_Item(int item){
	for(int i = 0; i < this->size; i++){
		if(item == this->buffer_itens[i]){
			return item;
		}

	}

	cerr<<"Item not found" << endl;
	return -1;
}

//Print all itens on the console
void
Buffer::Show_Itens(){
	for(int i = 0; i < this->size; i++)
		cout<<"Buffer item on position "<< i+1 <<":  "<< buffer_itens[i] << endl;
}

