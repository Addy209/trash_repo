#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <vector>
#define INF 1000000007
#define lli long long int
#define pb push_back
#define mp make_pair
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

lli dpa[100001];
lli dpb[100001];

lli aoperations(lli n, lli gd, lli bd);
lli boperations(lli n, lli gd, lli bd);


lli aoperations(lli n, lli gd, lli bd)
{
    if (dpa[n] == -1)
    {
        dpa[n] = ((aoperations(n-1, gd, bd)*(gd-1)) % INF + (boperations(n-1, gd, bd)*gd) % INF) % INF;
    }

    return (dpa[n] % INF);
}

lli boperations(lli n, lli gd, lli bd)
{
    if (dpb[n] == -1)
    {
        dpb[n] = ((aoperations(n-1, gd, bd)*bd)%INF + (boperations(n-1, gd, bd)*(bd-1) % INF)) % INF;
    }

    return dpb[n] % INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    lli gd = 0, bd = 0;
    memset(dpa, -1, sizeof(dpa));
    memset(dpb, -1, sizeof(dpb));

    if (s == t)
    {
        dpa[0] = 1;
        dpb[0] = 0;
        gd++;
    }
    else
    {
        dpb[0] = 1;
        dpa[0] = 0;
        bd++;
    }

    string str = s;
    FOR(i, s.length() - 1)
    {
        str[0] = s[s.length() - 1]; // s = abcd, t = bcda    str = d
        for (int j = 0; j < s.length() - 1; j++)
        {
            str[j + 1] = s[j];
        }

        s = str;
        if (s == t)
        {
            gd++;
        }
        else
        {
            bd++;
        }
    }

    cout<<aoperations(n, gd, bd)<<endl;
    //cout << gd << " " << bd;

    return 0;
}