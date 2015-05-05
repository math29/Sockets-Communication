//----------------------------------------------------------------------------

#include "crsUtils.h"

int main(int argc,char **argv)
{
//---- check command line arguments ----
  if(argc!=2)
    { fprintf(stderr,"usage: %s port\n",argv[0]); exit(1); }

//---- extract local port number ----
  int portNumber;
  if(sscanf(argv[1],"%d",&portNumber)!=1)
    { fprintf(stderr,"invalid port %s\n",argv[1]); exit(1); }

//---- create UDP socket ----

// ... À COMPLÉTER ...

for(;;)
  {
  //---- receive a 32-bit integer in network format ----
  int32_t tmp;
  (void)tmp;

  // ... À COMPLÉTER ...

  //---- convert to host format 32-bit integer ----
  int32_t request=0;
  (void)request; // avoid ``unused variable'' warning

  // ... À COMPLÉTER ...
  
  //---- display request and source address/port ----

  // ... À COMPLÉTER ...

  //---- prepare reply ----
  int32_t reply=2*request;
  (void)reply; // avoid ``unused variable'' warning

  //---- convert to network format 32-bit integer ----

  // ... À COMPLÉTER ...

  //---- send converted reply to client ----

  // ... À COMPLÉTER ...

  }

//---- close UDP socket ----

// ... À COMPLÉTER ...
 

return 0;
}

//----------------------------------------------------------------------------
