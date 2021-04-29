# CSP-S2020 T1 儒略日
## [洛谷传送门](https://www.luogu.com.cn/problem/P7075)
___
### 正解:
首先分析题目：
<br> 1. 得到 __常量__：
<br>① 格里高利历 ___400___ 年的天数为 ___146097___
<br>② ___4713.1.1___ ~ ___1582.10.4___ 的天数为 ___2299160___  　　~~算的时候记得减去88~~
<br>方法如下
 ```c++
int n, ans = 0;
scanf("%d", &n);
ans += (n / 4) * 366;
ans += (n - (n / 4)) * 365;
  ```
<br>③ 儒略历 __4__ 年的天数 ___1461___　~~手算即可~~
<br>④ ___4713.1.1___ ~ ___1200.1.1___ 的儒略日 ___2159351___
<br> <br> 2. 判断历法时 如果 ri < 2299160 那么必定是儒略日
<br> GOOOOOOD

```c++
#include <cstdio>

#define IL inline

typedef long long ll;

const int Geli = 146097 // 格里高利历 400 年的天数
const int Rulian = 1461; // 儒略日 4 年的天数

int T;
int day[Geli], month[Geli], year[Geli]
/*
    day[i] : 格里高利历 400 年天数
    month[i] : 格里高利历 400 年月数
    year[i] : 格里高利历 400 年年数
*/
ll n, t;

IL int check(int y, int m)
{
    if (m == 2) {
        return y % 4 ? 28 : y % 100 ? 29 : y % 400 ? 28 : 29;
        /*
         * 可以简单理解为 
         * if y % 4:
         *      if y % 100:
         *          return 28
         *      else:
         *          return 29
         * else if y % 400:
         *      return 29
         * else:
         *      return 28
         * */
    }
    return m == 4 || m == 6 || m == 9 || m == 11 ? 30 : 31;
}

int main()
{
    month[0] = day[0] = 1;
    scanf("%d", &T);
    for (int i = 1; i < Geli; i ++) {
        day[i] = day[i - 1] + 1; // 模拟天数增长
        m[i] = m[i - 1]; // 不到 30天 或 31天 月数不变
        y[i] = y[i - 1]; // 不到 365天 或 366天 年数不变
        if (day[i] > check(year[i], month[i])) { // 新的一个月开始了~！
            month[i] ++;
            day[i] = 1;
        }
        if (month[i] > 12) { // 新的一年开始了~！
            year[i] ++;
            m[i] = 1;
        }
    }
    while(T --) {
        scanf("%lld", &n);
        if (n > 2299160) { // 是格里高利历
            n -= 2159351;
            t = n / Geli * 400 + 1200;
            n %= Geli;
        } else {
            n = n / Rulian * 4 - 4712;
            n %= Rulian;
        }
        if (t + year[n] > 0) {
            printf("%d %d %lld", day[n], month[n], t + year[n]);
        } else {
            printf("%d %d %lld BC", day[n], month[n], 1 - t - year[n]);
        }
    }
    return 0;
}
```
___
#CSP-S2020 T2 动物园
### [洛谷传送门](https://www.luogu.com.cn/problem/P7076)
___
####


