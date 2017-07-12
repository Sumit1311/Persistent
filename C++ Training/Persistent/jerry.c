#include <stdio.h>
#include <string.h>


int findAllPossiblePaths(int n, int m)
{
   int arr[2552][2552]={0},x=0,y=0, possible_paths=0;
  
//   memset(arr,0,sizeof(int)*n+2*m+2);
 
   for(y=1,x=0;y<=m;y++)
   {
      arr[x][y] = 1;
   }

   for(x=1,y=0;x<=n;x++)
   {
      arr[x][y] = 1;
   }


   for(y=1;y<=m;y++)
   {
      for(x=1;x<=n;x++)
      {
         possible_paths = 0;
         possible_paths += (y == m/2 + 1 && x == n/2) ? 0 : (arr[x][y-1] % 10000);
         possible_paths += arr[x-1][y] % 10000;
         arr[x][y] = possible_paths % 10000;
      }
   }

   return arr[n][m];
}


int main()
{
   int n = 2550, m = 2550;
   
   int paths=findAllPossiblePaths(n,m);

   printf("Paths : %i\n",paths);

   return 1;
}
