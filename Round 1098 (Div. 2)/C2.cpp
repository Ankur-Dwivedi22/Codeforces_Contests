// HARE RAM HARE KRISHNA

#include <bits/stdc++.h>
using namespace std;
#define int long long
const double PI = 3.14159265358979323846;
#define INF (int)1e18
#define f first
#define s second
#define pb(a) push_back(a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define Ankur_Dwivedi()                   \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }

#define couty cout << "YES" << endl
#define coutn cout << "NO" << endl
#define cout(a) cout << a << endl

#define ain(i, arr, n)          \
    ;                           \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
    }
#define aout(i, arr, n)         \
    ;                           \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i] << " ";  \
    }

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

string binary(int x)
{
    string s = "";
    for (int i = 31; i >= 0; i--)
    {
        int a = ((x >> i) & 1);
        if (a == 1)
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
    }
    return s;
}

const int MAXN = 10000000;
std::bitset<MAXN + 1> is_prime;

void SieveOfEratosthenes()
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (int p = 2; p * p <= MAXN; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= MAXN; i += p)
            {
                is_prime[i] = 0;
            }
        }
    }
}

int ans;

void fun(int i, int num, bool grt, bool sm, string &s, int a, vector<int> &d)
{
    if (i == s.size())
    {
        ans = min(ans, abs(a - num));
        return;
    }

    int td = s[i] - '0';
    for (int dig : d)
    {
        if (grt)
        {
            if (dig == d[0])
            {
                fun(i + 1, num * 10 + dig, true, false, s, a, d);
            }
        }
        else if (sm)
        {
            if (dig == d.back())
            {
                fun(i + 1, num * 10 + dig, false, true, s, a, d);
            }
        }
        else
        {
            fun(i + 1, num * 10 + dig, dig > td, dig < td, s, a, d);
        }
    }
}

void solve()
{
    int a, n;
    cin >> a >> n;
    vector<int> d(n);
    ain(i, d, n);
    sort(all(d));
    string s = to_string(a);
    int l = s.size();
    ans = INF;

    if(a == 0){
        cout(d[0]);
        return;
    }

    if (l > 1)
    {
        int b = 0;
        for (int i = 0; i < l - 1; i++)
        {
            b = b * 10 + d.back();
        }
        ans = min(ans, abs(a - b));
    }
    else if (d[0] == 0 && l == 1)
    {
        ans = min(ans, a);
    }

    int d1 = (d[0] == 0 ? d[1] : d[0]);
    int b = d1;
    for (int i = 1; i < l + 1; i++)
    {
        b = b * 10 + d[0];
    }
    ans = min(ans, abs(a - b));

    fun(0, 0, false, false, s, a, d);
    cout(ans);
}

int32_t main()
{
    Ankur_Dwivedi();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}