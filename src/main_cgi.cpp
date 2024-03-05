#include "cgi.hpp"
#include <cstring>

int main()
{
    std::string envPath = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games";
    std::string fileName = "count.cgi";
    char *env[] = {strdup(envPath.c_str()), NULL};
    //char *env[] = {NULL};
    execScript(fileName, env);

    return 0;
}