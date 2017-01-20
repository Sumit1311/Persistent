#include"BankCustomerDetails.h"
#include<list>
#ifndef BankSystem_h
#define BankSystem_h

class BankSystem
{
		private:
			std::list<BankCustomerDetails> BCD;

		public:
			std::list<BankCustomerDetails>  GetBankCustomerDetails();
			void SetBankCustomerDetails(std::list<BankCustomerDetails>&);
			int GetTotalCustomerCount();
			void Create_AddCustomerAccount_BankSystem(BankCustomerDetails&);
			
			bool SearchCustomerDetails_byName(std::string);  
			bool SearchCustomerDetails_byAccountNumber(unsigned long int);

			void UpdateCustomerDetails_byAccountNumber(std::string ,unsigned long int );

			void DepositMoney_byAccountNumber(unsigned long int ,double);

			void WithdrawMoney_byAccountNumber(unsigned long int , double);

			double BalanceInquiryofCustomer_byAccountNumber(unsigned long int );

			void DeleteCustomerDetails_byAccountNumber(unsigned long int );
						
			void DisplayAllCustomerDetails();

};

#endif