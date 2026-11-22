// func _uac_dhcpdef_ap_disconnect_cb @ 00465e4c size=392

undefined4 _uac_dhcpdef_ap_disconnect_cb(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x3c) == 0) {
      if (2 < *(uint *)(param_1 + 0xc)) {
        return 0;
      }
      if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[%s]<%s():%d> --->IN:  %s(), ap_id=%d.\r\n","dhcp_defend",
               "_uac_dhcpdef_ap_disconnect_cb",0x88c,"_uac_dhcpdef_ap_disconnect_cb",
               (uint)*(ushort *)(param_1 + 0x10));
      }
      iVar1 = dhcpdef_db_apbind_entry_del_not_firmed(*(undefined2 *)(param_1 + 0x10));
      if (iVar1 == 0) {
        uVar3 = 0;
        if (g_dhcpdef_info == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        pcVar4 = "_uac_dhcpdef_ap_disconnect_cb";
        __format = "[%s]<%s():%d> <---OUT: %s() success.\r\n";
        uVar2 = 0x88c;
      }
      else {
        uVar3 = 0xffffffff;
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar4 = "dhcpdef_db_apbind_entry_del_not_firmed";
        __format = "\x1b[31;49m[%s]<%s():%d> Call %s() fail.\x1b[0m\r\n";
        uVar2 = 0x88c;
      }
    }
    else {
      uVar3 = 0;
      if (g_dhcpdef_warn == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      pcVar4 = (char *)(uint)*(ushort *)(param_1 + 0x10);
      __format = "\x1b[33;49m[%s]<%s():%d> apbind entry [%d] is firmed, can NOT delete!\x1b[0m\r\n";
      uVar2 = 0x888;
    }
    printf(__format,"dhcp_defend","_uac_dhcpdef_ap_disconnect_cb",uVar2,pcVar4);
  }
  return uVar3;
}

