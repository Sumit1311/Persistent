#include<iostream>
using namespace std;
#include"BankSystem.h"

int main()
{
	BankSystem BS;
	char Ch;
	do
	{
		try{
		cout<<endl<<"****** MENU ******"<<endl;
		cout<<"1.Create_AddCustomerAccount_BankSystem"<<endl;
		cout<<"2.SearchCustomerDetails_byName"<<endl;
		cout<<"3.SearchCustomerDetails_byAccountNumber"<<endl;
		cout<<"4.UpdateCustomerDetails_byAccountNumber"<<endl;
		cout<<"5.DepositCustomerDetails_byAccountNumber"<<endl;
		cout<<"6.WithdrawMoney_byAccountNumber"<<endl;
		cout<<"7.BalanceInquiryofCustomer_byAccountNumber"<<endl;
		cout<<"8.DeleteCustomerDetails_byAccountNumber"<<endl;
		cout<<"9.DisplayAllCustomerDetails"<<endl;
		cout<<"10.EXIT"<<endl;

		int Choice;
		
		cout<<"Enter your choice"<<endl;
		cin>>Choice;

		switch(Choice)
		{
			case 1:
				{
					BankCustomerDetails BCD;
					BCD.AcceptBankCustomerDetails();
					BS.Create_AddCustomerAccount_BankSystem(BCD);
				}
				break;
			case 2:
				{
					string nm;
					cout<<"Enter The Customer Name to Search Details"<<endl;
					cin>>nm;
					int flag = BS.SearchCustomerDetails_byName(nm);
				}
				break;

			case 3:
				{
					unsigned long int A_num;
					cout<<"Enter The Customer byAccountNumber to Search Details"<<endl;
					cin>>A_num;
					
					bool flag = BS.SearchCustomerDetails_byAccountNumber(A_num);
				}
			break;
			case 4:
				{
					string nm;
					unsigned long int A_num;
					cout<<"Enter The Customer byAccountNumber to Update The CustomerDetails"<<endl;
					cin>>A_num;
					cout<<"Enter The Customer to Search Details"<<endl;
					cin>>nm;
					BS.UpdateCustomerDetails_byAccountNumber(nm, A_num);
				}
			break;
			case 5:
					
					double Amount;
					unsigned long int A_num;
					cout<<"Enter The Customer AccountNumber to Deposit money"<<endl;
					cin>>A_num;
					cout<<"5.Enter the Amount to Deposit Customer AccountNumber"<<endl;
					cin>>Amount;
					BS.DepositMoney_byAccountNumber(A_num,Amount);

			break;
			case 6:
				{
					double Amount;
					unsigned long int A_num;
					cout<<"Enter The Customer AccountNumber to Withdraw money"<<endl;
					cin>>A_num;
					cout<<"5.Enter the Amount to WithdrawMoney from Customer Account"<<endl;
					cin>>Amount;
					BS.WithdrawMoney_byAccountNumber(A_num,Amount);
				}
			break;

		case 7:
			{
					unsigned long int A_num;
					cout<<"Enter The Customer AccountNumber to Balance Inquiry of Customer money"<<endl;
					cin>>A_num;
					BS.BalanceInquiryofCustomer_byAccountNumber(A_num);
			}
			break;

			case 8:
				{
					unsigned long int A_num;
					cout<<"Enter The Customer AccountNumber to Delete the CustomerDetails"<<endl;
					cin>>A_num;
					BS.DeleteCustomerDetails_byAccountNumber(A_num);
				}
	
			break;
			case 9:
				cout<<"9.DisplayAllCustomerDetails"<<endl;
				BS.DisplayAllCustomerDetails();
			break;
			case 10:
				exit(0);
			break;

			default:
				cout<<"Invalide Choice"<<endl;
		}
		}
		catch(std::string Str)
		{
			cout<<Str;
		}
		catch(exception &e)
		{
			cout<<e.what();
		}
		cout<<"\nDO YOU WANT TO CONTINUE.............. Y / N"<<endl;
		cin>>Ch;
	}while(Ch == 'Y' || Ch == 'y');

	return 0;
}




