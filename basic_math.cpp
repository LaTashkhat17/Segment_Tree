#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define en '\n'
#define ll long long int
#define trace(x) cout << #x << ": " << x << endl
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
#define tst int t;cin>>t;while(t--)
#define sortv(v) sort(v.begin(),v.end())
#define coutv(v) for(auto it:v)cout<<it<<" ";cout<<endl
#define cinv(v) for(auto &it:v)cin>>it
#define unique1(v) int sz=unique(v.begin(),v.end())-v.begin()
#define maxi(v)  int mx=*max_element(v.begin(),v.end())
void io()
{
#ifndef a
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/// Ctrl+H  replace
/// Ctrl+/  comment line
/// Ctrl+M  jump to matching brackets

const int mx = 1e7 + 123;
int ar[mx];
vector<int> d[mx];
int sumofdiv[mx];

///divisibility by 3 & 9
//if digitsum is divisible by 3 & 9 then the num will be divisible by 3 & 9

///divisibilty by 4
/*
The basic rule for divisibility by is that if the number formed by the last two digits in a
number is divisible by 4, the original number is divisible by 4.
4123 = (4 * 10^3 + 1 * 10 ^2 + 2 * 10 + 3) % 4
or, ((4 * 10^3)% 4 + (1 * 10 ^2)% 4 + (2 * 10)% 4 + (3) % 4) % 4
or, (0 + 0 + (2 * 10)% 4 + (3) % 4) % 4
or (2 * 10 + 3) % 4 ------->ans
*/

///divisible by 6
///if the number is divisible by 2 & divisible by 3 then the
//original number is divisible by 6


///divisible by 11
/*
Add and subtract digits in an alternating pattern (add a digit, subtract next digit, add next digit,
etc). Then check if that answer is divisible by 11.
---- 10 % 11 = -1
4123 = (4 * 10^3 + 1 * 10 ^2 + 2 * 10 + 3) % 11
or, ((4 * 10^3)%11 + (1 * 10 ^2)% 11 + (2 * 10)%11 + (3) % 11) % 11
or, (4*(-1) + 1*(1) + (2 *(-1) + 3) % 11
or (4 - 1 + 2 + 3) % 11 ------->ans
*/

///Divisibility and Large Numbers      11111111111111111111111111111111
/*for (int i = 0; i < a.size(); i++)ans = (ans * 10 + (a[i] - '0')) % b;
int main()
{

	io();
	optimize();
	string a; int b; cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		ans = (ans * 10ll % b + (a[i] - '0')) % b;
	}
	cout << ans << en;
	if (ans == 0) cout << "a is divisible by b" << en;
	else cout << "a is not divisible by b" << en;
}*/




///////////////////Problem: You are given an integer n(1<= n <= 100).2222222222222222222222222222222222
// Find an integer array of a1,a2,a3...........an of n
// length n such that for each subarray, the product of the elements of that
// subarray is divisible by the length of the subarray.
// All elements of the arrray should be <= 10e9.

/*ans: print 1 to n.how? (think!!!)*/

/*Divisible by All
How to check if a number is divisible by both a and b?
How to check if a number is divisible by all a,b and c?

Problem: Find numbers in between which are divisible by all Array elements of the
given array of size n.                 3333333333333333333333333333333333333333333333333333333333333333333333333
ans : n/lcm(a,b) , n/lcm(a,b,c) ----[52-53 min]*/

///sum of pair in an array divisible by k.4444444444444444444444444444444444444
/* Given an array and positive integer k, the task is to count the total number of pairs
in the array whose sum is divisible by k.*/
/*
void solve()
{
	int x, k; cin >> x >> k;
	vector<int> v(x);
	cinv(v);
	for (auto &u : v) u %= k;
	map<int, int>mp;
	int cnt = 0;
	for (int i = 0; i < x; i++)
	{
		mp[v[i]]++;
		cnt += mp[k - v[i]];
	}
	cout << cnt << en;
}
int main()
{

	io();
	optimize();
	tst
	{
		solve();
	}
}
*/

///subarray sum divisible by k.5555555555555555555555555555555555555555555555555555


//Problem: You are given an array of positive and/or negative integers and a value K. The task is
//to find the count of all sub-arrays whose sum is divisible by K?
/*
void solve()
{
	int x, k; cin >> x >> k;
	vector<int> v(x), pr(x + 1);
	cinv(v);
	map<int, int>mp;
	pr[0] = 0;
	for (int i = 1; i <= x; i++)
	{
		pr[i] = pr[i - 1]  + v[i - 1];
	}
	coutv(pr);
	for (auto &u : pr) u %= k;
	coutv(pr);
	ll cnt = 0;
	for (int i = 0; i <= x ; i++)
	{
		cnt += 1ll * mp[pr[i]];
		mp[pr[i]]++;
	}
	for (auto &u : mp) cout << u.first << " " << u.second << en;;
	cout << cnt << en;
}
int main()
{
	io();
	optimize();
	tst
	{
		solve();
	}
}

*/

//Problem: Given an array of integer numbers of size n, we need to find the maximum size of a
//subset such that the sum of each pair of this subset is not divisible by k.666666666666666666666666666666666666666666666
/*
void solve()
{
	int x, k; cin >> x >> k;
	vector<int> v(x);
	cinv(v);
	map<int, int>mp;
	for (auto &u : v) u %= k;
	for (auto &u : v) mp[u]++;
	//mp[0] = 0;
	if (k % 2 == 0) mp[k / 2] = 1;
	int maxsize = 0;
	for (auto &u : mp)
	{
		//cout << u.first << " " << u.second << en;
		if (u.first == 0) u.second = 1;
		else maxsize += u.second;
	}
	mp[k] = 1;
	ll cnt = 0;
	int maxi = 0;
	for (int i = 0; i < x; i++)
	{
		maxi = max(maxi, maxsize - mp[k - v[i]]);
		//cout << "when " << v[i] << " :" << maxsize - mp[k - v[i]] << en;
	}
	cout << maxi << en;
}

int main()
{
	io();
	optimize();
	tst
	{
		solve();
	}
}*/


//////Problem: Legendres formula.777777777777777777777777777777777777777777777777

// Given an integer nand a prime number p, find the largest x such that p^x divides (factorial) n!
/*
int legendra(ll x, ll p)
{
	int ans = 0;
	ll cur = p;
	while (cur <= x)
	{
		ans += x / cur;
		if (cur <= x / p)
		{
			cur *= p;
		}
		else break;
	} return ans;
}

int legendra_better(ll x, ll p)
{
	int ans = 0;
	while (x)
	{
		ans += x / p;
		x /= p;
	}
	return ans;
}

void solve()
{
	ll x, y; cin >> x >> y;
	cout << legendra(x, y) << en;
	cout << legendra_better(x, y) << en;
}

int main()
{

	io();
	optimize();

	{
		solve();
	}
}
*/


///////Trailing zeros(using legendra).8888888888888888888888888888888888888888888888888

///find the trailing zeros in factorial of an integer n.
///ans----> minimum power of 2 & 5 divisible by n! (or) power of 5 divisible by n!
/*
int legendra(ll x, ll y)
{
	int ans = 0;
	while (x)
	{
		ans += x / y;
		x /= y;
	}
	return ans;
}
void solve()
{
	ll x; cin >> x;
	cout << legendra(x, 2) << en;
	cout << legendra(x, 5) << en;
	cout << min(legendra(x, 2), legendra(x, 5)) << en;
}

int main()
{

	io();
	optimize();
	{
		solve();
	}
}*/

////Divisors of A Factorial
//Find the number of divisors in factorial of an integer n in O(nlogn).99999999999999999999999999999999999999999999999999999
/*
const int n = 1e6 + 9;
int spf[n];
map<int, ll>mp;

void sieve(int q)
{
	for (int i = 2; i < n; i++)
	{
		spf[i] = i;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = i; j < n; j += i)
		{
			spf[j] = min(spf[j], i);
		}
	}
	for (int i = 2; i <= q; i++)
	{
		int x = i;
		while (x > 1)
		{
			// cout << spf[x] << " ";
			mp[spf[x]]++;
			x /= spf[x];
			// } cout << en;
		}
	}
}

int main()
{

	io();
	optimize();
	int x; cin >> x;
	sieve(x);
	unsigned ll ans = 1;
	for (auto &u : mp) cout << u.first << " " << u.second << en;
	for (auto &u : mp) {
		ans *= (u.second + 1);
	}
	cout << ans << en;
}
*/

///Find the number of odd divisors in factorial of an integer n  in O(nlogn).aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
/*
const int n = 1e6 + 9;
int spf[n];
map<int, ll>mp;

void sieve(int q)
{
	for (int i = 2; i < n; i++)
	{
		spf[i] = i;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = i; j < n; j += i)
		{
			spf[j] = min(spf[j], i);
		}
	}
	for (int i = 2; i <= q; i++)
	{
		int x = i;
		while (x > 1)
		{
			// cout << spf[x] << " ";
			mp[spf[x]]++;
			x /= spf[x];
			// } cout << en;
		}
	}
}
int main()
{

	io();
	optimize();
	int x; cin >> x;
	sieve(x);
	unsigned ll ans = 1;
	for (auto &u : mp) cout << u.first << " " << u.second << en;
	mp[2] = 0;
	for (auto &u : mp) {

		ans *= (u.second + 1);
	}
	cout << ans << en;
}
*/

/////////Given an integer n. How to find the number of divisors which are odd?bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
/*const int n = 1e6 + 9;
int spf[n];
map<int, ll>mp;

void sieve(int x)
{
	for (int i = 2; i < n; i++)
	{
		spf[i] = i;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = i; j < n; j += i)
		{
			spf[j] = min(spf[j], i);
		}
	}
	while (x > 1)
	{
		//cout << spf[x] << " ";
		mp[spf[x]]++;
		x /= spf[x];

	}
	//cout << en;

}
int main()
{

	io();
	optimize();
	int x; cin >> x;
	sieve(x);
	unsigned ll ans = 1;
	//for (auto &u : mp) cout << u.first << " " << u.second << en;
	mp[2] = 0;
	for (auto &u : mp) {

		ans *= (u.second + 1);
	}
	cout << ans << en;
}
*/


///////////Goldbachs Conjecture
/*Conjecture: Every even integer greater than 2 can be expressed as the sum of two primes. No
proof, that's why it's called a conjecture.*/
/*
Problem: For all even integers x from 4 to 10^5, find any two primes such that their sum is x.cccccccccccccccccccccccccccccccccccccccccccccc
Solve it in less than 1s.*/
/*

const int size = 1e5 + 9;
bool f[size];
set<int>s;
vector<int>v;
void pf()
{
	f[1] = true;
	for (int i = 2; i * i <= size; i++)
	{
		if (!f[i])
		{
			for (int j = i * i; j <= size; j += i)
			{
				f[j] = true;
			}
		}
	}

	for (int i = 1; i <= size; i++)
	{
		if (!f[i])
		{
			v.push_back(i);
			s.insert(i);
		}
	}
}
void primegenerate(int x)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s.find(x) != s.end())
		{
			cout << "not possible" << en;
			return;
		}
		if (s.find(x - v[i]) != s.end())
		{
			cout << v[i] << " " <<  x - v[i] << en;
			return;
		}
	}
}
void solve()
{
	int x; cin >> x;
	pf();
	primegenerate(x);
}

int main()
{

	io();
	optimize();
	tst
	{
		solve();
	}
}
*/


/*
Bonus: For all odd integers x from 4 to 10^5 , find any three primes such that their sum is x.
Solve it in less than 1s.
*/
///////////////using primefactorization
/*
const int size = 1e5 + 9;
bool f[size];
set<int>s;
vector<int>v;
void pf()
{
	f[1] = true;
	for (int i = 2; i * i <= size; i++)
	{
		if (!f[i])
		{
			for (int j = i * i; j <= size; j += i)
			{
				f[j] = true;
			}
		}
	}

	for (int i = 1; i <= size; i++)
	{
		if (!f[i])
		{
			v.push_back(i);
			s.insert(i);
		}
	}
}
void primegenerate(int x)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s.find(x) != s.end())
		{
			cout << "not possible" << en;
			return;
		}
		if (s.find(x - v[i]) != s.end())
		{
			cout << 3 << " " << v[i] << " " <<  x - v[i] << en;
			return;
		}
	}
}
void solve()
{
	int x; cin >> x;
	pf();
	primegenerate(x - 3);
}

int main()
{

	io();
	optimize();
	tst
	{
		solve();
	}
}
*/



///For all integers x from 4 to 10^5, find any two primes such that their sum is x.
const int n = 1e6 + 9;
int spf[n];
map<int, ll>mp;

void sieve()
{
	for (int i = 2; i < n; i++)
	{
		spf[i] = i;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = i; j < n; j += i)
		{
			spf[j] = min(spf[j], i);
		}
	}
}

bool ok(int n)
{
	for (int i = 2; i < n ; i++)
	{
		if (spf[i] == i and spf[n - i] == n - i) return true;
	}
	return false;
}
void solve()
{
	sieve();
	for (int i = 1; i <= 100; i++)
	{
		if (ok(i)) cout << i << en;
	}
}
int main()
{

	io();
	optimize();
	//tst
	{
		solve();
	}
}


///digits count in a factorial of a number n.
//////////.....ans ---------- >log10(n!)

