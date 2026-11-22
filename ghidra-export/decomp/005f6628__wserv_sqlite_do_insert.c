// func _wserv_sqlite_do_insert @ 005f6628 size=308

undefined4 _wserv_sqlite_do_insert(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_808 [2048];
  
  memset(acStack_808,0,0x800);
  iVar1 = param_1[1];
  uVar2 = 0;
  snprintf(acStack_808,0x800,
           "INSERT INTO %s (radio_id,wserv1,vlan1,wserv2,vlan2,wserv3,vlan3,wserv4,vlan4,wserv5,vlan5,wserv6,vlan6,wserv7,vlan7,wserv8,vlan8) VALUES(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d);"
           ,"bind_tbl",*param_1,(int)*(short *)(iVar1 + 2),(int)*(short *)(iVar1 + 4),
           (int)*(short *)(iVar1 + 8),(int)*(short *)(iVar1 + 10),(int)*(short *)(iVar1 + 0xe),
           (int)*(short *)(iVar1 + 0x10),(int)*(short *)(iVar1 + 0x14),(int)*(short *)(iVar1 + 0x16)
           ,(int)*(short *)(iVar1 + 0x1a),(int)*(short *)(iVar1 + 0x1c),
           (int)*(short *)(iVar1 + 0x20),(int)*(short *)(iVar1 + 0x22),(int)*(short *)(iVar1 + 0x26)
           ,(int)*(short *)(iVar1 + 0x28),(int)*(short *)(iVar1 + 0x2c),
           (int)*(short *)(iVar1 + 0x2e));
  iVar1 = FUN_00407d60(l_wserv_rf_handle,acStack_808);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, cmd=%s\r\n",
           "_wserv_sqlite_do_insert",0x2e1,acStack_808);
  }
  return uVar2;
}

