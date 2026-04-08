#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char *g_s;

void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int parse_sum(void);

int parse_factor(void)
{
    int n;

    if (isdigit(*g_s))
        return (*g_s++ - '0');
    if (*g_s == '(')
    {
        g_s++;
        n = parse_sum();
        if (*g_s != ')')
        {
            unexpected(*g_s);
            exit(1);
        }
        g_s++;
        return (n);
    }
    unexpected(*g_s);
    exit(1);
}

int parse_product(void)
{
    int n;

    n = parse_factor();
    while (*g_s == '*')
    {
        g_s++;
        n *= parse_factor();
    }
    return (n);
}

int parse_sum(void)
{
    int n;

    n = parse_product();
    while (*g_s == '+')
    {
        g_s++;
        n += parse_product();
    }
    return (n);
}

int main(int argc, char **argv)
{
    int result;

    if (argc != 2)
        return (1);
    g_s = argv[1];
    result = parse_sum();
    if (*g_s)
    {
        unexpected(*g_s);
        return (1);
    }
    printf("%d\n", result);
    return (0);
}