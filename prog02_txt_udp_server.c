//----------------------------------------------------------------------------

#include "crsUtils.h"

int main(int argc, char **argv){
  //---- check command line arguments ----
  if(argc!=2){
    fprintf(stderr,"usage: %s port\n",argv[0]);
    exit(1);
  }

  //---- extract local port number ----
  int portNumber;
  if(sscanf(argv[1],"%d",&portNumber)!=1){
    fprintf(stderr,"invalid port %s\n",argv[1]);
    exit(1);
  }

  //---- create UDP socket ----

  // ... À COMPLÉTER ...
  int udpSocket=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in myAddr;
  myAddr.sin_family=AF_INET;
  myAddr.sin_port=htons(portNumber);
  myAddr.sin_addr.s_addr=htonl(INADDR_ANY);
  bind(udpSocket,(struct sockaddr *)&myAddr,sizeof(myAddr));

  for(;;){
    //---- receive request ----
    char request[0x100];
    (void)request; // avoid ``unused variable'' warning

    // ... À COMPLÉTER ...
    struct sockaddr_in fromAddr;
    socklen_t len=sizeof(fromAddr);
    int nb=recvfrom(udpSocket,request,sizeof(request),0,(struct sockaddr_in *)&fromAddr,&len);

    //---- display request and source address/port ----

    // ... À COMPLÉTER ...
    request[nb]='\0';
    printf("from %s:%d : %s\n",inet_ntoa(fromAddr.sin_addr),ntohs(fromAddr.sin_port),request);

    //---- send reply to client ----
    char reply[0x100];
    (void)reply; // avoid ``unused variable'' warning

    sprintf(reply,"%d bytes received",nb);

    // ... À COMPLÉTER ...
    sendto(udpSocket,reply,strlen(reply),0,(struct sockaddr_in*)&fromAddr,sizeof(fromAddr));

  }

  //---- close UDP socket ----

  // ... À COMPLÉTER ...
  close(udpSocket);

  return 0;

}

//----------------------------------------------------------------------------
