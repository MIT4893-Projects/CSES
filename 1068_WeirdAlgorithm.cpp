#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll n;
int main()
{
    scanf("%lld", &n);

    while (n != 1)
    {
        printf("%lld ", n);
        if (n & 1)
            n = n * 3 + 1;
        else
            n /= 2;
    }
    printf("1");


    return 0;
}