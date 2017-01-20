#include<string>
using namespace std;
#ifndef Book_h
#define Book_h
class Book
{
	private:
		string book_Number;
		string book_Name;
		string book_Author;
		string book_Publisher;
		string book_Edition;
		int book_Quantity;
	public:
		Book();
		Book(string,string,string,string,string,int);

		//Getter Functions/method
		string Getbook_Number();
		string Getbook_Name();
		string Getbook_Author();
		string Getbook_Publisher();
		string Getbook_Edition();
		int Getbook_Quantity();

		//Setter Functions/method
		void Setbook_Number(string);
		void Setbook_Name(string);
		void Setbook_Author(string);
		void Setbook_Publisher(string);
		void Setbook_Edition(string);
		void Setbook_Quantity(int);

		void Accept_BookDetails();
		void Display_BookDetails();

		void SaveToFile(ostream &os);
		void ReadFromFile(istream &is);
};

#endif