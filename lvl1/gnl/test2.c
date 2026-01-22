#include <unistd.h>
#include <stdlib.h>

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
    while(r!= 0 && ret[rd-1] != '\n'){
        r = read(fd, ret+rd, 1);
        if(r == -1){
            free(ret);
            return(NULL);
        }
        rd += r;
    }
    ret[rd] = '\0';
    if(!*ret){
        free(ret);
        return(NULL);
    }
    return(ret);
}