#include "shell.h"

/**
 *  * from_integer_string - Convert an integer to a string.
 *   * @_user_input: The integer to be converted.
 *    * @_string_for_num: The string to store the converted.
 *     **/

void from_integer_string(int _user_input, char _string_for_num[])
{
	int i;
	int _user_input_holder = _user_input;
	int _remainder, _input_length = 0;

	while (_user_input_holder != 0)
	{
		_input_length++;
		_user_input_holder /= 10;
	}

	for (i = 0; i < _input_length; i++)
	{
		_remainder = _user_input % 10;
		_user_input /= 10;

		_string_for_num[_input_length - (i + 1)] = _remainder + '0';
	}

	_string_for_num[_input_length] = '\0';
}
