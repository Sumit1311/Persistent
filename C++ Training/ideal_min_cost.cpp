#include <iostream>
//#include <cstdio>

using namespace std;

//int a[1000000];
int b[1000000];
bool vis[1000000];
int place[1000000]= {0};
int find_min_cost(int *a, int size) {
    int t = 0;
    /*while (scanf("%d", &N) && N) {
        t++;*/
        for (int i = 0; i < size; ++i) {
            //scanf("%d", &a[i]);
            b[i] = a[i];
            vis[i] = false;
        }
        sort(b, b + size);

        // Map the numbers to their desired place after sort
        //map<int, int> place;
        
        for (int i = 0; i < size; ++i) {
            place[b[i]] = i;
        }
    
        int res = 0;
        for (int i = 0; i < size; ++i) {
            if (vis[i] == false) {
                if (place[a[i]] == i) {
                    vis[i] = true;
                    continue;
                }
                // We're in new cycle
                int min_val = a[i];
                int num = 0;
                int sum = 0;
                int j = i;

                while (vis[j] == false) {
                    sum += a[j];
                    num++;
                    if (a[j] < min_val) {
                        min_val = a[j];
                    }
                    vis[j] = true;
                    j = place[a[j]];
                }
                sum -= min_val;
                res += sum + min_val * (num - 1);
                
                // Let's try to borrow the minimum value.
                // If it's less costly then update our result.
                if (2 * (b[0] + min_val) <
                    (min_val - b[0]) * (num - 1)) {
                    res -= (min_val - b[0]) * (num - 1) -
                           2 * (b[0] + min_val);
                }    
            }
        }
        //printf("Case %d: %d\n\n", t, res);
    //}
    //return 0;
    return res;
}

int main()
{
   int arr[] = {12,11,4,3,1,14,8,6,5,13,9,10,2,16,7,15};
   int size = 16;
   printf("%d\n",find_min_cost(arr, size));
}
