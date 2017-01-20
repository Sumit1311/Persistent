//Implementation for all member Functions
#include<iostream>
using namespace std;
#include<vector>
#include"Phone Directory.h"

//Default Constructor
PhoneDirectory::PhoneDirectory():Name(),Number()
{
	//No Need To Implement
}

//Parametrized Constructor
PhoneDirectory::PhoneDirectory(std::string nm, std::string num):Name(nm),Number(num)
{
	//No Need To Implement
}

//Get method for Name
std::string PhoneDirectory::GetName()const
{
	return Name;
}

//Get method for Number
std::string PhoneDirectory::GetNumber()const
{
	//No Need To Implement
	return Number;
}

//Set method for Name
void PhoneDirectory::SetName(std::string nm)					
{
	//No Need To Implement
	Name = nm;
}

//Set method for Number
void PhoneDirectory::SetNumber(std::string num)					
{
	//No Need To Implement
	Number = num;
}

void PhoneDirectory::Accept()													//Accept Method
{
	cout<<"Enter Name:";
	cin>>Name;
	cout<<"Enter Number";
	cin>>Number;
	//Need To Implement
}

void PhoneDirectory::Display()
{
	//Need To Implement
	cout<<Name<<"\t"<<Number<<endl;
}