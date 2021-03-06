//----------------------------------------------------------------------------

#include "crsUtils.h"

void showIpAddress(const char *hostName){
  (void)hostName; // avoid ``unused parameter'' warning

  // ... À COMPLÉTER ...
  
  struct hostent* host = gethostbyname(hostName);
  if(host){
    in_addr_t ipAdress=*((in_addr_t*)(host->h_addr));
    struct in_addr addr={ipAdress};
    printf("%s==>%s\n", hostName, inet_ntoa(addr));
  }
  else {
    printf("%s inconnu\n",hostName);
  }
    
  //
  
}

int main(int argc,char **argv){
  char hostName[0x100]="";

  // ... À COMPLÉTER ...
  
  gethostname(hostName,sizeof(hostName));
  printf("%s\n",hostName);
  
  //
  
  showIpAddress(hostName);
  for(int i=1;i<argc;++i){
    showIpAddress(argv[i]);
  }
  return 0;
}

//----------------------------------------------------------------------------
