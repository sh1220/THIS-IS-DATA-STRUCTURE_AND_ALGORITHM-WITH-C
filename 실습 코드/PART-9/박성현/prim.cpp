/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};


int main() {
	int N, M, sum = 0;
	cin >> N >> M;
	vector<vector<pair<int, int>>> g(N+1);
	vector<bool> visited(N + 1, false);
	int a, b,  c;
	for (size_t i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		// a, b : 노드, c: 가중치
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	


	int start;
	cout << "시작할 번호  : ";
	cin >> start;

	visited[start] = true;

	// <저장할 자료값, 컨테이너, 비교함수>
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (size_t i = 0; i < g[start].size(); i++)
	{
		pq.push(g[start][i]);
	}


	int index, w, visited_sum = 1;
	while (visited_sum < N)
	{
		
		index = pq.top().first;
		w = pq.top().second;
		pq.pop();

		if (visited[index]) continue;


		visited[index] = true;
		visited_sum++;

		sum += w;
		for (size_t i = 0; i < g[index].size(); i++)
		{
			if (!visited[g[index][i].first]) pq.push(g[index][i]);
		}

		


	}

	cout << "결과 : " << sum;

	

	


}
*/

	/* // 출력
	for (size_t i = 1; i <= N; i++)
	{
		cout << i << "\n";
		for (size_t j = 0; j < g[i].size(); j++)
		{
			cout << g[i][j].first << " " << g[i][j].second << "\n";

		}
	}
	*/