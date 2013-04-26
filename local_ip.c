#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>

//struct pcap_if {
// 	  struct pcap_if *next;
//	  char *name;		/* name to hand to "pcap_open_live()" */
//	  char *description;	/* textual description of interface, or NULL */
//	  struct pcap_addr *addresses;
//	  bpf_u_int32 flags;	/* PCAP_IF_ interface flags */
//};

//struct pcap_addr {
//    struct pcap_addr *next;
//    struct sockaddr *addr;		/* address */
//	  struct sockaddr *netmask;	/* netmask for that address */
//	  struct sockaddr *broadaddr;	/* broadcast address for that address */
//	  struct sockaddr *dstaddr;	/* P2P destination address for that address */
//};

// char *inet_ntoa(struct in_addr in);
static char errbuf[PCAP_ERRBUF_SIZE];
void *get_local_ip(char *buffer);
int main() {
	char buffer[20];
	get_local_ip(buffer);
//	pcap_freealldevs(alldevs);
	printf("%s\n",buffer);
	return 0;
}

void *get_local_ip(char *buf) {

	pcap_if_t *alldevs;
	pcap_if_t *d;
	pcap_addr_t *a;

	int status = pcap_findalldevs(&alldevs, errbuf);
	if(status != 0) {
		printf("%s\n",errbuf);
		return NULL;
	}
	for(d = alldevs; d != NULL; d= d->next) {
		for(a = d->addresses; a!= NULL; a = a->next) {
			if(a->addr->sa_family == AF_INET)  {
				strcpy(buf, inet_ntoa(((struct sockaddr_in*)a->addr)->sin_addr));
				return;
			}
		}
	}
}
