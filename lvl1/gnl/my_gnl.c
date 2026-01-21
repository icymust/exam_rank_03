#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	pos;
	static int	by_read;
	int			i;
	char		*line;

	if (fd < 0)
		return (NULL);
	line = malloc(100000);
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		if (pos >= by_read)
		{
			by_read = read(fd, buf, BUFFER_SIZE);
			pos = 0;
            if (by_read < 0)
            {
                free(line);
                return (NULL);
            }
            if (by_read == 0)
                break ;
			// if (by_read <= 0)
			// 	break ;
		}
		line[i++] = buf[pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int main(void)
{
	char	*s;
	int fd = open("subject.txt", O_RDONLY);
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%s", s);
	}
	close (fd);
}