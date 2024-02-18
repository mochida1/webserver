

#include "test_main.hpp"

TEST(GtestTest, SimpleAssertion) {
	int a = 5;
	EXPECT_EQ(a, 5);
}


/*
	-------------------------------------------------------------------
	*******************  ArgumentsValidator  **************************
	-------------------------------------------------------------------
*/

TEST(ArgumentValidator, noFile_EARG_NOARGS){
	int argc = 1;

	char *arg0 = (char *)("./gtest_websev");
	char *argv[argc + 1] = {arg0, NULL};

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e)
	{
		const char *expected = EARG_NOARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		return ;
	}
	//fails
	EXPECT_EQ(0,1);
	
}

TEST(ArgumentValidator, avEARG_TOOMANYARGS){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	bool hasThrownException = false;

	for (int i = 2; i < 51; i++){
		try {
			ArgumentValidator::validateArguments(i, argv);
		}
		catch(const std::exception& e){
			const char *expected = EARG_TOOMANYARGS;
			
			EXPECT_EQ( (i > CONSTRAINT_ARGC_MAX_VALUE), 1);
			EXPECT_EQ(std::strcmp(expected, e.what()), 0);
			hasThrownException = true;
		}
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, wrongFileExt){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.meme");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, wrongArgumentFlags){
	int argc = 3;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-p");
	char *argv[argc + 1] = {arg0, arg1, arg2, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, wrongArgumentFlags2){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-d");
	char *arg3 = (char *)("-error");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, wrongArgumentFlags3){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-d");
	char *arg3 = (char *)("--logLevel=-1");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, wrongArgumentFlags4){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-d");
	char *arg3 = (char *)("--logLevel=4");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, wrongArgumentFlags5){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("--logLevel=4");
	char *arg3 = (char *)("-d");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, rightArgumentFlags){
	int argc = 3;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-d");
	char *argv[argc + 1] = {arg0, arg1, arg2, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = "NOT EXPECTED!!!";
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}

TEST(ArgumentValidator, rightArgumentFlags2){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-d");
	char *arg3 = (char *)("--logLevel=0");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = "NOT EXPECTED!!!";
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}

TEST(ArgumentValidator, rightArgumentFlags3){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("-d");
	char *arg3 = (char *)("--logLevel=3");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = "NOT EXPECTED!!!";
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}

TEST(ArgumentValidator, rightArgumentFlags4){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *arg2 = (char *)("--logLevel=3");
	char *arg3 = (char *)("-d");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = "NOT EXPECTED!!!";
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}

TEST(ArgumentValidator, rightArgumentFlags5){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("--logLevel=3");
	char *arg2 = (char *)("conf/mock.conf");
	char *arg3 = (char *)("-d");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = "NOT EXPECTED!!!";
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}

TEST(ArgumentValidator, doubleConf){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("--logLevel=3");
	char *arg2 = (char *)("conf/mock.conf");
	char *arg3 = (char *)("conf/default.conf");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_DOUBLECONF;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, doubleFlag){
	int argc = 4;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("--logLevel=3");
	char *arg2 = (char *)("conf/mock.conf");
	char *arg3 = (char *)("--logLevel=3");
	char *argv[argc + 1] = {arg0, arg1, arg2, arg3, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		const char *expected = EARG_WRONGARGS;
		
		EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, onlyFileNotExists){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/lolollolmock.conf");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, onlyFileNoPerm){
	uid_t uid = getuid(); // Get real user ID of the current process
	struct passwd* pwd = getpwuid(uid); // Retrieve user information

	if (pwd != nullptr) {
		std::string userID(pwd->pw_name);
		if (userID.compare("root") == 0) //checks wheter the user is root. If so, will always be able to access the W/R locked file.
			return;
	}
	else {
		std::cerr << "Failed to get user information." << std::endl;
		EXPECT_STREQ("THIS IS", "fucked up"); // fails gloriously
	}

	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/000perms.conf");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, true);
}

TEST(ArgumentValidator, onlyFile){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}

/*
	-------------------------------------------------------------------
	**********************  ConfigsLoader  ****************************
	-------------------------------------------------------------------
*/

// Makes sure ConfigsLoader can be constructed
TEST(ConfigsLoader, Constructor01){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/ConfigsLoader.conf");
	char *argv[argc + 1] = {arg0, arg1, NULL};
	extern char **environ;
	bool hasThrownException = false;
	try {
		ConfigsLoader tempInstance(argc, argv, environ);
	}
	catch(const std::exception& e){
		hasThrownException = true;
	}
	ConfigsLoader instance(argc, argv, environ);
	EXPECT_EQ(hasThrownException, false);
	EXPECT_STREQ(instance.getPathToFile().c_str(), arg1);

	const std::vector<std::string> configsVector = instance.getConfigsVector();

	EXPECT_STREQ(configsVector[0].c_str(), "first line");
	EXPECT_STREQ(configsVector[1].c_str(), "second line");
	EXPECT_STREQ(configsVector[2].c_str(), "third line");
}


/*
	-------------------------------------------------------------------
	***********************  DEATHTESTS  *****************************
	-------------------------------------------------------------------
*/
