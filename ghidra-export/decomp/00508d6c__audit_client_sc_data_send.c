// func _audit_client_sc_data_send @ 00508d6c size=440

/* WARNING: Type propagation algorithm not settling */

undefined4 _audit_client_sc_data_send(int param_1,int param_2)

{
  void *__dest;
  int __fd;
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  int local_58 [2];
  sockaddr local_50;
  undefined1 auStack_40 [8];
  char local_38 [32];
  
  uVar3 = 0xffffffff;
  memset(auStack_40,0,0x24);
  local_58[1] = 0;
  local_58[0] = 0;
  if (((param_1 != 0) && (0 < param_2)) && (param_2 < 0xfff8)) {
    if ((DAT_007688d0 == (void *)0x0) &&
       (DAT_007688d0 = (void *)FUN_00408450(0x10000,0x1bd), DAT_007688d0 == (void *)0x0)) {
      if (audit_err_switch != 0) {
        printf("[AUDIT_ERR]%s()/%d Out of memory\n","_audit_client_sc_data_send",0x1c0);
      }
    }
    else {
      __dest = DAT_007688d0;
      uVar3 = 0xffffffff;
      memset(DAT_007688d0,0,0x10000);
      local_58[1] = 0xaabbccdd;
      local_58[0] = param_2;
      memcpy(__dest,local_58 + 1,4);
      memcpy((void *)((int)__dest + 4),local_58,4);
      snprintf((char *)((int)__dest + 8),0xfff8,"%s",param_1);
      __fd = socket(2,2,6);
      if (-1 < __fd) {
        audit_client_db_server_get(auStack_40);
        local_50.sa_data[6] = '\0';
        local_50.sa_data[7] = '\0';
        local_50.sa_data[8] = '\0';
        local_50.sa_data[9] = '\0';
        local_50.sa_family = 2;
        local_50.sa_data[10] = '\0';
        local_50.sa_data[0xb] = '\0';
        local_50.sa_data[0xc] = '\0';
        local_50.sa_data[0xd] = '\0';
        local_50.sa_data[2] = local_38[0];
        local_50.sa_data[3] = local_38[1];
        local_50.sa_data[4] = local_38[2];
        local_50.sa_data[5] = local_38[3];
        local_50.sa_data[0] = -0x3d;
        local_50.sa_data[1] = 'U';
        iVar1 = connect(__fd,&local_50,0x10);
        if ((iVar1 == -1) || (sVar2 = send(__fd,DAT_007688d0,param_2 + 8,0), sVar2 == -1)) {
          close(__fd);
        }
        else {
          uVar3 = 0;
          close(__fd);
        }
      }
    }
  }
  return uVar3;
}

