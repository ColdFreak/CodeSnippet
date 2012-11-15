/* 使用inet_ntoa(struct in_addr in)
 * 来转换二进制地址至字符串(192.168.1.1)*/
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
	int i;
	struct hostent *host;
	struct in_addr **list;
	if((host = gethostbyname(argv[1])) == NULL) {
		herror("gethostbyname");
		return 2;
	}

	/* 把hostent中的h_addr_list 强制转换为(struct in_addr **)
	 * 再用inet_ntoa(struct in_addr in)很重要  */
	list = (struct in_addr **)host->h_addr_list;
	for( i = 0; list[i]; i++)
		printf("%s\n",inet_ntoa(*list[i] ));
	return 0;
}
