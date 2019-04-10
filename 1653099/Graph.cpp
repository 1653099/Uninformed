#include "Graph.h"

QUEUE::QUEUE()
{
	front = NULL;
	rear = NULL;
}
QUEUE::~QUEUE()
{
	while (front != NULL)
	{
		NODE * cur = front;
		front = front->next;
		delete cur;
	}
	front = NULL;
	rear = NULL;
}
void QUEUE::enqueue(int &x)
{
	NODE *tmp = new NODE;
	tmp->val = x;
	if (front == NULL)
	{
		front = tmp;
		front->next = NULL;
		rear = front;
	}
	else
	{
		rear->next = tmp;
		rear = tmp;
		tmp->next = NULL;
	}
}
int QUEUE::dequeue()
{
	if (front == NULL) {
		cout << "Don't have list." << endl;
		return 0;
	}
	else
	{
		NODE * tmp = front;
		front = front->next;
		int value = tmp->val;
		delete tmp;
		return value;
	}
}
int QUEUE::countST()
{
	int count = 0;
	NODE * cur = front;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
STACK::STACK()
{
	front = NULL;
	rear = NULL;
}
STACK::~STACK()
{
	while (front != NULL)
	{
		NODE * cur = front;
		front = front->next;
		delete cur;
	}
	front = NULL;
	rear = NULL;
}
void STACK::push(int &x)
{
	NODE *tmp = new NODE;
	tmp->val = x;
	if (front == NULL)
	{
		front = tmp;
		front->next = NULL;
		rear = front;
	}
	else
	{
		tmp->next = front;
		front = tmp;
	}
}
int STACK::pop()
{
	if (front == NULL) {
		cout << "Don't have list." << endl;
		return 0;
	}
	else if (front->next == NULL) {
		NODE *tmp = front;
		int value = tmp->val;
		front = NULL;
		rear = NULL;
		delete tmp;
		return value;
	}
	else
	{
		NODE * cur = front;
		while (cur->next != rear)
			cur = cur->next;
		NODE  *tmp = cur->next;
		rear = cur;
		rear->next = NULL;
		int value = tmp->val;
		delete tmp;
		return value;
	}
}
int STACK::countST()
{
	int count = 0;
	NODE * cur = front;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void InputFile(int **&graph,int &n, int &source, int &dest, int &typeSearch)
{
	ifstream ifs;
	ifs.open("input.txt");
	if (!ifs.is_open()) {
		cout << "Open File is fail" << endl;
		return;
	}
	ifs >> n;
	ifs >> source;
	ifs >> dest;
	ifs >> typeSearch;
	graph = new int *[n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
		for (int j = 0; j < n; j++) {
			ifs >> graph[i][j];
		}
	}

}
void Output(int **graph, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j]<<" ";
		}
		cout << endl;
	}
}

void BFS(int **graph, int n, int source, int dest, vector <int>& result)
{
	int *path;
	path = new int[n];
	bool *visited = new bool[n];
	bool *visitedchild = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		visitedchild[i] = false;
	}
	QUEUE open;
	int curPoint;
	open.enqueue(source);
	visited[source] = true;
	while (open.countST() != 0) {
		do {
			if (open.countST() == 0)
				break;
			curPoint = open.dequeue();
		} while (visited[curPoint] == true);
		visited[curPoint] = true;
		if (curPoint == dest)
			break;
		for (int i = 0; i < n; i++) {
			if (graph[curPoint][i] == 1 && visited[i] == false) {
				if (visitedchild[i] == false)
				{
					path[i] = curPoint;
					open.enqueue(i);
					visitedchild[i] = true;
				}
			}
		}
	}
	if (curPoint != dest) {
		return;
	}
	int cur = dest;
	result.push_back(dest);
	while(cur != source){
		cur = path[cur];
		result.push_back(cur);
	}
}

void DFS(int ** graph, int n, int source, int dest, vector <int>& result)
{
	int *path;
	path = new int[n];
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	STACK open;
	int curPoint;
	open.push(source);
	visited[source] = true;
	while (open.countST() != 0) {
		do {
			if (open.countST() == 0)
				break;
			curPoint = open.pop();
		} while (visited[curPoint] == true);
		visited[curPoint] = true;
		if (curPoint == dest)
			break;
		for (int i = 0; i < n; i++) {
			if (graph[curPoint][i] == 1 && visited[i] == false) {
				path[i] = curPoint;
				open.push(i);
			}
		}
	}
	if (curPoint != dest) {
		return;
	}
	int cur = dest;
	result.push_back(dest);
	while (cur != source) {
		cur = path[cur];
		result.push_back(cur);
	}
}

void OutputFile(vector <int> result)
{
	ofstream ofs;
	ofs.open("output.txt");
	if (!ofs.is_open()) {
		cout << "Open File is fail";
		return;
	}
	if (result.size() == 0) {
		ofs << "No path is found!";
	}
	else {
		ofs << result.size() - 1 << endl;
		for (int i = result.size() - 1; i >= 0; i--)
			ofs << result[i] << " ";
	}
}
