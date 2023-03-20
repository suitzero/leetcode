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
	int tt;
	cin >> t;
	while(tt--){
		int n,q;
		cin >> n >> q;
		vector<long long> a(n);
		for ( int i = 0 ; i < n ; i++ ) {
			cin >> a[i];
		}
		while (q--){
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			--l1; --r1; -l2; --r2;
			int cnt = (r1 - l1 + 1) + (r2 - l2 + 1);
			long long low = (long long) -1e10;
			long long high = (long long) 1e10;
			while ( low < high ) {
				long long mid = (low+high) >> 1;
				cur += (int) (upper_bound(a.begin() + l1, a.begin() + r1+ 1, mid) - (a.begin()+l1));
				cur += (int) (upper_bound(a.begin() + l1, a.begin() + r1+ 1, mid) - (a.begin()+l2));
				if ( 2* cur >= cnt ){
					high = mid;
				}else{
					low = mid+ 1;
				}
			}
			if ( cnt %2 == 0 ) {
				int cur = 0;
				auto it1 = (int) (upper_bound(a.begin() + l1, a.begin()+r1+1, low);
				auto it2 = (int) (upper_bound(a.begin() + l2, a.begin()+r2+1 , low);
				cur += (it1 - l1);
				cur += (it2 - l2);
				long long nxt = (long long) 9e18;
				if( it1 <= r1) {
					nxt = min(nxt, a[it1]);
				}
				if( it2 <= r2){
					nxt = min(nxt,a[it2]);
				}
				cout << fixed << setprecision(1) << (long double) 0.5 * ( long double)k
			}
		}
	}
	return 0;
}
