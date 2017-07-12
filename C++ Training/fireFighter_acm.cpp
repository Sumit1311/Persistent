#include <vector>
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll finalIndex;
//Calculate Cost Return Minimum Frontier
ll calculateCost(vector<ll>& v, vector<ll> costA, vector<bool>& visited, ll source, ll& cost)
{
    ll min = 0, minIndex = -1;
    for(ll i = 0; i < v.size(); i++)
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
ll findMinSource(vector<ll>& v, ll& cost, ll s)
{
    vector<ll> costA(v.size(), 1);
    vector<bool> visited(v.size(), false);
    //visited[s] = true;
    ll minIndex = s /*calculateCost(v, costA, visited, s, cost)*/, oldIndex = s;
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
ll findAllPaths(vector<ll>& v, vector<vector<ll> >& cost)
{
    //vector<ll> v = {0,10,9,4,3,6} ;
    vector<ll> d = vector<ll>(2);
    vector<vector<ll> > cost_l(v.size(), d) ;
    cost = cost_l;
    for(ll i = 0; i < v.size(); i++)
    {
        cost[i][1] = findMinSource(v, cost[i][0], i);
        //cout<<"D : "<<v[i]<<", S :"<<v[cost[i][1]]<<", C : "<<cost[i][0]<<endl;
    }
}

//Calculate cost of each path in each group
ll findAllLocalMinimum(vector<vector <ll> >& v, vector<vector<vector<ll> > >& cost)
{
    //vector<vector<ll> > v = {{5,2,9,4,3,6},{2,4,5,6,7}} ;
    //vector<vector<ll> > d = vector<ll>(v.size(), vector<ll>(2));
    //vector<vector<vector<ll> > > cost(v.size());
    //vector<vector<ll> > cost(v.size(), d) ;
    for(ll i = 0; i < v.size(); i++)
    {
        //cout<<"Group : "<<i<<endl;
        findAllPaths(v[i], cost[i]);
    }
}

//Calculate the final Path cost
ll findMinimumPathCost(ll group, vector<vector<vector<ll> > >& cost, ll& index, vector<vector<ll> > v, vector<vector<ll> >& finalCost)
{
    ll minCost = 0, minSource = 0, minDestination = 0;
    if(group == -1)
    {
        return 0;
    }
   for(ll i = 0; i < cost[group].size(); i++)
   {

       //cout<<"Cost : "<<cost[group][i][0]<<", Add : "<<cost[group][i][1] - index<<endl;
       ll temp = cost[group][i][0] + (index == -1 ? 0 : abs(index - v[group][cost[group][i][1]]));
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
   vector<ll> d = vector<ll>(5);
   //vector<ll> cost_l(v.size(), d) ;
   finalCost[group] = d;
   finalCost[group][0] = minSource ;
   finalCost[group][1] = minDestination;
   finalCost[group][2] = minCost;
   finalCost[group][3] = 0;
   finalCost[group][4] = 0;
   ll finalMinCost, finalMinSource, finalMinDestination ;
   for(ll i = 0; i < cost[group].size(); i++)
   {
       finalMinCost = minCost;
       ll temp = cost[group][i][0] + (index == -1 ? 0 : abs(index - v[group][cost[group][i][1]]));
       if(temp == minCost) {
            ll current = v[group][i];
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
   cout<<"Group : "<<group<<", Min Source : "<<v[group][finalCost[group][0]]<<", Min Destination : "<<v[group][finalCost[group][1]]<<", Min Cost :"<<finalCost[group][2]<<endl;
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
   /*vector<ll> d = vector<ll>(5);
   //vector<ll> cost_l(v.size(), d) ;
   finalCost[group] = d;
   finalCost[group][0] = minSource ;
   finalCost[group][1] = minDestination;
   finalCost[group][2] = minCost;
   finalCost[group][3] = 0;
   finalCost[group][4] = 0;
   ll finalMinCost, finalMinSource, finalMinDestination ;
   for(ll i = 0; i < cost[group].size(); i++)
   {
       ll temp = cost[group][i][0] + (index == -1 ? 0 : abs(index - v[group][cost[group][i][1]]));
       if(temp == minCost) {
            ll current = v[group][i];
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

ll minimumTime(vector<ll> v)
{
    //vector<ll> fireIndices = {1,2,3,2,4,3,5,6,7};
    //ll ARRAY[] = {2,6,5,1,4,5,2,3,3,4};
    //ll N = 10;
    //cout<<v.size()<<endl;
    vector<ll> fireIndices(v);
    //vector<ll> fireIndices = {2,3,2,1,3};
    ll max = 0;
    for(ll i = 0; i < fireIndices.size(); i++ )
    {
        if(max < fireIndices[i])
        {
            max = fireIndices[i];
        }
    }
    vector<vector<ll> > groups(max);
    
    for(ll i = 0; i < fireIndices.size(); i++)
    {
        groups[fireIndices[i] - 1].push_back(i);
    }

    vector<vector<vector<ll> > > cost(groups.size());
    findAllLocalMinimum(groups, cost);
    ll currentIndex = -1, minCost = 0;
    vector<vector<ll> > finalMinCost(groups.size());
    minCost = findMinimumPathCost(groups.size() - 1, cost, currentIndex, groups, finalMinCost); 
    /*for(ll i = groups.size() - 1; i >= 0 ; i--)
    {
       minCost += findMinimumPathCost(i, cost, currentIndex, groups, finalMinCost); 
    }*/
    //cout<<"Initial : "<<finalIndex<<endl;
    //cout<<"Global Minimum cost : "<<minCost + finalIndex<<endl;
    return (minCost + finalIndex);
}

int main() {
   //ll ARRAY[] = {2,6,5,1,4,5,2,3,3,4};
   //ll size = 10;
   //35

   //ll ARRAY[] = {1, 2, 3, 4};
   //ll size = 4;
   //7

   //ll ARRAY[] = {4, 3, 2, 1};
   //ll size = 4;
   //10

   //ll ARRAY[] = {2,3,1,2,3};
   //ll size = 5;
   //ll ARRAY[] = {3,3,2,1,4,2};
   //ll size = 6;
   //15

   ll size;
   ll count = 0;
   cin>>size;
   //cout<<size;
   vector<ll> v;
   //cout<<v.size();
   /*while(size > 0) {
    ll ret = 0, ch;
    while(!isdigit(ch = getc(stdin)));
    ret = ch - '0';
    while(isdigit(ch = getc(stdin)))
        ret = ret*10 + ch - '0';
    cout<<ret<<",";
    v.push_back(ret);
    size--;
    }*/
   while(size > 0) {
      ll temp;
      cin>>temp;
      v.push_back(temp);
      size--;
      //cout<<size;
   }
   
   //cout<<v.size();
   //ll ARRAY[]= {1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 2, 1, 2, 2, 1, 2,   1, 2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1,   1, 1, 1, 2, 2, 2};
   //ll size = 100;
   
   cout<<minimumTime(v);
}
