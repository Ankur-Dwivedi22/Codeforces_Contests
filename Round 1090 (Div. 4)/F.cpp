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
vector<bool> prime;
void SieveOfEratosthenes(int n)
{

    prime.resize(n + 1, true);
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
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int sum = x + y;
    if (sum == 1)
    {
        if (y == 1)
        {
            couty;
        }
        else
        {
            coutn;
        }
    }
    else
    {
        int minx = 0, miny = 1;
        int req = sum / 2;
        if (sum % 2 == 1)
        {
            miny++;
        }
        else
        {
            minx++;
        }
        if (x < minx || y < miny || x > req)
        {
            coutn;
            return;
        }
        couty;
        int i = 1, ct = sum;
        while (x > 0)
        {
            cout << i << " " << i + 1 << "\n";
            i++;
            if (ct % 2 == 0)
                x--;
            ct--;
        }
        for (int j = i + 1; j <= sum; j++)
        {
            cout << i << " " << j << "\n";
        }
    }
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