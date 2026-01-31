#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	char	c;

	c = fgetc(f);
	if (c == ' ')
		return (0);
	ungetc(c, f);
	return (-1);
}

int match_char(FILE *f, char tc)
{
	char	c;
	
	c = fgetc(f);
	if (c == tc)
		return (1);
	ungetc(c, f);
	return (-1);
}

int scan_char(FILE *f, va_list ap)
{
 	char	c;
 	char	*rtn_c;
 	
 	rtn_c = va_arg(ap, char*);
 	
 	c = fgetc(f);
	if (c == EOF)
	{
		ungetc(c, f);
		return (-1);
	}
	*rtn_c = c;
	return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int	*rtn_value;
	int	value;
	int	sign;
	char	c;

	rtn_value = va_arg(ap, int*);
	
	// trap for sign '+' or '-'
	sign = 1;
	c = fgetc(f);
	if ((c != '-') && (c != '+'))
		ungetc(c, f);
	if (c == EOF)
		return (-1);
	if (c == '-')
		sign = -1;

	// check if at least next number is a digit
	c = fgetc(f);
	ungetc(c, f);
	if (isdigit(c) == 0)
		return (-1);
	
	// convert each digit to int value
	value = 0;	
	while (1)
	{
		c = fgetc(f);
		if (isdigit(c) == 0)
		{
			ungetc(c, f);
			break;
		}
		value = (value * 10) + (c - '0');
	}
	
	*rtn_value = value * sign;
	return (1);
}

int scan_string(FILE *f, va_list ap)
{
	char	*rtn_str;
	char	*tmp;
	char	c;
	
	rtn_str = va_arg(ap, char*);
	
	tmp = rtn_str;
	while (1)
	{
		c = fgetc(f);
		if ((c == ' ') || (c == EOF))
		{
			ungetc(c, f);
			break;
		}
		if (c != '\n')
		{
			*tmp = c;
			tmp++;
		}
	}
	*tmp = 0;
	if (tmp == rtn_str)
		return (-1);
	return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list	ap;
	
	va_start (ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

