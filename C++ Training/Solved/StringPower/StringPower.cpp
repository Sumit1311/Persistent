#include"StringPower.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<regex>
using namespace std;

StringPower::StringPower():Word_Sentence("")	//Default Constructor
{
	//No need to implement
}
StringPower::StringPower(string word_sentence):Word_Sentence(word_sentence)	//Parametrized Constructor
{
	//No need to implement
}
string StringPower::GetWord_Sentence()	//Getter method
{
	return Word_Sentence;	//No need to implement
}
void StringPower::SetWord_Sentence(string word_sentence)	//Setter method
{
	Word_Sentence = word_sentence;	//No need to implement
}

//Find the frequency of character in a string
int StringPower::FindFrequencyOfCharacter_String(string word_sentence,char ch)
{
	//Need to implement and return the frequency of character
	int count=0;
	for(int i=0;i<word_sentence.length();i++){
		if(word_sentence.at(i)==ch)
		{
			count++;
		}
	}
		return count;
}

//Find the given string is palindrome or not 
bool StringPower::FindPalindrome_String(string word_sentence)
{
			//Need to implement and on success return true and on error return false
	std::string org=word_sentence;
	reverse(word_sentence.begin(),word_sentence.end());
	if(word_sentence==org)
	{
		return true;
	}
	return false;
}

//Concatenate two strings.
string StringPower::Concatenate_String(string s1, string s2)
{
			//Need to implementand return the first string
	s1.append(s2);
	
	return s1;
}

//Sort all characters inside the string
string StringPower::SortAllCharactersInside_String(string word_sentence)
{
	//Need to implementand return the sorted string
	sort(word_sentence.begin(),word_sentence.end());
	return word_sentence;
}

//Reverse the order of all characters inside the string
string	StringPower::ReverseOrderAllCharactersInside_String(string word_sentence)
{
			//Need to implmente and return the reversed string
	reverse(word_sentence.begin(),word_sentence.end());
	return word_sentence;
}

//Convert given string into Title Case
string StringPower::ConvertTitleCase_String(string word_sentence)
{
	//Need to implmente and return the converted string
	int Index=-1;
	int length=word_sentence.length()-1;
	do
	{
		if(((int)word_sentence.at(Index+1))>=97 && word_sentence.at(Index+1)<=122)
		{
			char temp=(char)(((int)word_sentence.at(Index+1))-32);
			word_sentence=word_sentence.replace(Index+1,1,1,temp);
		}
		Index=word_sentence.find_first_of(" ",Index+1);
		cout<<Index;
		cout<<word_sentence;
		if(Index==word_sentence.length()-1){
			break;
		}
	}while(Index!=-1);
	return word_sentence;
}

//Count the Character in the given string
int StringPower::CountChar_String(string word_sentence)
{
	//Need to implmente and return the count	
	return word_sentence.length();
}

//Count the space in the given string
int StringPower::SpaceChar_String(string word_sentence)
{
	//Need to implmente and return the count
	int count=0,Index=-1;
	do
	{
		Index=word_sentence.find_first_of(" ",Index+1);
		if(Index!=-1)
			count++;
	}while(Index!=-1);
	return count;
}

//Count the Tab in the given string
int StringPower::TabsChar_String(string word_sentence)
{
	//Need to implmente and return the count
	int count=0,Index=-1;
	do
	{
		Index=word_sentence.find_first_of("    ",Index+1);
		if(Index!=-1)
			count++;
	}while(Index!=-1);
	return count;
}

//Count the total word from the String
int StringPower::CountWord_String(string word_sentence)
{
	//Need to implmente and return the count
	int count=0,Index=-1;
	int flag=word_sentence.length()-1;
	do
	{
		if(word_sentence.at(Index+1)==' '){
			Index++;
			cout<<Index;
			if(Index==flag)
				break;
			continue;
		}
		
		
		Index=word_sentence.find_first_of(" ",Index+1);y

		count++;		
		
	}while(Index!=-1);
	return count;

}

//Count the Tab in the given string
int StringPower::PeriodCharacterCount_String(string word_sentence)
{
	//Need to implmente and return the count
	int count=0,Index=-1;
	do
	{
		Index=word_sentence.find_first_of(".",Index+1);
		if(Index!=-1)
			count++;
	}while(Index!=-1);
	return count;
	return 0;
}

//Converts all lowercase characters in a given string to its equivalent uppercase character.
string StringPower::Converts_Lowercase_To_Uppercase_String(string word_sentence)
{
	int Index=0,limit=word_sentence.length()-1;
	//Need to implmente and return the converted string
	while(Index<=limit)
	{
	if(((int)word_sentence.at(Index))>=97 && word_sentence.at(Index)<=122)
		{
			char temp=(char)(((int)word_sentence.at(Index))-32);
			word_sentence=word_sentence.replace(Index,1,1,temp);
		}
	Index++;
	}
	return word_sentence;
	
}

//Converts all uppercase characters in a given string to its equivalent lowercase character.
string StringPower::Converts_Uppercase_To_Lowercase_String(string word_sentence)
{
	//Need to implmente and return the converted string
	int Index=0;
	//Need to implmente and return the converted string
	while(Index!=word_sentence.length())
	{
	if(((int)word_sentence.at(Index))>=65 && word_sentence.at(Index)<=90)
		{
			char temp=(char)(((int)word_sentence.at(Index))+32);
			word_sentence=word_sentence.replace(Index,1,1,temp);
		}
	Index++;
	}
	return word_sentence;
}

//Menu of the StringPower Program
void StringPower::Menu()
{
		cout<<endl<<"\n****** MENU ******"<<endl;
		cout<<endl<<"1. Find the frequency of character in a string.";
		cout<<endl<<"2. Find the given string is palindrome or not ";
		cout<<endl<<"3. Concatenate two strings";
		cout<<endl<<"4. Sort all characters inside the string";
		cout<<endl<<"5. Reverse the order of all characters inside the string ";
		cout<<endl<<"6. Convert given string into Title Case";
		cout<<endl<<"7.Count the Character from the String";
		cout<<endl<<"8.Count the Space from the String";
		cout<<endl<<"9. Count the Tabs from the String";
		cout<<endl<<"10.Count the total word from the String";
		cout<<endl<<"11.Count the period(.) character from the String";
		cout<<endl<<"12. Converts all lowercase characters in a given string to its equivalent uppercase character.";
		cout<<endl<<"13. Converts all uppercase characters in a given string to its equivalent lowercase character";
		cout<<endl<<"14. Exit";
		cout<<endl<<endl;
}
