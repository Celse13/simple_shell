#include "shell.h"

/**
 *  * handling_for_ctrl_c - controling ctrl + c signal
 *   * @signal: number for signal to be received.
 *    **/
void handling_for_ctrl_c(int signal)
{
	switch (signal)
	{
		case SIGINT:
			write(1, "(New_shell)$ ", 13);
			break;

		default:
			fflush(stdout);
			break;
	}
}

/**
 *  * main - the main entry point for the sell
 *   * @argc: argument from command line
 *    * @argv: array for argument for cmd line
 *     * @_own_env: array for environment variable
 *      * Return: Always 0.
 *      **/
int main(int argc, char **argv, char **_own_env)
{
	char *_cmd_user = NULL;
	size_t _cmd_buffer = 0;
	ssize_t _cmd_len;
	int check_inter = 1;

	/* Check for ctrl + c from the user */
	signal(SIGINT, handling_for_ctrl_c);

	/* Display prompt for interactive shell */
	if (isatty(STDIN_FILENO) && argc == check_inter)
		write(1, "(New_shell)$ ", 14);

	while ((_cmd_len = _implement_get_line(&_cmd_user, &_cmd_buffer, stdin)) > 0)
	{
		/* Terminate the user input with '\0' */
		if (_cmd_len > 1 && _cmd_user[0] != '#')
		{
			_cmd_user[_cmd_len - 1] = '\0';
			_exec_cmd(_cmd_user);
		}

		if (isatty(STDIN_FILENO) && argc == check_inter)
			write(1, "(New_shell)$ ", 14);
	}

	free(_cmd_user);
	(void)argv;
	(void)_own_env;
	return (0);
}

