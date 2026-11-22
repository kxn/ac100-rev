// func _bind_svr_num_cmp @ 00463c50 size=280

bool _bind_svr_num_cmp(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_bind_svr_num_cmp",0x167,
           "_bind_svr_num_cmp");
  }
  if (param_2 == (char *)0x0) {
    bVar3 = true;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_bind_svr_num_cmp",0x168,"search_value");
    }
  }
  else {
    iVar1 = atoi(param_2);
    iVar2 = dhcpdef_db_apbind_entry_shallow_get(param_1,&local_28);
    bVar3 = true;
    if (iVar2 == 0) {
      bVar3 = CONCAT31(local_20._1_3_,local_1c._0_1_) != iVar1;
    }
  }
  return bVar3;
}

