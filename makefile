all: user process

user: user.c
	gcc -o user user.c

process: process.c
	gcc -o process process.c
