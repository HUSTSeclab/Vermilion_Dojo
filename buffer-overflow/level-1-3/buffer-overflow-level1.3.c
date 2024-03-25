#include <stdio.h>
#include <stdlib.h>
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
	exit(0);
}

void round1()
{
	char buffer[0x10];

	puts("Give me your input");
	scanf("%s", buffer);
}

void play()
{
	round1();
}

int main()
{
        init();

	print_desc();
        play();
	print_exit();

	return 0;
}