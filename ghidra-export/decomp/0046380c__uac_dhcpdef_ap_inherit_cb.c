// func _uac_dhcpdef_ap_inherit_cb @ 0046380c size=336

undefined4 _uac_dhcpdef_ap_inherit_cb(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *__format;
  undefined4 uVar3;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_ap_inherit_cb",0x8f4,
           "_uac_dhcpdef_ap_inherit_cb");
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "(ap_entry && template_entry)";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar3 = 0x8f5;
  }
  else {
    if (*(int *)(param_1 + 0x40) == *(int *)(param_2 + 0x40)) {
      iVar1 = dhcpdef_db_apbind_entry_inherit
                        (*(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_1 + 0x10));
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = *(char **)(param_1 + 0x40);
    __format = "\x1b[31;49m[%s]<%s():%d> AP model(%d) does NOT match template model(%d)!\x1b[0m\r\n"
    ;
    uVar3 = 0x8fa;
  }
  printf(__format,"dhcp_defend","_uac_dhcpdef_ap_inherit_cb",uVar3,pcVar2);
  return 0xffffffff;
}

