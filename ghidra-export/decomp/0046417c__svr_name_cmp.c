// func _svr_name_cmp @ 0046417c size=420

bool _svr_name_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  bool bVar4;
  undefined1 auStack_1c0 [4];
  undefined1 auStack_1bc [168];
  char acStack_114 [260];
  
  memset(acStack_114,0,0x101);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_svr_name_cmp",0x89,"_svr_name_cmp");
  }
  if (param_3 == (char *)0x0) {
    bVar4 = true;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_svr_name_cmp",
             0x8b,"search_value");
    }
  }
  else {
    if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[%s]<%s():%d> svr name: %s\r\n","dhcp_defend","_svr_name_cmp",0x8d,param_3);
    }
    memset(auStack_1c0,0,0xac);
    iVar1 = dhcpdef_db_svr_entry_get(param_2,auStack_1c0);
    if (iVar1 == -1) {
      snprintf(acStack_114,0x100,"---");
    }
    else {
      snprintf(acStack_114,0x100,"%s",auStack_1bc);
    }
    sVar2 = strlen(acStack_114);
    dhcpdef_str2upper(acStack_114,sVar2);
    pcVar3 = strstr(acStack_114,param_3);
    bVar4 = pcVar3 == (char *)0x0;
  }
  return bVar4;
}

