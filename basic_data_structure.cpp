#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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

// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


/// Ctrl+H  replace
/// Ctrl+/  comment line
/// Ctrl+M  jump to matching brackets

////////////////////policy based data structure
/*
void solve()
{
	o_set<int> st;
	st.insert(1);
	st.insert(5);

	st.insert(4);

	st.insert(2);
	st.insert(6);
	for (auto &u : st) cout << u << " ";
	auto it = st.find_by_order(1);
	cout << *it << en;
	cout << st.order_of_key(5) << en;


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

*/



//././././././././././.s.e.g.m.e.n.t.-.t.r.e.e./././././././././././/././././././../././/.///

////////////////problem: subarray sum of range [l,r] in an array.1111111111111111111111111111111111111111111111



















///////////////////////////////segment_tree_lazy ---addition
/*
const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		// cout << node << " " << start << " " << end << en;
		tree[node] += (end - start + 1) * lazy[node]; // Apply the lazy value

		if (start != end) { // Not a leaf node
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = v[start];
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = tree[l] + tree[r];
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return 0;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return query(l, start, mid, i, j) + query(r, mid + 1, end, i , j);

}

void update_val(int node, int start, int end, int index, int x) {
	if (start > index or end < index) return;
	if (start == end and start == index) {
		tree[node] = x;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	update_val(l, start, mid, index, x);
	update_val(r, mid + 1, end, index, x);
	tree[node] = tree[l] + tree[r]; /////////////////changes
}

void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] += val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = 0;
	// coutv(v);
	segment_tree_lazy(1, 0, n - 1);
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r, val;
			cin >> l >> r >> val;
			update(1, 0, n - 1, l , r - 1, val);
			// coutv(v);
		}
		else {
			int ind;
			cin >> ind;
			cout << query(1, 0, n - 1, ind, ind) << en;

		}
	}


	// Query range [1, 3]
	//cout << "Sum of range [1, 3]: " << query(1, 0, n - 1, 0, 2) << en;

	// Add 10 to range [1, 3]
	//update(1, 0, n - 1, 0, 2, 10);
	// for (int i = 0; i <= 4 * n; i++) cout << lazy[i] << " " << tree[i] << en;
	// Query again
	//cout << "Sum of range [1, 3] after update: " << query(1, 0, n - 1, 0, 2) << en;
}

int main() {
	optimize();

	solve();
}
*/




///////////////////////////////segment_tree_lazy ---max
/*
const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		// cout << node << " " << start << " " << end << en;
		tree[node] =  max(tree[node] , lazy[node]); // Apply the lazy value

		if (start != end) { // Not a leaf node
			lazy[2 * node] = max(lazy[2 * node], lazy[node]);
			lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
		}
		lazy[node] = 0; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = v[start];
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = max(tree[l] , tree[r]);
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return 0;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return max(query(l, start, mid, i, j) , query(r, mid + 1, end, i , j));

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] = val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
}


void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = 0;
	// coutv(v);
	segment_tree_lazy(1, 0, n - 1);
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r, val;
			cin >> l >> r >> val;
			update(1, 0, n - 1, l , r - 1, val);
			// coutv(v);
		}
		else {
			int ind;
			cin >> ind;
			cout << query(1, 0, n - 1, ind, ind) << en;

		}
	}


}

int main() {
	optimize();
	io();
	solve();
}
*/


/////////////////////  segment tree --range value change
/*
const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != -1) {
		tree[node] = lazy[node];
		if (start != end) { // Not a leaf node
			lazy[2 * node] = lazy[node];
			lazy[2 * node + 1] = lazy[node];
		}
		lazy[node] = -1; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = -1;
	if (start == end) {
		tree[node] = v[start];
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	//tree[node] = tree[l] + tree[r];
}

ll query(int node, int start, int end, int idx) {
	push(node, start, end);
	if (start == end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	if (idx <= mid) {
		return query(2 * node, start, mid, idx);
	} else {
		return query(2 * node + 1, mid + 1, end, idx);
	}

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (end < l || start > r) return;
	if (l <= start && end <= r) { // Total overlap
		lazy[node] = val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	//tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = 0;
	// coutv(v);
	segment_tree_lazy(1, 0, n - 1);
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r, val;
			cin >> l >> r >> val;
			//cout << "update" << en;
			update(1, 0, n - 1, l , r - 1, val);
			// for (int i = 1; i < 4 * n; i++) cout << i << " " << tree[i] << en;
			// cout << en;
		}
		else {
			int ind;
			cin >> ind;
			//cout << "query" << en;
			cout << query(1, 0, n - 1, ind) << en;
			// for (int i = 1; i < 4 * n; i++) cout << i << " " << tree[i] << en;
			// cout << en;

		}
	}

}

int main() {
	optimize();

	solve();
}
*/


///////////////////Segement Tree Lazy Propagation//////////////////////
/*
const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		// cout << node << " " << start << " " << end << en;
		tree[node] += (end - start + 1) * lazy[node]; // Apply the lazy value

		if (start != end) { // Not a leaf node
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = v[start];
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = min(tree[l], tree[r]);
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return 10000000000;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return min(query(l, start, mid, i, j), query(r, mid + 1, end, i , j));

}

void update_val(int node, int start, int end, int index, int x) {
	if (start > index or end < index) return;
	if (start == end and start == index) {
		tree[node] = x;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	update_val(l, start, mid, index, x);
	update_val(r, mid + 1, end, index, x);
	tree[node] = min(tree[l], tree[r]); /////////////////changes
}

void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] += val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	cinv(v);

	segment_tree_lazy(1, 0, n - 1);
	//for (int i = 0; i < 4 * n; i++) cout << i << " " << tree[i] << en;
	//cout << en << en;

	// Initial segment tree sum of entire array
	// cout << "Initial Total Sum: " << tree[1] << en;
	for (int i = 0; i < q; i++) {
		int a, l, r; cin >> a >> l >> r;
		if (a == 1) {
			update_val(1, 0, n - 1, l, r);
			//for (int i = 0; i < 4 * n; i++) cout << i << " " << tree[i] << en;
		}
		if (a == 2) {
			cout << query(1, 0, n - 1, l, r - 1) << en;
		}
	}
	// // Query range [1, 3]
	// cout << "Sum of range [1, 3]: " << query(1, 0, n - 1, 0, 2) << en;

	// // Add 10 to range [1, 3]
	// update(1, 0, n - 1, 0, 2, 10);
	// // for (int i = 0; i <= 4 * n; i++) cout << lazy[i] << " " << tree[i] << en;
	// // Query again
	// cout << "Sum of range [1, 3] after update: " << query(1, 0, n - 1, 0, 2) << en;
}

int main() {
	optimize();
	io();
	solve();
}

*/
/*

const int N = 1e5 + 9;

vector<ll> v(N);
ll min_tree[4 * N];
int count_tree[4 * N];

void build(int node, int start, int end) {
	if (start == end) {
		min_tree[node] = v[start];
		count_tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);

	if (min_tree[2 * node] < min_tree[2 * node + 1]) {
		min_tree[node] = min_tree[2 * node];
		count_tree[node] = count_tree[2 * node];
	} else if (min_tree[2 * node + 1] < min_tree[2 * node]) {
		min_tree[node] = min_tree[2 * node + 1];
		count_tree[node] = count_tree[2 * node + 1];
	} else {
		min_tree[node] = min_tree[2 * node];
		count_tree[node] = count_tree[2 * node] + count_tree[2 * node + 1];
	}
}

pair<ll, int> query(int node, int start, int end, int l, int r) {
	if (start > r || end < l) {
		return {LLONG_MAX, 0};
	}
	if (start >= l && end <= r) {
		return {min_tree[node], count_tree[node]};
	}
	int mid = (start + end) / 2;
	pair<ll, int> left = query(2 * node, start, mid, l, r);
	pair<ll, int> right = query(2 * node + 1, mid + 1, end, l, r);

	if (left.first < right.first) {
		return left;
	} else if (right.first < left.first) {
		return right;
	} else {
		return {left.first, left.second + right.second};
	}
}

void update(int node, int start, int end, int idx, ll val) {
	if (start == end) {
		min_tree[node] = val;
		count_tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;


	if (idx <= mid) {
		update(2 * node, start, mid, idx, val);
	} else {
		update(2 * node + 1, mid + 1, end, idx, val);
	}
	if (min_tree[2 * node] < min_tree[2 * node + 1]) {
		min_tree[node] = min_tree[2 * node];
		count_tree[node] = count_tree[2 * node];
	} else if (min_tree[2 * node + 1] < min_tree[2 * node]) {
		min_tree[node] = min_tree[2 * node + 1];
		count_tree[node] = count_tree[2 * node + 1];
	} else {
		min_tree[node] = min_tree[2 * node];
		count_tree[node] = count_tree[2 * node] + count_tree[2 * node + 1];
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	build(1, 0, n - 1);
	// for (int i = 0; i < 4 * n; i++) cout << i << " " << min_tree[i] << " " << count_tree[i] << en << en;
	while (q--) {
		int a, l, r;
		cin >> a >> l >> r;
		if (a == 1) {
			update(1, 0, n - 1, l, r);
		} else {
			pair<ll, int> res = query(1, 0, n - 1, l, r - 1);
			cout << res.first << " " << res.second << endl;
		}
	}
}

int main() {
	optimize();
	io();
	solve();
	return 0;
}*/

/*



/////////////problem: maximum value of a subarray of range [l,r] in an array.
vector<int>ar(N);
vector<int>t(4 * N);
void segment_tree1(int node, int start, int end) {
	if (start == end) {
		t[node] = ar[start];
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	segment_tree1(l, start, mid);
	segment_tree1(r, mid + 1, end);
	t[node] = max(t[l] , t[r]);
	//cout << t[node]
}

int query1(int node, int start, int end, int i, int j, int mini) {
	if (end < i or start > j) return mini;
	if (start >= i and end <= j) return t[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	int maxi =  max(query1(l, start, mid, i, j, mini) , query1(r, mid + 1, end, i , j, mini));
	return maxi;
}

void update(int node, int start, int end, int index, int value) {
	if (end < index or start > index) return;
	if (start == end and start == index)
	{
		t[node] = value;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	update(l, start, mid, index, value);
	update(r, mid + 1, end, index, value);
	t[node] = max(t[l] , t[r]);
}

void solve1()
{
	int x; cin >> x;
	for (int i = 1; i <= x; i++) cin >> ar[i];
	int mini = *min_element(ar.begin() + 1, ar.begin() + x + 1);
	segment_tree1(1, 1, x);
	cout << query1(1, 1, x, 2, 4, mini) << en;
	cout << query1(1, 1, x, 1, 6, mini) << en;
	cout << query1(1, 1, x, 1, 3, mini) << en;
	update(1, 1, x, 3, 3);
	cout << query1(1, 1, x, 2, 4, mini) << en;
	cout << query1(1, 1, x, 1, 6, mini) << en;
	cout << query1(1, 1, x, 1, 3, mini) << en;
	update(1, 1, x, 4, 3);
}


/*
void solve12() {
	int x; cin >> x;
	vector<int>v(x);
	vector<int>mx(x);
	cinv(v);
	v.push_back(0);
	mx.push_back(0);
	int mxi = v[0];
	mx[0] = v[0];
	for (int i = 1; i < x; i++) {
		if (mxi < v[i]) {
			mx[i] = v[i];
			mxi = v[i];
		} else mx[i] = mxi;
	}
	// coutv(mx);
	ll sum = 0;
	vector<ll>ans(x), rsum(x + 1, 0);
	for (int i = x - 1; i >= 0; i--) rsum[i] += v[i] + rsum[i + 1];
	// coutv(rsum);
	for (int i = x; i >= 1; i--) {
		ans[i - 1] = rsum[i] + 1ll * mx[i - 1];
	}

	reverse(ans.begin(), ans.end());
	coutv(ans);
}
*/



////There is an array of n elements, initially filled with zeros. You need to write a data structure that processes two types of queries:
// add v to the segment from l to r−1, find the minimum on the segment from l to r−1
/*

const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		// cout << node << " " << start << " " << end << en;
		tree[node] += lazy[node]; // Apply the lazy value

		if (start != end) { // Not a leaf node
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = v[start];
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = min(tree[l] , tree[r]);
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return LLONG_MAX;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return min(query(l, start, mid, i, j) , query(r, mid + 1, end, i , j));

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] += val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = 0;
	segment_tree_lazy(1, 0, n - 1);
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r;
			ll val;
			cin >> l >> r >> val;
			update(1, 0, n - 1, l , r - 1, val);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 0, n - 1, l, r - 1) << en;

		}
	}
}

int main() {
	optimize();
	io();
	solve();
}
*/








// There is an array of n

// elements, initially filled with ones. You need to write a data structure that processes two types of queries:



// multiply all elements on the segment from l

// to r−1

// by number v

// ,

// find the sum on the segment from l

// to r−1

// .
/*
Both operations are performed modulo 10^9+7
const int  mod = 1e9 + 7;

const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != 1) {
		// cout << node << " " << start << " " << end << en;
		tree[node] = (tree[node]  * (lazy[node]) % mod);
		if (start != end) { // Not a leaf node
			lazy[2 * node] = ((lazy[2 * node] % mod) * (lazy[node] % mod) % mod);
			lazy[2 * node + 1] = ((lazy[2 * node + 1] % mod) * (lazy[node] % mod) % mod);
		}
		lazy[node] = 1; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 1;
	if (start == end) {
		tree[node] = 1;
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = (tree[l] + tree[r]) % mod;
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return 0;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return (query(l, start, mid, i, j) + query(r, mid + 1, end, i , j)) % mod;

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] = (lazy[node] * val) % mod;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = (tree[2 * node] + tree[2 * node + 1]) % mod;
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	segment_tree_lazy(1, 0, n - 1);
	// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
	// cout << en;
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r;
			ll val;
			cin >> l >> r >> val;
			//cout << "update" << en;
			update(1, 0, n - 1, l , r - 1, val);
			//for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			//cout << en;
		}
		else {
			int l, r; cin >> l >> r;
			//cout << "query" << en;
			cout << query(1, 0, n - 1, l, r - 1) << en;
			//for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			//cout << en;

		}
	}


	// Query range [1, 3]
	//cout << "Sum of range [1, 3]: " << query(1, 0, n - 1, 0, 2) << en;

	// Add 10 to range [1, 3]
	//update(1, 0, n - 1, 0, 2, 10);
	// for (int i = 0; i <= 4 * n; i++) cout << lazy[i] << " " << tree[i] << en;
	// Query again
	//cout << "Sum of range [1, 3] after update: " << query(1, 0, n - 1, 0, 2) << en;
}

int main() {
	optimize();
	io();
	solve();
}

*/


////////////////// lazy segment tree for range bitwise OR updates and range bitwise AND queries.
/*

const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		// cout << node << " " << start << " " << end << en;
		tree[node] |= lazy[node];
		if (start != end) { // Not a leaf node
			lazy[2 * node] |= lazy[node];
			lazy[2 * node + 1] |= lazy[node];
		}
		lazy[node] = 0; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = 0;
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = (tree[l] & tree[r]);
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return ((1ll << 32) - 1);
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return (query(l, start, mid, i, j) & query(r, mid + 1, end, i , j));

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] |=  val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2 * node] & tree[2 * node + 1];
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	segment_tree_lazy(1, 0, n - 1);
	// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
	// cout << en;
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r;
			ll val;
			cin >> l >> r >> val;
			//cout << "update" << en;
			update(1, 0, n - 1, l , r - 1, val);
			// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			// cout << en;
		}
		else {
			int l, r; cin >> l >> r;
			//cout << "query" << en;
			cout << query(1, 0, n - 1, l, r - 1) << en ;
			// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			// cout << en;


		}
	}


	// Query range [1, 3]
	//cout << "Sum of range [1, 3]: " << query(1, 0, n - 1, 0, 2) << en;

	// Add 10 to range [1, 3]
	//update(1, 0, n - 1, 0, 2, 10);
	// for (int i = 0; i <= 4 * n; i++) cout << lazy[i] << " " << tree[i] << en;
	// Query again
	//cout << "Sum of range [1, 3] after update: " << query(1, 0, n - 1, 0, 2) << en;
}

int main() {
	optimize();
	io();
	solve();
}*/


// segment tree implementation that supports range assignment and range sum queries.
/*

const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];

void push(int node, int start, int end) {
	if (lazy[node] != -1) {
		// cout << node << " " << start << " " << end << en;
		tree[node] = (end - start + 1) * lazy[node]; // Apply the lazy value

		if (start != end) { // Not a leaf node
			lazy[2 * node] = lazy[node];
			lazy[2 * node + 1] = lazy[node];
		}
		lazy[node] = -1; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = -1;
	if (start == end) {
		tree[node] = 0;
		//cout << start << " " << end <<  en;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = (tree[l] + tree[r]);
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return 0;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return (query(l, start, mid, i, j) + query(r, mid + 1, end, i , j));

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] = val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = (tree[2 * node] + tree[2 * node + 1]);
}

void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	segment_tree_lazy(1, 0, n - 1);
	// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
	// cout << en;
	// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << mini[i] << " " << lazy_mini[i] << en;
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r;
			ll val;
			cin >> l >> r >> val;
			update(1, 0, n - 1, l , r - 1, val);
			// coutv(v);
			// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			// cout << en;
			// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << mini[i] << " " << lazy_mini[i] << en;
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 0, n - 1, l, r - 1) << en;

		}
	}
}

int main() {
	optimize();
	io();
	solve();
}*/



/*
const int N = 1e5 + 9;
vector<ll> v(N);
ll tree[4 * N], lazy[4 * N];
ll bitCount[4 * N][31];

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		// cout << node << " " << start << " " << end << en;
		for (int i = 0; i < 31; i++) {
			if ((lazy[node] >> i) & 1) {
				bitCount[node][i] = (end - start + 1) - bitCount[node][i];
			}

		}

		if (start != end) { // Not a leaf node
			lazy[2 * node] ^= lazy[node];
			lazy[2 * node + 1] ^= lazy[node];
		}
		lazy[node] = 0; // Reset
	}
}

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		for (int i = 0; i < 31; i++) {
			bitCount[node][i] = (v[start] >> i) & 1;
		}

		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	for (int i = 0; i < 31; i++) {
		bitCount[node][i] = bitCount[2 * node][i] + bitCount[2 * node + 1][i];
	}
}

ll query(int node, int start, int end, int i, int j) {
	push(node, start, end);
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return 0;
	if (start >= i and end <= j) {
		for (int i = 0; i < 31; i++) {
			ll sum = 0;
			for (int k = 0; k < 31; k++) {
				sum += (1LL << k) * bitCount[node][k];
			}
			return sum;
		}
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return (query(l, start, mid, i, j) + query(r, mid + 1, end, i , j));

}


void update(int node, int start, int end, int l, int r, ll val) {
	push(node, start, end);
	if (r < start || end < l) return; // No overlap
	if (l <= start && end <= r) { // Total overlap
		lazy[node] ^= val;
		//cout << lazy[node] << en;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	for (int i = 0; i < 31; i++) {
		bitCount[node][i] = bitCount[2 * node][i] + bitCount[2 * node + 1][i];
	}
}

void solve() {
	int n, q;
	cin >> n;
	v.resize(n);
	cinv(v);
	cin >> q;
	segment_tree_lazy(1, 0, n - 1);
	// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
	// cout << en;
	// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << mini[i] << " " << lazy_mini[i] << en;
	while (q--) {
		int a; cin >> a;

		if (a == 2) {
			int l, r;
			ll val;
			cin >> l >> r >> val;
			update(1, 0, n - 1, l - 1 , r - 1, val);
			// coutv(v);
			// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			// cout << en;
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 0, n - 1, l - 1, r - 1) << en;
			// for (int i = 1; i <= 4 * n ; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
			// cout << en;

		}
	}
}

int main() {
	optimize();
	io();
	solve();
}*/


/////https://codeforces.com/contest/483/problem/D
/*
const int N = 1e5 + 9;
ll tree[4 * N], lazy[4 * N];
vector<int>v;

void segment_tree_lazy(int node, int start, int end) {
	lazy[node] = -1;
	if (start == end) {
		tree[node] = v[start];
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	//cout << start << " " << end <<  en;
	segment_tree_lazy(l, start, mid);
	segment_tree_lazy(r, mid + 1, end);
	tree[node] = (tree[l] & tree[r]);
}

ll query(int node, int start, int end, int i, int j) {
	// cout << node << " " << start << " " << end << " " << i << " " << j << en;
	if (start > j or end < i) return (1ll << 31) - 1;
	if (start >= i and end <= j) return tree[node];
	int l = 2 * node, r = 2 * node + 1;
	int mid = (start + end) / 2;
	return (query(l, start, mid, i, j) & query(r, mid + 1, end, i , j));

}



void solve() {
	int n, q;
	cin >> n >> q;
	v.resize(n);
	vector<int>l(q), r(q), q1(q);
	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		l[i] = a;
		r[i] = b;
		q1[i] = c;
	}

	for (int i = 0; i < 31; i++) {
		vector<int>pre(n, 0);
		for (int j = 0; j < q; j++) {
			if ((q1[j] >> i) & 1) {
				pre[l[j] - 1]++;
				if (r[j] < n) pre[r[j]]--;
			}
		} int sum = 0;
		// for (int j = 0; j < n; j++) {
		// 	cout << pre[j] << en;
		// } cout << en;
		for (int j = 0; j < n; j++) {
			sum += pre[j];
			if (sum > 0) v[j] |= (1 << i);
		}
	}
	segment_tree_lazy(1, 0, n - 1);
	for (int i = 0; i < q; i++) {
		if (q1[i] != query(1, 0, n - 1, l[i] - 1, r[i] - 1)) {
			no;
			return;
		}
	} yes;
	coutv(v);


}

int main() {
	optimize();
	io();
	solve();
}
*/



////////////template segment_treeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
/*
const int n = 1e5 + 9;
vector<ll> v;
ll tree[4 * n], lazy[4 * n];



void push(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		} lazy[node] = 0;

	}
}

void calc(int node, int l, int r) {
	tree[node] = tree[l] + tree[r];
}

void segment_tree(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = v[start];
		return;
	}
	int mid = (start + end) / 2;
	int l = 2 * node, r = 2 * node + 1;
	segment_tree(l, start, mid);
	segment_tree(r, mid + 1, end);
	calc(node, l, r);
}


void update(int node, int start, int end, int l , int r, ll val) {
	push(node, start, end);
	if (l <= start and r >= end) {
		lazy[node] = val;
		push(node, start, end);
		return;
	}
	if (r < start or end < l) return;
	int mid = (start + end) / 2;
	int l1 = 2 * node, r1 = 2 * node + 1;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	calc(node, l1, r1);
}

ll query(int node, int start, int end, int l, int r) {
	push(node, start, end);
	if (l <= start and r >= end) return tree[node];
	if (r < start or end < l) return 0;
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}


void solve()
{
	int x; cin >> x;
	v.resize(x);
	for (int i = 0; i < x; i++) cin >> v[i];
	segment_tree(1, 0, x - 1);
	//for (int i = 0; i < 4 * x; i++) cout << i << " " << tree[i] << en;
	update(1, 0, x - 1, 0, 2, 4);
	//for (int i = 0; i < 4 * x; i++) cout << i << " " << tree[i] << " " << lazy[i] << en;
	cout << query(1, 0, x - 1, 0, 4) << en;



}

int main()
{

	io();
	optimize();
	{
		solve();
	}
}*/


////////////////num of inversion
/*
const int N = 2e5 + 7;

ll tree[4 * N], lazy[4 * N]; // Segment tree
ll arr[N];
void push(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		} lazy[node] = 0;

	}
}

void calc(int node, int l, int r) {
	tree[node] = tree[l] + tree[r];
}

void segment_tree(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = 0;
		return;
	}
	int mid = (start + end) / 2;
	int l = 2 * node, r = 2 * node + 1;
	segment_tree(l, start, mid);
	segment_tree(r, mid + 1, end);
	calc(node, l, r);
}


void update(int node, int start, int end, int l , int r, ll val) {
	push(node, start, end);
	if (l <= start and r >= end) {
		lazy[node] = val;
		push(node, start, end);
		return;
	}
	if (r < start or end < l) return;
	int mid = (start + end) / 2;
	int l1 = 2 * node, r1 = 2 * node + 1;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	calc(node, l1, r1);
}

ll query(int node, int start, int end, int l, int r) {
	push(node, start, end);
	if (l <= start and r >= end) return tree[node];
	if (r < start or end < l) return 0;
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}




ll count_inversions(const string &s) {
	segment_tree(1, 1, 26);  // Reinitialize segment tree
	ll inv = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		int val = s[i] - 'a' + 1;
		inv += query(1, 1, 26, 1, val - 1);
		update(1, 1, 26, val, val, 1);
	}
	return inv;
}

void solve() {
	int n; cin >> n;
	string s;
	cin >> s;

	ll normal_inv = count_inversions(s);

	reverse(s.begin(), s.end());

	ll reversed_inv = count_inversions(s);

	cout << "Original Inversion Count: " << normal_inv << '\n';
	cout << "Reversed Inversion Count: " << reversed_inv << '\n';

}

int main()
{

	io();
	optimize();
	//tst
	{
		solve();
	}
}*/




const int N = 2e5 + 7;

ll tree[4 * N], lazy[4 * N]; // Segment tree
ll arr[N];
void push(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		} lazy[node] = 0;

	}
}

void calc(int node, int l, int r) {
	tree[node] = tree[l] + tree[r];
}

void segment_tree(int node, int start, int end) {
	lazy[node] = 0;
	if (start == end) {
		tree[node] = 0;
		return;
	}
	int mid = (start + end) / 2;
	int l = 2 * node, r = 2 * node + 1;
	segment_tree(l, start, mid);
	segment_tree(r, mid + 1, end);
	calc(node, l, r);
}


void update(int node, int start, int end, int l , int r, ll val) {
	push(node, start, end);
	if (l <= start and r >= end) {
		lazy[node] = val;
		push(node, start, end);
		return;
	}
	if (r < start or end < l) return;
	int mid = (start + end) / 2;
	int l1 = 2 * node, r1 = 2 * node + 1;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	calc(node, l1, r1);
}

ll query(int node, int start, int end, int l, int r) {
	push(node, start, end);
	if (l <= start and r >= end) return tree[node];
	if (r < start or end < l) return 0;
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}





void solve() {
	int n; cin >> n;
	std::vector<int> v(n);
	cinv(v);
	ll inv = 0;
	for (int i =  n - 1; i >= 0; i--) {
		inv += query(1, 1, 26, 1, v[i] - 1);
		update(1, 1, 26, v[i], v[i], 1);
	} cout << max(0ll, inv - 2) << en;

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