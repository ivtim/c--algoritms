#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <initializer_list>

using namespace std;

struct vertex {
	int val;
	vertex* next;
	vertex() = default;
	vertex(int m_val, vertex* m_next) : val(m_val), next(m_next) {};
};

class graph {
public:
	int vertex_count;
	vertex** vertices;

	graph() {
		this->vertices = new vertex * [100];
		this->vertex_count = 0;
	}

	graph(initializer_list<int> args) {
		this->vertices = new vertex * [100];
		this->vertex_count = 1;

		vertex* old = new vertex;
		for (auto it = args.begin(); it != args.end(); ++it)
		{
			vertex* temp = new vertex();
			temp->val = *it;
			if (it == args.begin()) {
				temp->next = nullptr;
				this->vertices[vertex_count - 1] = temp;
			}
			else
				old->next = temp;
			old = temp;
		}
	}

	void insert(int* rebra, int size) {
		this->vertex_count++;

		vertex* old = new vertex;
		for (int i = 0; i < size; i++)
		{
			vertex* temp = new vertex();
			temp->val = rebra[i];
			if (i == 0) {
				temp->next = nullptr;
				this->vertices[vertex_count] = temp;
			}
			else
				old->next = temp;
			old = temp;
		}
	}

	void insert(vector<int> rebres) {
		vertex* old = new vertex;
		for (int i = 0; i < rebres.size(); i++)
		{
			vertex* temp = new vertex();
			temp->val = rebres[i];
			if (i == 0) {
				temp->next = nullptr;
				this->vertices[vertex_count] = temp;
			}
			else
				old->next = temp;
			old = temp;
		}
		this->vertex_count++;
	}

	void print() {
		for (int i = 0; i < this->vertex_count; i++)
		{
			printf("%d:", i);
			vertex* temp = this->vertices[i];
			while (temp != nullptr) {
				printf(" %d", temp->val);
				temp = temp->next;
			}
			printf("\n");
		}
	}

	void dfs(int ver_number) {
		vector<bool> visited;
		for (int i = 0; i < this->vertex_count; i++)
		{
			visited.push_back(false);
		}

		dfs_util(ver_number, visited);
	}

	void bfs(int ver_number) {
		queue<int> que;
		que.push(ver_number);

		vector<bool> visited;
		for (int i = 0; i < this->vertex_count; i++)
		{
			visited.push_back(false);
		}

		bfs_util(que, visited);
	}

private:
	void dfs_util(int now, vector<bool>& visited) {
		visited[now] = true;

		cout << now << endl;

		vertex* temp = this->vertices[now];
		while (temp != nullptr) {
			if (!visited[temp->val])
				dfs_util(temp->val, visited);
			temp = temp->next;
		}
	}

	void bfs_util(queue<int>& que, vector<bool>& visited) {
		visited[que.front()] = true;
		vertex* temp = this->vertices[que.front()];
		cout << que.front() << endl;
		que.pop();
		while (temp != nullptr) {
			if (!visited[temp->val])
				que.push(temp->val);
			temp = temp->next;
		}

		if (!que.empty() && !visited[que.front()])
			bfs_util(que, visited);
	}
};
