#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
			int sr = board.size()-1, sc=board[0].size()-1;
			vector<vector<int>> board_score(board.size());
			vector<vector<long long>> board_path(board.size());
			for( int i = board.size()-1 ; i >=0; --i ){
				board_score[i].resize(board[0].size());
				board_path[i].resize(board[0].size());
				int sum = 0;
				board_path[board.size()-1][board.size()-1]=1;
				for( int j = board[0].size()-1 ; j >=0  ; --j ){
					if( '0' <= board[i][j] && board[i][j] <= '9' || board[i][j] == 'E'){
						int num = 0;
						if( board[i][j] != 'E' ) num = board[i][j]-'0';

						if( i == board.size()-1 ){
							sum += num;
							board_score[i][j] = sum;
							board_path[i][j] = 1;
						}else{
							if(board[i+1][j] != 'X' && board_path[i+1][j] > 0 ){
								board_score[i][j] = board_score[i+1][j]+num;
								board_path[i][j]+=board_path[i+1][j];
							}
							if( j != board.size()-1 ){
								if(board[i][j+1] != 'X' && board_path[i][j+1] > 0 ){
									int a = board_score[i][j+1]+num;
									if(board_score[i][j]==a) board_path[i][j]+=board_path[i][j+1];
									if(board_score[i][j]<a){
										board_score[i][j]=a; 
										board_path[i][j]=board_path[i][j+1];

									}
								}
								if(board[i+1][j+1] != 'X'&& board_path[i+1][j+1] > 0 ){
									int a = board_score[i+1][j+1]+num;
									if(board_score[i][j]==a) board_path[i][j]+=board_path[i+1][j+1];
									if(board_score[i][j]<a){
										board_score[i][j]=a; 
										board_path[i][j]=board_path[i+1][j+1];
									}
								}
							}

							board_path[i][j]=board_path[i][j]%(long long)(1e9+7);
						}
					}
					else if( i == board.size()-1 && board[i][j] == 'X'){
						break;
					}
				}
			}

			/*
			static vector<vector<int>> dirs{{-1,0},{0,-1},{-1,-1}};       
			auto comp = []( vector<int> a, vector<int> b ) { return a[2] < b[2]; };
			priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> q(comp);
			q.push(vector<int>{sr,sc,0,1});
			while(!q.empty()){
				auto cur = q.top(); q.pop();
				int r=cur[0],c=cur[1],score=cur[2],paths=cur[3];
				for( auto d : dirs ){
					int nr = r+d[0], nc = c+d[1];
					if ( nr < board.size() && nr >= 0 &&
								nc < board[0].size() && nc >= 0 )
					{
						if ( '0' <= board[nr][nc] && board[nr][nc] <= '9' )
						{
							int cs = score+board[nr][nc]-'0';
							if( board_score[nr][nc] == cs ){
								board_path[nr][nc]+= 1;
							}else if( board_score[nr][nc] < cs ){
								board_score[nr][nc] = cs;
								board_path[nr][nc] = 1;
							}else{
								continue;
							}
							q.push(vector<int>{nr,nc,score+board[nr][nc]-'0',board_path[nr][nc]});
						}else if( 'E' == board[nr][nc]){
							if( board_score[nr][nc] == score ){
								board_path[nr][nc]+= 1;
							}else if( board_score[nr][nc] < score ){
								board_score[nr][nc] = score;
								board_path[nr][nc] = 1;
							}
						}
					}
				}
			}*/
			vector<int> res(2);
			res[0] = board_score[0][0];
			res[1] = (int)board_path[0][0];
			/*
			for( int i = 0 ; i < board_path.size() ; ++i )
			{
				for( int j = 0 ; j < board_path[0].size(); ++j )
					cout << board_path[i][j] << " ";
				cout << endl;
			}*/
			return res;
	}
};
int main()
{
	vector<string> i1{"E23","2X2","12S"};
	auto s = Solution();
	auto o1 = s.pathsWithMaxScore(i1);
	for( auto a : o1 ) cout << a << " ";
	cout << endl;

	vector<string> i2{"E11345","X452XX","3X43X4","422812","284522","13422S"};
	auto o2 = s.pathsWithMaxScore(i2);
	for( auto a : o2 ) cout << a << " ";
	cout << endl;

	vector<string> i3{"E4789338X943596124X2676X552X587877X456943458X29735","611684759486631913932337237231351921X2152919376427","4499519117827344997451XX34X46693XX7181343557483669","414951X685152X89829782685X4912581351X3216914721551","X387271851925X3629265X99195X5897581179XX369637813X","1X8X2682518937289551X98X7983XX34993116413343558825","X92X12119593186X675113X682143777XX8981619298251984","X671798198463X5314971262X9392393XXX544537813812728","81856146535454X3678775784456289257XX8221X2488XXX68","77X3592XX94844399282X2X6336122XX7X18244862821X26XX","28885X948512X3585X27824186222X73X9X56441X9X4689517","344X495X682875968X82X9877379XX386748175X6293X44159","1924352186149295919715X27X555626X17798524189528625","3435681879X49727366745492X648X5952772978787143263X","412933788234154913356X2X9X144818X21XX5629259785133","489644765X456XX44XX2X5387637879X662941398337817381","7617826679176XX173173537173164967296764519X3427693","7X69X5466277665871135253486758156766536X5436X16728","318152574426X696X18X833396113X31862234511611X89691","X147492241256344555237X94772X9X5136226469551942X29","X29846X49419853778154XX636X35XX5232391787617416258","8885851X996538X163323347235993741926591X72X1761X14","226X8136988863232963682217521777419144333838517835","3197757518X241117949451X423XX55861XX6161938551X752","49X149355329X617X51X21965452X962X42762X25968X73754","X1176483834957794897816132X5X942366794665183797399","48294674492176X1X663644X58X17729X4482638X92X482422","51X16X157889846864X1436338776687677X44895154219626","782XX82XX432848434721692X55564975938X2649681569663","26792517214X8863X9896XX64619817916123168945761X526","X7XX319393797X184679X421943743279X1486126364341595","11425763X68563511X2496983325426X151456X5X459542989","89872654932254X5525587692326476X65562X59X635129314","6X944371656471737X9673645X4145X821X942995885X86522","64XX328X8243XX3445X6412955X87X42355234X73223243421","944391299X158X962X9X259552884441434XX9349X5XX79855","98422711429356771336494176X56X2584376X2354X72X5416","7135X7X9X3X699929714X61664916968X1896X5X1985386642","22969X77414X2154167176388X3313X918X1558161XX413862","4X141958614412616921588565488847635X837996835937X6","X416X64649X955369739187781488XX77129X6966899351X74","9X2349175X345X7469265842X591X4748167996963X63X7211","3117349374592412365636726147X52469X8921X1888159627","254513X73629359514989286822X7X89391797X357546X9145","8882877128738295914941X56995X243888XX595873XX99217","X947591X382X19613453263544415821689719794546655278","51X4565271954965486X492693X731844471486X149X7166X5","731X1816268181645946X2123376981X13X834338226X28X36","6X72X3599546159X378191718821X746789239488712584143","5982153336X61729X66339596838X77751396645929982913S"};
	auto o3 = s.pathsWithMaxScore(i3);
	for( auto a : o3 ) cout << a << " ";
	cout << endl;
}
