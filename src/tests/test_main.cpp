

#include "test_main.hpp"

TEST(GtestTest, SimpleAssertion) {
    int a = 5;
    EXPECT_EQ(a, 5);
}

// Makes sure ConfigsLoader can be constructed
TEST(ConfigsLoader, defaultConstructor){
	ConfigsLoader instance;
}

TEST(ConfigsLoader, argumentConstructor_noFile_EARG_NOARGS){
	extern char **environ;
	int argc = 1;

	char *arg0 = (char *)("./gtest_websev");
	char *argv[1] = {arg0};
	char **envp = environ;

	try {
		ConfigsLoader configs(argc, argv, envp);
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

TEST(ConfigsLoader, argumentConstructor_EARG_TOOMANYARGS){
	extern char **environ;

	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *argv[2] = {arg0, arg1};
	char **envp = environ;
	
	for (int i = 2; i < 51; i++){
		try {
			ConfigsLoader configs(i, argv, envp);
		}
		catch(const std::exception& e){
			const char *expected = EARG_TOOMANYARGS;
			
			EXPECT_EQ( (i > CONSTRAINT_ARGC_MAX_VALUE), 1);
			EXPECT_EQ(std::strcmp(expected, e.what()), 0);
		}
	}
}

TEST(ConfigsLoader, argumentConstructor_onlyFile){
	extern char **environ;
	int argc = 2;

	char *arg0 = (char *)("./gtest_websev");
	char *arg1 = (char *)("conf/mock.conf");
	char *argv[2] = {arg0, arg1};
	char **envp = environ;

	ConfigsLoader configs(argc, argv, envp);
}
