#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int
__listen (int socket_fd, struct sockaddr address)
{
    socklen_t addr_len = sizeof (address);
    int new_socket_fd = 0;
    if (listen (socket_fd, 3) < 0)
        {
            perror ("listen");
            return -1;
        }
    if ((new_socket_fd
         = accept (socket_fd, &address, &(addr_len)))
        < 0)
        {
            perror ("accept");
            return -1;
        }
    return new_socket_fd;
}