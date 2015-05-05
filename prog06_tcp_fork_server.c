//----------------------------------------------------------------------------

#include "crsUtils.h"

void
waitChildren(int signum)
{
(void)signum;
for(;;)
  {
  pid_t pid=waitpid(-1,(int *)0,WNOHANG);
  if(pid<=0) break;
  else printf("child %d terminated\n",pid);
  }
}

void
dialogFunction(int dialogSocket)
{
(void)dialogSocket; // avoid ``unused parameter'' warning
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
}

int
main(int argc,
     char **argv)
{
//---- check command line arguments ----
if(argc<2)
  { fprintf(stderr,"usage: %s port [cmd line ...]\n",argv[0]); exit(1); }

//---- extract local port number ----
int portNumber;
if(sscanf(argv[1],"%d",&portNumber)!=1)
  { fprintf(stderr,"invalid port %s\n",argv[1]); exit(1); }

//---- install signal handler for child termination ----
struct sigaction sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=&waitChildren;
if(sigaction(SIGCHLD,&sa,(struct sigaction *)0)==-1)
  { perror("sigaction"); exit(1); }

//---- create listen socket ----

// ... À COMPLÉTER ...

for(;;)
  {
  //---- accept new connection ----

  // ... À COMPLÉTER ...

  //---- start a new dialog process (dialogFunction or execvp) ----

  // ... À COMPLÉTER ...

  //---- close dialog socket (useless in parent process) ----

  // ... À COMPLÉTER ...

  }

//---- close listen socket ----

// ... À COMPLÉTER ...

return 0;
}

//----------------------------------------------------------------------------
