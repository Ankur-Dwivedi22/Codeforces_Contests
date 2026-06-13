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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ain(i, a, n);

    sort(all(a));
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (v.empty() || (v.back().first != a[i]))
        {
            v.push_back({a[i], 1});
        }
        else
        {
            v.back().second += 1;
        }
    }
    int m = v.size();
    int r = m - 1, l = m - 1;
    vector<int> dp(m, 0);
    int ct = 0;
    bool ans = false;

    while (l >= 0)
    {
        while (r > l && v[r].first > v[l].first + k)
        {
            if (dp[r] == 1)
            {
                ct--;
            }
            r--;
        }
        if (ct == 0)
            dp[l] = (v[l].second % 2 != 0);
        else
            dp[l] = 0;

        if (!dp[l])
        {
            ans = true;
            break;
        }
        else
        {
            ct++;
        }
        l--;
    }

    if (ans)
        couty;
    else
        coutn;
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