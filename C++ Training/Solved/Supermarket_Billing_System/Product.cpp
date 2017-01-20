#include"Product.h"
#include<iostream>
#include<string>
using namespace std;

Product::Product()
{
	Product_no = 0;
	Product_name = "";
	Product_price = 0.0;
	Product_qty = 0;
	Product_tax = 0.0;
	Product_dis = 0.0;
}
Product::Product(long int P_no, string P_name, double P_price, int P_qty, double P_tax, double P_dis):Product_no(P_no),Product_name(P_name),Product_price(P_price),Product_qty(P_qty),Product_tax(P_tax),Product_dis(P_dis)
{
}
long int Product::GetProduct_no()
{
	return Product_no;
}
string Product::GetProduct_name()
{
	return Product_name;
}
double Product::GetProduct_price()
{
	return Product_price;
}
int Product::GetProduct_qty()
{
	return Product_qty;
}
double Product::GetProduct_tax()
{
	return Product_tax;
}
double Product::GetProduct_dis()
{
	return Product_dis;
}

void Product::SetProduct_no(long int product_No)
{
	Product_no = product_No;
}
void Product::SetProduct_name(string product_Name)
{
	Product_name = product_Name;
}
void Product::SetProduct_price(double product_Price)
{
	Product_price = product_Price;
}
void Product::SetProduct_qty(int product_Qty)
{
	Product_qty = product_Qty;
}
void Product::SetProduct_tax(double product_Tax)
{
	Product_tax = product_Tax;
}
void Product::SetProduct_dis(double product_Dis)
{
	Product_dis = product_Dis;
}

void Product::Accept_Product()
{
	//Need To Implement
	cout<<"Enter Product No. :"<<endl;
	cin>>Product_no;
	cout<<"Enter Product Name :"<<endl;
	fflush(stdin);
	getline(cin,Product_name);
	cout<<"Enter Product Price :"<<endl;
	cin>>Product_price;
	cout<<"Enter Quantity Of Product :"<<endl;
	cin>>Product_qty;
	cout<<"Enter Tax On Product :"<<endl;
	cin>>Product_tax;
	cout<<"Enter Discount On Product :"<<endl;
	cin>>Product_dis;
}
void Product::Display_Product()
{
	//Need To Implement
	cout<<"Product No.\t"<<Product_no<<endl;
	cout<<"Product Name\t"<<Product_name<<endl;
	cout<<"Product Price\t"<<Product_price<<endl;
	cout<<"Product Quantity\t"<<Product_qty<<endl;
	cout<<"Product Tax\t"<<Product_tax<<endl;
	cout<<"Product Discount\t"<<Product_dis<<endl;
}
void Product::Accept_ProductForBilling()
{
	long int temp=0;
	int qt;
	cout<<"Enter Product No.";
	cin>>temp;
	this->Cp.SetProduct_id(temp);
	cout<<"Enter Quantity Of Product :";
	cin>>qt;
	this->Cp.SetProduct_qty(qt);
}

void Product::store(ostream& os)
{
	int Len=this->Product_name.length();
	os.write((char *)&Len,sizeof(Len));
	os.write((char *)&this->Product_no,sizeof(this->Product_no));
	os.write(this->Product_name.c_str(),Len);
	os.write((char *)&this->Product_price,sizeof(this->Product_price));
	os.write((char *)&this->Product_qty,sizeof(this->Product_qty));
	os.write((char *)&this->Product_tax,sizeof(this->Product_tax));
	os.write((char *)&this->Product_dis,sizeof(this->Product_dis));
}
void Product::read(istream& is)
{
	int Len=0;
	is.read((char *)&Len,sizeof(int));
	char *name=new char[Len+1];
	is.read((char *)&this->Product_no,sizeof(this->Product_no));
	is.read((char *)name,Len);
	name[Len]='\0';
	is.read((char *)&this->Product_price,sizeof(this->Product_price));
	is.read((char *)&this->Product_qty,sizeof(this->Product_qty));
	is.read((char *)&this->Product_tax,sizeof(this->Product_tax));
	is.read((char *)&this->Product_dis,sizeof(this->Product_dis));
	this->Product_name.assign(name);
}

CustomerProduct::CustomerProduct(){
}
long int CustomerProduct::GetProduct_id()
{
	return this->Product_id;
}
int CustomerProduct::GetProduct_qty()
{
	return this->Product_qty;
}
void CustomerProduct::SetProduct_id(long int id)
{
	this->Product_id=id;
}
void CustomerProduct::SetProduct_qty(int qt)
{
	this->Product_qty=qt;
}
void CustomerProduct::Display_Product()
{
	cout<<"Product Id :"<<this->Product_id<<endl;
	cout<<"Product Qty :"<<this->Product_qty<<endl;
}