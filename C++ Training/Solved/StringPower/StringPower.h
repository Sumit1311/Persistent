
#include<string>
using namespace std;

#ifndef StringPower_h
#define StringPower_h

class StringPower
{
	private:
		string Word_Sentence;

	public:
		StringPower();		//Default Constructor
		StringPower(string);	//Parametrized Constructor
		string GetWord_Sentence();	//Getter method
		void SetWord_Sentence(string);	//Setter method
		int FindFrequencyOfCharacter_String(string word_sentence,char);
		bool	FindPalindrome_String(string word_sentence);
		string Concatenate_String(string s1, string s2);
		string SortAllCharactersInside_String(string word_sentence);
		string ReverseOrderAllCharactersInside_String(string word_sentence);
		string 	ConvertTitleCase_String(string word_sentence);
		int CountChar_String(string word_sentence);
		int SpaceChar_String(string word_sentence);
		int TabsChar_String(string word_sentence);
		int CountWord_String(string);
		int PeriodCharacterCount_String(string word_sentence);
		string Converts_Lowercase_To_Uppercase_String(string word_sentence);
		string Converts_Uppercase_To_Lowercase_String(string word_sentence);
		void Menu();
};

#endif