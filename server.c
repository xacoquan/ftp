/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 21:26:59 by xacoquan          #+#    #+#             */
/*   Updated: 2015/07/07 22:33:36 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void usage(char *str)
{
	printf("conard : %s <port>\n", str);
	exit (-1);
}

int create_server(int port)
{
	int		sock;
	struct protoent *proto;
	struct sockaddr_in sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY); 
	bind(sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen (sock, 42);
	return (sock);
}


int		main(int ac, char **av)
{
	int port;
	int sock;
	int cs;
	unsigned int cslen;
	struct sockaddr_in csin;
	int r;
	char buf[1024];

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port);
	cs = accept(sock, (struct sockaddr*)&csin, &cslen);

	while ((r = read(cs, buf, 1023)) > 0)
	{
		if (r > 0)
		{
			select 
			buf[r] = '\0';
			printf(" jai recu %d, message :%s\n", r, buf); 

		}
	}
	close (cs);
	select_sock(sock);
	close(sock);
	return (0);
}

int select_sock(int sock)
{
	fd_set active_set;
	fd_set read_set;
	int i;

	if (listen(sock, 1) < 0)
		exit (-1);
	FD_ZERO (&active_set);
  	FD_SET (sock, &active_set);
  	While (1)
  	{
  		read_set = active_set;
  		if (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
			exit (-1);
		
  	}

}

