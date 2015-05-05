//----------------------------------------------------------------------------

#include "crsUtils.h"

void *
dialogThread(void *arg)
{
pthread_detach(pthread_self());
//---- obtain dialog socket from arg ----

// ... À COMPLÉTER ...

free(arg);

for(;;)
  {
  //---- receive and display request from client ----
  char request[0x100];
  (void)request; // avoid ``unused variable'' warning

  // ... À COMPLÉTER ...

  //---- send reply to client ----
  char reply[0x100];
  (void)reply; // avoid ``unused variable'' warning

  // ... À COMPLÉTER ...

  }

//---- close dialog socket ----

// ... À COMPLÉTER ...

printf("client disconnected\n");
return (void *)0;
}

int
main(int argc,
     char **argv)
{
//---- check command line arguments ----
if(argc!=2)
  { fprintf(stderr,"usage: %s port\n",argv[0]); exit(1); }

//---- extract local port number ----
int portNumber;
if(sscanf(argv[1],"%d",&portNumber)!=1)
  { fprintf(stderr,"invalid port %s\n",argv[1]); exit(1); }

//---- create listen socket ----

// ... À COMPLÉTER ...

int listenSocket=socket(AF_INET,SOCK_STREAM,0);
int on=1;
setsockopt(listenSocket,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
struct sockaddr_in myAddr; 
myAddr.sin_family=AF_INET;
myAddr.sin_port=htons(portNumber); 
myAddr.sin_addr.s_addr=htonl(INADDR_ANY);
bind(listenSocket,(struct sockaddr *)&myAddr,sizeof(myAddr));
listen(listenSocket,10);

for(;;)
  {
  //---- accept new connection ----

  // ... À COMPLÉTER ...
  
  struct sockaddr_in fromAddr; 
  socklen_t len=sizeof(fromAddr);
  int * dialogSocket=(int *) malloc(sizeof(int));
  * dialogSocket=accept(listenSocket,(struct sockaddr *)&fromAddr,&len);
  
  //---- start a new dialog thread ----

  // ... À COMPLÉTER ...
  pthread_t th;
  pthread_create(*th,NULL,dialogThread,(void*)dialogSocket);

  }

//---- close listen socket ----

// ... À COMPLÉTER ...

close(listenSocket);

return 0;
}

//----------------------------------------------------------------------------
