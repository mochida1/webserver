#!/bin/bash

if [ $$(sudo docker ps -q -f name=webserv) ]; then \
        sudo docker exec -it webserv /bin/bash; \
    elif [ $$(sudo docker images -q webserv) ]; then \
        sudo docker run -it webserv bash; \
    else \
        sudo ./tools/add_nameservers.sh && \
		sudo docker volume create --name webserv_vol --opt type=none --opt device=$(PWD) --opt o=bind && \
		sudo docker-compose up -d && \
		sudo docker exec -it webserv bash; \
    fi