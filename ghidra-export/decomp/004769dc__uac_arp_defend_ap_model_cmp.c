// func _uac_arp_defend_ap_model_cmp @ 004769dc size=260

bool _uac_arp_defend_ap_model_cmp(undefined2 param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  bool bVar4;
  int iVar3;
  char acStack_558 [260];
  undefined1 auStack_454 [218];
  char acStack_37a [65];
  char local_339 [81];
  undefined1 auStack_2e8 [64];
  undefined4 local_2a8;
  undefined1 auStack_d0 [196];
  
  memset(acStack_558,0,0x101);
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_454,0,0x168);
  bVar4 = true;
  if (param_2 != (char *)0x0) {
    if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d ap model: %s\n","_uac_arp_defend_ap_model_cmp",0x99,param_2)
      ;
    }
    apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    apdb_get_ap_by_id(local_2a8,auStack_d0,auStack_454);
    pcVar2 = local_339;
    if (local_339[0] == '\0') {
      pcVar2 = acStack_37a;
    }
    strncpy(acStack_558,pcVar2,0x100);
    sVar1 = strlen(acStack_558);
    arp_defend_str2upper(acStack_558,sVar1);
    pcVar2 = strstr(acStack_558,param_2);
    bVar4 = pcVar2 == (char *)0x0;
  }
  return bVar4;
}

