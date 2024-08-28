/*
#include <iostream>
#include <vector>
using namespace std;


class tag
{
public:
	int data;
	tag* next;
	tag();
	tag(int _data);
	void insert( int temp);
	void print();
};
tag::tag() {
	data = NULL;
	next = nullptr;
}

tag::tag(int _data) {
	data = _data;
	next = nullptr;
}


void tag::insert(int temp) {
	if (data == NULL) {
		data = temp;
		return;
	}

	// tag newTag(temp); // 스택에 생성됨
	tag* newTag;


	// 오름차순을 위해 첫번째 데이터와 input 크기 비교
	if (data < temp) {
		newTag = new tag(temp); // 힙에 생성
	}
	else {
		newTag = new tag(data); // 힙에 생성
		data = temp;
	}

	if (next == nullptr) {
		next = newTag;
		return;
	}




	tag* current = next;
	tag* previous = next;

	// 마지막이거나 노드들 사이에 들어갈 경우를 찾음
	while (current->next != nullptr && current->data < newTag->data)
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
	if (current->next == NULL) current->next = newTag;

}

void tag::print() {
	if (data == NULL) {
		cout << "\n";
		return;
	}
	cout << data << " ";

	tag* current = next;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}

	cout << "\n";

}

vector<tag> graph;
vector<bool> visited;

int main() {
	int row, M, V;
	cin >> row >> M >> V;
	graph = vector<tag>(row + 1);
	visited = vector<bool>(row + 1, false);

	int a, b;
	for (size_t i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	for (size_t i = 1; i <= row; i++)
	{
		cout << i << ": ";
		graph[i].print();
	}



}

*/

