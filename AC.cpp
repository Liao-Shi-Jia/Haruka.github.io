#include<cstdio>

#define IL inline

typedef long long ll;

const int Geli = 146097;
const int Rulian = 1461;

int T;
int year[Geli], month[Geli], day[Geli];
ll n, t;
IL int check(int y, int m)
{
    if (m == 2) {
        return y % 4 ? 28 : y % 100 ? 29 : y % 400 ? 28 : 29;
    }
    return m == 4 || m == 6 || m == 9 || m == 11 ? 30 : 31;
}
int main()
{
    month[0] = day[0] = 1;
    for (int i = 1; i < Geli; i ++) {
        day[i] = day[i - 1] + 1;
        month[i] = month[i - 1];
        year[i] = year[i - 1];
        if (day[i] > check(year[i], month[i])) {
            month[i] ++;
            day[i] = 1;
        }
        if (month[i] > 12) {
            year[i] ++;
            month[i] = 1;
        }
    }
    scanf("%d", &T);
    while(T --) {
        scanf("%lld", &n);
        if (n > 2299160) {
            n -= 2159351;
            t = n / Geli * 400 + 1200;
            n %= Geli;
        } else {
            t = n / Rulian * 4 - 4712;
            n %= Rulian;
        }
        if (t + year[n] > 0) {
            printf("%d %d %lld\n", day[n], month[n], t + year[n]);
        } else {
            printf("%d %d %lld BC\n", day[n], month[n], 1 - t - year[n]);
        }
    }
    return 0;
}