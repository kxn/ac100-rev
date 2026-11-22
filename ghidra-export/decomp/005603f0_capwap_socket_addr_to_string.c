// func capwap_socket_addr_to_string @ 005603f0 size=164

char * capwap_socket_addr_to_string(int param_1,int param_2,char *param_3,size_t param_4)

{
  int __af;
  void *__cp;
  char acStack_40 [40];
  
  memset(acStack_40,0,0x28);
  __af = 10;
  if (param_2 == 0) {
    __af = 2;
    __cp = (void *)(param_1 + 4);
  }
  else {
    __cp = (void *)(param_1 + 8);
  }
  inet_ntop(__af,__cp,acStack_40,0x28);
  snprintf(param_3,param_4,"%s:%d",acStack_40,(uint)*(ushort *)(param_1 + 2));
  return param_3;
}

