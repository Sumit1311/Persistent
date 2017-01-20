#include"BankCustomerDetails.h"
#include<iostream>
#include<string>
using namespace std;

BankCustomerDetails::BankCustomerDetails():Name(""),Account_Number(0),Account_Balance(0)
{
	//No Need to implement
}
BankCustomerDetails::BankCustomerDetails(std::string name,unsigned long int A_Num, double A_Bal):Name(name),Account_Number(A_Num),Account_Balance(A_Bal)
{
	//No Need to implement
}

std::string BankCustomerDetails::GetBankCustomerName()
{
	return this->Name;	//No Need to implement
} 
unsigned long int BankCustomerDetails::GetBankCustomerAccount_Number()
{
	return Account_Number;	//No Need to implement
}
double BankCustomerDetails::GetBankCustomerAccount_Balance()
{
	return Account_Balance;	//No Need to implement
}

void BankCustomerDetails::SetBankCustomerName(std::string &name)
{
	Name = name;	//No Need to implement
} 
void BankCustomerDetails::SetBankCustomerAccount_Number(unsigned long int &A_Num)
{
	Account_Number = A_Num;	//No Need to implement
}
void BankCustomerDetails::SetBankCustomerAccount_Balance(double &A_Bal)
{
	Account_Balance = A_Bal;	//No Need to implement
}

void BankCustomerDetails::AcceptBankCustomerDetails()
{
	//Need to implement
	cout<<"Enter Name Of Customer:";
	cin>>this->Name;
	cout<<endl;
	cout<<"Enter A/c No. Of Customer:";
	cin>>this->Account_Number;
	cout<<endl;
	cout<<"Enter Balance Of Customer:";
	cin>>this->Account_Balance;
	cout<<endl;
}
void BankCustomerDetails::DisplayBankCustomerDetails()
{
	// Need to implement
	cout<<"Name : "<<this->Name;
	cout<<"\tA/c No. : "<<this->Account_Number;
	cout<<"\tBalance : "<<this->Account_Balance<<endl;
}
