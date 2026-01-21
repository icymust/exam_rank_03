#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int total;
    int match;
    int pos;
    int by_read;
    char    buf[100000];
    char    *pattern;
    int     pattern_len;

    if (ac != 2 || !av[1][0])
        return (1);
    pattern = av[1];
    pattern_len = strlen(pattern);

    total = 0;
    while ((by_read = read(0, buf + total, 99999 - total)) > 0)
        total += by_read;
    if (by_read < 0)
    {
        perror("Error");
        return (1);
    }
    pos = 0;
    while (pos < total)
    {
        match = 0;
        while (match < pattern_len && pos + match < total
            && buf[pos + match] == pattern[match])
                match++;
        if (match == pattern_len)
        {
            while (match--)
                printf("*");
            pos += pattern_len; 
        }
        else
            printf("%c", buf[pos++]); 
    }
    return (0);
}