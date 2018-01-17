#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

//Essentially BellmanFord with finding longest path in "k-length/edges"
//Codecon prob #4. Tried using BellmanFord to find K-th length longest weight
//But fails because at one point path goes to an dead end with the current Bellmanford Algorithm. Should use dynamic problem.
//Try 3 3 15 0 0 1 0 1 2 3 5 5 5 11 11 11

int infinity=numeric_limits<int>::max();	//assign max number as int to 'infinity'

class Edge{
	public:
	int dest;
	int weight;
};

class Graph{
	public:
	int V=0;
	int E=0;
	vector<vector<Edge>> adjList;		//adjacency 2D vector

	void addVert();				//simply push_back 1D vector into 2D vector
	void addEdge(int, int, int);
};


void Graph::addVert(){
	vector<Edge> newVertex;
	adjList.push_back(newVertex);
	++V;
}

void Graph::addEdge(int u, int v, int weight){
	Edge newEdge;
	newEdge.dest=v;
	newEdge.weight=weight;
	adjList[u].push_back(newEdge);
	++E;
}

int bellmanFord(Graph* graph, int s, int t, int pathLength, bool min=true){
	int abs=1;
	if(!min){
		abs*=-1;
	}
	int V=graph->V;
	int E=graph->E;
	int dist[V];
	int dist2[V];
	int parent[V];
	int parent2[V];

	//need dist2 and parent2 to only  update dist1 at the end of each loop
	for(int i=0; i!=V; ++i){
		dist[i]=infinity;
		dist2[i]=infinity;
		parent[i]=-1;
		parent2[i]=-1;
	}
	dist[s]=0;
	dist2[s]=0;

	for(int i=1;i!=pathLength+1;++i){
		//loop thru each vertex
		for(int j=0;j!=V;++j){		
			auto leng=(*graph).adjList[j].size();
			//each adj, essentially all edges
			for(int k=0;k!=leng;++k){
				int u=j;
				int v=graph->adjList[j][k].dest;
				int weight=(*graph).adjList[j][k].weight;
				weight*=abs;	//needed in case of finding longest path
				if(u==t)
					continue;	//skip if u is the target

				if(dist[u]!=infinity && dist[v]>(dist[u]+weight)){
					int u2=u;
					while(parent[u2]!=-1){
						if(parent[u2]==v){ //to avoid cycle
							break;
						}else{
							u2=parent[u2]; //recursive call
						}
					}
					if(parent[u2]==-1 && dist2[v]>dist[u]+weight){	//relaxation
						dist2[v]=dist[u]+weight;
						parent2[v]=u;
					}
				}
			}
		}
		for(int l=0;l!=V;++l){		//now update to avoid "over relaxation"
			if(dist2[l]<dist[l]){
				dist[l]=dist2[l];
				parent[l]=parent2[l];
			}

		}
		cout<<"Round "<<i<<":"<<endl;	//print dist and parent for each relax
		cout<<"Distance: ";
		for(auto &x:dist)
			cout<<x*abs<<" ";
		cout<<endl<<"Parents: ";
		for(auto &y:parent)
			cout<<y<<" ";
		cout<<endl;

	}
	return dist[t]*abs;		//v.d after k times of relaxations

}

int bellmanFordMax(Graph* graph, int s, int v, int pathLength){
	return bellmanFord(graph, s, v,  pathLength, false);
}

int main(){
	Graph graph;
	Graph* ptr=&graph;

	int numRow, numCol, pathLength, startX, startY, endX, endY;
	cin>>numRow>>numCol>>pathLength>>startX>>startY>>endX>>endY;
	int s=startX*numCol+startY;
	int v=endX*numCol+endY;
	int V=numRow*numCol;
	for(int i=0;i!=V;++i){
		graph.addVert();
	}
	int begin;

	for(int i=0;i!=numRow;++i){
		for(int j=0;j!=numCol;++j){
			int weight;
			cin>>weight;
			int k=i*numCol+j;	//convert x,y coord to decial representation of the vertext
			if(k==s){
				begin=weight;
			}
				
			if(j==0){
				graph.addEdge(k+1,k,weight);
			}else if(j==numCol-1){
				graph.addEdge(k-1,k,weight);
			}else{
				graph.addEdge(k+1,k,weight);
				graph.addEdge(k-1,k,weight);
			}
			if(i==0){
				graph.addEdge(k+numCol,k,weight);
			}else if(i==numRow-1){
				graph.addEdge(k-numCol,k,weight);
			}else{
				graph.addEdge(k+numCol,k,weight);
				graph.addEdge(k-numCol,k,weight);
			}
		}
	}
	cout<<endl<<"max candy is "<<bellmanFordMax(ptr, s,v, pathLength)+begin;
}	
