#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
	int i;
	struct hostent *host;
	struct in_addr **list;
	char buf[128];
	if((host = gethostbyname(argv[1])) == NULL) {
		herror("gethostbyname");
		return 2;
	}

	list = (struct in_addr **)host->h_addr_list;
	for( i = 0; list[i]; i++)
		/* struct in_addr 很重要
		 * 给inet_ntop()传递的是指向in_addr 的指针
		 * 而给inet_ntoa()传递的是in_addr 的实例*/
		printf("%s\n",inet_ntop(AF_INET,list[i],buf,sizeof(buf) ));
	return 0;
}
