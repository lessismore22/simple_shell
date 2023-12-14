#include "shell.h"


int main(void)
{
	char command[120];

	while (1)
	{
		_prompt();
		read_cmd(command, sizeof(command));

	}

	return (0);
}
