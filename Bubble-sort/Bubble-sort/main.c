#include <stdio.h>
#include <assert.h>
int my_cmp_char(const void *p1, const void *p2)
{
	assert(p1);
	assert(p2);
	return *(char *)p1 - *(char *)p2;
}
int my_cmp_int(const void *p1, const void *p2)
{
	assert(p1);
	assert(p2);
	return *(int *)p1 - *(int *)p2;
}
void my_swmp(char*p1, char *p2, int width)
{
	char temp = 0;
	int i = 0;
	assert(p1);
	assert(p2);
	for (i = 0; i<width; i++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
}
void my_Bubble_sort(void *base, int sz, int width, int(*cmp)(const void *p1, const void *p2))
{
	int i = 0;
	int j = 0;
	assert(base);
	assert(cmp);
	for (i = 0; i<sz - 1; i++)
	{
		for (j = 0; j<sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				my_swmp((char*)base + j*width, (char*)base + (j + 1)*width, width);

			}
		}
	}
}
void print_arr(const void *arr, int sz, int width)
{
	int i = 0;
	char *ret = 0;
	int *ret2 = 0;
	char *ret3 = 0;
	assert(arr);
	for (i = 0; i<sz; i++)
	{
		if (width == 1)
		{
			ret = (char*)arr;
			printf("%c ", ret[i]);
		}
		else if (width == 4)
		{
			ret2 = (int*)arr;
			printf("%d ", ret2[i]);
		}
		else
		{
			ret3 = (char*)arr;
			printf("%s", ret3);
		}
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 1, 6, 9, 8, 7, 4, 5, 10, 3, 2 };
	char arr2[10] = "asdghqwerh";
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int width1 = sizeof(arr[0]);
	int width2 = sizeof(arr2[0]);
	my_Bubble_sort(arr, sz1, width1, my_cmp_int);
	my_Bubble_sort(arr2, sz2, width2, my_cmp_char);
	print_arr(arr, sz1, width1);
	print_arr(arr2, sz2, width2);
	return 0;
}