#include "shell.h"

/**
 *  * func_for_mem_cpy -function for memory copy
 *   * @old_alloc: for old allocation
 *    * @where: void data structure
 *     * @n: number to be allocated
 *     **/
void func_for_mem_cpy(void *old_alloc, void *where, size_t n)
{
	size_t i = 0;
	const char *src = (const char *)where;
	char *dest = (char *)old_alloc;
	while (i < n)
	{
		dest[i] = src[i];
		++i;
	}
}

/**
 * * func_for_mem_set - funcition for memory set
 * * @new_string: for new_string
 * * @z: for number of alloc
 * * @n: for the size to be alloc
 * */

void *func_for_mem_set(void *new_string, int z, size_t n)
{
	unsigned char _new_str = (unsigned char)z;
	size_t i = 0;
	unsigned char *_alloc = (unsigned char *)new_string;

	while (i < n)
	{
		_alloc[i] = _new_str;
		i++;
	}

	return (new_string);
}

/**
 * * func_for_realloc - realloc function
 * * @param _str_input: input_string.
 * * @param _rem_size: size of new alloc.
 * * @param _new_input: new string
 * */

void *func_for_realloc(void *_str_input, size_t _rem_size, size_t _new_input)
{
	void *new__str_input;
	if (_rem_size == 0)
	{
		free(_str_input);
		return (NULL);
	}
	if (_str_input == NULL)
	{
		return (malloc(_rem_size));
	}

	new__str_input = malloc(_rem_size);
	if (new__str_input != NULL)
	{
		func_for_mem_cpy(new__str_input, _str_input, (_rem_size < _new_input) ? _rem_size : _new_input);
		free(_str_input);
	}

	return (new__str_input);
}

