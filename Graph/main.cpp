#include <iostream>
#include <vector>
using namespace std;
#include "Graph.h"
void main() {
	cout << "Select the Mode" << endl;
	cout << "1. show the example of Graph" << endl;
	cout << "2. Make a Graph" << endl;
	int Mode_num;
	cin >> Mode_num;

	switch (Mode_num) {
	case 1:
		show_ex_graph();
		break;
	case 2:
		make_graph_ing();
		break;
	}
}

