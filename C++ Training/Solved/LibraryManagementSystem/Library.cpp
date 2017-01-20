#include"Library.h"
#include"Student.h"
#include<iostream>
#include<fstream>
#include<list>
using namespace std;



void Library:: ReadBook_List()
{
	// Need to implement
	ifstream is;
	is.open("Library",ios::binary);
	if(is.is_open())
	{
		while(!(is.eof())){
		book_List.ReadFromFile(is);
		if(is.fail())
			break;
		book_List.Display_BookDetails();
		}
		is.close();
	}
}
void Library:: WriteBook_List(Book book_list)
{
	// Need to implement
	ofstream os;
	os.open("Library",ios::binary | ios::app);
	if(os.is_open())
	{
		book_list.SaveToFile(os);
		os.close();
	}
}
void Library:: ModifyBook_List(Book book_list)
{
	// Need to implement
	list<Book> BList;
	ifstream is;
	is.open("Library",ios::binary);
	if(is.is_open())
	{
		while(!(is.eof())){
		book_List.ReadFromFile(is);
		if(is.fail())
			break;
		BList.push_back(book_List);
		}
		is.close();
		
	}
	std::list<Book>::iterator it;
	ofstream os;
	os.open("Library",ios::binary);
	os.seekp(0,ios::beg);
	if(os.is_open())
	{
	for(it=BList.begin();it!=BList.end();it++)
	{
			if(it->Getbook_Number()==book_list.Getbook_Number())
			{
				book_list.SaveToFile(os);
				continue;
			}
			it->SaveToFile(os);
	}
	os.close();
	}
}
void Library:: DeleteBook_List(string book_number)
{
		// Need to implement
	list<Book> BList;
	ifstream is;
	is.open("Library",ios::binary);
	if(is.is_open())
	{
		while(!(is.eof()))
		{
		book_List.ReadFromFile(is);
		if(is.fail())
			break;
		BList.push_back(book_List);
		}
		is.close();
	}
	std::list<Book>::iterator it;
	ofstream os;
	os.open("Library",ios::binary);
	os.seekp(0,ios::beg);
	if(os.is_open())
	{

	for(it=BList.begin();it!=BList.end();it++)
		{
			if((*it).Getbook_Number()==book_number)
			{
				continue;
			}
			it->SaveToFile(os);
		}
	os.close();
	}
}

void Library::Issue_book_to_student_from_Library(Student student,string book_number)
{
	// Need to implement
	ifstream is;
	Student std;
	bool flag=true;
	is.open("Library",ios::binary);
	if(is.is_open())
	{
		while(!(is.eof())){
		book_List.ReadFromFile(is);
		if(is.fail())
			break;
		if(book_List.Getbook_Number()==book_number)
		{
			
			if(book_List.Getbook_Quantity()==0){
				flag=false;
				break;
			}
			book_List.Setbook_Quantity(book_List.Getbook_Quantity()-1);
			break;
		}
		}
		is.close();
	}
	
	ofstream os;
	if(flag){
	os.open("StudentLibraryCard",ios::binary | ios::app);
	if(os.is_open())
	{
		student.SaveToFile(os);
		book_List.SaveToFile(os);
		os.close();
		ModifyBook_List(book_List);
	}
	}
	else{
		cout<<"Error:Can't Issue, Insufficient Quantity";
	}
}
void Library::Submit_Issued_book_from_student_in_the_Library(string student_id_num,string book_number)
{
	// Need to implement
	ifstream is;
	ofstream os;
	Student std;
	is.open("StudentLibraryCard",ios::binary);
	os.open("tmp",ios::binary);
	if(is.is_open())
	{
		if(os.is_open()){
		while(!(is.eof())){
		std.ReadFromFile(is);
		book_List.ReadFromFile(is);
		if(is.fail())
			break;
		if(std.Getstudent_ID_Num()==student_id_num && book_List.Getbook_Number()==book_number)
		{
			book_List.Setbook_Quantity(book_List.Getbook_Quantity()+1);
			ModifyBook_List(book_List);
			continue;
		}
		std.SaveToFile(os);
		book_List.SaveToFile(os);
		}
		os.close();
		}
		is.close();
	}
	remove("StudentLibraryCard");
	rename("tmp","StudentLibraryCard");
}

void Library::Read_the_Student_library_card()
{
	// Need to implement
	ifstream is;
	Student std;
	is.open("StudentLibraryCard",ios::binary);
	if(is.is_open()){
		while(!(is.eof())){

			std.ReadFromFile(is);
			book_List.ReadFromFile(is);
			if(is.fail())
				break;
			std.Display_Student_Details();
			book_List.Display_BookDetails();
		}
		is.close();
	}
}
Book Library::Getbook_List()
{
	return book_List;	// No Need to implement
}
void Library:: Setbook_List(Book book_list)
{
	book_List = book_list;	// No Need to implement
}