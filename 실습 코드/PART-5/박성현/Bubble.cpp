/*
#include <iostream>
using namespace std;
const int Len = 5;

int arr[Len] = {7,4,5,1,3};

int main()
{
	for (size_t j = 0; j < Len; j++)
	{
		cout << arr[j] << " ";
	}
	cout << "\n";


	for (size_t i = Len-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
		for (size_t j = 0; j < Len; j++)
		{
			cout << arr[j] << " ";
		}
		cout << "\n";
	}

}
*/

