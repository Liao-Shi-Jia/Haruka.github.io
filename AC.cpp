#include <cstdio>
#include <cctype>

#define IL inline

typedef unsigned long long ull;

ull n, m, c, k;
ull ans, p, q, num;

IL ull read()
{
    ull s = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        ch = getchar();
    }
    while (isdigit(ch)) {
        s = (s << 3) + (s << 1) + ch - '0';
        ch = getchar();
    }
    return s;
}

int main()
{
    n = read();
    m = read();
    c = read();
    k = read();
    for (int i = 1; i <= n; i ++) {
        num |= read();
    }
    for (int i = 1; i <= m; i ++) {
        p |= 1ull << read();
        q = read(); // 屁用没有
    }
    for (int i = 0; i < k; i ++) {
        ans += !((p >> i) & 1) || ((num >> i) & 1);
    }
    if (ans == 64 && !n) {
        puts("18446744073709551616");
    } else {
        printf("%llu\n", ans == 64 ? -n : (1ull << ans) - n);
    }
    return 0;
}