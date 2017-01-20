
#include<string>
using namespace std;

#ifndef Student_h
#define Student_h

class Student
{
	private:
	string student_ID_Num;
	string student_Name;

	public:

		void Accept_Student_Details();
		void Display_Student_Details();

		Student();
		Student(string,string);
		string Getstudent_ID_Num();
		string Getstudent_Name();

		void Setstudent_ID_Num(string);
		void Setstudent_Name(string);

		void SaveToFile(ostream & os);
		void ReadFromFile(istream & is);
};

#endif