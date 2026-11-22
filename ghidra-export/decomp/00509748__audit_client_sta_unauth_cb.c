// func _audit_client_sta_unauth_cb @ 00509748 size=412

undefined4 _audit_client_sta_unauth_cb(int param_1)

{
  int iVar1;
  undefined4 *__s;
  undefined4 uVar2;
  undefined1 uVar3;
  char *__format;
  
  iVar1 = audit_client_db_is_server_enable();
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d Para is invalid.\n";
    uVar2 = 0xd2;
  }
  else {
    __s = (undefined4 *)FUN_004082a0(1,0x74,0xd6);
    if (__s != (undefined4 *)0x0) {
      memset(__s,0,0x74);
      if (*(char *)(param_1 + 0x80) == '\b') {
        uVar2 = 4;
      }
      else {
        uVar2 = 0xc;
        if (*(char *)(param_1 + 0x80) != '\x02') {
          if (audit_debug_switch != 0) {
            printf("[AUDIT_DBG]%s()/%d Not support now.\n","_audit_client_sta_unauth_cb",0xe8);
          }
          FUN_00407df0(__s);
          return 0;
        }
      }
      *__s = uVar2;
      snprintf((char *)(__s + 1),0x40,"%s",param_1 + 0xa3);
      memcpy((void *)((int)__s + 0x6d),(void *)(param_1 + 0xc),6);
      memcpy((void *)((int)__s + 0x45),(void *)(param_1 + 0x58),0x28);
      iVar1 = FUN_00407db0((void *)(param_1 + 0x58));
      uVar3 = 6;
      if (iVar1 != 2) {
        uVar3 = 4;
      }
      *(undefined1 *)(__s + 0x11) = uVar3;
      *(undefined1 *)((int)__s + 0x73) = 0;
      audit_client_db_msg_send(1,__s,1,audit_client_db_msg_data_free);
      return 0;
    }
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d Memory is not enough.\n";
    uVar2 = 0xd9;
  }
  printf(__format,"_audit_client_sta_unauth_cb",uVar2);
  return 0xffffffff;
}

