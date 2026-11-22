// func _svr_bind_status_cmp @ 00463d68 size=336

bool _svr_bind_status_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int local_20 [3];
  
  local_20[0] = 0;
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_svr_bind_status_cmp",0xd0,
           "_svr_bind_status_cmp");
  }
  if (param_3 == (char *)0x0) {
    bVar3 = true;
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_svr_bind_status_cmp",0xd1,"search_value");
    }
  }
  else {
    if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[%s]<%s():%d> searching bind status: \'%s\'\r\n","dhcp_defend","_svr_bind_status_cmp",
             0xd3,param_3);
    }
    dhcpdef_db_svr_entry_is_binded_to_ap(param_1,param_2,local_20);
    iVar2 = local_20[0];
    iVar1 = atoi(param_3);
    bVar3 = iVar2 != iVar1;
  }
  return bVar3;
}

