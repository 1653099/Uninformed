#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class QUEUE
{
private:
	struct NODE
	{
		int val;
		NODE *next;
	};
	NODE *front;
	NODE *rear;
public:
	QUEUE();
	~QUEUE();
	void enqueue(int &x);
	int dequeue();
	int countST();
};
class STACK
{
private:
	struct NODE
	{
		int val;
		NODE *next;
	};
	NODE *front;
	NODE *rear;
public:
	STACK();
	~STACK();
	void push(int &x);
	int  pop();
	int countST();
};
void InputFile(int **&graph, int &n, int &source, int &dest, int &typeSearch);
void Output(int **graph, int n);
void BFS(int **graph, int n, int source, int dest, vector <int>& result);
void DFS(int **graph, int n, int source, int dest, vector <int>& result);
void OutputFile(vector <int> result);