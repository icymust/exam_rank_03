#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d", arr[i]);
		if (i < len - 1)
			printf(" ");
		i++;
	}
	printf("\n");
	return;
}

void	solve(int *nums, int *arr, int target, int pos, int len, int sum, int size)
{
	int	i;

	if (sum == target)
		print_arr(arr, len);
	
	i = pos;
	while (i < size)
	{
		arr[len] = nums[i];
		solve(nums, arr, target, i + 1, len + 1, sum + nums[i], size);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac <= 2)
		return (1);
	int nums[ac - 2];
	int arr[ac - 2];
	int	i;

	i = 2;
	while (av[i])
	{
		nums[i - 2] = atoi(av[i]);
		i++;
	}
	solve(nums, arr, atoi(av[1]), 0, 0, 0, ac - 2);
	return (0);
}