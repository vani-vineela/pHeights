#include <stddef.h>
#include <stdlib.h>

int* getLeaderIndex(int *arr, int len){
	if (arr == NULL || len <= 0)
		return NULL;
	int i, count = 0, j, len1 = len - 1, frequency = 0;
	static int *max;
	max = (int*)malloc(100000*sizeof(int));
	//static int max[100000];
	static int res[2];
	max[len - 1] = len - 1;
	for (i = len - 2; i >= 0; i--)
	{
		if (arr[max[i + 1]] > arr[i])
			max[i] = max[i+1];
		else
			max[i] = i;
	}
	j = max[len - 1];
	for (i = len - 2; i >= 0; i--)
	{
		if (j == max[i])
		{
			count++;
		}
		else
		{
			if (count >= frequency)
			{
				len1 = j;
				frequency = count;
				j = max[i];
			}
			count = 0;
		}
	}
	if (count >= frequency)
	{
		len1 = j;
	}
	if (len1 == len - 1)
		frequency = len - 1;
	res[0] = len1;
	res[1] = frequency;
	return res;
}
