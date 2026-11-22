// func uac_com_get_dev_id @ 00513950 size=668

undefined4 uac_com_get_dev_id(char *param_1,uint param_2)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *__src;
  undefined4 uVar4;
  size_t __n;
  undefined1 auStack_118 [260];
  
  memset(auStack_118,0,0x100);
  if (param_1 != (char *)0x0) {
    __n = 0x28;
    if (param_2 < 0x29) {
      __n = param_2;
    }
    if (DAT_00782004 != 0) {
      __src = &l_dev_id;
      pcVar3 = param_1;
LAB_00513b2c:
      memcpy(pcVar3,__src,__n);
      return 0;
    }
    if (uac_comm_dbg_switch != 0) {
      printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n","uac_com_get_dev_id",
             0x2f6);
    }
    __stream = popen("ubus call tddpServer getInfo \'{\"infoMask\":45}\'","r");
    if (__stream == (FILE *)0x0) {
      if (uac_comm_err_switch != 0) {
        uVar4 = 0x2fa;
        pcVar3 = "[UAC_COMM_ERR]%s()/line %d : popen ubus_stream failed\n";
LAB_00513aec:
        printf(pcVar3,"uac_com_get_dev_id",uVar4);
        return 0xffffffff;
      }
    }
    else {
      memset(auStack_118,0,0x100);
      fread(auStack_118,1,0x100,__stream);
      pclose(__stream);
      if (uac_comm_dbg_switch != 0) {
        printf("[UAC_COMM_DBG]%s()/line %d : get device info by ubus, buf is %s\n",
               "uac_com_get_dev_id",0x302,auStack_118);
      }
      iVar1 = cJSON_Parse(auStack_118);
      if (iVar1 == 0) {
        if (uac_comm_err_switch != 0) {
          uVar4 = 0x306;
          pcVar3 = "[UAC_COMM_ERR]%s()/line %d : get jsonrpc obj failed.\n";
          goto LAB_00513aec;
        }
      }
      else {
        iVar2 = cJSON_GetObjectItem(iVar1,"dev_id");
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) == 4)) {
          strncpy(param_1,*(char **)(iVar2 + 0x10),__n);
          cJSON_Delete(iVar1);
          DAT_00782004 = 1;
          __n = 0x28;
          pcVar3 = &l_dev_id;
          __src = param_1;
          goto LAB_00513b2c;
        }
        if (uac_comm_err_switch != 0) {
          printf("[UAC_COMM_ERR]%s()/line %d : get mac from json failed.\n","uac_com_get_dev_id",
                 0x312);
        }
        cJSON_Delete(iVar1);
      }
    }
  }
  return 0xffffffff;
}

