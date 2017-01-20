#include<iostream>
#include"StringPower.h"
using namespace std;

int main()
{
	StringPower SP;
	char Ch;
	int Choice;
	do
	{
		SP.Menu();
		cout<<endl<<"Enter your choice"<<endl;
		cin>>Choice;
		switch(Choice)
		{
			case 1:
			{
				char ch;
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				cout<<"Enter a characeter to find frequency: "<<endl;
				fflush(stdin);
				cin>>ch;
				int Char_count = SP.FindFrequencyOfCharacter_String(word_sentence, ch);
				cout<<"The Frequency of Character in given string is"<<Char_count<<endl;
			}
			break;

			case 2:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);

				bool flag = SP.FindPalindrome_String(word_sentence);
				if(flag)
				{
					cout<<"The given string is palindrome"<<endl;
				}
				else
				{
					cout<<"The given string is not palindrome"<<endl;
				}
			}
			break;
			case 3:
			{
				string s1,s2;
				cout<<"\nEnter the Strings to Concatination with first string"<<endl;
				cout<<"String1"<<endl;
				fflush(stdin);
				cin>>s1;
				cout<<"String2"<<endl;
				fflush(stdin);
				cin>>s2;

				cout<<SP.Concatenate_String(s1,s2);

			}
			break;
			case 4:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);

				cout<<SP.SortAllCharactersInside_String(word_sentence);
			}
			break;
			case 5:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);

				cout<<SP.ReverseOrderAllCharactersInside_String(word_sentence);	
			}
			break;
			
			case 6:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				
				cout<<SP.ConvertTitleCase_String(word_sentence);
			}
			break;
			case 7:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				int Count = SP.CountChar_String(word_sentence);
				cout<<"The total count of character is "<<Count<<endl;
			}
			break;
			case 8:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				int Count = SP.SpaceChar_String(word_sentence);
				cout<<"The total count of space characters is "<<Count<<endl;
				
			}
			break;
			case 9:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				int Count = SP.TabsChar_String(word_sentence);
				cout<<"The total count of tab character is "<<Count<<endl;
			}
			break;
			case 10:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				int Count = SP.CountWord_String(word_sentence);
				cout<<"The total count of word is "<<Count<<endl;
			}
			break;
			case 11:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				int Count = SP.PeriodCharacterCount_String (word_sentence);
				cout<<"The total count of period is "<<Count<<endl;
			}
			break;
			case 12:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				cout<<SP.Converts_Lowercase_To_Uppercase_String (word_sentence);
				
			}
			break;
			case 13:
			{
				string word_sentence;
				cout<<"Enter The Word / Sentence"<<endl;
				fflush(stdin);
				getline(cin,word_sentence);
				cout<<SP.Converts_Uppercase_To_Lowercase_String (word_sentence);
			}
			break;
			case 14:
			{
				exit(0);
			}
			break;
			default:
				cout<<"Invalide Choice"<<endl;
		}
		cout<<"\nDO YOU WANT TO CONTINUE...... Y / N"<<endl;
		fflush(stdin);
		cin>>Ch;
	}while(Ch == 'y' || Ch == 'Y');
	return 0;
}
