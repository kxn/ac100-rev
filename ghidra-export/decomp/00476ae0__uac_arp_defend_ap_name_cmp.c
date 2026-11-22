// func _uac_arp_defend_ap_name_cmp @ 00476ae0 size=212

bool _uac_arp_defend_ap_name_cmp(undefined2 param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  bool bVar4;
  int iVar3;
  char acStack_3f0 [264];
  undefined1 auStack_2e8 [78];
  char acStack_29a [654];
  
  memset(acStack_3f0,0,0x101);
  memset(auStack_2e8,0,0x2d8);
  bVar4 = true;
  if (param_2 != (char *)0x0) {
    if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d _ap_name_cmp begins, search name:%s\n",
             "_uac_arp_defend_ap_name_cmp",0x7f,param_2);
    }
    apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    strncpy(acStack_3f0,acStack_29a,0x100);
    sVar1 = strlen(acStack_3f0);
    arp_defend_str2upper(acStack_3f0,sVar1);
    pcVar2 = strstr(acStack_3f0,param_2);
    bVar4 = pcVar2 == (char *)0x0;
  }
  return bVar4;
}

