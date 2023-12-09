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
	vector<vector<Edge>> adjacencyList; // vector �� ũ�⸦ ������ ������ �ʾƵ� �ż� ����.
	// vector<Edge> = {(t1,w1),(t2,w2),...,(tn,wn)} 
	// �� Edge ���� vector ���·� ���ǵǾ���. �ϳ��� vector<Edge> �� �ϳ��� vertex �� �����.
	// adjacencyList[0] = {(t1,w1),(t2,w2),...,(tn,wn)} 0 ��° vertex�� ����� edge �� n��
	// adjacencyList[1] = {(t1,w1),(t2,w2),...,(tm,wm)} 1 ��° vertex�� ����� edge �� m��
	// adjacencyList[2] = {(t1,w1),(t2,w2),...,(tk,wk)} 2 ��° vertex�� ����� edge �� k��
public:
	// Constructor
	Graph(int num) { // ������ ���� �Է��Ķ���ͷ� �޾� Graph �� ������.
		vertices = num;
		adjacencyList.resize(num); // vector �� ���ǵ� adjacency list �� ũ�⸦ �Է°����� ����(����)
	}

	// member function
	void addEdge(int v, int toward_w, int weight){ // v--weight--->w
		adjacencyList[v].emplace_back(Edge(toward_w, weight));
	}
	void print_Graph() {
		for (int i = 0; i < vertices; i++) {
			for (auto& edge : adjacencyList[i]) { // adjacencyList[i] ���� ���ҵ��� ió�� Ȱ���ϴµ� �� �����Ⱑ edge �̸� Ÿ���� auto& �� ������ pointer type
				cout << i << "th vertex -- weight " << edge.weight << "--> " << edge.toward << "th vertex" << endl;
			}
		}
	}
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