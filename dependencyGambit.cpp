#include<iostream>
#include<list>
#include<map>
#include<iterator>
#include<utility>
#include<string>
#include<vector>
using namespace std;

/* Dependency Gambit
 * Given a list of libs & their dependencies, and a target library we want to build, print out the perfect linkline according to the rules listed in the Output Specs
 * Input Specs:
 * 1. Target lib
 * 2. # of libs and dependencies
 * 3 ~ [lib-name] [Q] [dep-1] [dep-2]
 * (example):
 * lib-x
 * 3
 * lib-x 2 lib-a lib-b
 * lib-a 1 lib-b
 * lib-b 0
 * Output:
 * The linkline for the target library
 * (example):
 * lib-a lib-b lib-c lib-x
 * 
 */

//uses Depth first search & topological sort to create an array of libs 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;
    int DFSUtil(int v, bool visited[],vector<int>*);
    
    public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void DFS(int v,map<string,int>&);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

//util function
int Graph::DFSUtil(int v, bool visited[], vector<int>* level)
{
    int lev, maxLev=0;
    visited[v] = true;

   //check leaf? 
    if(adj[v].empty()){
	    (*level)[v]=0;
	    return 0;
    }

    list<int>::iterator it2;
    for (it2 = adj[v].begin(); it2 != adj[v].end(); ++it2){
        if (!visited[*it2]){
            lev=DFSUtil(*it2, visited, level);
	}else{
		lev=(*level)[*it2];
	}
	if(lev>maxLev)
		maxLev=lev;
    }
    (*level)[v]=maxLev+1;
    return (*level)[v];
}

//Depth-First search to sort topologically
void Graph::DFS(int v, map<string,int>& hash)
{
    int maxLevel;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    vector<int> *level=new vector<int>(V);
    for (int i = 0; i < V; i++){
        visited[i] = false;
	(*level)[i]=-1;
    }
 
    maxLevel=DFSUtil(v, visited, level);
    for(int k=0;k!=maxLevel+1;++k){
   	 for(int j=0;j!=V;++j){
		if((*level)[j]==k){
	    		map<string,int>::iterator it;
	    		for(it=begin(hash);it!=end(hash);it++){
		   		 if(j==it->second){
			   	 cout<<it->first<<" ";
		    		}
			}
		    }
	    }
    }
}

int main(){
	map <string, int> hash;
	string root;
	int counter=0;
	int num, adNum, u, v, adjNum;

	cin>>root>>num;
	Graph g(num);

	//takes in inputs
	for(int i=0;i!=num;++i){
		string key;
		cin>>key;
		if(hash.count(key)<=0){
			hash.emplace(make_pair(string(key),int(counter)));
			u=counter;
			++counter;
		}else{
			u=hash[key];
		}
		cin>>adjNum;
		for(int j=0;j!=adjNum;++j){
			string key2;
			cin>>key2;
			if(hash.count(key2)<=0){
				hash.emplace(make_pair(string(key2),int(counter)));
				v=counter;
				++counter;
			}else{
				v=hash[key];
			}
			g.addEdge(u,hash.find(key2)->second);
		}
	}
	//run topo sort and print
	g.DFS(hash[root],hash);
}
