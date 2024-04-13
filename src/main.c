#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "bind.h"
#include "listen.h"

#define PORT 3001
#define PATH_TO_LISTENER 

int main(int argc, char const *argv[])
{
    struct sockaddr address;
    int *sockets = calloc(1, sizeof(int));
    size_t sockets_lenght = 0; 
    __bind(3001, 1024,&sockets[0],&address);
    int pid  = fork();
    if(pid < 0 )
        exit(EXIT_FAILURE);
    if(pid){
        //father
    }
    else{
        execv();
        //child
    }

    if(!__listen(sockets[0],address))
        exit(EXIT_FAILURE);
    __listen(sockets[0],);
    // if (listen (*socket_fd, 3) < 0)
    //     {
    //         perror ("listen");
    //         exit (EXIT_FAILURE);
    //     }
    // if ((*new_socket_fd = accept (*socket_fd, (struct sockaddr *)&address, &addr_len)) < 0)
    //     {
    //         perror ("accept");
    //         // exit (EXIT_FAILURE);
    //         return -1;
    //     }
    //   char *buffer = (char*)malloc(buffer_lenght*sizeof(char));
    // valread =  read(new_socketfd,buffer, buffer_lenght-1);
    // printf("val read: %d\n", valread);
    // // valread = read (new_socketfd, buffer, BUFFER_LENGHT-1);
    // //printf ("%s ", buffer);
    // int i = 0;
    // for(; i < buffer_lenght; i++){
    //     if(buffer[i] == '\n')
    //         break;
    // }
    // char *hd = (char*)malloc(i*sizeof(char));
    // memcpy(hd,buffer, i + 1);
    // printf("header : %s", hd);
    
    // FILE *fl = fopen("batata.html","r");
    // if(fl==NULL){
    //     printf("file not exist\n");
    //     return -1;
    //     }
    // char bf[1024] = {0};
    // size_t sizehtml = fread(bf, sizeof(char), 1024,fl);
    // printf("f=bff : %s\n",bf);
    // send (new_socketfd, bf, sizehtml, 0);
    // close(fl);
    // close (new_socketfd);
    // close (sockfd);
    // return 0;
}
// #define	__SOCKADDR_COMMON(sa_prefix) \
//   sa_family_t sa_prefix##family