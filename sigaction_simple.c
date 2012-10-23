#include <stdio.h>
#include <signal.h>
#include <string.h> /* memset() */

struct sigaction osa;

void bypass_sigint(int sig_no) {
	printf("I tap SIGINT and returns back\n");

	/* reset sigaction handler */
	sigaction(SIGINT, &osa, NULL);
	
	/* 因为pid是0， 所以SIGINT会被送到所有那些
	 * group id 与sender 的group id 相同的进程 
	 * 若没有kill，则程序一直执行下去*/
	kill(0, SIGINT);
}

int main(void) {
	
	struct sigaction sa, osa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &bypass_sigint;
	sigaction(SIGINT, &sa, &osa);

	while(1) {
		sleep(1);
		printf("do nothing\n");
	}
	return 0;
}
