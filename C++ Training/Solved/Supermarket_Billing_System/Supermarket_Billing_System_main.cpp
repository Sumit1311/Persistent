#include"Supermarket_Billing_System.h"
#include<iostream>
using namespace std;

int main()
{
	char ch;
	int Choice;
	Product p1;
	Supermarket_Billing_System Supmktbillsys;
	do
	{
		cout<<"\n****** Main menu ******\n";
		cout<<"1. Login as an Administrator"<<endl;
		cout<<"2. Login as a Customer"<<endl;
		cout<<"\nEnter Your Choice"<<endl;
		cin>>Choice;
		switch(Choice)
		{
			case 1:
				{
					Supmktbillsys.AdministratorLogin();
				}
				break;
			case 2:
				{
					Supmktbillsys.CustometLogin();
				}
				break;
			default:
				cout<<"Invalide Choice"<<endl;
		}

		cout<<"\nDo you want to continue with main menu...... Y/N"<<endl;
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
	return 0;
}