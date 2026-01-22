#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd){
    if(fd<0)
        return(NULL);
    char *ret = malloc(9999);
    if(!ret)
        return(NULL);
    int r, rd = 0;
    r = read(fd, ret+rd, 1);
    if(r<=0){
        free(ret);
        return(NULL);}
    rd += r;
    while(r!=0 && ret[rd-1] != '\n'){
        r = read(fd, ret+rd, 1);
        if(r == -1){
            free(ret);
            return(NULL);
        }
        rd += r;
    }
    ret[rd] = '\0';
    if(!*ret)
    {
        free(ret);
        return(NULL);
    }
    return(ret);
}

int main(int ac, char **av)
{
    int fd;
    char *line;

    if (ac != 2)
        return (1);

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}