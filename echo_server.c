#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

int main(void)
{
  char buff[1024] = { 0 };
  struct addrinfo hints = { 0 };
  struct addrinfo *res = NULL;
  int sock = -1;
  int csock = -1;
  int err;
  struct sockaddr_storage peer;
  socklen_t len;
  int yes;

  hints.ai_flags = AI_PASSIVE;
  hints.ai_socktype = SOCK_STREAM;
  err = getaddrinfo(NULL, "12345", &hints, &res);
  if (err != 0) {
    printf("getaddrinfo: failed: %s\n", gai_strerror(err));
    return 1;
  }

  sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  yes = 1;
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes)) < 0) {
    perror("setsockopt");
    return 1;
  }

  err = bind(sock, res->ai_addr, res->ai_addrlen);
  if (err != 0) {
    perror("bind");
    return 1;
  }

  freeaddrinfo(res);

  listen(sock, 5);

  len = sizeof(peer);
  csock = accept(sock, (struct sockaddr *)&peer, &len);
  if (csock < 0) {
    perror("accept");
    return 1;
  }

  err = recv(csock, buff, sizeof(buff), 0);
  if (csock < 0) {
    perror("recv");
    return 1;
  }

  printf("%.*s\n", err, buff);

  err = send(csock, buff, err, 0);
  if (err < 0) {
    perror("send");
    return 1;
  }

  close(csock);
  close(sock);

  return 0;
}

/* vim: se nu ts=2 sw=2 si et : */
