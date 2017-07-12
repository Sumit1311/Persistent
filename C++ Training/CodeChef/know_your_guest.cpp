#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
   int number = 0;
   cin >> number;
   unordered_map<string,int> names;
   string name;
   int count = 0;
   while(count < number)
   {
      cin >> name;
      names[name] += 1;
      count++;
   }
   cin >> number;
   count = 0;
   while(count < number)
   {  
      cin >> name;
      cout<<names[name]<<endl;
      count++;
   }
}
