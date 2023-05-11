#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    ll sum = 0;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << n * (n + 1) / 2 - sum;

    return 0;
}