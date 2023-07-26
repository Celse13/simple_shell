#include "shell.h"

/**
 *  * _exec_cmd - Execute a command from user .
 *   * @_cmd_user: command to execute.
 *    *
 *     * Return: 0 on success; -1 on failure.
 *      **/
int _exec_cmd(char *_cmd_user)
{
	int _sign = 0;
	pid_t child_id;
	int _status = 0;
	char **arr_tokenized = _remains_arr(_cmd_user, " \t\n\a\r");

	if (_cmd_user == NULL || arr_tokenized == NULL)
	{
		_free_up_arr(arr_tokenized);
		return (-1);
	}

	_sign = _is_exit_function(arr_tokenized);

	switch (_sign)
	{
		case -1:
			{
				fprintf(stderr, "no cmd found\n");
				_free_up_arr(arr_tokenized);
				return (-1);
			}
		case 3:
			{
				funct_inside(arr_tokenized);
				break;
			}
		default:
			{
				child_id = fork();
				if (child_id == 0)
				{
					execve(arr_tokenized[0], arr_tokenized, NULL);
					if (errno == EACCES)
						exit(126);
					exit(1);
				}
				else
				{
					wait(&_status);
					if (WIFEXITED(_status))
					{
						_status = WEXITSTATUS(_status);

					}
				}
				break;
			}
	}

	_free_up_arr(arr_tokenized);

	return (0);
}

