/*
#include <iostream>
using namespace std;
const int Len = 5;

int arr[Len] = { 8,5,6,2,4 };

int main()
{
	for (size_t i = 1; i < Len; i++)
	{
		int temp = arr[i];
		for (size_t j = i; j >=0; j--)
		{
			if (temp < arr[j - 1])
			{
				arr[j] = arr[j - 1];
				continue;
			}
			arr[j] = temp;
			break;
		}
		for (size_t j = 0; j < Len; j++)
		{
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
}
*/
