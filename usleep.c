#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("Hello world before sleep.");
	/* 因为上面的printf没有'\n',所以要用上fflush
	 * 如果有'\n'了，则下面的fflush()就不必要了*/
	fflush(stdout);
	usleep(2000000);
	printf("hello world after sleep.\n");
	return 0;
}
