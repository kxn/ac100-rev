// func _addr_type_cmp @ 00464034 size=328

bool _addr_type_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char local_28 [4];
  undefined1 auStack_24 [20];
  
  local_28[0] = -1;
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_addr_type_cmp",0xa2,"_addr_type_cmp");
  }
  if (param_3 == (char *)0x0) {
    bVar3 = true;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_addr_type_cmp",
             0xa3,"search_value");
    }
  }
  else {
    iVar1 = atoi(param_3);
    if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[%s]<%s():%d> addr_type: %d\r\n","dhcp_defend","_addr_type_cmp",0xa6,iVar1);
    }
    get_svr_addr_by_id(param_2,local_28,auStack_24);
    bVar3 = local_28[0] != iVar1;
  }
  return bVar3;
}

