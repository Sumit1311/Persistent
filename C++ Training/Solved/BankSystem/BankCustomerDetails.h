//class BankCustomerDetails
#include<string>
#ifndef BankCustomerDetails_h
#define BankCustomerDetails_h

class BankCustomerDetails
{
		private:
			std::string Name;
			unsigned long int Account_Number;
			double Account_Balance;
		public:

			BankCustomerDetails();
			BankCustomerDetails(std::string, unsigned long in, double);

			std::string GetBankCustomerName(); 
			unsigned long int GetBankCustomerAccount_Number();
			double GetBankCustomerAccount_Balance();

			void SetBankCustomerName(std::string&); 
			void SetBankCustomerAccount_Number(unsigned long int&);
			void SetBankCustomerAccount_Balance(double&);

			void AcceptBankCustomerDetails();
			void DisplayBankCustomerDetails();
};

#endif