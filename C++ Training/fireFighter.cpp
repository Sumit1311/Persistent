#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int finalIndex;
//Calculate Cost Return Minimum Frontier
int calculateCost(vector<int>& v, vector<int> costA, vector<bool>& visited, int source, int& cost)
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
                //cout<<"Setting min"<<min<<endl;
            //cout<<"CostA[i]"<<costA[i]<<endl;
            if(min > costA[i])
            {
                min = costA[i]; minIndex = i;
            }
            //cout<<min<<endl;
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
    //visited[s] = true;
    int minIndex = s /*calculateCost(v, costA, visited, s, cost)*/, oldIndex = s;
    //cout<<"Source : "<< s << endl;
    cost = 1;
    while(minIndex != -1)
    {
        //cout << "Min : "<<minIndex << ", Cost : "<<cost<<endl;
        visited[minIndex] = true;
        oldIndex = minIndex;
        minIndex = calculateCost(v, costA, visited, minIndex, cost);
    }

    //cout<<"Destination : "<< oldIndex << endl;
    //cout<<"Cost : "<< cost << endl;
    return oldIndex;
}

//Find All possible paths within group
int findAllPaths(vector<int>& v, vector<vector<int> >& cost)
{
    //vector<int> v = {0,10,9,4,3,6} ;
    vector<int> d = vector<int>(2);
    vector<vector<int> > cost_l(v.size(), d) ;
    cost = cost_l;
    for(int i = 0; i < v.size(); i++)
    {
        cost[i][1] = findMinSource(v, cost[i][0], i);
        //cout<<cost[i][1]<<endl;
        cout<<"D : "<<v[i]<<", S :"<<v[cost[i][1]]<<", C : "<<cost[i][0]<<endl;
    }
}

//Calculate cost of each path in each group
int findAllLocalMinimum(vector<vector <int> >& v, vector<vector<vector<int> > >& cost)
{
    //vector<vector<int> > v = {{5,2,9,4,3,6},{2,4,5,6,7}} ;
    //vector<vector<int> > d = vector<int>(v.size(), vector<int>(2));
    //vector<vector<vector<int> > > cost(v.size());
    //vector<vector<int> > cost(v.size(), d) ;
    for(int i = 0; i < v.size(); i++)
    {
        cout<<"Group : "<<i<<endl;
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

       //cout<<"Cost : "<<cost[group][i][0]<<", Add : "<<cost[group][i][1] - index<<endl;
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
   //vector<int> cost_l(v.size(), d) ;
   finalCost[group] = d;
   finalCost[group][0] = minSource ;
   finalCost[group][1] = minDestination;
   finalCost[group][2] = minCost;
   finalCost[group][3] = 0;
   finalCost[group][4] = 0;
   int finalMinCost, finalMinSource, finalMinDestination ;
   if(cost[group].size() == 0) {
      finalMinCost += findMinimumPathCost(group - 1, cost, index, v, finalCost);
   }
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
   cout<<"Group : "<<group;
   //cout<<"Group : "<<group<<", Min Source : "<<v[group][finalCost[group][0]]<<", Min Destination : "<<v[group][finalCost[group][1]]<<", Min Cost :"<<finalCost[group][2]<<endl;
   //index = v[group][finalCost[group][0]];
   if(group == 0)
   {
       //cout <<"Final";
        finalIndex = v[group][finalCost[group][0]];
   }
   finalCost[group][4] = 1;
   return finalCost[group][3];
   /*if(finalCost[group].size() == 5 && finalCost[group][4] == 1)
   {
   cout<<"Group : "<<group<<", Min Source : "<<v[group][finalCost[group][0]]<<", Min Destination : "<<v[group][finalCost[group][1]]<<", Min Cost :"<<finalCost[group][2]<<endl;
   index = v[group][finalCost[group][0]];
   finalCost[group][4] = 1;
   return finalCost[group][2];
   }
   else
   {*/
   /*vector<int> d = vector<int>(5);
   //vector<int> cost_l(v.size(), d) ;
   finalCost[group] = d;
   finalCost[group][0] = minSource ;
   finalCost[group][1] = minDestination;
   finalCost[group][2] = minCost;
   finalCost[group][3] = 0;
   finalCost[group][4] = 0;
   int finalMinCost, finalMinSource, finalMinDestination ;
   for(int i = 0; i < cost[group].size(); i++)
   {
       int temp = cost[group][i][0] + (index == -1 ? 0 : abs(index - v[group][cost[group][i][1]]));
       if(temp == minCost) {
            int current = v[group][i];
            finalMinCost = findMinimumPathCost(group - 1, cost, current, v, finalCost);
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
   cout<<"Group : "<<group<<", Min Source : "<<v[group][finalCost[group][0]]<<", Min Destination : "<<v[group][finalCost[group][1]]<<", Min Cost :"<<finalCost[group][2]<<endl;
   index = v[group][finalCost[group][0]];
   finalCost[group][4] = 1;
   return finalCost[group][2];*/
   //}
}

int minimumTime(int N, int *ARRAY)
{
    //vector<int> fireIndices = {1,2,3,2,4,3,5,6,7};
    //int ARRAY[] = {2,6,5,1,4,5,2,3,3,4};
    //int N = 10;
    vector<int> fireIndices(ARRAY, ARRAY + N);
    //vector<int> fireIndices = {2,3,2,1,3};
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
    /*for(int i = groups.size() - 1; i >= 0 ; i--)
    {
       minCost += findMinimumPathCost(i, cost, currentIndex, groups, finalMinCost); 
    }*/
    //cout<<"Initial : "<<finalIndex<<endl;
    //cout<<"Global Minimum cost : "<<minCost + finalIndex<<endl;
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
   //int ARRAY[] = {3,3,2,1,4,2};
   //int size = 6;
   //15
   int size = 6;
   int ARRAY[] = {3,2,5,6,2,5};
   
   cout<<"Minimum Time : "<<minimumTime(size, ARRAY)<<endl;
}
