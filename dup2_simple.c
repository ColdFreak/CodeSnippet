#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void test_func() {
	/* this line of content will be redirected to file */
	puts("Hello, world");
}

void forkfunc(int fd) {
	int pid = fork();
	if(pid == 0) {
		dup2(fd,1);
		test_func();
		return;
	}
	else
		return;
}
int main(void) {
	FILE *test = fopen("tmp.txt", "w+");
	int fd = fileno(test);
	forkfunc(fd);
	test_func();
	return 0;
}

