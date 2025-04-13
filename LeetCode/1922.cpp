#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    const long long int maxn = 1e9 + 7;
    long long int r;
    long long int modCount(long long a, long long n, long long m)
    {
        a = a % m;
        r = 1;
        while (n != 0)
        {
            if (n & 1)
                r = (r * a) % m;
            a = (a * a) % m;
            n = n >> 1;
        }
        return r;
    }
    long long int o, e;
    int countGoodNumbers(long long n)
    {
        // 设偶数位有e个，奇数位有o个，则长度为n的数字中可能有的组合为4^o*5^e
        // 也就是说，要用两次快速幂再mod再相乘
        // 如果n为偶数，则o=e=n/2；如果n为奇数，则o=n/2，e=n/2+1
        if (n % 2)
        {
            o = n / 2;
            e = n / 2 + 1;
        }
        else
        {
            o = e = n / 2;
        }
        return ((modCount(4, o, maxn)) % maxn * (modCount(5, e, maxn) % maxn)) % maxn;
    }
};
int main()
{
}