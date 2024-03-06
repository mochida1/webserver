#include <cstring>
#include <unistd.h>
#include <iostream>
#include <cerrno>
#include <sys/wait.h>
#include <cstdio> // APAGAR!

int    execScript(std::string path, std::string  fileName, char **env);

void    cgiFork(std::string path, std::string  fileName, char **env)
{
        int	fd[2];
        int	wstatus;
        int	pid;
        char buf[200];
    
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execScript(path, fileName, env);
		}
		else
		{
			waitpid(pid, &wstatus, 0);
            read(fd[0], buf, 200);
            printf("%s\n", buf);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
		}
}

int    execScript(std::string path, std::string  fileName, char **env)
{
    char *argv[] = {NULL};

    chdir(path.c_str());
    path.append(fileName);
    if (execve(path.c_str(), argv, env) == -1)
    {
        std::cerr << "execve() failed: " << strerror(errno) << std::endl;
        return 1;
    }
    return 0;
}