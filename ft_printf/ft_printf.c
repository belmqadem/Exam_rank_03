#include <stdarg.h>
#include <unistd.h>

char    *ft_strchr(const char *str, int c)
{
    while (*str && *str != (unsigned char)c)
        str++;
    if (*str == (unsigned char)c)
        return ((char *)str);
    return (0);
}

int    ft_putchar(char c)
{
    write (1, &c, 1);
    return (1);
}

int    ft_putstr(char *s)
{
    if (!s)
    {
        write (1, "(null)", 6);
        return (6);
    }
    int i = 0;
    while (s[i])
    {
        write (1, &s[i], 1);
        i++;
    }
    return (i);
}

int    ft_putnbr_base(long n, int base)
{
    int len = 0;
    char *b = "0123456789abcdef";
    if (n < 0)
    {
        ft_putchar('-');
        len += ft_putnbr_base(-n, base) + 1;
    }
    else if (n >= base)
    {
        len += ft_putnbr_base(n / base, base);
        len += ft_putchar(b[n % base]);
    }
    else
        len += ft_putchar(b[n]);
    return (len);
}

int print_format(va_list ap, const char f)
{
    int count = 0;
    if (f == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if (f == 'd')
        count += ft_putnbr_base((long)va_arg(ap, int), 10);
    else if (f == 'x')
        count += ft_putnbr_base((long)va_arg(ap, unsigned int), 16);
    else
        count = -1;
    return (count);
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    int i = 0;
    int len = 0;

    va_start(ap, s);
    while (s[i])
    {
        if (s[i] == '%' && s[i+1] == '\0')
            return 0;
        else if (s[i] == '%' && ft_strchr("sdx", s[i + 1]))
        {
            len += print_format(ap, s[i + 1]);
            i++;
        }
        else
            len += ft_putchar(s[i]);
        i++;
    }
    va_end(ap);
    return (len);
}
