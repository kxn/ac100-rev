// func audit_client_db_server_get @ 0050a050 size=156

undefined4 audit_client_db_server_get(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
    if (audit_err_switch != 0) {
      printf("[AUDIT_ERR]%s()/%d Audit server is invalid.\n","audit_client_db_server_get",0x97);
    }
  }
  else {
    *param_1 = audit_server;
    memcpy(param_1 + 1,&DAT_007688e4,0x14);
    param_1[6] = DAT_007688f8;
    param_1[7] = DAT_007688fc;
    uVar1 = 0;
    param_1[8] = DAT_00768900;
  }
  return uVar1;
}

