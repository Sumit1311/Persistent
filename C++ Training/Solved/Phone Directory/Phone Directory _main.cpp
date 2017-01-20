

#include"Phone Directory.h"
#include"CustomerDetaila.h"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	char Ch;
	PhoneDirectory Pdetails;
	CustomerDetail Cdetails;
	std::string Decision;
	//As Per Requirement Declare Objects or Variables.
	
	do
	{
		try
		{
		std::cout<<"\n***** MENU *****\n"<<endl;
		//Need to Implement menu
		std::cout<<"1. Add Customer Details\t2. Stastics Of Phone Directory \t3. Search For Customer Details \t4. Update CustomerDetail\t5. Display All Details\n"<<endl;
		int Choice;
		std::cout<<"Please Enter your choice"<<endl;
		std::cin>>Choice;
		
		switch(Choice)
		{
				case 1:
				{
					Cdetails.AddCustomerDetails(Pdetails);
					//Need To Call a method		
				}
					break;
				case 2:
				{
					Cdetails.Count();
					//Need To Call a method		
				}
					break;
				case 3:
				{
					Cdetails.Select("Search");
					//Need To Call a method		
				}
					break;
				
				case 4:
				{
					Cdetails.Select("Update");
					//Need To Call a method		
				}
					break;
				case 5:
					Cdetails.Display();
					//Need To Call a method		
					break;
				default:
					std::cout<<"Please enter correct Option"<<endl;

		}
		}
		catch(std::string Str){
		cout<<Str;
		}
						
		std::cout<<"\nDO YOU WANT TO CONTINUE.........\n"<<endl;
		std::cin>>Ch;
	}while(Ch=='Y' || Ch == 'y');
	
	return 0;
}


