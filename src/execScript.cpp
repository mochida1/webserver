#include <cstring>
#include <unistd.h>
#include <iostream>
#include <cerrno>


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