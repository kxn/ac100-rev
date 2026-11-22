// func _uac_dhcpdef_ap_del_cb @ 00463308 size=332

undefined4 _uac_dhcpdef_ap_del_cb(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((g_dhcpdef_info == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    if (param_1 == 0) goto LAB_004633d0;
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  else {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_ap_del_cb",0x8b0,
           "_uac_dhcpdef_ap_del_cb");
    if (param_1 == 0) {
LAB_004633d0:
      if (g_dhcpdef_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("\x1b[31;49m[%s]<%s():%d> ap_entry is NULL!\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_ap_del_cb",0x8b4);
      return 0xffffffff;
    }
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  if ((iVar1 == 0) || (2 < *(uint *)(param_1 + 0xc))) {
    uVar2 = 0;
    if ((g_dhcpdef_warn != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[33;49m[%s]<%s():%d> apbind entry [%d] is NOT firmed, it should be deleted in disconnect()!\x1b[0m\r\n"
             ,"dhcp_defend","_uac_dhcpdef_ap_del_cb",0x8ba,(uint)*(ushort *)(param_1 + 0x10));
    }
  }
  else {
    uVar2 = 0xffffffff;
    iVar1 = dhcpdef_db_apbind_entry_del_force(*(undefined2 *)(param_1 + 0x10));
    if ((iVar1 == 0) &&
       (iVar1 = dhcpdef_db_apbind_entry_unfirm(*(undefined2 *)(param_1 + 0x10)), iVar1 == 0)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

