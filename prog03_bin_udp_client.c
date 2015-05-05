//----------------------------------------------------------------------------

#include "crsUtils.h"

int main(int argc,char **argv){
//---- check command line arguments ----
  if(argc!=3)
    { fprintf(stderr,"usage: %s destination port\n",argv[0]); exit(1); }

//---- extract destination IP address ----

// ... À COMPLÉTER ...

  struct hostent *host=gethostbyname(argv[1]);
  in_addr_t ipAddress=*((in_addr_t *)(host->h_addr));

//---- extract destination port number ----
  int portNumber;
  if(sscanf(argv[2],"%d",&portNumber)!=1)
    { fprintf(stderr,"invalid port %s\n",argv[2]); exit(1); }

//---- create UDP socket ----

// ... À COMPLÉTER ...

  int udpSocket=socket(PF_INET,SOCK_DGRAM,0);

  for(;;)
    {
  //---- read next line on standard input ----
    char msg[0x100];
    if(!fgets(msg,0x100,stdin)) { break; } // [Control]+[d] --> EOF

  //---- extract 32-bit integer ----
    int32_t value;
    if(sscanf(msg,"%d",&value)!=1)
      { fprintf(stderr,"input does not look like an integer\n"); continue; }

  //---- convert to network format 32-bit integer ----
    int32_t tmp;
    (void)tmp; // avoid ``unused variable'' warning

  // ... À COMPLÉTER ...
  
    tmp=htonl(value);
    struct sockaddr_in toAddr;
    toAddr.sin_family=AF_INET;
    toAddr.sin_port=htons(portNumber);
    toAddr.sin_addr.s_addr=ipAddress;
    
    

  //---- send converted value to the specified destination/port ----

  // ... À COMPLÉTER ...
  
    sendto (udpSocket,&tmp,sizeof(tmp),0,(struct sockaddr *) &toAddr,sizeof(toAddr));

  //---- receive a 32-bit integer in network format ----

  // ... À COMPLÉTER ...
    struct sockaddr_in fromAddr;
    socklen_t len=sizeof(fromAddr);
    int nb = recvfrom(udpSocket,&tmp,sizeof(tmp),0,(struct sockaddr *) &fromAddr,&len);
    

  //---- convert to host format 32-bit integer ----
  int32_t reply;
  (void)reply; // avoid ``unused variable'' warning

  // ... À COMPLÉTER ...
  
    reply=tmp;
    reply=ntohl(tmp);

  //---- display reply and source address/port ----

  // ... À COMPLÉTER ...
    msg[nb]='\0';
    printf("from %s:%d :%d\n",inet_ntoa(fromAddr.sin_addr),ntohs(fromAddr.sin_port),reply);
  }

//---- close UDP socket ----

// ... À COMPLÉTER ...

  close(udpSocket);

return 0;
}

//----------------------------------------------------------------------------
