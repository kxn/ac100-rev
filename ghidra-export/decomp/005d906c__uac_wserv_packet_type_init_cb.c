// func _uac_wserv_packet_type_init_cb @ 005d906c size=272

undefined4 _uac_wserv_packet_type_init_cb(uint *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 0xffffffff;
  if ((((param_1 != (uint *)0x0) && (param_2 != 0)) &&
      (iVar1 = rdmngr_db_get_rd_status(*param_1), iVar1 != 0)) &&
     (uVar3 = 0xffffffff, *(int *)(param_2 + 0x11b) != 0)) {
    uVar2 = rdmngr_db_generate_ap_id(*param_1);
    uVar4 = *param_1;
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> init packet type. rd_id[0x%08x], wlan_id[%d], ssid[%s].\r\n"
             ,"_uac_wserv_packet_type_init_cb",0x812,*param_1,(uint)*(byte *)(param_1 + 1),
             param_2 + 0x130);
    }
    FUN_004082d0(DAT_007598e4,0xffffffff);
    uVar3 = 0;
    _uac_wserv_packet_type_set_by_wlan_id(uVar2,(uVar4 & 0xf) - 1,*(char *)(param_1 + 1) + -1,0x10);
    FUN_00407f30(DAT_007598e4);
  }
  return uVar3;
}

