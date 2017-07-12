#include <stdio.h>
struct vector{
   int arr[1000];
   int count;
} undirected[1000] = {{0}, 0}, tree1[1000]={{0},0}, tree2[1000]={{0},0}, path={{0}, 0};

int visited[999] = {0};

void DFS(int root, int *arr, int size)
{  
   int k = 0, i = 0;
   for(;i < (size - 1) * 2; i += 2)
   {
      //printf("(%d, %d) \n", arr[i], arr[i + 1]);
      if(visited[i] != 1 && ((arr[i] - 1) == root || (arr[i + 1] - 1) == root))
      {
         visited[i] = 1;
         tree1[root].arr[tree1[root].count++] = ((arr[i] - 1) == root ? (arr[i+1] - 1) : (arr[i] -1));
         while(k < tree1[root].count)
         {
            DFS(tree1[root].arr[k], arr, size);
            k++;
         }
      }
   }
}


void reverse_graph(int size)
{
   int i = 0, j = 0;
   for(;i < size; i++)
   {
      j = 0;
      while(j < tree1[i].count)
      {
         tree2[tree1[i].arr[j]].arr[tree2[tree1[i].arr[j]].count++] = i;
         j++;
      }
   }
}

int find_path(struct vector *graph, int s, int d)
{
   int j = 0, temp;
   visited[s] = 1;
   if(s == d)
   {
      return 1;
   }
   else
   {
      if(graph[s].count == 0)
      {
         return -1;
      }
      while(j < graph[s].count)
      {
         if(!visited[graph[s].arr[j]])
         {
            temp = find_path(graph, graph[s].arr[j], d);
            if(temp == 1)
            {
               path.arr[path.count++] = s;
               return 1;
            }
         }
         j++;
      
      }
   }

}

int is_neighbour(struct vector *graph, int size, int s, int n)
{
   //printf("(%d,%d) \n",path.arr[s], path.arr[n]); 
   int i = 0;
   for(;i < graph[s].count; i++)
   {
      if(graph[s].arr[i] == n)
      {
         return 1;
      }
   }
   return 0;
}

int create_two_trees(int size, int s, int d, int *arr)
{
   s--;
d--;
   int i = 0, j = 0, k = 0, flag, count;
   for(;i < (size - 1) * 2; i += 2)
   {
      undirected[arr[i] - 1].arr[undirected[arr[i] - 1].count++] = arr[i+1] - 1;
      undirected[arr[i + 1] - 1].arr[undirected[arr[i + 1] - 1].count++] = arr[i] - 1;
         
   }
   /*printf("Undirected Graph : \n");
   for(i = 0; i < size; i++)
   {
      printf("%d : ",i);
      j = 0;
      while(j < undirected[i].count)
      {
         printf("%d,",undirected[i].arr[j]);
         j++;
      }
      printf("\n");
   }*/
   DFS(0, arr, size);
   /*printf("Tree at Day 1 : \n");
   for(i = 0; i < size; i++)
   {
      printf("%d : ",i);
      j = 0;
      while(j < tree1[i].count)
      {
         printf("%d,",tree1[i].arr[j]);
         j++;
      }
      printf("\n");
   }
   printf("Tree at Day 2 : \n");*/
   for(i=0; i < size; i++)
      visited[i] = 0;
   reverse_graph(size);
   /*for(i = 0; i < size; i++)
   {  
      printf("%d : ",i);
      j = 0;
      while(j < tree2[i].count)
      {
         printf("%d,",tree2[i].arr[j]);
         j++;
      }
      printf("\n");
   }*/
   for(i=0; i < size; i++)
      visited[i] = 0;
   find_path(undirected, s, d);
   /*printf("The path :\n");
   for(i = 0; i < path.count; i++)
   {
      printf("%d,",path.arr[i]);
   }*/
   //printf("\n");
   flag = 1;
   count = 0;
   for(i = (path.count - 1); i >= 0;)
   {
      count++;
      //printf("(%d,%d),",path.arr[i], (i == 0 ? d : path.arr[i - 1]));
      if(flag)
      {
         if(is_neighbour(tree1, size, path.arr[i], (i == 0 ? d : path.arr[i - 1])))
         {
            i--;
         }
         flag = 0;
      }
      else
      {
         if(is_neighbour(tree2, size, path.arr[i], (i == 0 ? d : path.arr[i - 1])))
         {
            i--;
         }
         flag = 1;
      }
   }
   //printf("%d ",count);
   return count;
}




int main()
{
   /*int arr[8] = {1,2,2,4,2,5,2,3};

   int n = 5;
   int s = 1;
   int d = 1;*/
   /*int arr[] = {1,2,1,3,2,4,2,5,2,6,6,7,6,8};

   int n = 8;
   int s = 4;
   int d = 8;*/
   /*int arr[8] = {4,2,2,1,1,3,3,5};


   int n = 5;
   int s = 4;
   int d = 1;*/
   /*int arr[] = {1,2,1,3,2,4,2,6,3,5};

   int n = 6;
   int s = 4;
   int d = 5;*/

   int arr[] = {1,2};


   int n = 2;
   int s = 1;
   int d = 2;
   printf("%d\n",create_two_trees(n, s, d,arr));


   
   return 0;
}
