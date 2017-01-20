#include"Supermarket_Billing_System.h"
#include<fstream>
#include<iostream>
#include<list>
using namespace std;
list<Product> Supermarket_Billing_System::GetProduct_list()
{
	return Product_list;
}

void Supermarket_Billing_System::SetProduct_list(list<Product> product_list)
{
	Product_list = product_list;
}
//Administrator Login
void Supermarket_Billing_System::AdministratorLogin()
{
	char ch;
	int Choice;
	do
	{
		cout<<"\n****** Product list menu ******\n";
		cout<<"1. Add and write a new product in product list"<<endl;
		cout<<"2. Read display the product from product list"<<endl;
		cout<<"\nEnter Your Choice"<<endl;
		cin>>Choice;
			switch(Choice)
			{
				case 1:
				{
						Product p1;
						p1.Accept_Product();
						Add_and_WriteNewProduct(p1);	
				}
				break;

				case 2:
				{
						Read_DisplayProductFromProductList();
				}
				break;

				default:
					cout<<"Invalide Choice"<<endl;
			}	

			cout<<"\nDO YOU WANT TO CONTINUE...... Y/N"<<endl;
			cin>>ch;
		}while(ch == 'y' || ch == 'Y');
}

//Customet Login
void Supermarket_Billing_System::CustometLogin()
{
	char ch;
	int Choice;
	do
	{
		cout<<"\n****** Customer bill menu******\n";
		cout<<"1. Add and write new product in customer bill"<<endl;
		cout<<"2. Read and display the product from customer bill"<<endl;
		cout<<"\nEnter Your Choice"<<endl;
		cin>>Choice;
			switch(Choice)
			{
				case 1:
				{
						//Need To Implement
					Product p1;
					Read_DisplayProductFromProductList();
					p1.Accept_ProductForBilling();
					this->Write_AddNewProductInCustomerBill(p1);
				}
				break;
				case 2:
				{
					this->Read_DisplayProductFromInCustomerBill();
				}
				break;
			default:
				cout<<"Invalide Choice"<<endl;
		}

		cout<<"\nDO YOU WANT TO CONTINUE...... Y/N"<<endl;
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
}

//Add and write a new product in product list
void Supermarket_Billing_System::Add_and_WriteNewProduct(Product P)
{
	//Need To Implement
	ofstream os;
	os.open("Product.bin",ios::out | ios::binary | ios::app);
	if(os.is_open()){
	P.store(os);
	os.close();
	}
	throw "Can't Open File ProductList";
}

//Read display the product from product list
void Supermarket_Billing_System::Read_DisplayProductFromProductList()
{
	//Need To Implement
	this->ReadProductList();
	std::list<Product>::iterator it;
	for(it=Product_list.begin();it!=Product_list.end();it++){
		it->Display_Product();
	}
	//cout<<"Completed Reading File";
}

//Add and write new product in customer bill
void Supermarket_Billing_System::Write_AddNewProductInCustomerBill(Product P)
{
	//Need To Implement
	ofstream os;
	os.open("Customer_bill",ios::out | ios::binary | ios::app);
	if(os.is_open()){
	os.write((char *)&P.Cp,sizeof(P.Cp));
	os.close();
	}
	throw "Can't Open File Customer_bill";

}

//Read and display the product from customer bill
void Supermarket_Billing_System::Read_DisplayProductFromInCustomerBill()
{
	//Need To Implement
	this->ReadProductList();
	std::list<Product>::iterator it;
	ifstream is;
	CustomerProduct temp;
	is.open("Customer_bill",ios::in | ios::binary);
	if(is.is_open()){
	while(!(is.eof())){
		is.read((char *)&temp,sizeof(temp));
		if(is.fail())
			break;
		temp.Display_Product();
		for(it=Product_list.begin();it!=Product_list.end();it++)
		{
			if(it->GetProduct_no()==temp.GetProduct_id())
			{
				it->Display_Product();
			}
		}
	}
	is.close();
	}
	throw "Can't Open File Customer_bill";
}

void Supermarket_Billing_System::ReadProductList()
{
	if(!(Product_list.empty()))
	{
		Product_list.erase(Product_list.begin(),Product_list.end());
	}
	ifstream is;
	Product temp;
	if(is.is_open()){
	is.open("ProductList",ios::in | ios::binary);
	while(!(is.eof())){
		temp.read(is);
		if(is.fail())
			break;
		//temp.Display_Product();
		Product_list.push_back(temp);
	}
	is.close();
	}
	throw "Can't Open File ProductList ";
}
