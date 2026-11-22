// func mac_auth_db_get_bind_vlan @ 00453f04 size=156

undefined4 mac_auth_db_get_bind_vlan(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid params.\n","mac_auth_db_get_bind_vlan",0x5c6);
    }
  }
  else {
    FUN_004082d0(DAT_00766ff8,0xffffffff);
    uVar1 = 0;
    memcpy(param_1,DAT_00767018,(DAT_00766fec + 1) * 4);
    FUN_00407f30(DAT_00766ff8);
  }
  return uVar1;
}

