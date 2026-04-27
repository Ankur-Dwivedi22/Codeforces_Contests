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

bool SieveOfEratosthenes(int n)
{

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    if (prime[n])
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int mod = 998244353;
int fact[100];

int modexp(int n)
{
    int b = n, e = mod - 2;
    int ans = 1;
    b = b % mod;
    while (e > 0)
    {
        if (e & 1)
        {
            ans = (ans * 1ll * b) % mod;
        }
        b = (b * 1ll * b) % mod;
        e = e / 2;
    }
    return ans;
}

int lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    ain(i,a,n);
    int t = 0 , i = 0;
    while(i < n){
        t++;
        int val = (a[i] + t) % m;
        if(val == 0){
            int prev = -1;
            if(i-1 >= 0){
                prev = (a[i-1] + t) % m;
            }
            if(prev == 0){
                coutn;
                return;
            }
        }
        else i++;
    }

    couty;
}

int32_t main()
{
    Ankur_Dwivedi();
    // fact[0] = 1;
    // for (int i = 1; i < 100; i++)
    // {
    //     fact[i] = (fact[i - 1] * 1ll * i) % mod;
    // }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}