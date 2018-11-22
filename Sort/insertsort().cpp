#include <stdio.h>

int * insert_sort(int *p,int n)
{
	int i,j,key;
	for (i = 1; i < n; i++)
	{
		key = p[i];
		j = i - 1;
		while ((j >= 0) && (key < p[j]))
		{
			p[j + 1] = p[j];
			j--;
		}
		p[j+1] = key;
	}
	return p;
}


int main()
{
	int list[] = { 10,1,3,4,6,9,5,7 };
	int i;
	insert_sort(list,8);
	for (i = 0; i < 8; i++)
		printf("%d", list[i]);
}
