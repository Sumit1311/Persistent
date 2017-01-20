#include"Book.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

Book::Book():book_Number(""),book_Name(""),book_Author(""),book_Publisher(""),book_Edition(""),book_Quantity(0)
{
	//No need to implement
}
Book::Book(string book_number,string book_name, string book_author, string book_publisher, string book_edition,int book_quantity):book_Number(book_number),book_Name(book_name),book_Author(book_author),book_Publisher(book_publisher),book_Edition(book_edition),book_Quantity(book_quantity)
{
	//No need to implement
}

//Accept the Book Details
void Book::Accept_BookDetails()
{
	//Need to implement
	cout<<"Enter Book Number :";
	fflush(stdin);
	getline(cin,this->book_Number);
	cout<<"Enter Book Name :";
	fflush(stdin);
	getline(cin,this->book_Name);
	cout<<"Enter Book Author :";
	fflush(stdin);
	getline(cin,this->book_Author);
	cout<<"Enter Book Publisher :";
	fflush(stdin);
	getline(cin,this->book_Publisher);
	cout<<"Enter Book Edition :";
	fflush(stdin);
	getline(cin,this->book_Edition);
	cout<<"Enter Quantity Of Book :";
	cin>>this->book_Quantity;
}

//Show the Book Details
void Book::Display_BookDetails()
{
	//Need to implement
	cout<<"Book Number :"<<this->book_Number<<endl;
	cout<<"Book Name :"<<this->book_Name<<endl;
	cout<<"Book Author :"<<this->book_Author<<endl;
	cout<<"Book Publisher :"<<this->book_Publisher<<endl;
	cout<<"Book Edition :"<<this->book_Edition<<endl;
	cout<<"Quantity Of Book :"<<this->book_Quantity<<endl;

}

//Getter Functions/method
string Book::Getbook_Number()
{
	return book_Number;	//No Need to implement
}

string Book::Getbook_Name()
{
	return book_Name;//No Need to implement
}
string Book::Getbook_Author()
{
	return book_Author;//No Need to implement
}
string Book::Getbook_Publisher()
{
	return book_Publisher;//No Need to implement
}
string Book::Getbook_Edition()
{
	return book_Edition;//No Need to implement
}
int Book::Getbook_Quantity()
{
	return book_Quantity;//No Need to implement
}
//Setter Functions/method

void Book::Setbook_Number(string book_number)
{
	book_Number = book_number;//No Need to implement
}

void Book::Setbook_Name(string book_name)
{
	book_Name = book_name;//No Need to implement
}
void Book::Setbook_Author(string book_author)
{
	book_Author = book_author;//No Need to implement
}
void Book::Setbook_Publisher(string book_publisher)
{
	book_Publisher = book_publisher;//No Need to implement
}
void Book::Setbook_Edition(string book_edition)
{
	book_Edition = book_edition;//No Need to implement
}
void Book::Setbook_Quantity(int book_quantity)
{
	book_Quantity = book_quantity;//No Need to implement
}

void Book::SaveToFile(ostream &os)
{
	int LenId=this->book_Number.length();
	int LenName=this->book_Name.length();
	int LenAuthor=this->book_Author.length();
	int LenPublish=this->book_Publisher.length();
	int LenEdition=this->book_Edition.length();
	os.write((char *)&LenName,sizeof(LenName));
	os.write((char *)&LenId,sizeof(LenId));
	os.write((char *)&LenAuthor,sizeof(LenAuthor));
	os.write((char *)&LenPublish,sizeof(LenPublish));
	os.write((char *)&LenEdition,sizeof(LenEdition));
	os.write(this->book_Name.c_str(),LenName);
	os.write(this->book_Number.c_str(),LenId);
	os.write(this->book_Author.c_str(),LenAuthor);
	os.write(this->book_Publisher.c_str(),LenPublish);
	os.write(this->book_Edition.c_str(),LenEdition);
	os.write((char *)&this->book_Quantity,sizeof(book_Quantity));
}
void Book::ReadFromFile(istream &is)
{
	int LenId=this->book_Number.length();
	int LenName=this->book_Name.length();
	int LenAuthor=this->book_Author.length();
	int LenPublish=this->book_Publisher.length();
	int LenEdition=this->book_Edition.length();
	is.read((char *)&LenName,sizeof(LenName));
	is.read((char *)&LenId,sizeof(LenId));
	is.read((char *)&LenAuthor,sizeof(LenAuthor));
	is.read((char *)&LenPublish,sizeof(LenPublish));
	is.read((char *)&LenEdition,sizeof(LenEdition));
	char *name=new char[LenName+1];
	char *id=new char[LenId+1];
	char *auth=new char[LenAuthor+1];
	char *publ=new char[LenPublish+1];
	char *edi=new char[LenEdition+1];
	name[LenName]='\0';
	id[LenId]='\0';
	auth[LenAuthor]='\0';
	publ[LenPublish]='\0';
	edi[LenEdition]='\0';
	is.read(name,LenName);
	is.read(id,LenId);
	is.read(auth,LenAuthor);
	is.read(publ,LenPublish);
	is.read(edi,LenEdition);
	is.read((char *)&this->book_Quantity,sizeof(book_Quantity));
	this->book_Name.assign(name);
	this->book_Number.assign(id);
	this->book_Author.assign(auth);
	this->book_Publisher.assign(publ);
	this->book_Edition.assign(edi);
}