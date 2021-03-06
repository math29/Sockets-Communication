//----------------------------------------------------------------------------

#include "crsUtils.h"

int main(int argc, char **argv){
  //---- check command line arguments ----
  if(argc!=3){
    fprintf(stderr,"usage: %s destination port\n",argv[0]);
    exit(1);
  }

  //---- extract destination IP address ----

  // ... À COMPLÉTER ...
  struct hostent *host=gethostbyname(argv[1]);
  in_addr_t ipAddress=*((in_addr_t *)(host->h_addr));

  //---- extract destination port number ----
  int portNumber;
  if(sscanf(argv[2],"%d",&portNumber)!=1){
    fprintf(stderr,"invalid port %s\n",argv[2]);
    exit(1);
  }

  //---- create client socket ----

  // ... À COMPLÉTER ...
  int clientSocket=socket(AF_INET,SOCK_STREAM,0);

  for(;;){
    //---- read next line on standard input ----
  char msg[0x100];
  if(!fgets(msg,0x100,stdin)) {
    break;
  } // [Control]+[d] --> EOF

  //---- send message to server ----

  // ... À COMPLÉTER ...
  struct sockaddr_in toAddr;
  toAddr.sin_family=AF_INET;
  toAddr.sin_port=htons(portNumber);
  toAddr.sin_addr.s_addr=ipAddress;
  int etat = connect(clientSocket,(struct sockaddr *)&toAddr,sizeof(toAddr));
  if (etat == -1){
    printf("ERROR : connection impossible");
  }

  //---- receive and display reply ----
  char reply[0x100];
  (void)reply; // avoid ``unused variable'' warning

  // ... À COMPLÉTER ...
  int r;
  r = send(clientSocket,msg,strlen(msg),0);

  r = recv(clientSocket,reply,strlen(reply),0);

  }

//---- close client socket ----

// ... À COMPLÉTER ...
close(clientSocket);

return 0;
}

//----------------------------------------------------------------------------
