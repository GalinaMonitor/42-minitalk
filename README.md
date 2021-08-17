# Minitalk

## Making a server and client programmes
Made a connection between server and client using signal.h. Works with multiple clients. Client sends strings and supports ack.

[minitalk_subject.pdf](https://github.com/GalinaMonitor/minitalk/files/7003485/minitalk_subject.pdf)


## Usage:
How to make server and client

	make
	./server
	My pid is ***
	Waiting...
In the another terminal you have to launch client

	./client *** 'your message'

There are additional commands for make

	make clean // clean all .o and .d files in ./libft
	make fclean // clean server, client, libft.a, all .o and .d files

![Screenshot_2021-08-17_19-21-20](https://user-images.githubusercontent.com/82672680/129813098-0d4480c2-97c4-40be-ab7a-55df6dcf7c46.png)
