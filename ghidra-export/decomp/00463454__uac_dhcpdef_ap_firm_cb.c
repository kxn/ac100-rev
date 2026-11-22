// func _uac_dhcpdef_ap_firm_cb @ 00463454 size=428

undefined4 _uac_dhcpdef_ap_firm_cb(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  uVar3 = 0xffffffff;
  memset(auStack_2e8,0,0x2d8);
  if ((param_1 != 0) && (uVar3 = 0, *(uint *)(param_1 + 0xc) < 3)) {
    if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[%s]<%s():%d> --->IN:  %s(), ap_id=%d.\r\n","dhcp_defend","_uac_dhcpdef_ap_firm_cb",
             0x895,"_uac_dhcpdef_ap_firm_cb",(uint)*(ushort *)(param_1 + 0x10));
    }
    iVar2 = dhcpdef_db_apbind_entry_firm_insert(*(undefined2 *)(param_1 + 0x10));
    if (iVar2 == 0) {
      if (g_dhcpdef_info == 0) {
        iVar2 = *(int *)(param_1 + 0x14);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x14);
        }
        else {
          printf("[%s]<%s():%d> <---OUT: %s() success.\r\n","dhcp_defend","_uac_dhcpdef_ap_firm_cb",
                 0x895,"_uac_dhcpdef_ap_firm_cb");
          iVar2 = *(int *)(param_1 + 0x14);
        }
      }
      if (((iVar2 == 4) || (iVar2 == 8)) || (uVar3 = 0, iVar2 == 6)) {
        uVar3 = 0xffffffff;
        iVar2 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x18),auStack_2e8);
        if (iVar2 == 0) {
          uVar1 = *(undefined2 *)(param_1 + 0x10);
          iVar2 = dhcpdef_db_apbind_entry_inherit(local_2d8,uVar1);
          if ((iVar2 == 0) && (iVar2 = dhcpdef_db_apbind_entry_firm_update(uVar1), iVar2 == 0)) {
            uVar3 = 0;
          }
        }
      }
    }
    else {
      uVar3 = 0xffffffff;
      if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> Call %s() fail.\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_ap_firm_cb",0x895,"dhcpdef_db_apbind_entry_firm_insert");
      }
    }
  }
  return uVar3;
}

