// func audit_client_db_server_set @ 0050a0ec size=124

undefined4 audit_client_db_server_set(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
    if (audit_err_switch != 0) {
      printf("[AUDIT_ERR]%s()/%d Audit server is invalid.\n","audit_client_db_server_set",0xa9);
    }
  }
  else {
    audit_server = *param_1;
    uVar1 = 0;
    memcpy(&DAT_007688e4,param_1 + 1,0x14);
  }
  return uVar1;
}

