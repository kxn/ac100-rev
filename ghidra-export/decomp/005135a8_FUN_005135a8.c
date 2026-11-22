// func FUN_005135a8 @ 005135a8 size=8

undefined4 FUN_005135a8(void *param_1)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  char acStack_130 [16];
  ushort uStack_120;
  undefined1 auStack_11c [264];
  
  memset(auStack_11c,0,0x100);
  acStack_130[0] = '\0';
  acStack_130[1] = '\0';
  acStack_130[2] = '\0';
  acStack_130[3] = '\0';
  acStack_130[4] = '\0';
  acStack_130[5] = '\0';
  acStack_130[6] = '\0';
  acStack_130[7] = '\0';
  acStack_130[8] = '\0';
  acStack_130[9] = '\0';
  acStack_130[10] = '\0';
  acStack_130[0xb] = '\0';
  acStack_130[0xc] = '\0';
  acStack_130[0xd] = '\0';
  acStack_130[0xe] = '\0';
  acStack_130[0xf] = '\0';
  uStack_120 = 0;
  if (param_1 == (void *)0x0) {
    return 0xffffffff;
  }
  if (DAT_00781ff8 != 0) {
LAB_00513734:
    memcpy(param_1,&dev_mac,6);
    return 0;
  }
  if (uac_comm_dbg_switch != 0) {
    printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n","uac_com_get_dev_mac",
           0x2a5);
  }
  __stream = popen("ubus call tddpServer getInfo \'{\"infoMask\":33}\'","r");
  if (__stream == (FILE *)0x0) {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar4 = 0x2a9;
    pcVar3 = "[UAC_COMM_ERR]%s()/line %d : popen ubus_stream failed\n";
LAB_00513770:
    printf(pcVar3,"uac_com_get_dev_mac",uVar4);
    return 0xffffffff;
  }
  memset(auStack_11c,0,0x100);
  fread(auStack_11c,1,0x100,__stream);
  pclose(__stream);
  if (uac_comm_dbg_switch != 0) {
    printf("[UAC_COMM_DBG]%s()/line %d : get device info by ubus, buf is %s\n","uac_com_get_dev_mac"
           ,0x2b1,auStack_11c);
  }
  iVar1 = cJSON_Parse(auStack_11c);
  if (iVar1 == 0) {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar4 = 0x2b5;
    pcVar3 = "[UAC_COMM_ERR]%s()/line %d : get jsonrpc obj failed.\n";
    goto LAB_00513770;
  }
  iVar2 = cJSON_GetObjectItem(iVar1,"mac");
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0xc) != 4)) {
    if (uac_comm_err_switch == 0) goto LAB_00513700;
    uVar4 = 0x2c1;
    pcVar3 = "[UAC_COMM_ERR]%s()/line %d : get mac from json failed.\n";
  }
  else {
    strncpy(acStack_130,*(char **)(iVar2 + 0x10),0x11);
    uStack_120 = uStack_120 & 0xff00;
    iVar2 = sscanf(acStack_130,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",&dev_mac,&DAT_00781ffd,&DAT_00781ffe,
                   &DAT_00781fff,&DAT_00782000,&DAT_00782001);
    if (iVar2 == 6) {
      cJSON_Delete(iVar1);
      DAT_00781ff8 = 1;
      goto LAB_00513734;
    }
    if (uac_comm_err_switch == 0) goto LAB_00513700;
    uVar4 = 0x2c8;
    pcVar3 = "[UAC_COMM_ERR]%s()/line %d : trans mac_str failed.\n";
  }
  printf(pcVar3,"uac_com_get_dev_mac",uVar4);
LAB_00513700:
  cJSON_Delete(iVar1);
  return 0xffffffff;
}

