#ifndef BIND_H
#define BIND_H

int __bind(unsigned int port, unsigned int buffer_lenght, int *socket_fd, struct sockaddr_in *address);

#endif
