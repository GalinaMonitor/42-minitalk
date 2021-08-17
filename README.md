# Minitalk

## Making a server and client programmes
Made a connection between server and client using signal.h. Works with multiple clients. Client sends strings and supports ack.

[libft_subject.pdf](https://github.com/GalinaMonitor/libft/files/6797738/libft_subject.pdf)

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
