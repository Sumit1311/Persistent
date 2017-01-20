#include<vector>
#include"Phone Directory.h"
#ifndef CustomerDetaila_H
#define CustomerDetaila_H

class CustomerDetail
{
	
		
		public:
			std::vector<PhoneDirectory> V;
			int GetTotalCustomerCount()const;
			PhoneDirectory GetCustomerDetails(int )const;
			
			//Accept Method
			void AddCustomerDetails(PhoneDirectory &PD);													

		    //Search Method
			int SearchByName(std::string nm);
			int SearchByNumber(std::string num);

			//Update method
			void UpdateByName(std::string nm,std::string num);	
			void UpdateByNumber(std::string nm,std::string num);
			
			//Display method
			void Display();											

			//Selection of Name or Number
			void Select(std::string);

			//Display details of phone directory
			void Count();
};

#endif