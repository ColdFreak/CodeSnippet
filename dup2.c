#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void test_func(void) {
	printf("hello, world\n");
}

int main(void) {
	FILE *test = fopen("tmp.txt", "w");

	/*用dup()复制一个stdout，一会儿在18行把它弄回来
	 * 这就意味着我们不须要fork()了*/
	int fd = fileno(test), copy = dup(1);
	/*这时copy的值很可能为4*/

	dup2(fd, 1);
	/*内容输入到文件*/
	test_func();
	/*如果没有fflush()，内容会存储在buffer中
	 * 随第二个test_func()一起打印到屏幕上*/
	fflush(stdout);
	dup2(copy,1);
	test_func();
	return 0;
}
