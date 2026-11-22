// func _dnsq_sync_query_once @ 0043b674 size=336

undefined4 _dnsq_sync_query_once(char *param_1,uint param_2,char *param_3,size_t param_4)

{
  int iVar1;
  char *pcVar2;
  sockaddr *psVar3;
  addrinfo *paVar4;
  undefined4 uVar5;
  addrinfo *local_88;
  _union_1051 local_84;
  code *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  addrinfo local_68;
  char acStack_48 [48];
  
  local_84.sa_handler = (__sighandler_t)0x0;
  local_7c = 0;
  local_78 = 0;
  uVar5 = 0xffffffff;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_80 = _alarm_timeout;
  iVar1 = sigaction(0xe,(sigaction *)&local_84,(sigaction *)0x0);
  if (-1 < iVar1) {
    memset(&local_68,0,0x20);
    local_68.ai_flags = 1;
    local_68.ai_family = 2;
    local_68.ai_socktype = 2;
    alarm(param_2);
    iVar1 = getaddrinfo(param_1,(char *)0x0,&local_68,&local_88);
    alarm(0);
    if (iVar1 != -1) {
      paVar4 = local_88;
      if (local_88 != (addrinfo *)0x0) {
        psVar3 = local_88->ai_addr;
        while( true ) {
          pcVar2 = psVar3->sa_data + 6;
          if (paVar4->ai_family == 2) {
            pcVar2 = psVar3->sa_data + 2;
          }
          pcVar2 = inet_ntop(paVar4->ai_family,pcVar2,acStack_48,0x2d);
          if (pcVar2 != (char *)0x0) break;
          paVar4 = paVar4->ai_next;
          if (paVar4 == (addrinfo *)0x0) goto LAB_0043b778;
          psVar3 = paVar4->ai_addr;
        }
        snprintf(param_3,param_4,"%s",acStack_48);
      }
LAB_0043b778:
      uVar5 = 0xffffffff;
      if (paVar4 != (addrinfo *)0x0) {
        uVar5 = 0;
      }
      freeaddrinfo(local_88);
    }
  }
  return uVar5;
}

