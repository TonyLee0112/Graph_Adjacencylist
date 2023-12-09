#pragma once

struct Edge{
	int toward;
	int weight;

	//Constructor
	Edge(int destination_index, int w) {
		toward = destination_index; weight = w;
	}
} ;

class Graph {
private:
	int vertices; // the number of vertices
	vector<vector<Edge>> adjacencyList; // vector 의 크기를 사전에 말하지 않아도 돼서 편함.
	// vector<Edge> = {(t1,w1),(t2,w2),...,(tn,wn)} 
	// 즉 Edge 들이 vector 형태로 정의되었음. 하나의 vector<Edge> 는 하나의 vertex 에 연결됨.
	// adjacencyList[0] = {(t1,w1),(t2,w2),...,(tn,wn)} 0 번째 vertex에 연결된 edge 수 n개
	// adjacencyList[1] = {(t1,w1),(t2,w2),...,(tm,wm)} 1 번째 vertex에 연결된 edge 수 m개
	// adjacencyList[2] = {(t1,w1),(t2,w2),...,(tk,wk)} 2 번째 vertex에 연결된 edge 수 k개
public:
	// Constructor
	Graph(int num) { // 정점의 수를 입력파라미터로 받아 Graph 를 생성함.
		vertices = num;
		adjacencyList.resize(num); // vector 로 정의된 adjacency list 의 크기를 입력값으로 조정(설정)
	}

	// member function
	void addEdge(int v, int toward_w, int weight){ // v--weight--->w
		adjacencyList[v].emplace_back(Edge(toward_w, weight));
	}

	void print_Graph() {
		for (int i = 0; i < vertices; i++) {
			for (auto& edge : adjacencyList[i]) { // adjacencyList[i] 안의 원소들을 i처럼 활용하는데 그 껍데기가 edge 이며 타입은 auto& 즉 임의의 pointer type
				cout << i << "th vertex -- weight " << edge.weight << "--> " << edge.toward << "th vertex" << endl;
			}
		}
	}

	void dijkstraShortestPath(int start);
};

void make_graph_ing() {
	int num;
	cout << "type the number of vertices" << endl;
	cin >> num;
	Graph graph(num);
	for (int i = 0; i < num; i++) {
		cout << "for " << i << "th vertex, how many edges would you make?" << endl;
		int edges;
		cin >> edges;
		for (int j = 0; j < edges; j++) {
			cout << "Okay then, " << endl;
			cout << "Type destination vertex and weight" << endl;
			int des_vertex, w;
			cin >> des_vertex >> w;
			graph.addEdge(i, des_vertex, w);
		}
	}
	cout << "Here is the graph" << endl;
	graph.print_Graph();
}

void show_ex_graph() {
	Graph g(3);

	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 3);

	g.addEdge(1, 2, 4);

	g.addEdge(2, 0, 1);
	g.addEdge(2, 1, 5);

	cout << "Here is the graph" << endl;
	g.print_Graph();
}



