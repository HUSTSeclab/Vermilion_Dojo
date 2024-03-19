#include <stdio.h>
#include <stdlib.h>

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level4.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly overflow the return address to read flag\n");
}

void read_flag()
{
	char flag[100];
	FILE *file;

	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		exit(-1);
	}

	while (fgets(flag, sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);
}

int main()
{
	short a = 0x1234;
	long unused_int = 0xdeadbeef;
	char buffer[0x13];
        
        init();

	print_desc();

        puts("Give me your input");
	
	scanf("%s", buffer); // vulnerable scanf
        
	puts("Bye bye~");

	return 0;
}