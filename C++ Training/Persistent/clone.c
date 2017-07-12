#include "stdio.h"
#include "string.h"

int increment_number(int num)
{
   if(num == -1)
   {
      return 1;
   }
   if(num == 1)
   {
      return 0;
   }
   if(num == 0)
   {
      return 2;
   }
   if(num >= 2)
   {
      return num+1;
   }
}

int smallest_clone(int n)
{
   int orig = n, i = -1, no_of_digits=0, rem, arr[n], j=0, arr2[10];

   memset(arr2,-1, 10*sizeof(int));

   while(n)
   {
      rem = n%10;
      arr[no_of_digits] = rem;
      no_of_digits++;
      n = n/10;
   }
   i = increment_number(i);
   for(j = no_of_digits - 1; j >= 0 ; j--)
   {
         {
            if(arr2[arr[j]] != -1)
            { 
               rem = arr2[arr[j]]; 
            }
            else
            {      
               rem = i; arr2[arr[j]] = i;
               i = increment_number(i);
            }        
            arr[j] = rem;
         }
      
   }

   while(no_of_digits)
   {
      n = n*10 + arr[--no_of_digits];
   }

   return n;
}

int arithmetic_hash(int n, int m)
{
   if(n == 0)
   {
      return 0;
   }
   int i=1, hash=0;
   for(i = 1; i<= n; i++)
   {
      hash += smallest_clone(i) % m;
      hash %= 10000;
   }
   return hash;
}

int main()
{
   int n = 9999,m = 9999;

   int hash = arithmetic_hash(n,m);

   printf("%d",hash);

   return 1;
}


/*int main()
{
   int n=0;

   scanf("%d",&n);   

   printf("%d",smallest_clone(n));
}*/
