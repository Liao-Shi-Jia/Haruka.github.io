#include <cstdio>



#define int long long
#define ll long long
template <typename T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

const int INF = (2e5 + 5e4 + 10);
const int Inf = 1e18;

int n, k;
int h = 1, t = 0;
ll ans = 0;
ll q[INF];
ll a[INF];
ll pre[INF];
ll f[INF];


ll get_pre(int l, int r)
{
    if (l <= r) {
        return pre[r] - pre[l - 1];
    } else {
        return 0;
    }
}

int get_val(int j)
{
    return a[j + 1] + f[j];
}

void add(int j)
{
    while (h <= t && get_val(q[t]) + get_pre(q[t] + 2, j + 1) <= get_val(j)) {
        t --;
    }
    q[++ t] = j;
}

signed main ()
{
    scanf ("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf ("%lld", &a[i]);
        pre[i] = pre[i - 1];
        if (a[i] > 0) {
            pre[i] += a[i];
        }
    }
    for (int i = 1; i <= n; i++) {

        f[i] = -Inf;
        if (i <= k) {
            f[i] = Max(f[i], a[i] + get_pre (1, i - 1));
        }
        f[i] = Max(f[i], a[i] + f[i - 1]);

        while (h <= t && i - k > q[h]) {
            h ++;
        }
        if (h < t) {
            f[i] = Max(f[i], a[i] + a[q[h] + 1] + f[q[h]] + get_pre(q[h] + 2, i - 1));
        }
        add (i - 1);

        ans = Max(ans, f[i]);
    }

    printf ("%lld", ans);
    return 0;
}