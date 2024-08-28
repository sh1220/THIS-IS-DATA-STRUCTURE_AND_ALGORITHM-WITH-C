#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;
vector<int> tree_size;

int find(int index)
{
	if (parent[index] == index) {
		return index;
	}
	// find �Ҷ����� ����
	parent[index] = find(parent[index]);
	return parent[index];
}


void kruskal_union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (tree_size[a] > tree_size[b]) {
		parent[b] = a;
		tree_size[a] += tree_size[b];
	}
	else {
		parent[a] = b;
		tree_size[b] += tree_size[a];
	}
}

int main() {
	int N, M, sum = 0, visted_sum = 0;
	cin >> N >> M;
	//pq <����ġ, <���, ���>>
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	vector<bool> visited(N + 1, false);

	parent = vector<int>(N + 1);
	tree_size = vector<int>(N + 1, 1);

	// �θ� �ʱ�ȭ: �� ���� �ڱ� �ڽ��� �θ�� ����
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int a, b, w;
	for (size_t i = 0; i < M; i++)
	{
		cin >> a >> b >> w;
		// a, b : ���, w: ����ġ
		pq.push(make_pair(w, make_pair(a, b)));
	}


	for (size_t i = 0; i < M; i++)
	{
		w = pq.top().first;
		a = pq.top().second.first;
		b = pq.top().second.second;
		pq.pop();
		if (find(a) != find(b)) {
			kruskal_union(a, b);
			sum += w;
		}
	}
	cout << "��� : " << sum;

	
	
	

}