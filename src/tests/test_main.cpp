

#include "test_main.hpp"

TEST(GtestTest, SimpleAssertion) {
    int a = 5;
    EXPECT_EQ(a, 5);
}

TEST(ArgumentValidator, noFile_EARG_NOARGS){
	int argc = 1;

	char *arg0 = (char *)("./gtest_websev");
	char *argv[2] = {arg0, NULL};

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
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *argv[3] = {arg0, arg1, NULL};
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
	char *argv[3] = {arg0, arg1, NULL};
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
	char *argv[4] = {arg0, arg1, arg2, NULL};
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
	char *argv[5] = {arg0, arg1, arg2, arg3, NULL};
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
	char *argv[4] = {arg0, arg1, arg2, NULL};
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

TEST(ArgumentValidator, onlyFile){
	int argc = 2;
	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *argv[3] = {arg0, arg1, NULL};
	bool hasThrownException = false;

	try {
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		hasThrownException = true;
	}
	EXPECT_EQ(hasThrownException, false);
}


// Makes sure ConfigsLoader can be constructed
TEST(ConfigsLoader, defaultConstructor){
	ConfigsLoader instance;
}