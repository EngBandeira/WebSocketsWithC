#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
int
__bind (unsigned int port, int *socket_fd, struct sockaddr_in *address)
{
    int opt = 1;
    socklen_t addr_len = sizeof (address);
    if ((*socket_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
        {
            perror ("socket init error");
            exit (EXIT_FAILURE);
        }
    if (setsockopt (*socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt)))
        {
            perror ("setsockopt");
            exit (EXIT_FAILURE);
        }
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons (port);
    if (bind (*socket_fd, (struct sockaddr *)address, sizeof (*address)) < 0)
        {
            perror ("bind error");
            exit (EXIT_FAILURE);
        }

    return 0;
}
