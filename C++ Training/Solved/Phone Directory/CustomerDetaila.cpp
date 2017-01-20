//Implementation for all member Functions
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"CustomerDetaila.h"
#include"Phone Directory.h"

void CustomerDetail::AddCustomerDetails(PhoneDirectory &PD)													//Accept Method
{
	
	PD.Accept();
	if(SearchByName(PD.GetName())==-1){
	V.push_back(PD);
	}
	else{
		throw std::string("Name Already Exists");
	}
		//Need To Implement
}

int CustomerDetail::SearchByName(std::string nm)														//Search Method ByName
{
	//Need To Implement and return index number on success and on error return -1
	for(int i=0;i<GetTotalCustomerCount();i++){
		if(V[i].GetName()==nm){
			return i;
		}
	}
	throw std::string("Name doesnot exist");
	return -1;
}

int CustomerDetail::SearchByNumber(std::string num)														//Search Method ByNumber
{
	//Need To Implement and return index number on success and on error return -1
	for(int i=0;i<GetTotalCustomerCount();i++){
		if(V[i].GetNumber()==num){
			return i;
		}
	}
	throw std::string("Number doesnot exist");
	return -1;
}

void CustomerDetail::UpdateByName(std::string nm,std::string num)														//Update Method ByName
{
	//Update the Phone Number according to Customer Name
	//Need To Implement 
	int index=SearchByName(nm);
	if(index==-1){
		throw std::string("Name not in phone directory");
	}
	cout<<"Before Updating :";
	GetCustomerDetails(index).Display();
	if(index!=-1){
		V[index].SetNumber(num);
	}
	cout<<"After Updating :";
	GetCustomerDetails(index).Display();
}

void CustomerDetail::UpdateByNumber(std::string nm,std::string num)														//Update Method ByNumber
{
	//Update the  Customer Name according to Phone Number
	//Need To Implement 
	int index=SearchByNumber(num);
	if(index==-1){
		throw std::string("Number not in phone directory");
	}
	cout<<"Before Updating :";
	GetCustomerDetails(index).Display();
	if(index!=-1){
		V[index].SetName(nm);
	}
	cout<<"After Updating :";
	GetCustomerDetails(index).Display();

}

void CustomerDetail::Display()
{
	//Need To Implement
	cout<<"Sr. Name\t Number "<<endl;
	for(int i=0;i<GetTotalCustomerCount();i++){
		cout<<i+1<<". ";
		GetCustomerDetails(i).Display();
	}
}

int CustomerDetail::GetTotalCustomerCount()const
{
	//No Need To Implement
	return V.size();
}

PhoneDirectory CustomerDetail::GetCustomerDetails(int index)const
{
	return V[index];		// No Need To Implement
}

void CustomerDetail::Select(std::string Str){
	int Choice;
	int Index;
	std::string name,number;
	cout<<"\n1. "<<Str<<" By Name\t2. "<<Str<<" By Number"<<endl;
	cin>>Choice;
	switch(Choice){
	case 1:
		cout<<"Enter Name To "<<Str<<":";
		cin>>name;
		if(Str=="Search"){
			Index=SearchByName(name);
			GetCustomerDetails(Index).Display();
		}
		if(Str=="Update"){
			cout<<"Enter New Number:";
			cin>>number;
			UpdateByName(name,number);
		}
		break;
	case 2:
		cout<<"Enter Number To "<<Str<<":";
		cin>>number;
		if(Str=="Search"){
			Index=SearchByNumber(number);
			GetCustomerDetails(Index).Display();
		}
		if(Str=="Update"){
			cout<<"Enter New Name:";
			cin>>name;
			UpdateByNumber(name,number);
		}
		break;
	default:
		cout<<"Please enter correct Option"<<endl;
	}
}

void CustomerDetail::Count(){
	cout<<"No. of contacts in phone directory : "<<GetTotalCustomerCount();
}