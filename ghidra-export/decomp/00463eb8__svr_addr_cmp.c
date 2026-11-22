// func _svr_addr_cmp @ 00463eb8 size=380

bool _svr_addr_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  bool bVar4;
  char local_128 [4];
  undefined1 auStack_124 [16];
  char acStack_114 [260];
  
  memset(acStack_114,0,0x101);
  local_128[0] = -1;
  if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_svr_addr_cmp",0xb9,"_svr_addr_cmp");
  }
  if (param_3 == (char *)0x0) {
    bVar4 = true;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_svr_addr_cmp",
             0xba,"search_value");
    }
  }
  else {
    if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[%s]<%s():%d> svr addr: %s\r\n","dhcp_defend","_svr_addr_cmp",0xbc,param_3);
    }
    get_svr_addr_by_id(param_2,local_128,auStack_124);
    dhcpdef_addr2str((int)local_128[0],auStack_124,acStack_114);
    sVar1 = strlen(acStack_114);
    dhcpdef_str2upper(acStack_114,sVar1);
    pcVar2 = strstr(acStack_114,param_3);
    bVar4 = pcVar2 == (char *)0x0;
  }
  return bVar4;
}

