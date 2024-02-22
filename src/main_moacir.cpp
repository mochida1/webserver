#include "HTTPRequest.hpp"

HTTPRequest createRequest()
{
    std::string method = "Hello world!";
    std::string uri = "/foo.html";
    std::string version = "1.1";
    std::map<std::string, std::string> headers;
    headers["1"] = "header1";
    headers["2"] = "header2";
    std::string body = "this is the body";
    HTTPRequest a(method, uri, version, headers, body);

    return (a);
}


int main ()
{

    //HTTPRequest a = createRequest();
    // std::cout << "Hello World!" << std::endl;
    // std::map<std::string, std::string>::iterator it;
    // std::map<std::string, std::string> h = a.getHeaders();
    // for (it = h.begin(); it != h.end(); ++it)
    //     std::cout << it->second << std::endl;
    // std::cout << a.getMethod() << std::endl;
    // std::cout << a.getRequestURI() << std::endl;
    // std::cout << a.getHTTPVersion() << std::endl;
    // std::cout << a.getBody() << std::endl;


    // std::string parseThis = "GET / HTTP/1.0\nUser-Agent: Mozilla/3.0 (compatible; Opera/3.0; Windows 95/NT4)\nAccept: */*\nHost: birk105.studby.uio.no:81";
    // HTTPRequest req = parse_request(parseThis);

    std::string parseThis2 = "POST /echo/post/form HTTP/1.1\nHost: reqbin.com\nContent-Type: application/x-www-form-urlencoded\nContent-Length: 23\n\nkey1=value1&key2=value2";
    HTTPRequest req2 = parse_request(parseThis2);

    std::cout << "method = " << req2.getMethod() << std::endl;
    std::cout << "requestURI = " << req2.getRequestURI() << std::endl;
    std::cout << "version = " << req2.getHTTPVersion() << std::endl;
    std::map<std::string, std::string>::iterator it;
    std::map<std::string, std::string> headers = req2.getHeaders();
    for (it = headers.begin(); it != headers.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
    std::cout << "body = " << req2.getBody() << std::endl;
    return (0);
}