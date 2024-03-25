#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void read_flag()
{
	char flag[100];
	FILE *file;

	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("[-] cannot open\n");
		exit(-1);
	}

	while (fgets(flag, sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);
}

void input_message(char * name) 
{
	char buf[0x100];

	printf("Hello, %s\n", name);
	puts("Say something to me:");
	scanf("%256s*c", buf);
	printf("Copy that, %s\n", buf);
	puts("Bye bye~");
}

void read_input()
{
	char name[0x20];
	
	puts("Give me your name:");
	read(0, name, 0x20);
        input_message(name);
}

void play()
{
	read_input();
}

int main()
{
	init();
        
	print_desc();

	play();

	print_exit();

	return 0;
}
