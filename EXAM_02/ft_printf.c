#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>


int ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_putstr(char *s, int *j)
{
    if (!s)
        s = "(null)";
    *j += write(1, s, ft_strlen(s));
}

void ft_putchar(char c, int *j)
{
    *j += write(1, &c, 1);
}

void ft_putnbr_hex(unsigned int n, int *j)
{
    char *base;
    base = "0123456789abcdef";

    if (n < 16)
       ft_putchar(base[n], j);
    else
    {
        ft_putnbr_hex(n / 16, j);
        ft_putnbr_hex(n % 16, j);
    }
}

void ft_putnbr(int n, int *j)
{
    if (n == INT_MIN)
        ft_putstr("-21474823648", j);
    else
    {
        if (n < 0)
        {
            ft_putchar('-', j);
            n = -n;
        }
        if (n > 9)
        {
            ft_putnbr(n / 10, j);
            ft_putnbr(n % 10, j);
        }
        else
            ft_putchar(n + '0', j);
    }
}



void ft_type(const char s, va_list *ap, int *j)
{
    if (s == 's')
        ft_putstr(va_arg(*ap, char *), j);
    else if (s == 'd')
        ft_putnbr(va_arg(*ap, int), j);
    else if (s == 'x')
        ft_putnbr_hex(va_arg(*ap, unsigned int), j);
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    int i = 0;
    int j = 0;

    va_start(ap, s);
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            ft_type(s[i], &ap, &j);
        }
        else
            ft_putchar(s[i], &j);
        i++;
    }
    va_end(ap);
    return (j);
}


int main(void)
{
 //   char *s;

   // s = "a";
 //   ft_printf("%x", s);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    ft_printf("Magic %s is %d", "number", 42);
    ft_printf("%s\n", "toto");
    return 1;
}
