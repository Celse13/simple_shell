#include "shell.h"

/**
 *  * _own_string_trimmer - Trims trailing spaces, newlines,
 *   * and tabs from a string.
 *    * @_string: Pointer to the string to be trimmed.
 *     * return void
 *      **/
void _own_string_trimmer(char *_string)
{
	int i = _handler_for_length(_string) - 1;

	for (; i > 0;)
	{
		if (_string[i] == ' ' || _string[i] == '\n'
				|| _string[i] == '\t')
			i--;
		else
			break;
	}
	_string[i + 1] = '\0';

}

/**
 * * _func_mult_cmd - Execute user multiple commands
 * * @_cmd_user: The string separeted by ';'
 * * Return: Always returns 0.
 * **/


int _func_mult_cmd(char *_cmd_user)
{
	int _cmd_count = 0;
	char  **_cmd_tokenizer = _remains_arr(_cmd_user, ";");
	char **_cmd_holder = _cmd_tokenizer;


	while (*_cmd_holder)
	{
		_cmd_count++;
		_cmd_holder++;
	}
	_cmd_holder = _cmd_tokenizer;

	while (*_cmd_holder)
	{
		_own_string_trimmer(*_cmd_holder);
		_exec_cmd(*_cmd_holder);
		_cmd_holder++;

	}

	_free_up_arr(_cmd_tokenizer);
	return (0);
}
