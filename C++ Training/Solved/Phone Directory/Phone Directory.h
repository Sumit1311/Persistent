// Class Declaration for Phone Directory

#ifndef PhoneDirectory_H
#define PhoneDirectory_H

#include<string>
class PhoneDirectory
{
		private:
			std::string Name;
			std::string Number;

		public:
			PhoneDirectory();												//Default Constructor
			PhoneDirectory(std::string, std::string);				//Parametrized Constructor
			std::string GetName()const;									//Get method for Name
			std::string GetNumber()const;								//Get method for Number
			void SetName(std::string);									//Set method for Name
			void SetNumber(std::string);								//Set method for Number
			
			void Accept();														//Accept Method
									
			void Display();													//Display method
			
};

#endif