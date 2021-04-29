#include <cstdio>
#include <cctype>
#define INF int(25 * 1e4 + 10)
typedef long long ll;
int n, k;
int a[INF];
int h, t = 1;
ll f[INF];
ll q[INF];
ll pre[INF];
ll ans;
template <typename T>
void read(T &x)
{
    T s = 1;
    x = 0;
    char ch = getchar();
    while (0 == isdigit(ch)) {
        if (ch == '-') {
            s = -1;
        }
        ch = getchar();
    }
    while (0 != isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    x *= s;
}

template <typename T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

template <typename T>
T Min(T x, T y)
{
    return x > y ? y : x;
}

int main()
{
    read(n);
    read(k);
    for (int i = 1; i <= n; i ++) {
        read(a[i]);
        pre[i] = pre[i - 1] + Max(a[i], 0);
    }
    if (k == 1)
    {
        printf("%d\n", Max(0, a[1]));
        return 0;
    }
    f[1] = a[1];
    for (int i = 1; i <= n; i ++)
    {
        while (h < t && i - k > q[h]) {
            h ++;
        }
        int j = q[h];
        f[i] = f[j] + a[i] + a[i - 1] + pre[i - 2] - pre[j];
        while (h < t && f[q[t - 1]] - pre[q[t - 1]] <= f[i - 1] - pre[i - 1]) {
            t --;
        }
        q[t ++] = i - 1;
    }
    for (int i = 1; i <= n; i ++) {
        ans = Max(ans, f[i] + pre[Min(n, i + k - 1)] - pre[i]);
    }
    printf("%lld\n", Max(ans, pre[k]));
    return 0;
}