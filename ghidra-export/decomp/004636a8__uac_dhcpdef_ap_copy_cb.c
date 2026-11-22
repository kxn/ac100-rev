// func _uac_dhcpdef_ap_copy_cb @ 004636a8 size=356

undefined4 _uac_dhcpdef_ap_copy_cb(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  char *__format;
  undefined4 uVar4;
  
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_ap_copy_cb",0x910,
           "_uac_dhcpdef_ap_copy_cb");
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "(ap_entry && matched_entry)";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar4 = 0x911;
  }
  else {
    if (*(int *)(param_1 + 0x40) == *(int *)(param_2 + 0x40)) {
      uVar1 = *(undefined2 *)(param_1 + 0x10);
      iVar2 = dhcpdef_db_apbind_entry_inherit(*(undefined2 *)(param_2 + 0x10),uVar1);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      iVar2 = dhcpdef_db_apbind_entry_firm_update(uVar1);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = *(char **)(param_1 + 0x40);
    __format = "\x1b[31;49m[%s]<%s():%d> AP model(%d) does NOT match model(%d)!\x1b[0m\r\n";
    uVar4 = 0x916;
  }
  printf(__format,"dhcp_defend","_uac_dhcpdef_ap_copy_cb",uVar4,pcVar3);
  return 0xffffffff;
}

