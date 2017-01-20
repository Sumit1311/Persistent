#include"BankSystem.h"
#include<iostream>
#include<list>
#include<iterator>
using namespace std;

std::list<BankCustomerDetails> BankSystem::GetBankCustomerDetails()
{
	return BCD;//No Need to implement
}
void BankSystem::SetBankCustomerDetails(std::list<BankCustomerDetails>&bcd)
{
	BCD = bcd;//No Need to implement
}

void BankSystem::Create_AddCustomerAccount_BankSystem(BankCustomerDetails &bcd)
{
	//Need to implement
	if(SearchCustomerDetails_byAccountNumber(bcd.GetBankCustomerAccount_Number())){
		throw std::string("Customer Already Exists");
	}
	BCD.push_back(bcd);
	cout<<"New Customer Added Successfully";
}

int BankSystem::GetTotalCustomerCount()
{
	return BCD.size();//No Need to implement
}
bool BankSystem::SearchCustomerDetails_byName(std::string name)
{
	//Need to implement and if record is found return true else return false
	std::list<BankCustomerDetails>::iterator ListIterator;
	bool flag=false;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if((ListIterator->GetBankCustomerName())==name){
			cout<<"Customer Found";
			ListIterator->DisplayBankCustomerDetails();
			flag=true;
		}	
	}
	if(!(flag)){
		cout<<"No Customer Found";
	}
	return flag;
}  
bool BankSystem::SearchCustomerDetails_byAccountNumber(unsigned long int A_Num)
{
	//Need to implement and if record is found return true else return false
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if((ListIterator->GetBankCustomerAccount_Number())==A_Num){
			cout<<"Customer Found";
			ListIterator->DisplayBankCustomerDetails();
			return true;
		}
	}
	cout<<"No Customer Found";
	return false;
}


void BankSystem::UpdateCustomerDetails_byAccountNumber(std::string name,unsigned long int A_Num)
{
	//Need to implement
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if(((ListIterator->GetBankCustomerAccount_Number())==A_Num) && ((ListIterator->GetBankCustomerName())==name)){
			cout<<"Before Updating:";
			ListIterator->DisplayBankCustomerDetails();
			ListIterator->AcceptBankCustomerDetails();
			cout<<"After Updating:";
			ListIterator->DisplayBankCustomerDetails();
			return;
		}
	}
	cout<<"No Customer Found";
}

void BankSystem::DepositMoney_byAccountNumber(unsigned long int A_Num, double Balance)
{
	//Need to implement
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if((ListIterator->GetBankCustomerAccount_Number())==A_Num){
			double bal;
			bal=ListIterator->GetBankCustomerAccount_Balance()+Balance;
			ListIterator->SetBankCustomerAccount_Balance(bal);
			cout<<"Balance After Deposit :"<<bal;
			return;
		}
	}
	cout<<"No Customer Found";
}

void BankSystem::WithdrawMoney_byAccountNumber(unsigned long int A_Num, double amount)
{
	// No need ti implement
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if((ListIterator->GetBankCustomerAccount_Number())==A_Num){
			double bal;
			bal=ListIterator->GetBankCustomerAccount_Balance()-amount;
			if(bal>500){														//Considering min. balance to be 500
				ListIterator->SetBankCustomerAccount_Balance(bal);
				cout<<"Can't Perform Withdrawal";
			}
			cout<<"Balance After Withdrawal :"<<ListIterator->GetBankCustomerAccount_Balance();
			return;
		}
	}
	cout<<"No Customer Found";
}

double BankSystem::BalanceInquiryofCustomer_byAccountNumber(unsigned long int A_Num)
{
	// Need to implement BalanceInquiryofCustomer_byAccountNumber  if found return actual customer balance else 0
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if((ListIterator->GetBankCustomerAccount_Number())==A_Num){
			cout<<"Balance is :"<<ListIterator->GetBankCustomerAccount_Balance();
			return ListIterator->GetBankCustomerAccount_Balance();
		}
	}
	return 0.0;
}

void BankSystem::DeleteCustomerDetails_byAccountNumber(unsigned long int A_Num)
{
	// No need ti implement
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		if((ListIterator->GetBankCustomerAccount_Number())==A_Num){
			BCD.erase(ListIterator);
			cout<<"Account successfully deleted";
			return;
		}
	}
	cout<<"No Customer Found";
}

void BankSystem::DisplayAllCustomerDetails()
{
	// No need ti implement
	std::list<BankCustomerDetails>::iterator ListIterator;
	for(ListIterator=BCD.begin();ListIterator!=BCD.end();ListIterator++){
		ListIterator->DisplayBankCustomerDetails();
	}
}