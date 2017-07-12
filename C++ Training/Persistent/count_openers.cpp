#include <iostream>

int find_max_opening_pairs(int num, int num_of_pairs, int *pairs)
{
   //int index=0;
   bool isChanged=false;
   int arr[num],team_size[num];
   int lastChanged = num+1;
   for(int i=0;i<num;i++)
   {
      arr[i]=i;
      team_size[i]=0;
   }
   do
   {
      isChanged=false;
      for(int i=0, index=0;i<num_of_pairs; i++,index+=2)
      {
         if(arr[pairs[index]] != arr[pairs[index+1]])
         {
            int common_parent=arr[pairs[index]] < arr[pairs[index+1]] ? arr[pairs[index]] : arr[pairs[index+1]];
            arr[pairs[index]]=common_parent;
            arr[pairs[index + 1]]=common_parent;
            isChanged=true;
         }
      }
   }
   while(isChanged);
   
   int total_pairs=0, sum=0;
   for(int i=0;i<num;i++)
   {
      team_size[arr[i]]+=1;
   }
   for(int i=0; i<num; i++)
   {
      if(team_size[i] != 0)
      {
         //std::cout<<"Team : "<<i<<", Size :"<<team_size[i]<<std::endl;
         total_pairs += sum*team_size[i];
         sum+=team_size[i];
      }
   }

   return total_pairs;
   
}


int main()
{
   //int a[]={0, 1, 2,3,1, 2 ,4,5,6,7};
   //int a[]={0,1,2,3,1,2,4,5,6,7,8,1,4,1};
   //int m=7, n=10;
   /*int a[]={0,1,2,3,1,2,5,6,7,8,21,22,23,24,25,26,27,28,29,30};
   int m=10, n=10000;*/
   /*int a[]={4,5,3,1,2,3,0,1};
   int m=4,n=10;*/
   int a[20000];
   int m=10000,n=10000;
   int i=0;
   for(i=0;i < 10000;i++)
   {
      a[i]=i;
   }
   for(;i<20000;i++)
   {
      a[i]=i-10001+1;
   }
   int total_pairs=find_max_opening_pairs(n,m,a);
   std::cout<<total_pairs<<std::endl;
   return 1;
}
