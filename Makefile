

NAME = webserv
NAME_TEST = gtest_webserv
MAKEFLAGS = --no-print-directory
BUILDDIR = objs
TEST_BUILDDIR = test_objs
VPATH = src src/tests

# headers
INCLUDES = -I ./headers
LDFLAGS = -pthread
TEST_LDFLAGS = -lgtest -lgtest_main 

# Lists sources. Manually because of norm...
MAIN = main.cpp
SRC = Webserv.cpp Server.cpp ConfigsLoader.cpp ArgumentValidator.cpp
TEST_MAIN = test_main.cpp

# Names sources
SOURCES = $(MAIN)
SOURCES += $(SRC)

TEST_SOURCES = $(TEST_MAIN)
TEST_SOURCES += $(SRC)

# Names objects
OBJS = $(addprefix $(BUILDDIR)/, $(SOURCES:%.cpp=%.o))
TEST_OBJS = $(addprefix $(TEST_BUILDDIR)/, $(TEST_SOURCES:%.cpp=%.o))

# Configuration
PWD = $(shell pwd)
CONF = conf/default.conf

# Compiler
CC = c++
CF = -Wall -Wextra -Werror -std=c++98
TEST_CF = -Wall -Wextra -Werror
GDB = -ggdb
GO = ./$(NAME) "$(PWD)/$(CONF)"
VAL = valgrind --trace-children=no --leak-check=full --track-origins=yes $(GO)

$(NAME): $(BUILDDIR) $(OBJS)
	@printf "Compiling $(NAME)\n"
	@$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)
	@printf "Done!\n"

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.cpp
	@$(CC) $(CF) $(GDB) $(INCLUDES) $(LDFLAGS) -c $< -o $@

##TESTS
$(NAME_TEST): $(TEST_BUILDDIR) $(TEST_OBJS)
	@printf "Compiling test files...\n"
	@$(CC) $(TEST_CF) $(TEST_OBJS) $(INCLUDES) $(LDFLAGS) $(TEST_LDFLAGS) -o $(NAME_TEST)

$(TEST_BUILDDIR):
	@mkdir -p $(TEST_BUILDDIR)
	
$(TEST_BUILDDIR)/%.o: %.cpp
	@$(CC) $(TEST_CF) $(GDB) $(INCLUDES) -c $< -o $@



all: $(NAME)

test: cls $(NAME_TEST) $(NAME)
	@echo "--------- Running tests ----------"
	@./tools/runtests.sh

cls:
	@clear

docker:
	sudo ./tools/add_nameservers.sh
	sudo docker volume create --name webserv_vol --opt type=none --opt device=$(PWD) --opt o=bind
	sudo docker-compose up -d
	sudo docker exec -it webserv bash

docker_clean:
	sudo docker-compose down
	sudo docker volume rm webserv_vol
	sudo docker system prune -af

pwd:
	echo -e $(PWD)
	sudo docker volume create --name webserv_vol --opt type=none --opt device=$(PWD) --opt o=bind
	sudo docker volume inspect webserv_vol
	sudo docker volume rm webserv_vol

clean:
	@rm -rf $(BUILDDIR)
	@rm -rf $(TEST_BUILDDIR)
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_TEST)
	@rm -f vgcore*

re: fclean all

# from here on shit ain't mandatory or bonus
run: 
	@sudo ./tools/add_nameservers.sh
	@if [ $$(docker ps -q -f name=webserv) ]; then \
        sudo docker-compose up -d; \
    elif [ $$(docker images -q webserv) ]; then \
        sudo docker-compose up -d; \
    else \
		sudo docker volume create --name webserv_vol --opt type=none --opt device=$(PWD) --opt o=bind && \
		sudo docker-compose up -d; \
    fi
	sudo docker exec -it webserv bash

go: all
	$(GO)

fs: $(NAME_FS)
	./$(NAME_FS)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run docker docker_clean
