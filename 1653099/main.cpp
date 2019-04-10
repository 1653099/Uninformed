#include "Graph.h"

void main()
{
	vector <int> result;
	int **graph;
	int n, source,dest,typeSearch;
	int countcost = 0;
	InputFile(graph, n, source, dest, typeSearch);
	//Output(graph, n);
	if (typeSearch == 0) {
		BFS(graph, n, source, dest, result);
		if (result.size() ==0) {
			cout << "No path is found!" << endl;
		}
		else {
			cout << result.size() - 1 << endl;
			for (int i= result.size()-1; i>=0; i--)
				cout << result[i] << " ";
		}
		cout << endl;
		OutputFile(result);
		cout << "Output file is done!" << endl;
	}
	else if (typeSearch == 1) {
		DFS(graph, n, source, dest, result);
		if (result.size() == 0) {
			cout << "No path is found!" << endl;
		}
		else {
			cout << result.size() - 1 << endl;
			for (int i = result.size() - 1; i >= 0; i--)
				cout << result[i] << " ";
		}
		cout << endl;
		OutputFile(result);
		cout << "Output file is done!" << endl;
	}
	system("Pause");
}