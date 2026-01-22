#include <unistd.h>
#include <stdarg.h>

int print_str(char *s){
    int i = 0;
    if(!s)
        s = "(null)";
    while(s[i]){
        write(1, &s[i], 1);
        i++;
    }
    return(i);
}

void put_char(char c){
    write(1, &c, 1);
}

void put_digit(long num){
    if(num < 0){
        write(1, "-", 1);
        num = -num;
    }
    if(num >= 10){
        put_digit(num/10);
    }
    put_char(num%10 +'0');
}

int digit_len(long num){
    int i = 0;
    if(num <= 0){
        i++;
        num = -num;
    }
    while(num){
        i++;
        num/=10;
    }
    return(i);
}

int print_digit(int num){
    put_digit(num);
    return(digit_len(num));
}

void put_hex(unsigned int num){
    char *hex = "0123456789abcdef";
    if(num >= 16){
        put_hex(num/16);
    }
    put_char(hex[num%16]);
}

int hex_len(unsigned int num){
    int i = 0;
    if(num == 0)
        return(1);
    while(num){
        num/=16;
        i++;
    }
    return(i);
}

int print_hex(unsigned int num){
    put_hex(num);
    return(hex_len(num));
}

int check_format(va_list args, char c){
    int i = 0;
    if(c == 's'){
        i+= print_str(va_arg(args, char *));
    }
    else if(c == 'd'){
        i+= print_digit(va_arg(args, int));
    }
    else if(c == 'x'){ 
        i+= print_hex(va_arg(args, unsigned int));
    }
    return(i);
}

int ft_printf(char *str, ...){
    va_list args;
    va_start(args, str);
    int i = 0;
    while(*str){
        if(*str == '%'){
            str++;
            i+=check_format(args, *str);
        }
        else{
            write(1, str, 1);
            i++;
        }
        str++;
    }
    va_end(args);
    return(i);
}