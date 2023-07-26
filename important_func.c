#include "shell.h"


/**
 *  * _is_exit_function - exit function
 *   * @_arguments: array of command arguments.
 *    *
 *     * Return: 3 if it's an exit function,
 *      * 1 if it's an executable file, 2 if found in PATH,
 *       * or -1 if not found.
 *        **/
int _is_exit_function(char **_arguments)
{
	char *_directory_path, *_full_path, *_path_list;
	char **_path_tokens, **_path_tokens_free;

	if (_function_built_in(_arguments) == 1)
		return (3);

	if (access(_arguments[0], X_OK) == 0)
		return (1);

	_path_list = _get_env_var("PATH");
	_path_tokens = _remains_arr(_path_list, ":");
	_path_tokens_free = _path_tokens;

	for (; *_path_tokens; _path_tokens++)
	{
		_directory_path = malloc(_handler_for_length(*_path_tokens) + 2);
		_full_path = malloc(_handler_for_length(*_path_tokens) +
				_handler_for_length(_arguments[0]) + 2);

		func_for_str_copy(_directory_path, *_path_tokens);
		strcat(_directory_path, "/");

		func_for_str_copy(_full_path, _directory_path);
		strcat(_full_path, _arguments[0]);

		if (access(_full_path, X_OK) == 0)
		{
			free(_arguments[0]);
			_arguments[0] = _full_path;
			free(_directory_path);
			_free_up_arr(_path_tokens_free);
			return (2);
		}

		free(_directory_path);
		free(_full_path);
	}
	free(_path_list);
	_free_up_arr(_path_tokens_free);

	return (-1);
}


/**
 * * _arguments_handler - arugment handler
 * * @_arguments: arr of args.
 * *
 * * Return: Always returns 0.
 * **/

int _arguments_handler(char **_arguments)
{
	int i = 0;
	int j = 0;
	int some_id = 0;

	char *_handle_names[] = {"#", "$$", "$?", NULL};

	void (*_handlers[])(char **, int, int) = {_pound_handler,
		pound_handler_for_2_dollars, _pound_handler_for_2_marks, NULL };
	for (i = 0; _handle_names[i] != NULL; i++)
	{
		for (j = 0; _arguments[j] != NULL; j++)
		{
			if (_arguments[j][0] == '#' && _handle_names[i][0] == '#')
			{
				_handlers[i](_arguments, j, some_id);
			}
			else if (strcmp(_handle_names[i], _arguments[j]) == 0)
			{
				_handlers[i](_arguments, j, some_id);
			}
		}
	}

	return (0);
}




