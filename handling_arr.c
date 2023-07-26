#include "shell.h"

/**
 *  * _free_up_arr - Free up the memory array.
 *   * @_str_array: freed array.
 *    **/
void _free_up_arr(char **_str_array)
{
	char **_temp_ptr = {NULL};

	if (_str_array == NULL)
		return;

	_temp_ptr = _str_array;

	while (*_str_array != NULL)
	{
		free(*_str_array);
		_str_array++;
	}

	free(_temp_ptr);
}

/**
 * * _function_built_in - verify if built commands
 * * @_arugments: command arguments.
 * *
 * * Return: 1 if the command is a built-in, -1 otherwise.
 * **/
int _function_built_in(char **_arugments)
{
	int i;
	char *_function_list[] = {"exit", "env", "cd", "setenv", "unsetenv", NULL};
	bool is_function_list = false;

	for (i = 0; _function_list[i] != NULL; i++)
	{
		if (strcmp(_function_list[i], _arugments[0]) == 0)
		{
			is_function_list = true;
			break;
		}
	}

	return (is_function_list ? 1 : -1);
}

/**
 * * _pound_handler - Handle the '#' character
 * * @_user_args: user arguments.
 * * @n: Index of the args to be removed.
 * * @_id: handling parameter.
 * **/
void _pound_handler(char *_user_args[], int n, int _id)
{
	free(_user_args[n]);
	_user_args[n] = NULL;
	n++;

	for (; _user_args[n] != NULL; )
	{
		free(_user_args[n]);
		_user_args[n]++;

	}
	(void)_id;
}

/**
 * * pound_handler_for_2_dollars - this function is for handling pound sign
 * * @_usr_args: argument from the user
 * * @n: Index of the argument to be replaced.
 * * @_id: The integer value to replace the argument with.
 * **/
void pound_handler_for_2_dollars(char *_usr_args[], int n, int _id)
{
	char *_usr_str_holder;

	free(_usr_args[n]);

	_usr_str_holder = (char *)malloc(sizeof(char) * 128);
	from_integer_string(_id, _usr_str_holder);

	_usr_args[n] = _usr_str_holder;

}
/**
 * * _pound_handler_for_2_marks - handling double marks
 * * @_usr_args: argument from the user
 * * @n: Index of the argument to be replaced.
 * * @_id: The integer value to replace the argument with.
 * **/

void _pound_handler_for_2_marks(char *_usr_args[], int n, int _id)
{
	char *_usr_str_holder;

	free(_usr_args[n]);

	_usr_str_holder = (char *)malloc(sizeof(char) * 128);

	from_integer_string(_id, _usr_str_holder);

	_usr_args[n] = _usr_str_holder;
}
