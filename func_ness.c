#include "shell.h"
/**
 *  * num_of_iter - Finding the number of times of a delim-separated string.
 *   * @_user_cmd: string to count occurrences from.
 *    * @_delimeter:  delim used to separate the string.
 *     *
 *      * Return: The number of times of the delim -separated string.
 *       **/

int num_of_iter(const char *_user_cmd, char *_delimeter)
{
	int _cmd_count = 0;
	int _cmd_index = 0;
	char *_user_cmd_cpy = NULL;
	char *remain_str;
	size_t num = 0;

	while (_user_cmd[_cmd_index])
	{
		_cmd_index++;
	}

	num = _cmd_index + 1;
	_user_cmd_cpy = malloc(sizeof(char) * num);
	strcpy(_user_cmd_cpy, _user_cmd);
	remain_str = strtok(_user_cmd_cpy, _delimeter);
	while (remain_str)
	{
		_cmd_count++;
		remain_str = strtok(NULL, _delimeter);
	}

	free(_user_cmd_cpy);
	return (_cmd_count);
}

/**
 * * _remains_arr - Tokenize and create an array after tokenization.
 * * @_usr_cmd: string to be tokenized
 * * @_delimeter: delimeter for tokenization.
 * *
 * * Return: A dynamically allocated array of strings,
 * * or NULL on failure.
 * **/



char **_remains_arr(char *_usr_cmd, char *_delimeter)
{
	int i = 0;
	char *_cmd_new = NULL;
	char **new_append;
	char *remain;
	size_t num = 0;
	char *current;

	num = _handler_for_length(_usr_cmd) + 1;
	_cmd_new = malloc(sizeof(char) * num);
	strcpy(_cmd_new, _usr_cmd);

	new_append = malloc(sizeof(char *) * (num_of_iter(_usr_cmd, _delimeter) + 1));

	remain = strtok(_cmd_new, _delimeter);
	while (remain)
	{
		current = malloc(sizeof(char) * (_handler_for_length(remain) + 1));
		strcpy(current, remain);
		new_append[i] = current;
		remain = strtok(NULL, _delimeter);
		i++;
	}
	if (i == 0)
	{
		free(new_append);
		free(_cmd_new);
		return (NULL);
	}

	new_append[i] = NULL;
	free(_cmd_new);
	return (new_append);
}
