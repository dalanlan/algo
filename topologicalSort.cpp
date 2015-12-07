// Depth First Traversal 
// Use a boolean visit array

class Graph {
	int V; 
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);

	public:
		Graph(int v);
		void addEdge(int v, int w);
		void DFS(int v);
};

Graph::Graph(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited) {
	visited[v] = true;
	cout<< v <<" ";
	for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++) {
		if(! visited[*i]) {
			DFSUtil(*i, visited);
		}
	}
}

void Graph::DFS(int v) {
	bool *visited = new bool[v];

	for(int i=0;i<v;i++) {
		visited[i] = false;
	}
	DFSUtil(v, visited);
}



// Topological sorting
// DAG: Directed Acyclic Graph(DAG)
/*
The first vertex in topological sorting is 
always a vertex with in-degree as 0
*/


class Graph {
	int V; 
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &stack);

	public:
		Graph(int v);
		void addEdge(int v, int w);
		void topologicalSort();

};

void Graph::Graph(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &stack) {
	visited[v] = true;

	for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++) {
		if(!visited[*i]) {
			topologicalSortUtil(*i, visited, stack);
		}
	}
	stack.push(v);
}

void Graph::topologicalSort() {
	stack<int> Stack;
	bool *visited = new bool[v];

	for(int i = 0; i < v; i++) {
		visited[i] = false;
	}

	for(int i = 0; i < v; i++) {
		if (!visited[i]) {
			topologicalSort(i, visited, Stack);
		}
	}
	while(!Stack.empty()) {
		cout<< Stack.()<<" ";
		Stack.pop();
	}
}

