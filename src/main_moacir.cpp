#include "HTTPRequest.hpp"

int main ()
{
    std::string method = "Hello world!";
    std::string uri = "/foo.html";
    std::string version = "1.1";
    std::map<std::string, std::string> headers;
    headers["1"] = "header1";
    headers["2"] = "header2";
    std::string body = "this is the body";


    std::cout << "Hello World!" << std::endl;
    HTTPRequest a(method, uri, version, headers, body);
    std::map<std::string, std::string>::iterator it;
    std::map<std::string, std::string> h = a.getHeaders();
    for (it = h.begin(); it != h.end(); ++it)
        std::cout << it->second << std::endl;
    std::cout << a.getMethod() << std::endl;
    std::cout << a.getRequestURI() << std::endl;
    std::cout << a.getHTTPVersion() << std::endl;
    std::cout << a.getBody() << std::endl;


    return (0);
}