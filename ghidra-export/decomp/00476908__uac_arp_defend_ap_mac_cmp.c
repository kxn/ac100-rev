// func _uac_arp_defend_ap_mac_cmp @ 00476908 size=212

bool _uac_arp_defend_ap_mac_cmp(undefined2 param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  undefined4 local_3f8;
  undefined2 local_3f4;
  char acStack_3f0 [264];
  undefined1 auStack_2e8 [72];
  undefined4 local_2a0;
  undefined2 local_29c;
  
  memset(acStack_3f0,0,0x101);
  memset(auStack_2e8,0,0x2d8);
  bVar4 = true;
  if (param_2 != (char *)0x0) {
    apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    local_3f8 = local_2a0;
    local_3f4 = local_29c;
    arp_defend_mac2str(&local_3f8,acStack_3f0,0x14);
    sVar1 = strlen(acStack_3f0);
    arp_defend_str2upper(acStack_3f0,sVar1);
    iVar2 = strcmp(acStack_3f0,"00-00-00-00-00-00");
    if (iVar2 == 0) {
      snprintf(acStack_3f0,0x101,"---");
    }
    pcVar3 = strstr(acStack_3f0,param_2);
    bVar4 = pcVar3 == (char *)0x0;
  }
  return bVar4;
}

