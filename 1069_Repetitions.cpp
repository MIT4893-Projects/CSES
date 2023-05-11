#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    s += ' ';

    int result = 1;
    int curr = 1;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i-1])
            ++curr;
        else
        {
            result = max(result, curr);
            curr = 1;
        }
    }

    cout << result;

    return 0;
}