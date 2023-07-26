#include "shell.h"

/**
 *  * read_and_adjust_buffer - read and adjust memory
 *   * @adjusted_buf: Pointer directing to buffer.
 *    * @adjusted_buf_size: Pointer directing to adjusted buffer.
 *     * @data_stream: The data stream to read from.
 *      *
 *       * Return: characters read and adjusted,
 *        * or -1 on failure.
 *         **/
ssize_t read_and_adjust_buffer(char **adjusted_buf, size_t *adjusted_buf_size, FILE *data_stream)
{
	char *new_adjusted_buffer;
	ssize_t content_length = 0;
	int current_character;

	for (;;)
	{
		current_character = fgetc(data_stream);
		if (current_character == EOF)
			break;

		if (content_length >= (ssize_t)(*adjusted_buf_size) - 1)
		{
			size_t new_adjusted_size = (*adjusted_buf_size) * INCREASE_RATE;

			new_adjusted_buffer = func_for_realloc(*adjusted_buf,
					new_adjusted_size * sizeof(char), 64);

			if (new_adjusted_buffer == NULL)
				return (-1);

			*adjusted_buf = new_adjusted_buffer;
			*adjusted_buf_size = new_adjusted_size;
		}

		(*adjusted_buf)[content_length++] = (char)current_character;
		if (current_character == '\n')
			break;
	}

	(*adjusted_buf)[content_length] = '\0';
	return (content_length);
}


/**
 * * _initializing_for_buf - dealing with buffer
 * * @_handling_buf: handling buffer.
 * * @_handling_buf_size: handling buffer.
 * **/
void _initializing_for_buf(char **_handling_buf, size_t *_handling_buf_size)
{
	*_handling_buf = (char *)malloc(STARTING_BUFFER * sizeof(char));
	if (*_handling_buf != NULL)
		*_handling_buf_size = STARTING_BUFFER;
}

/**
 * * _release_for_buf -releasing buffer
 * * @_handling_buf: handling buffer.
 * **/
void _release_for_buf(char *_handling_buf)
{
	free(_handling_buf);
}

/**
 * * _implement_get_line - implementation for getline
 * * @_user_line: buffer for storing the user line.
 * * @_actual_sz: Pointer to the size .
 * * @input_stream: The input stream to read from.
 * *
 * * Return: characters read, or -1 on failure.
 * **/
ssize_t _implement_get_line(char **_user_line, size_t *_actual_sz, FILE *input_stream)
{
	ssize_t _user_line_len;

	if (_user_line == NULL || _actual_sz == NULL || input_stream == NULL)
		return (-1);

	_initializing_for_buf(_user_line, _actual_sz);

	_user_line_len = read_and_adjust_buffer(_user_line, _actual_sz, input_stream);
	return (_user_line_len);
}




