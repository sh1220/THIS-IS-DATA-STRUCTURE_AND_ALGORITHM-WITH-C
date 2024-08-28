/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 인접 행렬 생성
	int row;
	cin >> row;
	vector<vector<int>> am(row+1, vector<int>(row + 1, 0));

	// 그래프 input
	int count, a, b;
	cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		cin >> a >> b;
		am[a][b] = 1;
		am[b][a] = 1;

	}



	for (size_t i = 1; i <= row; i++)
	{
		for (size_t j = 1; j <= row; j++)
		{
			cout <<  am[i][j] << " ";
		}
		cout << "\n";
	}


}
*/