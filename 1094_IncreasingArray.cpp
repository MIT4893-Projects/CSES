#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int last;
    cin >> last;

    ll result = 0;
    for (int i = 1; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if (temp < last)
            result += last - temp;
        else
            last = temp;
    }

    cout << result;

    return 0;
}