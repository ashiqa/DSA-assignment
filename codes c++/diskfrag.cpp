#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    char B[n];
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    int i = 0;
    for (int j = n - 1; j != i; --j)
    {
        while (B[i] == 'A')
            ++i;
        if (B[j] == 'A')
        {
            swap(B[j], B[i]);
            ++cnt;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << B[i];
    cout << cnt;
    return 0;
}