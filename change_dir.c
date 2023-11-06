#include "shell.h"

/**
 * handle_change_dir - handle the change directory command
 * @args: the argument
 * Return: void
 */
void handle_change_dir(char **args)
{
	char *new_d;
	char *full_new_d;
	char *current_d;

	if (args == NULL || args[0] == NULL)
		new_d = getenv("HOME");
	else if (strcmp(args[0], "-") == 0)
		new_d = getenv("OLDPWD");
	else
		new_d = args[0];
	if (new_d == NULL)
	{
		perror("./hsh");
		return;
	}

	current_d = getcwd(NULL, 0);
	if (current_d == NULL)
	{
		perror("./hsh");
		return;
	}

	if (chdir(new_d) != 0)
		perror("./hsh");
	else
	{
		full_new_d = getcwd(NULL, 0);
		if (setenv("pwd", full_new_d, 1) != 0)
		{
			perror("./hsh");
		}
	}
	free(current_d);
	free(full_new_d);

}
