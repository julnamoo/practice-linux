#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXCONNECTION 5
#define BUFSIZE 256

static void session_with_client(int);


int main(int argc, char* argv[]) {
  int ssid, csid;
  struct sockaddr_in s_addr, c_addr;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s PORT\n", argv[0]);
  }

  /* create sockets and prepare data */
  if ((ssid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  memset(&s_addr, 0, sizeof(s_addr));
  s_addr.sin_family = AF_INET;
  s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  s_addr.sin_port = htons(atoi(argv[1]));

  /* assign port and receive a connectio */
  if (bind(ssid, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0) {
    perror("Binding socket failed");
    exit(1);
  }

  if (listen(ssid, MAXCONNECTION) < 0) {
    perror("Listening server socket failed");
    exit(1);
  }

  /* Session with client */
  while(1) {
    unsigned int len = sizeof(c_addr);

    /* ready the connection from client */
    if ((csid = accept(ssid, (struct sockaddr *) &c_addr, &len)) < 0) {
      perror("Client connection failed");
      exit(1);
    }
    printf("Client connected: %s\n", inet_ntoa(c_addr.sin_addr));

    session_with_client(csid);
  }
}

void session_with_client(int sid) {
  char buffer[BUFSIZE];
  int received = -1;

  do {
    if ((received = recv(sid, buffer, BUFSIZE, 0)) < 0) {
      perror("Error in receiving message from client");
      exit(1);
    }
    if (send(sid, buffer, received, 0) != received) {
      perror("Error in sending message to client");
      exit(1);
    }
  }while(received > 0);

  close(sid);
}
