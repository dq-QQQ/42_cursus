#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *str, ...){
    va_list ap;
    int i;
    char c;
    
	i = 0;
    va_start(ap, str);
    while (str[i])
    {
        if (str[i] != '%')
            write(1, &str[i], 1);
        else
        {
            c = va_arg(ap, int);
            write(1, &c, 1);
            i++;
        }
        i++;
    }
    va_end(ap);
    return (0);
}

int main()
{
    char c = 'k';
    ft_printf("hello%c",c);
}

