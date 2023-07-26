#include "shell.h"

static void wrapper_deal_with_exit(char **args);
/**
 *  * funct_inside - implementation for
 *   * @_user_cmd: user_commend to be executed.
 *    * Return: 1 if command matches built-in function
 *     * and is executed successfully; otherwise, 0.
 *      **/
int funct_inside(char **_user_cmd)
{
	int i;

	funct_built inside_func [] = {{"cd", NULL}, {"env", deal_with_envir_var},
		{"exit", wrapper_deal_with_exit},
		{
			NULL, NULL
		}
	};

	if (_user_cmd == NULL || *_user_cmd == NULL)
		return (0);

	for (i = 0; inside_func[i].command != NULL; i++)
	{
		if (func_for_str_cmp(inside_func[i].command, *_user_cmd) == 0)
		{
			inside_func[i].func_fix(_user_cmd);
			return (1);
		}
	}



	return (0);
}
/**
 * * deal_with_envir_var - printing the environ variables
 * * @void: not user input
 * **/
void deal_with_envir_var(void)
{
	char **environ_handler = environ;

	for (; *environ_handler; environ_handler++)
	{
		puts(*environ_handler);

	}
}

/**
 * * wrapper_deal_with_exit - checking for exit
 * * @args: user command to be checked
 * * handling exit
 * **/

static void wrapper_deal_with_exit(char **args)
{
	deal_with_exit(0, args, 0);
}

/**
 * * deal_with_exit - checking if user command is exit
 * * @arg_count: Number of arguments.
 * * @arguments: Array of command arguments.
 * * @cmd_num: Command number in history.
 * * return: num for exit
 * **/
void deal_with_exit(int arg_count, char *arguments[], int cmd_num)
{
	int num = 0;
	int i = 0;

	if (arg_count > 1)
	{
		int n = atoi(arguments[1]);

		if (n == 0 && strcmp(arguments[1], "0") != 0)
		{
			num = 2;
			fprintf(stderr, "%s: %d: %s: ", arguments[0], cmd_num, arguments[0]);
			fprintf(stderr, "Invalid user_cmd: %s\n", arguments[1]);
		}
		else
		{
			num = n;
		}
	}

	for (i = 0; i < arg_count; i++)
	{
		free(arguments[i]);
	}

	exit(num);
}

