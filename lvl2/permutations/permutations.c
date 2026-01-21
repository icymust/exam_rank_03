#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void	sort(char *s)
{
	int left;
	int right;

	left = 0;
	while (s[left])
	{
		right = left + 1;
		while (s[right])
		{
			if (s[left] > s[right])
				swap(&s[left], &s[right]);
			right++;
		}
		left++;
	}
}

void	permutation(char *s, int pos)
{
	int	i;

	if (!s[pos])
	{
		printf("%s\n", s);
		return;
	}
	i = pos;
	while (s[i])
	{
		sort(s + pos);
		swap(s + i, s + pos);
		permutation(s, pos + 1);
		swap(s + i, s + pos);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
		permutation(av[1], 0);
}