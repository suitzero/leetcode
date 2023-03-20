
const int N = 52;

bool was[N][N][N][N][32];

int main(){
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> s(h);
	for ( int i = 0 ; i < h ; i++ ){
		cin >> s[i];
	}
	vector<array<int, 6>> que;
	for ( int i = 0 ; i < h ; ++i ){
		for ( int j = 0 ; j < w ; ++j ) {
			if ( s[i][j] == '0' ) {
				que.push_back((i,j,0,0,0,0});
				was[i][j][0+M][0+M][0] = true;
			}
		}
	}
	for ( int b = 0 ; b < (int) que.size() ; ++b ){
		if(s[que[0]][que[1]] == (char) ('1'+k) &&que[2] == 0 && que[3] == 0 
	}
	return 0;
}
