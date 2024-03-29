

#include "test_main.hpp"

// TEST(GtestTest, SimpleAssertion) {
// 	int a = 5;
// 	EXPECT_EQ(a, 5);
// }


// /*
// 	-------------------------------------------------------------------
// 	*******************  ArgumentsValidator  **************************
// 	-------------------------------------------------------------------
// */

// TEST(ArgumentValidator, noFile_EARG_NOARGS){
// 	int argc = 1;

// 	char *arg0 = (char *)("./gtest_websev");
// 	char *argv[argc + 1] = {arg0, NULL};

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		const char *expected = EARG_NOARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		return ;
// 	}
// 	//fails
// 	EXPECT_EQ(0,1);
	
// }

// TEST(ArgumentValidator, avEARG_TOOMANYARGS){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	bool hasThrownException = false;

// 	for (int i = 2; i < 51; i++){
// 		try {
// 			ArgumentValidator::validateArguments(i, argv);
// 		}
// 		catch(const std::exception& e){
// 			const char *expected = EARG_TOOMANYARGS;
			
// 			EXPECT_EQ( (i > CONSTRAINT_ARGC_MAX_VALUE), 1);
// 			EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 			hasThrownException = true;
// 		}
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, wrongFileExt){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.meme");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, wrongArgumentFlags){
// 	int argc = 3;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-p");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, wrongArgumentFlags2){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-d");
// 	char *arg3 = (char *)("-error");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, wrongArgumentFlags3){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-d");
// 	char *arg3 = (char *)("--logLevel=-1");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, wrongArgumentFlags4){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-d");
// 	char *arg3 = (char *)("--logLevel=4");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, wrongArgumentFlags5){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("--logLevel=4");
// 	char *arg3 = (char *)("-d");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, rightArgumentFlags){
// 	int argc = 3;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-d");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = "NOT EXPECTED!!!";
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
// }

// TEST(ArgumentValidator, rightArgumentFlags2){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-d");
// 	char *arg3 = (char *)("--logLevel=0");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = "NOT EXPECTED!!!";
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
// }

// TEST(ArgumentValidator, rightArgumentFlags3){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("-d");
// 	char *arg3 = (char *)("--logLevel=3");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = "NOT EXPECTED!!!";
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
// }

// TEST(ArgumentValidator, rightArgumentFlags4){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *arg2 = (char *)("--logLevel=3");
// 	char *arg3 = (char *)("-d");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = "NOT EXPECTED!!!";
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
// }

// TEST(ArgumentValidator, rightArgumentFlags5){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("--logLevel=3");
// 	char *arg2 = (char *)("conf/mock.conf");
// 	char *arg3 = (char *)("-d");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = "NOT EXPECTED!!!";
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
// }

// TEST(ArgumentValidator, doubleConf){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("--logLevel=3");
// 	char *arg2 = (char *)("conf/mock.conf");
// 	char *arg3 = (char *)("conf/default.conf");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_DOUBLECONF;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, doubleFlag){
// 	int argc = 4;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("--logLevel=3");
// 	char *arg2 = (char *)("conf/mock.conf");
// 	char *arg3 = (char *)("--logLevel=3");
// 	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		const char *expected = EARG_WRONGARGS;
		
// 		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, onlyFileNotExists){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/lolollolmock.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, onlyFileNoPerm){
// 	uid_t uid = getuid(); // Get real user ID of the current process
// 	struct passwd* pwd = getpwuid(uid); // Retrieve user information

// 	if (pwd != nullptr) {
// 		std::string userID(pwd->pw_name);
// 		if (userID.compare("root") == 0) //checks wheter the user is root. If so, will always be able to access the W/R locked file.
// 			return;
// 	}
// 	else {
// 		std::cerr << "Failed to get user information." << std::endl;
// 		EXPECT_STREQ("THIS IS", "fucked up"); // fails gloriously
// 	}

// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/000perms.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ArgumentValidator, onlyFile){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	bool hasThrownException = false;

// 	try {
// 		ArgumentValidator::validateArguments(argc, argv);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
// }

// /*
// 	-------------------------------------------------------------------
// 	**********************  ConfigsLoader  ****************************
// 	-------------------------------------------------------------------
// */

// // Makes sure ConfigsLoader can be constructed
// TEST(ConfigsLoader, Constructor01){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/ConfigsLoader.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	extern char **environ;
// 	bool hasThrownException = false;
// 	try { // tests if default constructor is working as it should.
// 		ConfigsLoader tempInstance(argc, argv, environ);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	ConfigsLoader instance(argc, argv, environ);
// 	EXPECT_EQ(hasThrownException, false);
// 	EXPECT_STREQ(instance.getPathToFile().c_str(), arg1);

// 	{ // tests reading from file
// 		const std::vector<std::string> configsVector = instance.getConfigsVector();
// 		int i = 0;
// 		EXPECT_STREQ(configsVector[i++].c_str(), "first line");
// 		EXPECT_STREQ(configsVector[i++].c_str(), "second line");
// 		EXPECT_STREQ(configsVector[i++].c_str(), "third line");
// 		EXPECT_STREQ(configsVector[i++].c_str(), "$TEST_ENV01 ${TEST_ENV02}");
// 		EXPECT_STREQ(configsVector[i++].c_str(), "${TEST_ENV03} $TEST_ENV04");
// 		EXPECT_STREQ(configsVector[i++].c_str(), "# comment");
// 		EXPECT_STREQ(configsVector[i++].c_str(), "last line # comment to remove");
// 	}

// 	{ // tests reading from envs
// 		const std::map<std::string, std::string> envs = instance.getEnvsMap();
// 		EXPECT_STREQ(envs.find("TEST_ENV01")->second.c_str(), "env01");
// 		EXPECT_STREQ(envs.find("TEST_ENV02")->second.c_str(), "env02");
// 	}

// 	{
// 		std::vector<std::string> expandedConfigs = instance.getExpandedConfigs();
// 		int i = 0;
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "first line");
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "second line");
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "third line");
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "env01 env02");
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "env03 env04");
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "# comment");
// 		EXPECT_STREQ(expandedConfigs[i++].c_str(), "last line # comment to remove");
// 	}
// }

// TEST(ConfigsLoader, Constructor02){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/ConfigsLoaderThrowExcept.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	extern char **environ;
// 	bool hasThrownException = false;
// 	try { // tests if default constructor is working as it should. Should throw when parsing config file
// 		ConfigsLoader tempInstance(argc, argv, environ);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, true);
// }

// TEST(ConfigsLoader, Constructor03){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/ConfigsLoaderComments.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	extern char **environ;
// 	bool hasThrownException = false;
// 	try { // tests if default constructor is working as it should. Should throw when parsing config file
// 		ConfigsLoader tempInstance(argc, argv, environ);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);

// 	ConfigsLoader instance(argc, argv, environ);
// 	{
// 		std::vector<std::string> noComments = instance.getNoCommentsConfigs();
// 		int i = 0;
// 		EXPECT_STREQ(noComments[i++].c_str(), "first line");
// 		EXPECT_STREQ(noComments[i++].c_str(), "second line");
// 		EXPECT_STREQ(noComments[i++].c_str(), "third line");
// 		EXPECT_STREQ(noComments[i++].c_str(), "env01 env02");
// 		EXPECT_STREQ(noComments[i++].c_str(), "env03 env04");
// 		EXPECT_STREQ(noComments[i++].c_str(), "last line");
// 	}
// }

// TEST(ConfigsLoader, Constructor04){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/template.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	extern char **environ;
// 	bool hasThrownException = false;
// 	try { // tests if default constructor is working as it should. Should throw when parsing config file
// 		ConfigsLoader tempInstance(argc, argv, environ);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);

// 	ConfigsLoader instance(argc, argv, environ);
// 	{
// 		std::vector<std::string> noComments = instance.getNoCommentsConfigs();
// 		int i = 0;
// 		EXPECT_STREQ(noComments[i++].c_str(), "events {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "http {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location /match/criteria {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location /other/criteria {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location nested_match {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location other_nested {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location /match/criteria {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location /other/criteria {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location nested_match {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location other_nested {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "upstream upstream_name {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server proxy_server1;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server proxy_server2;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 	}
// }

// TEST(ConfigsLoader, Constructor05){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	extern char **environ;
// 	bool hasThrownException = false;
// 	try { // tests if default constructor is working as it should. Should throw when parsing config file
// 		ConfigsLoader tempInstance(argc, argv, environ);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);

// 	std::cerr << "\n_____________TEST________________" << std::endl;
// 	ConfigsLoader instance(argc, argv, environ);
// 	{
// 		std::vector<std::string> noComments = instance.getNoCommentsConfigs();
// 		int i = 0;
// 		EXPECT_STREQ(noComments[i++].c_str(), "user       www www;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "worker_processes  5;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "error_log  logs/error.log;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "pid        logs/nginx.pid;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "worker_rlimit_nofile 8192;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "events {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "worker_connections  4096;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "http {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "include    conf/mime.types;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "include    /etc/nginx/proxy.conf;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "include    /etc/nginx/fastcgi.conf;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "index    index.html index.htm index.php;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "default_type application/octet-stream;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "log_format   main env01 - env02 env03  env04 env05 env06 env07 env08 env09;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "access_log   logs/access.log  main;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "sendfile     on;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "tcp_nopush   on;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server_names_hash_bucket_size 128;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "listen       80;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server_name  domain1.com www.domain1.com;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "access_log   logs/domain1.access.log  main;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "root         html;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location ~ \\.php {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "fastcgi_pass   127.0.0.1:1025;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "listen       80;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server_name  domain2.com www.domain2.com;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "access_log   logs/domain2.access.log  main;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location ~ ^/(images|javascript|js|css|flash|media|static)/  {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "root    /var/www/virtual/big.server.com/htdocs;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "expires 30d;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location / {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "proxy_pass      http://127.0.0.1:8080;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "upstream big_server_com {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server 127.0.0.3:8000 weight=5;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server 127.0.0.3:8001 weight=5;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server 192.168.0.1:8000;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server 192.168.0.1:8001;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "listen          80;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "server_name     big.server.com;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "access_log      logs/big.server.access.log main;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "location / {");
// 		EXPECT_STREQ(noComments[i++].c_str(), "proxy_pass      http://big_server_com;");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 		EXPECT_STREQ(noComments[i++].c_str(), "}");
// 	}
// 	for (auto it : instance.getConfigs().property) {
// 		std::cerr << "[" << it.first << "] Value:[ ";
// 		for (auto entry : it.second)
// 		 	std:: cerr << entry << " | ";
// 		 std::cerr << " ]" << std::endl;
// 	}
// }


// TEST(ConfigsParser, __________){
// 	int argc = 2;
// 	char *arg0 = (char *)("./gtest_websev");
// 	char *arg1 = (char *)("conf/mock.conf");
// 	char *argv[argc + 1] = {arg0, arg1, NULL};
// 	extern char **environ;
// 	bool hasThrownException = false;
// 	try { // tests if default constructor is working as it should. Should throw when parsing config file
// 		ConfigsLoader tempInstance(argc, argv, environ);
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);

// 	ConfigsLoader instance(argc, argv, environ);
// 	DTO_Configs configs = instance.getConfigs();
// 	std::cerr << "---------- " << configs.name << " ----------" << std::endl;
// 	for (size_t it = 0; it < configs.context.size(); it++){
// 		std::cout << "\t" << configs.context[it].name << std::endl;
// 	}

// 	try{
// 		ConfigsParser::parseConfigs(instance.getConfigs());
// 	}
// 	catch(const std::exception& e){
// 		hasThrownException = true;
// 	}
// 	EXPECT_EQ(hasThrownException, false);
	
// }


TEST(Configs, argConstructor){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/ConfigsLoaderTestContexts.conf");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	extern char **environ;
	// bool hasThrownException = false;
	// try { // tests if default constructor is working as it should. Should throw when parsing config file
	// 	Configs configs(argc, argv, environ);
	// }
	// catch(const std::exception& e){
	// 	hasThrownException = true;
	// }
	// EXPECT_EQ(hasThrownException, false);
	
	Configs configs(argc, argv, environ);
	std::cerr << "----------------------------------------" << std::endl;
	configs.printDTO();
}


/*
	-------------------------------------------------------------------
	***********************  DEATHTESTS  *****************************
	-------------------------------------------------------------------
*/

