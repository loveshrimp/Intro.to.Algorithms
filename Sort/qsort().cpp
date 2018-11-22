#include <stdio.h>
void swap(char *a, char *b, size_t width)
{
	char temp;
	if(a != b)
	{
		while (width-- != 0)
		{
			*a++ = *b++;
		}
	}
}
void qsort(void *base, size_t nmemb,  size_t size, int compare(const void *a, const void *b))
{
	int i = 0, j = nmemb - 1;
	char val[size];
	swap(val, (char *)base, size);
	if (size > 1)
	{
		while (i < j)
		{
			for (; j > i; j--)
				if (compare((char *)base + j * size, val) < 0)
				{
					swap((char *)base + i * size, (char *)base + j * size, size);
					break;
				}
			for (; i < j; i++)
				if (compare((char *)base + i * size, val) > 0)
				{
					swap((char *)base + j * size, (char *)base + i * size, size);
					break;
				}
		}
		swap(((char *)base + i * size), val, size);
		qsort(base, i, size, compare);
		qsort(((char *)base + (i + 1)*size), size - 1 - i, size, compare);
	}
}

int main()
{

}