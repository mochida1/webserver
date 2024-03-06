#include "cgi.hpp"
#include <cstring>

int main()
{
    std::string envPath = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games";
    std::string fileName = "count.cgi";
    std::string path = "/usr/lib/cgi-bin/";
    char *env[] = {strdup(envPath.c_str()), NULL};
    //char *env[] = {NULL};
    execScript(path, fileName, env);

    return 0;
}