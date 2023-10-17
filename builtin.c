#include "main.h"

/**
* get_builtin - selects the correct builtin.
* @cmd: The command.
* Return: a function pointer.
*/

int (*get_builtin(char *cmd))(char **)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
