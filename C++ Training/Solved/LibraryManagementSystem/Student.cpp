#include"Student.h"
#include<iostream>
using namespace std;

void Student:: Accept_Student_Details()
{
	//Need to Implement
	cout<<"Enter Name Of Student :";
	fflush(stdin);
	getline(cin,this->student_Name);
	cout<<"Enter Student Id :";
	fflush(stdin);
	getline(cin,this->student_ID_Num);
}
void Student:: Display_Student_Details()
{
	//Need to Implement
	cout<<"Student Name :\t"<<this->student_Name<<endl;
	cout<<"Student Id :\t"<<this->student_ID_Num<<endl;
}

Student:: Student():student_ID_Num(""),student_Name("")
{
	//No Need to ImplementNo Need to Implement
}
Student:: Student(string student_id_num,string student_name):student_ID_Num(student_id_num),student_Name(student_name)
{
	//No Need to Implement
}
string Student:: Getstudent_ID_Num()
{
	return student_ID_Num;// No Need to Implement
}
string Student:: Getstudent_Name()
{
	return student_Name;// No Need to Implement
}

void Student:: Setstudent_ID_Num(string student_id_Num)
{
	student_ID_Num = student_id_Num;// No Need to Implement
}
void Student:: Setstudent_Name(string student_name)
{
	student_Name = student_name;// No Need to Implement
}

void Student::SaveToFile(ostream &os)
{
	int LenName=this->student_Name.length();
	int LenId=this->student_ID_Num.length();
	os.write((char *)&LenName,sizeof(LenName));
	os.write((char *)&LenId,sizeof(LenId));
	os.write(this->student_Name.c_str(),LenName);
	os.write(this->student_ID_Num.c_str(),LenId);
}
void Student::ReadFromFile(istream &is)
{
	int LenName=0;
	int LenId=0;
	is.read((char *)&LenName,sizeof(LenName));
	is.read((char *)&LenId,sizeof(LenId));
	char *name=new char[LenName+1];
	char *id=new char[LenId+1];
	name[LenName]='\0';
	id[LenId]='\0';
	is.read(name,LenName);
	is.read(id,LenId);
	this->student_Name.assign(name);
	this->student_ID_Num.assign(id);
}