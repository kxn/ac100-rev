// func uac_com_get_dev_hw_id @ 005142d4 size=680

undefined4 uac_com_get_dev_hw_id(char *param_1,int param_2)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_118 [256];
  
  memset(auStack_118,0,0x100);
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_2 < 2) {
    return 0xffffffff;
  }
  if (DAT_007820b8 == 0) {
    if (uac_comm_dbg_switch != 0) {
      printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n",
             "uac_com_get_dev_hw_id",0x3e1);
    }
    __stream = popen("ubus call tddpServer getInfo \'{\"infoMask\":45}\'","r");
    if (__stream == (FILE *)0x0) {
      if (uac_comm_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x3e5;
      __format = "[UAC_COMM_ERR]%s()/line %d : popen ubus_stream failed\n";
    }
    else {
      memset(auStack_118,0,0x100);
      fread(auStack_118,1,0x100,__stream);
      pclose(__stream);
      if (uac_comm_dbg_switch != 0) {
        printf("[UAC_COMM_DBG]%s()/line %d : get device info by ubus, buf is %s\n",
               "uac_com_get_dev_hw_id",0x3ed,auStack_118);
      }
      iVar1 = cJSON_Parse(auStack_118);
      if (iVar1 != 0) {
        iVar2 = cJSON_GetObjectItem(iVar1,"hw_id");
        if ((iVar2 == 0) || (*(int *)(iVar2 + 0xc) != 4)) {
          if (uac_comm_err_switch != 0) {
            printf("[UAC_COMM_ERR]%s()/line %d : get fw id from json failed.\n",
                   "uac_com_get_dev_hw_id",0x3fd);
          }
          cJSON_Delete(iVar1);
          return 0xffffffff;
        }
        strncpy(&dev_hw_id,*(char **)(iVar2 + 0x10),0x80);
        DAT_0078213c = 0;
        cJSON_Delete(iVar1);
        DAT_007820b8 = 1;
        goto LAB_005144b0;
      }
      if (uac_comm_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x3f1;
      __format = "[UAC_COMM_ERR]%s()/line %d : get jsonrpc obj failed.\n";
    }
    uVar4 = 0xffffffff;
    printf(__format,"uac_com_get_dev_hw_id",uVar3);
  }
  else {
LAB_005144b0:
    uVar4 = 0;
    strncpy(param_1,&dev_hw_id,param_2 - 1);
    param_1[param_2 + -1] = '\0';
  }
  return uVar4;
}

