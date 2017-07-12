#include <stdio.h>

int global_sub[10000][10000] = {0};
static int count = 0;
int recursivePrisoners(int N, int M, int* CRIMES, int current, int *sub)
{
   //printf("%d,%d,%d\n",N,M,current);
   int with = 0, without = 0, i,j;
   if(N == 0)
   {
      printf("Found\n");
      for(i=0;i<current;i++)
      {
         //printf("%d",sub[i]);
         global_sub[count][i] = sub[i];
      }
      printf("\n");;
      //global_sub[count][current] = 1; 
   /*for(i = 0; i < 6; i++)
   {
      for(j=0;j < 10; j++)
      {
         printf("%d ",global_sub[i][j]);
      }
      printf("\n");
   }*/
      count++;
      return 1;
   }
   else if(N < 0)
   {
      return 0;
   }
   else if(current == M)
   {
      if(N != 0)
      {
         return 0;
      }
      return 1;
   }
   else
   {
      sub[current] = 1;
      with = recursivePrisoners(N - CRIMES[current],M,CRIMES,current+1,sub);
      sub[current] = 0;
      without =  recursivePrisoners(N,M,CRIMES,current+1,sub);
      return (with + without);
   }
}

/*int freePrisoners(int N,int M,int* CRIMES)
{

   //Write your code here and return required output.
   if()
   {

   }
   else
   {
      
   }
   
   return 0;
}*/

int isDisjoint(int *a, int *b, int size)
{  
   int i;
   for(i=0 ; i < size ; i++)
   {
      if(a[i] == 1 && a[i] == b[i])
      {
         return 0;
      }   
   }
   return 1;
}

void union_set(int *a, int *b, int size)
{
   int i;
   for(i=0; i < size; i++)
   {
      a[i] = b[i] ? 1 : a[i];
      //printf("%d",b[i]);
   }
   //printf("\n");
}
int main()
{
   int N = 6;
   int M = 6;
   int CRIMES[]={1,2,3,4,5,6};
   int i, j,local_max =0, max = 0, disjoint[100][100];
   /* Use console on right side of this window. Type your input in console. */
   /* you can test your code without console as well; In that scenario please do not use any cin statements */
      
   //printf("%d",freePrisoners(N,M,CRIMES));
   int sub[M];
   int no_of_subsets;
   printf("%d\n",(no_of_subsets = recursivePrisoners(N,M,CRIMES,0,sub)));
   for(i = 0; i < no_of_subsets; i++)
   {
      for(j=0;j < M; j++)
      {
         printf("%d ",global_sub[i][j]);
      }
      printf("\n");
   }
   /*for(i =0; i < no_of_subsets; i++)
   {
      global_sub[i][M+1] = 0;
   }*/   
   
   for(i=0;i<M;i++)
   {
      global_sub[no_of_subsets][i] = 0;
   }   

   for(i = 0; i < no_of_subsets; i++)
   {
      union_set(global_sub[no_of_subsets],global_sub[i], M);
      for(j = i+1; j < no_of_subsets; j++)
      {
         if(isDisjoint(global_sub[no_of_subsets],global_sub[j], M) )
         {
            union_set(global_sub[no_of_subsets],global_sub[j], M);
            local_max++;
         }
      }
      max = (max < local_max ? local_max : max);
      local_max = 1;
      for(j=0;j<M;j++)
      {
         printf("%d",global_sub[no_of_subsets][j]);
         global_sub[no_of_subsets][j] = 0;
      }   
      printf("\n");
   }   
   printf("%d\n",max);
   return 0;
}
