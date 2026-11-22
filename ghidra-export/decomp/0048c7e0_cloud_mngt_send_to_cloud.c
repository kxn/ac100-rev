// func cloud_mngt_send_to_cloud @ 0048c7e0 size=360

undefined4 cloud_mngt_send_to_cloud(uint param_1,char *param_2)

{
  size_t sVar1;
  char *__dest;
  int iVar2;
  undefined4 uVar3;
  int local_138;
  char *local_134;
  char *local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  char acStack_118 [260];
  
  memset(acStack_118,0,0x100);
  local_134 = (char *)0x0;
  uVar3 = 0xffffffff;
  local_130 = (char *)0x0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_138 = 0;
  if (((param_1 < 9) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    snprintf(acStack_118,0x100,"%s%s","/tums/devmsg/v1/",(&msg_url_str)[param_1]);
    local_134 = acStack_118;
    sVar1 = strlen(param_2);
    __dest = (char *)FUN_00408450(sVar1 + 1,0x58c);
    if (__dest != (char *)0x0) {
      strcpy(__dest,param_2);
      sVar1 = strlen(param_2);
      __dest[sVar1] = '\0';
      local_130 = __dest;
      if (cloud_mngt_send_pkt_switch != '\0') {
        printf("send_inf\'s json(%s):\n%s\n",acStack_118,__dest);
      }
      iVar2 = sendto_business_by_short_link_retran(&local_134,&local_138,3);
      if ((iVar2 == 0) && (local_138 == 0)) {
        uVar3 = 0;
        FUN_00407df0(__dest);
      }
      else {
        uVar3 = 0xffffffff;
        FUN_00407df0(__dest);
      }
    }
  }
  return uVar3;
}

