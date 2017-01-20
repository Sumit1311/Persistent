
#include"Book.h"
#include"Student.h"
#ifndef Library_h
#define Library_h

class Library
{
	private:
		Book book_List;
	public:

			Book Getbook_List();
			void Setbook_List(Book);

			void ReadBook_List();
			void WriteBook_List(Book book_list);
			void ModifyBook_List(Book book_list);
			void DeleteBook_List(string);
			void Issue_book_to_student_from_Library(Student,string);
			void Submit_Issued_book_from_student_in_the_Library(string,string);
			void Read_the_Student_library_card();

};

#endif