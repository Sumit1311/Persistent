#include <stdio.h>


int find_max_perimeter(char arr[][7], int w, int h)
{
   int temp[10][2]={0}, count = 0;
   temp[0][0] = 0;
   temp[0][1] = 0;
   int max =0;
   int i = 0,j = 0;
   while(i < h)
   {  
      j=0;
      while(j < w)
      {
         //left
         if(arr[i][j] == '*' )
         {
            if( j == 0)
            {
               temp[j][1] = 0;
            }
            else if(arr[i][j - 1] == 'X')
            {
               temp[j][1] = 0;
            }
            else if(arr[i][j - 1] == '*')
            {
               temp[j][1] = (temp [j - 1][1] + 1);
            }
         }
         if(arr[i][j] == 'X')
         {
            temp[j][0] = -1;
            temp[j][1] = -1;
            if(temp[j-1][0] == 0 || temp[j-1][1] == 0)
            {
               temp[j-1][0] = -1;
               temp[j-1][1] = -1;
            }
         }
         if(arr[i][j] == '*')
         {
            if(i == 0)
            {
               temp[j][0] = 0;
            }
            else if(arr[i - 1][j] == 'X')
            {
               temp[j][0] = 0;
            }
            else if(arr[i - 1][j] == '*')
            {
               temp[j][0] = (temp [j][0] + 1);
            }
         }
         if(temp[j][1] == 0 || temp[j][0] == 0 || temp[j][1] == -1 || temp[j][0] == -1)
         {
            max = (temp[j][0] + temp[j][1]) > max ? (temp[j][0] + temp[j][1]) : max;
         }
         printf("(%d, %d),",temp[j][0], temp[j][1]);
         /*for(count = 0;count < w;count++)
         {
            printf("%d ", temp[i][0]);
            printf("%d", temp[i][1]);
            printf("\n");
         }*/ 
         j++; 
      }
      printf("\n");
      i++;
   }
   
   /*for(i=0;i<w;i++)
   {
      for(j=0;j<2;j++)
      {
         printf("%d ", temp[i][j]);
      }
      printf("\n");
   }*/
   return max * 2; 
}

int main()
{
   /*char arr[][5] = {
               {'*','*','X','*','*'}, 
               {'*','X','*','X','*'},
               {'*','X','*','*','*'},
               {'*','X','*','*','*'}
               };
   int max = find_max_perimeter(arr,5,4);*/
   /*char arr[][5] = {
               {'*','*','*','*','*'},
               {'*','X','*','X','*'},
               {'*','*','*','*','*'}
               {'*','*','*','*','*'},
               {'*','*','*','*','*'}
               };
   int max = find_max_perimeter(arr,5,5);*/
   char arr[][7] = {
               {'X','X','X','X','*','*','*'},
               {'*','X','*','*','*','*','*'},
               {'*','X','*','X','X','X','*'},
               {'*','*','*','*','*','*','*'},
               {'X','X','*','*','X','*','*'}
               };
   int max = find_max_perimeter(arr,7,5);
   /*int width,height, i=0, j=0;
   char arr[100][100];
   scanf("%d %d",&height, &width);
  
   for(i=0;i<height;i++)
   {
      scanf("%s",arr[i]);
   }
   int max = find_max_perimeter(arr,width,height);*/
   printf("%d\n",max); 
   return 0;
}
