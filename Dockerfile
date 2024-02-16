FROM	debian:oldstable

RUN		apt update && apt upgrade -y

RUN		apt install -y \
		build-essential \
		libgtest-dev \
		cmake

RUN		cd /usr/src/gtest &&\
		cmake CMakeLists.txt &&\
		make &&\
		cd lib &&\
		cp *.a /usr/lib

EXPOSE	80:80

RUN		mkdir /webserv

WORKDIR /webserv

CMD ["/bin/bash"]