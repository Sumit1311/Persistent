#include<iostream>
using namespace std;
#include"Product.h"
#include<list>

#ifndef Supermarket_Billing_System_h
#define Supermarket_Billing_System_h

class Supermarket_Billing_System
{
	private:
		list<Product> Product_list;

		void Add_and_WriteNewProduct(Product);
		void Read_DisplayProductFromProductList();
		void ReadProductList();

		void Write_AddNewProductInCustomerBill(Product);
		void Read_DisplayProductFromInCustomerBill();
		
	public:
		list<Product> GetProduct_list();
		void SetProduct_list(list<Product>);
		void CustometLogin();
		void AdministratorLogin();
};

#endif