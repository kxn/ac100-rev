// func uac_com_update_dev_ip @ 005146d0 size=516

undefined4 uac_com_update_dev_ip(void)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 auStack_90 [128];
  
  memset(auStack_90,0,0x80);
  memset(&g_ac_ip,0,0x81);
  __stream = popen("ubus call cloudclient get_device_ip -t 5","r");
  if (__stream == (FILE *)0x0) {
    if (uac_comm_err_switch != 0) {
      printf("[UAC_COMM_ERR]%s()/line %d : popen exe [%s] failed\n\n","uac_com_update_dev_ip",0x49a,
             "ubus call cloudclient get_device_ip -t 5");
      return 0xffffffff;
    }
  }
  else {
    memset(auStack_90,0,0x80);
    fread(auStack_90,1,0x80,__stream);
    pclose(__stream);
    iVar1 = cJSON_Parse(auStack_90);
    if (iVar1 == 0) {
      if (uac_comm_err_switch != 0) {
        uVar4 = 0x4a5;
        pcVar5 = "[UAC_COMM_ERR]%s()/line %d : get jsonrpc obj failed.\n\n";
        goto LAB_00514828;
      }
    }
    else {
      iVar2 = cJSON_GetObjectItem(iVar1,"device_ip");
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) == 4)) {
        pcVar5 = *(char **)(iVar2 + 0x10);
        sVar3 = strlen(pcVar5);
        if (sVar3 < 0x81) {
          strncpy(&g_ac_ip,pcVar5,0x80);
          cJSON_Delete(iVar1);
          return 0;
        }
      }
      if (uac_comm_err_switch != 0) {
        uVar4 = 0x4b3;
        pcVar5 = "[UAC_COMM_ERR]%s()/line %d : get fw id from json failed.\n";
LAB_00514828:
        printf(pcVar5,"uac_com_update_dev_ip",uVar4);
        return 0xffffffff;
      }
    }
  }
  return 0xffffffff;
}

