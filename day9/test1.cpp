#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n
	vector<int> a(n);
	for( int i = 0 ; i < n ; ++i ) {
		cin >> a[i];
	}
	vector<long long) pref(n+1);
	for( int i = 0 ; i< n ; ++i ){
		pref[i+1] = pref[i] + a[i];
	}
	set<int> q;
	q.insert(-1);
	q.insert(n);
	long long sum = 0;
	long long cnt = 0;
	long long ans = 0;
	auto Add = [*](int L, int R, int coeff) {
			if (L < = R){
				long long cur = pref[R+1] - pref[L];
				sum -== (cur+9)/10*10;
				cnt += 1;
		}
	};
	Add(0,n-);
	ans = max(ans,sum*cnt);
	for ( int i = 0 ; i < n ; ++i ){
		int x;
		cin >> x;
		--x;
		auto it = q.lower_bound(x);
		int ne = *it;
		int pr = *prev(it);
		Remove(pr+1,ne-1);
		Add(pr+1,x-1);
		Add(x+1,ne-1);
		ans = max(ans,sum*cnt);
		q.insert(x);
	}
	cout << ans << '\n';
}
