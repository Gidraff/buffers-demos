#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hacking.h"

void pcap_fatal(const char *failed_in, const char *errbuf)
{
    printf("Fatal error in %s: %s\n", failed_in, errbuf);
    exit(1);
}

int main()
{
    struct pcap_pkthdr header;
    const u_char *packet;
    char errbuff[PCAP_ERRBUF_SIZE];
    char *device;
    pcap_t *pcap_handle;
    int i;

    device = pcap_lookupdev(errbuff);
    if (device == NULL)
    {
        pcap_fatal("pcap_lookupdev", errbuff);
    }
    printf("Sniffing on device %s\n", device);

    pcap_handle = pcap_open_live(device, 4096, 1, 0, errbuff);
    if (pcap_handle == NULL)
    {
        pcap_fatal("pcap_open_live", errbuff);
    }

    for (i = 0; i < 3; i++)
    {
        packet = pcap_next(pcap_handle, &header);
        printf("Go a %d byte packet\n", header.len);
        dump(packet, header.len);
    }
    pcap_close(pcap_handle);
}
