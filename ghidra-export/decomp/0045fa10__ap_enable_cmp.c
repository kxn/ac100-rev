// func _ap_enable_cmp @ 0045fa10 size=352

bool _ap_enable_cmp(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_ap_enable_cmp",0x153,"_ap_enable_cmp");
  }
  if (param_2 == (char *)0x0) {
    bVar3 = true;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_ap_enable_cmp",
             0x154,"search_value");
    }
  }
  else {
    iVar1 = atoi(param_2);
    if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[%s]<%s():%d> enable: %d\r\n","dhcp_defend","_ap_enable_cmp",0x157,iVar1);
    }
    iVar2 = dhcpdef_db_apbind_entry_shallow_get(param_1,&local_30);
    bVar3 = true;
    if (iVar2 == 0) {
      bVar3 = local_28._0_1_ != iVar1;
    }
  }
  return bVar3;
}

