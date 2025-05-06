#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int ks[5001][10001];

int main()
{
    while (true)
    {
        int n, m;
        double tmp;
        scanf("%d %lf", &n, &tmp);
        if (n == 0) break;

        m = (int)(tmp * 100 + 0.5); // 반올림
        int c[5001], p[5001];
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %lf", &c[i], &tmp);
            p[i] = (int)(tmp * 100 + 0.5); // 반올림
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (j < p[i]) ks[i][j] = ks[i - 1][j];
                else ks[i][j] = max(ks[i - 1][j], c[i] + ks[i][j - p[i]]);
            }
        }

        printf("%d\n", ks[n][m]);
    }
}