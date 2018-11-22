#include <stdio.h>
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void Max_Heapify(int arr[],int arr_len,int i)
//最大堆
{
	int left, right,largest;
	left = i * 2;
	right = i * 2 + 1;
	if (left<arr_len && arr[left-1]>arr[i-1])
		largest = left;
	else
		largest = i;
	if (right<arr_len && arr[right-1]>arr[i-1])
		largest = right;
	if (largest != i)
	{
		swap(arr[i-1], arr[largest-1]);
		Max_Heapify(arr, arr_len, largest);
	}
}

void Build_Max_Heap(int arr[],int arr_len)
//建堆
{
	int i;
	for (i = arr_len / 2; i > 0; i--)
	{
		Max_Heapify(arr, arr_len, i);
	}
}

void Heapsort(int arr[], int arr_len)
//堆排序
{
	int i;
	Build_Max_Heap(arr, 10);
	for (i = arr_len-1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		Max_Heapify(arr, i, 1);
	}
}
int main()
{
	int arr[10] = { 8,9,1,2,0,6,5,3,4,7 }, i;
	Build_Max_Heap(arr, 10);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);


	return 0;
}
//问题：调用 Max_Heapify 时 left = i * 2 i==0;