#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int sortedMeta[1000] = {0} ;

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

int partition(int *arr, int size, int pivot)
{
   //printf(" Part : %d,%d\n",size,pivot);
   int i = 0, j = size - 1, ele = arr[pivot], k = 0;
   swap(&arr[pivot], &arr[0]);
   pivot = 0;
      for(k = 0; k < size; k++)
      {
         printf("%d,", arr[k]);
      }
      printf("\n");
   while(i < j)
   {
      while(arr[i] <= ele )
      {
         i++;
      }
      while(arr[j] > ele)
      {
         j--;
      }
      if(i < j)
      {
         //printf("swap : %d %d\n", i, j);

         swap(&arr[i], &arr[j]);
      } 

   }
   swap(&arr[pivot], &arr[j]);
   printf("Right Ful Position of %d is %d\n", ele, j);
   for(k = 0; k < size; k++)
   {
      printf("%d,", arr[k]);
   }
   printf("\n");
   return j;
}

int find_rightful_position(int *arr, int size, int index)
{
   int random = (rand() % size), k = 0;
   printf("\n");
   int pos = partition(arr, size, random);
   //printf(" Right : %d,%d,%d, %d \n",size, index, random, pos);
   printf("Random : %d, Index : %d, Return : %d\n", random, index, pos);
   if(pos == index)
   {
      return random;
   }
   else if(pos < index)
   {
      return find_rightful_position((arr + pos + 1), size - pos - 1, index);
   }
   else if(pos > index)
   {
      return find_rightful_position(arr, pos + 1, index);
   }
}

int find_min(int *arr, int size)
{
   int min = 0, i = 0;
   for(;i < size; i++)
   {
      if(arr[min] > arr[i]) 
      {
         min = i;
      }
   }
   return 0;
}

int find_min_cost_rec(int *arr, int size, int minIndex, int sortedIndex, int minSum)
{
   int swapIndex;
   printf("%d, %d, %d\n", minIndex, sortedIndex, minSum);
   if(minIndex == sortedIndex)
   {
      if(sortedIndex == size - 1)
      {
         return minSum;
      }
      sortedIndex += 1;
      minIndex = sortedIndex + find_min(arr + sortedIndex, size);
   }
   if(sortedMeta[minIndex] == 1)
   {
      return find_min_cost_rec(arr, size, sortedIndex, sortedIndex, minSum);
   }
   swapIndex = find_rightful_position(arr, size, minIndex);

   swap(&arr[swapIndex], &arr[minIndex]);
   sortedMeta[minIndex] = 1;
   minSum = arr[swapIndex] + arr[minIndex];
   if(sortedIndex == swapIndex)
   {
      sortedMeta[sortedIndex] = 1;
   }
   return find_min_cost_rec(arr, size, swapIndex, minIndex, minSum);
}

int find_min_cost(int *arr, int size)
{
   //sortedMeta = (int *) malloc(size * sizeof(int));
   
   if(sortedMeta != NULL)
   {
      return find_min_cost_rec(arr, size, -1, -1, 0);
   } 
}

int main()
{
   int arr[]= {5,4,3,2,1}, size = 5;

   int cost = find_min_cost(arr, size);   

   printf("%d\n", cost);   

   return 0;
}
