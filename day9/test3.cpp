#include<iostream>
#include<vector>

using namespace std;
const double EPS = 1E-9;
int steps = 60;

struct pt{
	double x,y;
};

struct line{
	double a,b,c;
};

double dist(double x, double y, line &l ){
	return abs(x*l.a + y *l.b + l.c);
}

double radius (double x, double y, vector<line> & l ){
	int n = (int) l.size();
	double res = INF;
	for ( int i = 0 ; i < n ; ++i )
		res = min( res, dist (x,y,l[i]));
	return res;
}

double y_radisu( double x, vector<pt> & a, vector<line> & l){
kkj
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0):
	int m;
	cin >> n;
	vector<>;
	for ( int i = 0 ; i < n ; ++i ){
	}
	return 0;
}
