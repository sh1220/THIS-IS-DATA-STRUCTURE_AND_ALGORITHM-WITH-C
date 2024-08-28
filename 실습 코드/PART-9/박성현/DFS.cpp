// https://www.acmicpc.net/problem/1260 
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class tag
{
public:
	int data;
	tag* next;
	tag();
	tag(int _data);
	void insert(int temp);
	void print();
};
tag::tag() {
	data = NULL;
	next = NULL;
}

tag::tag(int _data) {
	data = _data;
	next = NULL;
}


void tag::insert(int temp) {
	if (data == NULL) {
		data = temp;
		return;
	}

	// tag newTag(temp); // 스택에 생성됨
	tag* newTag;


	// 오름차순을 위해 첫번째 데이터와 input 크기 비교 -- > 오름차순 발생시,매번 O(N) 발생.
	// 물론 병합정렬을 직접 구현해서 해도 괜찮지만, sort를 이용하기 위해서는 vector를 배열로 만드는 방식이 유효.. 끄아ㅏㅏㅏㅏ
	// 연결리스트로 구현안해.. 이제부터 vector배열이다
	if (data < temp) {
		newTag = new tag(temp); // 힙에 생성
	}
	else {
		newTag = new tag(data); // 힙에 생성
		data = temp;
	}

	if (next == NULL) {
		next = newTag;
		return;
	}

	


	tag* current = next;
	tag* previous = next;

	// 마지막이거나 노드들 사이에 들어갈 경우를 찾음
	while (current->next != NULL && current->data < newTag->data)
	{
		previous = current;
		current = current->next;
	}

	// 사이에 들어갈 경우
	if (current->data > newTag->data) {
		previous->next = newTag;
		newTag->next = current;
		return;
	}


	// 마지막인경우
	if(current->next == NULL) current->next = newTag;

}

void tag::print() {
	if (data == NULL) {
		cout << "\n";
		return;
	}
	cout << data << " ";

	tag* current = next;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}

	cout << "\n";

}







vector<tag> graph;
vector<bool> visited_DFS;
vector<bool> visited_BFS;
queue<int> q;

void DFS(int k) {
	// 오히려 재귀함수가 불필요하게 성능저하를 일으킨다고 함..
	// 그냥 보기 좋게 반복문 써야겠다..
	if (visited_DFS[k] == true) return;

	cout << k << " ";
	visited_DFS[k] = true;

	if (graph[k].data == NULL) return;
	DFS(graph[k].data);

	if (graph[k].next == NULL) return;

	tag* current = graph[k].next;

	while (current->next != NULL)
	{
		DFS(current->data);
		current = current->next;
	}

	DFS(current->data);


}

void BFS(int k) {
	q.push(k);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (visited_BFS[temp] == true) continue;

		cout << temp << " ";
		visited_BFS[temp] = true;

		if (graph[temp].data == NULL) continue;

		if (visited_BFS[graph[temp].data] == false) q.push(graph[temp].data);

		if (graph[temp].next == NULL) continue;

		tag* current = graph[temp].next;

		while (current->next != NULL)
		{
			if (visited_BFS[current->data] == false) q.push(current->data);
			current = current->next;
		}
		if (visited_BFS[current->data] == false) q.push(current->data);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int row, M, V;
	cin >> row>> M >> V;
	graph = vector<tag>(row + 1);
	visited_DFS = vector<bool>(row + 1, false);
	visited_BFS = vector<bool>(row + 1, false);

	int a, b;
	for (size_t i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	DFS(V);
	cout << "\n";
	BFS(V);

}
*/



