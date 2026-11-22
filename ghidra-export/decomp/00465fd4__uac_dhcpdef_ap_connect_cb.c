// func _uac_dhcpdef_ap_connect_cb @ 00465fd4 size=300

undefined4 _uac_dhcpdef_ap_connect_cb(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) && (uVar2 = 0, *(uint *)(param_1 + 0xc) < 3)) {
    if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[%s]<%s():%d> --->IN:  %s(), ap_id=%d.\r\n","dhcp_defend","_uac_dhcpdef_ap_connect_cb"
             ,0x87e,"_uac_dhcpdef_ap_connect_cb",(uint)*(ushort *)(param_1 + 0x10));
    }
    iVar1 = dhcpdef_db_apbind_entry_add(*(undefined2 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      uVar2 = 0;
      if (g_dhcpdef_info == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      pcVar3 = "_uac_dhcpdef_ap_connect_cb";
      __format = "[%s]<%s():%d> <---OUT: %s() success.\r\n";
    }
    else {
      uVar2 = 0xffffffff;
      if (g_dhcpdef_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "\x1b[31;49m[%s]<%s():%d> Call %s() fail.\x1b[0m\r\n";
      pcVar3 = "dhcpdef_db_apbind_entry_add";
    }
    printf(__format,"dhcp_defend","_uac_dhcpdef_ap_connect_cb",0x87e,pcVar3);
  }
  return uVar2;
}

