#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
	int i = -1;

	while (str[++i]);
	return (i);
}

int merror(int index, char *program)
{
	int i = -1;

	if (index == 1)
		write(2, "error: fatal\n", 13);
	if (index == 2)
	{
		write(2, "error: cannot execute ", 22);
		while (++i < ft_strlen(program))
			write(2, &program[i], 1);
		write(2, "\n", 1);
	}
	if (index == 3)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		while (++i < ft_strlen(program))
			write(2, &program[i], 1);
		write(2, "\n", 1);
	}
	if (index == 4)
		write(2, "error: cd: bad arguments\n", 25);
	return (1);
}

int built_cd(char **cmd)
{
	if (cmd[1] && !cmd[2])
	{
		if (chdir(cmd[1]))
			return (merror(3, cmd[1]));
		else
			return 0;
	}
	return (merror(4, NULL));
}

int exec_cmd(char **av, int i, int index, char **env, int s)
{
	char *cmd[i - index];
	int j = 0;
	int k = 0;
	pid_t pid;
	int status = 0;
	int pfd[2];
	int fd;
	int ret;

	if (s && (pipe(pfd) == -1 || (fd = dup(0)) == -1))
		return (merror(1, NULL));
	while (j < i - index)
	{
		while (av[index + j][k])
		{
			cmd[j] = av[index + j];
			k++;
		}
		j++;
		k = 0;
	}
	cmd[j] = NULL;
	if (!cmd[0])
		return 0;
	if (!strcmp(cmd[0], "cd"))
	{
		ret = built_cd(cmd);
		return (ret);
	}
	if ((pid = fork()) == -1)
		return (merror(1, NULL));
	if (pid == 0)
	{
		if (s)
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
			close(pfd[1]);
		}
		if (execve(cmd[0], cmd, env) == -1)
			exit(1);
	}
	else
		waitpid(-1, &status, 0);
	if (s)
	{
		close(fd);
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
	if (status)
	{
		merror(2, cmd[0]);
		return 1;
	}
	return 0;
}

int main(int ac, char **av, char **env)
{
	int i = 1;
	int	index = 1;

	(void)ac;
	while (av[i])
	{
		if (!strcmp(av[i], ";"))
		{
			exec_cmd(av, i, index, env, 0);
			index = i + 1;
		}
		else if (!strcmp(av[i], "|"))
		{
			exec_cmd(av, i, index, env, 1);
			index = i + 1;
		}
		i++;
	}
	exec_cmd(av, i, index, env, 0);
	return 0;
}
