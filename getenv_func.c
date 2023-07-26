#include "shell.h"
/**
 *  * _get_env_var - retrieve envrionment var.
 *   * @target_name: environment variable to be retrieved.
 *    *
 *     * Return: environment variable, or NULL if not found.
 *      **/
char *_get_env_var(char *target_name)
{
	int i;
	char *result_value;
	bool is_found = false;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *env_var = environ[i];
		size_t j = 0;
		size_t target_length = _handler_for_length(target_name);

		while (env_var[j] != '\0' && env_var[j] != '=')
			j++;

		if (strncmp(env_var, target_name, target_length) == 0 && env_var[j] == '=')
		{
			is_found = true;
			result_value = env_var + j + 1;
			break;
		}
	}
	if (is_found)
	{
		size_t value_len = _handler_for_length(result_value) + 1;
		char *copied_value = malloc(value_len);

		if (copied_value != NULL)
			strcpy(copied_value, result_value);
		return (copied_value);
	}
	return (NULL);
}
