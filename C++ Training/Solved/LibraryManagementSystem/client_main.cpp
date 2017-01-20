#include"Library.h"
#include"Book.h"
#include"Student.h"
#include<iostream>
using namespace std;

int main()
{
	char ch;
	int choice;
	Library L;
	Book B;
	Student S;
	do
	{
		cout<<endl<<"***** Main Menu *****"<<endl;
		cout<<endl<<"1. Read the Book list data from Library";
		cout<<endl<<"2. Write the Book Information data in Library";
		cout<<endl<<"3. Update / modify the book Information in library according book number.";
		cout<<endl<<"4. Delete the book from Library records according book number.";
		cout<<endl<<"5. Issue a book to student from Library according student Id Number and book number availability";
		cout<<endl<<"6. Submit the Issued book from student in the Library according student Id Number and book number";
		cout<<endl<<"7. Read the Student library card Information";
		cout<<endl<<"Enter your choice"<<endl;
		fflush(stdin);
		cin>>choice;

		switch(choice)
		{
			case 1:
			{
				L.ReadBook_List();
			}
			break;
			case 2:
			{
				B.Accept_BookDetails();
				L.WriteBook_List(B);
			}
			break;
			
			case 3:
			{
				cout<<endl<<"Enter the book details to update/modify...."<<endl;
				B.Accept_BookDetails();
				L.ModifyBook_List(B);
			}
			break;

			
			case 4:
			{
				string book_number;
				cout<<endl<<"Enter the Book Number to delete from book_list"<<endl;
				fflush(stdin);
				getline(cin,book_number);

				L.DeleteBook_List(book_number);

			}
			break;
			
			case 5:
			{
				string book_number;
				cout<<endl<<"Enter The Student details";
				S.Accept_Student_Details();
				cout<<endl<<"Enter the book number for book issue";
				fflush(stdin);
				getline(cin,book_number);
				L.Issue_book_to_student_from_Library(S,book_number);
			}
			break;
			case 6:
			{
				string book_number,student_id_num;
				cout<<endl<<"Enter The Student id number";
				fflush(stdin);
				getline(cin,student_id_num);
				cout<<endl<<"Enter the book number for book issue";
				fflush(stdin);
				getline(cin,book_number);
				L.Submit_Issued_book_from_student_in_the_Library(student_id_num,book_number);
			}
			break;
			case 7:
			{
				L.Read_the_Student_library_card();
			}
			break;
			default:
				cout<<endl<<"Invalide Choice";
		}

		cout<<endl<<"Do you want to continue ....... Y/N"<<endl;
		fflush(stdin);
		cin>>ch; 
	}while(ch == 'y' || ch == 'Y');
	return 0;
}