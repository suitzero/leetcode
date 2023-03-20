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
	int n, q;
	cin >> n >> q;
	vector<long long> a(n), b(n);
	for (int i = 0 ; i< n ; i++){
		cin >> a[i] >> b[i];
	}
	while (q--){
		int l, r;
		long long d;
		cin >> l >> r >> d;
		--l; --r;
		long long ans = (long long)9e18;
		for( int i = l; i <= r ; ++i ){
			ans = min(ans, a[i] * d + b[i] );
		}
		cout << ans << '\n';
	}
}
