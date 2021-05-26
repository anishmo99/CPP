#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <list>

using namespace std;


map<int, list<int>> adjlist;

void addEdge(int x, int y){
	adjlist[x].push_back(y);
}

void displayEdge(){
	for(auto x : adjlist){
		cout << x.first << " --> ";
		for(auto y : x.second){
			cout << y << " ";
		}
		cout << endl;
	}
}

int main(){
	int nodes, edges;
	cin >> nodes >> edges;

	int x, y;

	for(int i = 0; i < edges; i++){
		cin >> x >> y;

		addEdge(x, y);
	}

	displayEdge();

	return 0;
}