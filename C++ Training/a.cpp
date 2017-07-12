#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int finalIndex;
int calculateCost(vector<int>& v, vector<int>& costA, vector<bool>& visited, int source, int& cost)
{
    int min = 0, minIndex = -1;
    for(int i = 0; i < v.size(); i++)
    {
        if(!visited[i]) {
            costA[i] += abs(v[i] - v[source]);
            if(min == 0){
                min = costA[i];
                minIndex = i;
            }
            if(min > costA[i])
            {
                min = costA[i]; minIndex = i;
            }
        }
    }
    cost += min;
    return minIndex;
}

//Calculate Min Distance Destination for given source
int findMinSource(vector<int>& v, int& cost, int s)
{
    vector<int> costA(v.size(), 1);
    vector<bool> visited(v.size(), false);
    int minIndex = s /*calculateCost(v, costA, visited, s, cost)*/, oldIndex = s;
    cost = costA[s];
    while(minIndex != -1)
    {
        visited[minIndex] = true;
        oldIndex = minIndex;
        minIndex = calculateCost(v, costA, visited, minIndex, cost);
    }

    return oldIndex;
}

//Find All possible paths within group
int findAllPaths(vector<int>& v, vector<vector<int> >& cost)
{
    vector<int> d = vector<int>(2);
    vector<vector<int> > cost_l(v.size(), d) ;
    cost = cost_l;
    for(int i = 0; i < v.size(); i++)
    {
        cost[i][1] = findMinSource(v, cost[i][0], i);
    }
}

//Calculate cost of each path in each group
int findAllLocalMinimum(vector<vector <int> >& v, vector<vector<vector<int> > >& cost)
{
    for(int i = 0; i < v.size(); i++)
    {
        //cout<<"Group : "<<i<<endl;
        findAllPaths(v[i], cost[i]);
    }
}

//Calculate the final Path cost
int findMinimumPathCost(int group, vector<vector<vector<int> > >& cost, int& index, vector<vector<int> > v, vector<vector<int> >& finalCost)
{
    int minCost = 0, minSource = 0, minDestination = 0;
    if(group == -1)
    {
        return 0;
    }
   for(int i = 0; i < cost[group].size(); i++)
   {

       int temp = cost[group][i][0] + (index == -1 ? 0 : abs(index - v[group][cost[group][i][1]]));
       if(minCost == 0)
       {
            minCost = temp;
           minSource = i;
          minDestination = cost[group][i][1]; 
       }
       if(minCost > temp)
       {
           minSource = i;
           minDestination = cost[group][i][1];
           minCost = temp;
       }
   }
   vector<int> d = vector<int>(5);
   finalCost[group] = d;
   finalCost[group][0] = minSource ;
   finalCost[group][1] = minDestination;
   finalCost[group][2] = minCost;
   finalCost[group][3] = 0;
   finalCost[group][4] = 0;
   int finalMinCost, finalMinSource, finalMinDestination ;
   for(int i = 0; i < cost[group].size(); i++)
   {
       finalMinCost = minCost;
       int temp = cost[group][i][0] + (index == -1 ? 0 : abs(index - v[group][cost[group][i][1]]));
       if(temp == minCost) {
            int current = v[group][i];
            finalMinCost += findMinimumPathCost(group - 1, cost, current, v, finalCost);
            if(finalMinCost != 0 && finalCost[group][3] == 0)
            {
                finalCost[group][3] = finalMinCost;
                finalCost[group][2] = temp;
                finalCost[group][1] = cost[group][i][1];
                finalCost[group][0] = i;
            }
            if(finalMinCost != 0 && finalMinCost < finalCost[group][3] )
            {
                finalCost[group][3] = finalMinCost;
                finalCost[group][2] = temp;
                finalCost[group][1] = cost[group][i][1];
                finalCost[group][0] = i;
            }
       }
   }
   if(group == 0)
   {
       //cout <<"Final";
        finalIndex = v[group][finalCost[group][0]];
   }
   finalCost[group][4] = 1;
   return finalCost[group][3];
}

int minimumTime(int N, int *ARRAY)
{
    vector<int> fireIndices(ARRAY, ARRAY + N);
    int max = 0;
    for(int i = 0; i < fireIndices.size(); i++ )
    {
        if(max < fireIndices[i])
        {
            max = fireIndices[i];
        }
    }
    vector<vector<int> > groups(max);
    
    for(int i = 0; i < fireIndices.size(); i++)
    {
        groups[fireIndices[i] - 1].push_back(i);
    }

    vector<vector<vector<int> > > cost(groups.size());
    findAllLocalMinimum(groups, cost);
    int currentIndex = -1, minCost = 0;
    vector<vector<int> > finalMinCost(groups.size());
    minCost = findMinimumPathCost(groups.size() - 1, cost, currentIndex, groups, finalMinCost); 
    return (minCost + finalIndex);
}

int main() {
   //int ARRAY[] = {2,6,5,1,4,5,2,3,3,4};
   //int size = 10;
   //35

   //int ARRAY[] = {1, 2, 3, 4};
   //int size = 4;
   //7

   //int ARRAY[] = {4, 3, 2, 1};
   //int size = 4;
   //10

   //int ARRAY[] = {2,3,1,2,3};
   //int size = 5;
   int ARRAY[] = {3,3,2,1,4,2};
   int size = 6;
   //15
   cout<<"Minimum Time : "<<minimumTime(size, ARRAY)<<endl;
}
