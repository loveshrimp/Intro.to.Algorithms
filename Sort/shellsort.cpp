#include <stdio.h>
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void shell_sort(int arr[], int length)
{
	int step = length / 2, i,j ;
	while (step > 0)
	{
		i = 0;
		j = i + step;
		while (j < length)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
				i++;
				j++;
			}
			else
			{
				i++;
				j++;
			}
		}
		step /= 2;
	}
}

int main()
{
	int arr[10] = { 8,9,1,2,0,6,5,3,4,7 }, i;
	shell_sort(arr,10);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}