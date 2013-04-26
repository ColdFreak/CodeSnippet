#include <stdio.h>
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
int main() {
	pcap_if_t *alldevs;
	pcap_if_t *d;
	pcap_addr_t *a;

	int status = pcap_findalldevs(&alldevs, errbuf);
	if(status != 0) {
		printf("%s\n",errbuf);
		return 1;
	}
	for(d = alldevs; d != NULL; d= d->next) {
		printf("%s:", d->name);
		for(a = d->addresses; a!= NULL; a = a->next) {
			if(a->addr->sa_family == AF_INET) 
				printf(" %s", inet_ntoa(((struct sockaddr_in*)a->addr)->sin_addr));
		}
		printf("\n");
	}
	pcap_freealldevs(alldevs);
	return 0;
}
