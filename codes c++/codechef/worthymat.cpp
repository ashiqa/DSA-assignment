#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        ll cnt = 0;
        cin >> n >> m >> k;
        ll mat[n + 1][m + 1];

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (i == 0 || j == 0)
                    mat[i][j] = 0;
                else
                {
                    cin >> mat[i][j];
                }
            }
        }
        for (int i = 0; i <= n; ++i)
        {
            ll prev = 0;
            for (int j = 0; j <= m; ++j)
            {
                mat[i][j] += prev;
                prev = mat[i][j];
            }
        }
        for (int j = 0; j <= m; ++j)
        {
            ll prev = 0;
            for (int i = 0; i <= n; ++i)
            {
                mat[i][j] += prev;
                prev = mat[i][j];
            }
        }
        for (int i = 0; i <= n; ++i)
        {
            cout << endl;
            for (int j = 0; j <= m; ++j)
            {

                cout << mat[i][j] << " ";
            }
        }
        int limlen = min(m, n);
        for (int l = 1; l <= limlen; ++l)
        {
            for (int i = l; i <= n; ++i)
            {
                for (int j = l; j <= m; ++j)
                {
                    if ((mat[i][j] - mat[i - l][j] - mat[i][j - l] + mat[i - l][j - l]) / (l * l) >= k)
                    {
                        ++cnt;
                    }
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
