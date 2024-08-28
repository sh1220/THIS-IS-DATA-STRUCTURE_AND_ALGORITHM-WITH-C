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

	// tag newTag(temp); // ���ÿ� ������
	tag* newTag;


	// ���������� ���� ù��° �����Ϳ� input ũ�� ��
	if (data < temp) {
		newTag = new tag(temp); // ���� ����
	}
	else {
		newTag = new tag(data); // ���� ����
		data = temp;
	}

	if (next == nullptr) {
		next = newTag;
		return;
	}




	tag* current = next;
	tag* previous = next;

	// �������̰ų� ���� ���̿� �� ��츦 ã��
	while (current->next != nullptr && current->data < newTag->data)
	{
		previous = current;
		current = current->next;
	}

	// ���̿� �� ���
	if (current->data > newTag->data) {
		previous->next = newTag;
		newTag->next = current;
		return;
	}


	// �������ΰ��
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

