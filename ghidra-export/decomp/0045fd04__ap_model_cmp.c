// func _ap_model_cmp @ 0045fd04 size=432

bool _ap_model_cmp(undefined2 param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  bool bVar4;
  char acStack_558 [260];
  undefined1 auStack_454 [218];
  char acStack_37a [65];
  char local_339 [81];
  undefined1 auStack_2e8 [64];
  undefined4 local_2a8;
  undefined1 auStack_d0 [192];
  
  memset(acStack_558,0,0x101);
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_454,0,0x168);
  if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_ap_model_cmp",0x11a,"_ap_model_cmp");
  }
  if (param_2 == (char *)0x0) {
    bVar4 = true;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_ap_model_cmp",
             0x11b,"search_value");
    }
  }
  else {
    if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[%s]<%s():%d> ap model: %s\r\n","dhcp_defend","_ap_model_cmp",0x11c,param_2);
    }
    apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    apdb_get_ap_by_id(local_2a8,auStack_d0,auStack_454);
    pcVar2 = local_339;
    if (local_339[0] == '\0') {
      pcVar2 = acStack_37a;
    }
    strncpy(acStack_558,pcVar2,0x100);
    sVar1 = strlen(acStack_558);
    dhcpdef_str2upper(acStack_558,sVar1);
    pcVar2 = strstr(acStack_558,param_2);
    bVar4 = pcVar2 == (char *)0x0;
  }
  return bVar4;
}

