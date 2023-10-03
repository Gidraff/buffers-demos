#!/usr/sbin/dtrace -s

io:::start
{
    printf("I/O operation started\n");
}

vfs:::lookup
{
    printf("File lookup\n");
}

ip:::send
{
    printf("IP packet sent\n");
}
