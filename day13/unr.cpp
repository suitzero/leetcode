#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
				unordered_map<int,vector<int>> graph_map;
				for( int i = 0 ; i < edges.size() ; ++i ){
					for( int j = 0 ; j < 2 ; ++j ) {
						bool a=false,b=true;
						if( j == 1 ){ a = !a; b= !b;}
						graph_map[edges[i][a]].push_back(edges[i][b]);
					}
				}


				queue<int> q;
				vector<int> node_graph(n,-1);
				vector<int> number_of_nodes_in_graphs;

				for( int i = 0 ; i < n ; ++i )
				{
					if( node_graph[i] != -1 ) continue;
					int graph_num = number_of_nodes_in_graphs.size();
					node_graph[i] = graph_num;
					q.push(i);
					int number_of_nodes = 1;
					while(!q.empty()){
							int node = q.front(); q.pop();
							if( graph_map.find(node) != graph_map.end()){
								vector<int> e = graph_map[node];
								for( int j = 0 ; j < e.size() ; ++j )
								{
									if(node_graph[e[j]]==-1){
										node_graph[e[j]] = graph_num;
										++number_of_nodes;
										q.push(e[j]);
									}
								}
							}
					}
					number_of_nodes_in_graphs.push_back(number_of_nodes);
				}



				auto nums = number_of_nodes_in_graphs;
				
				long long cnt_pairs=0;
				for( int i = 0 ; i < number_of_nodes_in_graphs.size() ; ++i )
				{
					for( int j = i+1 ; j < number_of_nodes_in_graphs.size() ; ++j )
					{
						cnt_pairs += nums[i]*nums[j];
					}
				}
				return cnt_pairs;
		}
};
int main()
{
	vector<vector<int>> i1{{0,2},{0,5},{2,4},{1,6},{5,4}};
	vector<vector<int>> i2{{0,1},{0,2},{1,2}};

	auto s = Solution();
	cout << s.countPairs(7,i1) << endl;
	cout << s.countPairs(100000,i2) << endl;
}

