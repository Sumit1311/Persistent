#include<bits/stdc++.h>
using namespace std;

inline int getint()
{
    int ret = 0, ch;
    while(!isdigit(ch = getc(stdin)));
    ret = ch - '0';
    while(isdigit(ch = getc(stdin)))
        ret = ret*10 + ch - '0';
    return ret;
}

int main()
{
    int N = getint();
    std::vector<std::pair<int, int>> v;
    std::vector<int> u;
    std::vector<std::pair<int, int>> rl;
    for(int i = 0; i < N; i++)
    {
        int x = getint();
        v.push_back({x, i});
    }
    std::sort(v.begin(), v.end());
    u.push_back(v.front().first);
    rl.push_back( { v.front().second, v.front().second } );
    for(int i = 1; i < N; i++)
    {
        if(v[i].first != u.back())
        {
            u.push_back(v[i].first);
            rl.push_back( { v[i].second, v[i].second });
        }
        else
            rl.back().second = v[i].second;
    }
    long long Ln = 0, Rn = 0;
    long long Cr = 0, Cl = 0;
    for(int i = 0; i < u.size(); i++)
    {
        long long Crp = Cr, Clp = Cl;
        long long Lp = Ln, Rp = Rn;
        Rn = rl[i].second;
        Ln = rl[i].first;
        Cr = Rn - Ln + std::min(Crp + std::abs(Rp-Ln), Clp + std::abs(Lp-Ln));
        Cl = Rn - Ln + std::min(Crp + std::abs(Rp-Rn), Clp + std::abs(Lp-Rn));
    }
    std::cout << N + std::min(Cr, Cl) << std::endl;
    return 0;
}