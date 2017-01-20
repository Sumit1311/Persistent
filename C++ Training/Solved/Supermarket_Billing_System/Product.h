//Product Class

#include<iostream>
using namespace std;
#ifndef Product_h
#define Product_h

class Product;
class CustomerProduct
{
			private:
				long int Product_id;
				int Product_qty;
			public:
				CustomerProduct();
				long int GetProduct_id();
				int GetProduct_qty();
				void SetProduct_id(long int);
				void SetProduct_qty(int);
				void Display_Product();
};

class Product
{
	private:
		 long int Product_no;
		 std::string Product_name;
		 double Product_price;
		 int Product_qty;
		 double Product_tax;
		 double Product_dis;

	public:
		CustomerProduct Cp;
		
		//Constructor
		Product();
		Product(long int, string, double, int, double, double);

		//All Getters methods
		long int GetProduct_no();
		string GetProduct_name();
		double GetProduct_price();
		int GetProduct_qty();
		double GetProduct_tax();
		double GetProduct_dis();

		//All Setters methods
		void SetProduct_no(long int);
		void SetProduct_name(string);
		void SetProduct_price(double);
		void SetProduct_qty(int);
		void SetProduct_tax(double);
		void SetProduct_dis(double);

		void Accept_Product();
		void Accept_ProductForBilling();
		void Display_Product();

		//Storing and Loading Data From Files
		void store(ostream &os);
		void read(istream &is);
		

};


#endif