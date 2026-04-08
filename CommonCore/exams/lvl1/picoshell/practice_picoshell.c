#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
	int		i;
	int		prev_read;
	int		fd[2];
	int		status;
	int		ret;
	pid_t	pid;

	i = 0;
	prev_read = -1;
	ret = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
		{
			if (prev_read != -1)
				close(prev_read);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			if (prev_read != -1)
				close(prev_read);
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (prev_read != -1)
			{
				if (dup2(prev_read, 0) == -1)
					exit(1);
				close(prev_read);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], 1) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_read != -1)
			close(prev_read);
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev_read = fd[0];
		}
		else
			prev_read = -1;
		i++;
	}
	while (wait(&status) > 0)
	{
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			ret = 1;
	}
	return (ret);
}