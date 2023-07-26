#include "shell.h"

/**
 *  * _handler_for_length - function for finding length
 *   * @param _user_str: inpu string pointer.
 *    * return: length of the string
 *     **/
size_t _handler_for_length(const char *_user_str)
{
	size_t _len_handler;

	for (_len_handler = 0; _user_str[_len_handler] != '\0'; _len_handler++)
	{
	}

	return (_len_handler);
}
/**
 * * _str_con_canc - function for concatenation
 * * @param _str_a: initially user input string
 * * @param _str_b: secondly modified string.
 * *
 * * Return: concatenated string.
 * **/

char *_str_con_canc(char *_str_a, char *_str_b)
{
	int _len_a = 0, _len_b = 0, i = 0, j = 0;
	int _str_len;
	char *_str_result = NULL;

	for (; _str_a[_len_a]; _len_a++)
		;

	for (; _str_b[_len_b]; _len_b++)
		;

	_str_len = _len_a + _len_b + 1;

	_str_result = malloc(sizeof(char) * _str_len);
	if (!_str_result)
	{
		return (NULL);
	}
	for (i = 0; i < _len_a; i++)
	{
		_str_result[i] = _str_a[i];
	}
	i = _len_a;

	for (j = 0; j < _len_b; j++)
	{
		_str_result[i] = _str_b[j];
		i++;
	}

	_str_result[i] = '\0';

	return (_str_result);
}

/**
 * * func_for_str_copy - function for string copy
 * * @u: user input initial string
 * * @v: string to be copied
 * **/

char *func_for_str_copy(char *u, char *v)
{
	size_t i;
	for (i = 0; v[i]; i++)
	{
		u[i] = v[i];
	}
	u[i] = '\0';

	return (u);
}

/**
 * * func_for_str_cmp - function for string comparision
 * * @u: user initial string
 * * @x: second string to be compared to user string
 * **/

int func_for_str_cmp(const char *u, const char *x)
{
	int i;
	int _len_for_u = _handler_for_length(u);
	int _for_for_x = _handler_for_length(x);

	if (_len_for_u != _for_for_x)
		return (-1);


	for (i = 0; u[i] && x[i]; i++)
	{
		if (u[i] != x[i])
			return (-1);
	}

	return (0);
}


