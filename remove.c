#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void
sort(int* nums, int n)
{
	for(int i = 0; i < n; i++)
	{
		int min_idx = i;

		for(int j = i + 1; j < n; j++)
		{
			if(nums[j] < nums[min_idx]) { min_idx = j; }
		}

		int t = nums[min_idx];
		nums[min_idx] = nums[i];
		nums[i] = t;
	}
}

int
removeElement(int* nums, int n, int t)
{
	sort(nums, n);
	int i, k, c = 0;

	for(i = 0; i < n; i++)
	{
		if(nums[i] == t)
		{
			nums[i] = -1;
			c++;
		}
	}

	sort(nums, n);

	for(i = 0; i < c; i++)
	{
		nums[i] = nums[n - 1 - i];
	}

	return k = n - c;
}

int
main(int argc, char* argv[])
{
	const int n = argc - 2;
	int i, nums[n], target = strtol(argv[1], NULL, 0);

	if(argc < 2)
	{
		printf("Usage is: ./remove [target], nums[0], nums[1]...\n");
		exit(1);
	}

	for(i = 0; i < n; i++)
	{
		nums[i] = strtol(argv[i + 2], NULL, 0);
	}

	int n_solutions = removeElement(nums, n, target);

	printf("Solutions: %d\n", n_solutions);
	for(i = 0; i < n_solutions; i++)
	{
		printf("nums[%d] = %d\n", i, nums[i]);
	}
	return 0;
}