#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

void fatal(int listener)
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    close(listener);
    exit(1);
}

int main(int ac, char **av)
{

    if (ac != 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }

    int listener;
    fd_set master;
    fd_set read;
    int port = atoi(av[1]);
    struct sockaddr_in servaddr;
    struct sockaddr_in claddr;
    int client[16384];
    int fdmax;
    int cl_iter = 0;
    int nbytes = 0;
    char msg[4096];
    char buf[4096];
    char tmp[4096];

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = 127 | (1 << 24);
    servaddr.sin_port = port >> 8 | port << 8;

    if ((listener = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        fatal(listener);
    if (bind(listener, (const struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        fatal(listener);
    if (listen(listener, 0) < 0)
        fatal(listener);

    FD_ZERO(&master);
    FD_ZERO(&read);
    FD_SET(listener, &master);
    fdmax = listener;

    for(;;)
    {
        read = master;
        if (select(fdmax + 1, &read, NULL, NULL, NULL) == -1)
            fatal(listener);
        for (int i = 0 ; i <= fdmax ; i++)
        {
            if (FD_ISSET(i, &read))
            {
                if (i == listener)
                {
                    int newfd = 0;
                    unsigned int len = sizeof(claddr);
                    if ((newfd = accept(listener, (struct sockaddr *)&claddr, &len)) == -1)
                        fatal(listener);
                    if (newfd > fdmax)
                        fdmax = newfd;
                    FD_SET(newfd, &master);
                    client[newfd] = cl_iter;
                    bzero(&msg, 4096);
                    sprintf(msg, "server: client %d has just arrived\n", cl_iter);
                    for (int j = 0 ; j < fdmax + 1 ; j++)
                    {
                        if (FD_ISSET(j, &master) && j != i && j != newfd)
                        {
                            if (send(j, msg, strlen(msg), 0) < 0)
                                fatal(listener);
                        }
                    }
                    cl_iter++;
                    break ;
                }
                else
                {
                    if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0)
                    {
                        bzero(&msg, 4096);
                        sprintf(msg, "server: client %d just left\n", client[i]);
                        for (int j = 0 ; j < fdmax + 1 ; j++)
                        {
                            if (FD_ISSET(j, &master) && j != i && j != listener)
                            {
                                if (send(j, msg, strlen(msg), 0) < 0)
                                    fatal(listener);
                            }
                        }
                        FD_CLR(i, &master);
                        close(i);
                    }
                    else
                    {
                        int k = 0;
                        int l = 0;
                        while (buf[l])
                        {
                            tmp[k] = buf[l];
                            if (buf[l] == '\n')
                            {
                                bzero(&msg, 4096);
                                sprintf(msg, "client %d: %s", client[i], tmp);
                                for (int j = 0 ; j < fdmax + 1 ; j++)
                                {
                                    if (FD_ISSET(j, &master) && j != i && j != listener)
                                    {
                                        if (send(j, msg, strlen(msg), 0) < 0)
                                            fatal(listener);
                                    }
                                }
                                k = 0;
                                bzero(&tmp, 4096);
                                bzero(&msg, 4096);
                            }
                            k++;
                            l++;
                        }
                        bzero(&buf, 4096);
                    }
                }
            }
        }
    }
    return 0;
}