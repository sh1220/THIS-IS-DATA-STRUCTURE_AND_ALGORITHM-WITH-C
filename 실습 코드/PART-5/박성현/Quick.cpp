#include <iostream>
using namespace std;
const int Len = 7;

int arr[Len] = {5,3,8,9,2,4,7};
//¿ÞÂÊ ÇÇ¹þ ±âÁØ

void quick_sort(int start, int end)
{
	if (start == end) return;

	int pivot = start, low = start, high = end-1;

	if (arr[start] > arr[start + 1]) low = start + 1;

	while (low < high)
	{
		while (arr[high] > arr[pivot] && low < high)
		{
			high--;
		}
		while (arr[low] < arr[pivot] && low < high)
		{
			low++;
		}

		swap(arr[low], arr[high]);
		for (size_t j = 0; j < Len; j++)
		{
			cout << arr[j] << " ";
		}
		cout << "\n";
	}

	swap(arr[pivot], arr[low]);


	quick_sort(start, low);
	quick_sort(low + 1, end);

}


int main()
{
	quick_sort(0, Len);

	for (size_t j = 0; j < Len; j++)
	{
		cout << arr[j] << " ";
	}
}