/* include all libraries in Support.c file
   write all of your new functions in Support.c */

#include <stdio.h>
#include <math.h>
/*
   Implementation of this code is in Support.c
   We include all files created by you or given by us in compilation process. You do not have to include them explicitly
   */

int primes[36]={0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0};
int days[]={37,33,39,37,39,33,39,37,33,37,39,33,39,33};

/*int isPrime(int p)
{
   int count = floor(sqrt(p)), i = 2;
   while(i <= count)
   {
      if(p % i == 0)
      {
         return 0;
      }
      i++;
   }
   return 1;
}

void find_primes()
{
   int i;
   for(i=1;i<37;i++)
   {
      primes[i-1] = isPrime(i);     
   }
}*/

int isLeap(int y)
{
   int sum = 0;
   while(y)
   {
      sum += (y%10);
      y /= 10;
   }
   return primes[sum-1];
}

/*int no_of_days_year(int year)
{
   int leap=isLeap(year);
   if(leap)
   {
      return 534;
   }
   else
   {
      return 508;
   }
}*/

inline int no_of_days_month(int m, int leap)
{
   return (((leap && m % 3 == 0)) ? 41 : days[m-1]);
   /*if(leap)
   {
      if( m % 3 == 0 ) 
      {
         return 41;
      }
   }
   return days[m-1];*/
}

int index_of(char * search, char *arr[], int length)
{
   int i=0;
   for(;i < length;i++)
   {
      if(strcmp(search,arr[i]) == 0)
      {
         return i;
      }
   }
   return -1;
}

int find_index(int iDOM, int iMOY, int iYear, int iDay_index, int tDOM, int tMOY, int tYear)
{
   int year, no_of_leap = 0, no_of_days=0, tLeap = 0, iLeap = 0, count = 0, reminder;
   if(iYear != tYear)
   {
      year = iYear - 1;

      while(year > tYear)
      {
         if(isLeap(year))
         {
            //no_of_leap++;
            no_of_days += 534;
         }
         else
         {
            no_of_days += 508;
         }
         year--;
      //printf("No of Days (Years) : %d\n",no_of_days);
      }
      //no_of_days = ((!(iYear - tYear) ? 0 :( iYear - tYear - no_of_leap - 1)) * 508) /*% 11*/  + (no_of_leap * 534); //% 11;
      printf("No of Days (Years) : %d\n",no_of_days);
      printf("No of Leap Years : %d\n",no_of_leap);
   }
   tLeap = isLeap(tYear);
   iLeap = isLeap(iYear);

   printf("Leap Years(i) : %d\n",iLeap);
   printf("Leap Years(t) : %d\n",tLeap);
   /*if(iYear == tYear && tMOY > iMOY)
   {
      return -1;
   }*/
   for(count = (tMOY + 1) ; count <= ((iYear != tYear) ? 14 : 0) + iMOY - 1; count++ )
   {
      if(count <= 14)
         no_of_days = (no_of_days + (no_of_days_month((count == 14 ? 14 : (count % 14))  ,tLeap))); //% 11;
      else
         no_of_days = (no_of_days + (no_of_days_month((count % 14),iLeap))); //% 11;
      printf("%d\n",no_of_days);

   }
   printf("No of Days (Higher Months) : %d\n",no_of_days);

   /*if(iYear == tYear && tMOY == iMOY && tDOM > iDOM)
   {
      return -1;
   }*/
   no_of_days = (no_of_days + ((iYear == tYear && tMOY == iMOY ? 0 : (no_of_days_month(tMOY, tLeap))) - tDOM)); // % 11;
   no_of_days += iDOM; // % 11; 

   printf("No of Days (Lower Months) : %d\n",no_of_days);
   reminder = no_of_days % 11;
   printf("No of Days (Reminder) : %d\n",reminder);
   return reminder;

}

char * findTheDay(int iDOM,int iMOY,int iYear, char * iDay , int tDOM,int tMOY,int tYear)
{
   char* days[11] = {"C", "CPP", "JAVA", "PERL", "PYTHON", "RUBY", "C#", "SCALA", "ABAB", "R", "SWIFT"};
   //find_primes();
   /*for(i=0;i<36;i++)
   {
      printf("%d,",primes[i]);
   }*/
   /*int i =0, sum =0 ;
   for(i=0;i<14;i++)
   {
      sum += no_of_days_month(i+1, 1);
   }
   printf("Sum of Days in Leap year : %d\n",sum);
   i =0, sum =0 ;
   for(i=0;i<14;i++)
   {
      sum += no_of_days_month(i+1,0);
   }
   printf("Sum of Days in Normal year : %d\n",sum);
   printf("\n");*/
   int iDay_index = index_of(iDay, days ,11), rem, tDay_index;
   
   if ( iYear < tYear || (iYear == tYear && iMOY < tMOY) || (iYear == tYear && iMOY == tMOY && iDOM < tDOM) )
   {
      printf("tMOY : %d\n",tMOY);
      tDay_index = (iDay_index + find_index(tDOM, tMOY, tYear, iDay_index, iDOM, iMOY, iYear)) % 11;
      printf("No of i Day : %d\n",iDay_index);
      printf("No of t Day : %d\n",tDay_index);
      return days[tDay_index];
   }
   else
   {
      tDay_index = (11 + iDay_index - find_index(iDOM, iMOY, iYear, iDay_index, tDOM, tMOY, tYear)) % 11 ;
      printf("No of i Day : %d\n",iDay_index);
      printf("No of t Day : %d\n",tDay_index);
      return days[tDay_index];
   }
}
int main()
{


   /* Use console on right side of this window. Type your input in console */
   /* You can test your code without console as well; In that scenario please do not use any cin statements */
   char * orig="JAVA", *prev, *recent;
   /*prev = findTheDay(13,12,1,orig,13,12,9999);
   printf("%s\n",prev);
   recent = findTheDay(13,12,9999,prev,13,12,1);
   printf("%s\n",recent);
   printf("Is same : %d\n",!strcmp(orig,recent));
   //orig="JAVA";
   prev = findTheDay(13,12,2016,orig,13,12,2016);
   printf("%s\n",prev);
   recent = findTheDay(13,12,2016,prev,13,12,2016);
   printf("%s\n",recent);
   printf("Is same : %d\n",!strcmp(orig,recent));
   //orig="JAVA";
   prev = findTheDay(13,13,2016,orig,14,12,2016);
   printf("%s\n",prev);
   recent = findTheDay(14,12,2016,prev,13,13,2016);
   printf("%s\n",recent);
   printf("Is same : %d\n",!strcmp(orig,recent));
   //orig="JAVA";*/
   printf("%s\n",findTheDay(1,1,2011,"PERL",33,14,2010)); 
   printf("%s\n",findTheDay(33,14,2010,"JAVA",1,1,2011));
   printf("%s\n",findTheDay(13,6,1916,"R",11,7,1916));
   printf("%s\n",findTheDay(11,7,1916,"PYTHON",13,6,1916)); 
   /*prev = findTheDay(13,13,2017,orig,14,12,2010);
   printf("%s\n",prev);
   recent = findTheDay(14,12,2010,prev,13,13,2017);
   printf("%s\n",recent);
   printf("Is same : %d\n",!strcmp(orig,recent));*/
   /*prev = findTheDay(1,1,1,orig,33,14,9999);
   printf("%s\n",prev);
   recent = findTheDay(33,14,9999,prev,1,1,1);
   printf("%s\n",recent);
   printf("Is same : %d\n",!strcmp(orig,recent));*/

   /*prev = findTheDay(23,3,2015,orig,1,1,2017);
   printf("%s\n",prev);
   recent = findTheDay(1,1,2017,prev,23,3,2015);
   printf("%s\n",recent);
   printf("Is same : %d\n",!strcmp(orig,recent));*/
   /*printf("%s\n",findTheDay(13,12,2016,"JAVA",13,12,2016));
   printf("%s\n",findTheDay(13,12,2016,"JAVA",13,12,2016));*/

   /*printf("%s\n",findTheDay(13,12,2016,"JAVA",14,12,2016));
     printf("%s\n",findTheDay(14,12,2016,"PERL",13,12,2016));*/
   /*printf("%s\n",findTheDay(13,13,2016,"JAVA",14,12,2016));
     printf("%s\n",findTheDay(14,12,2016,"PERL",13,13,2016));*/
   /*printf("%s\n",findTheDay(13,13,2017,"JAVA",14,12,2010));
     printf("%s\n",findTheDay(14,12,2010,"C#",13,13,2017));*/

   //printf("%s",findTheDay(1,11,1912,"CPP",5,11,1912));
   return 0;
}

