// func uac_com_get_site_id @ 00513bec size=560

undefined4 uac_com_get_site_id(char *param_1,int param_2)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 auStack_110 [256];
  
  memset(auStack_110,0,0x100);
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  __stream = popen("ubus call cloudclient get_site_id","r");
  if (__stream == (FILE *)0x0) {
    if (uac_comm_err_switch == 0) goto LAB_00513d18;
    uVar3 = 0x331;
    __format = "[UAC_COMM_ERR]%s()/line %d : popen ubus_stream failed\n";
  }
  else {
    memset(auStack_110,0,0x100);
    fread(auStack_110,1,0x100,__stream);
    pclose(__stream);
    if (uac_comm_dbg_switch != 0) {
      printf("[UAC_COMM_DBG]%s()/line %d : get device info by ubus, buf is %s\n",
             "uac_com_get_site_id",0x339,auStack_110);
    }
    iVar1 = cJSON_Parse(auStack_110);
    if (iVar1 != 0) {
      iVar2 = cJSON_GetObjectItem(iVar1,"site_id");
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) == 4)) {
        strncpy(param_1,*(char **)(iVar2 + 0x10),param_2 - 1);
        param_1[param_2 + -1] = '\0';
        cJSON_Delete(iVar1);
        return 0;
      }
      if (uac_comm_err_switch != 0) {
        printf("[UAC_COMM_ERR]%s()/line %d : get mac from json failed.\n","uac_com_get_site_id",
               0x349);
      }
      cJSON_Delete(iVar1);
      goto LAB_00513d18;
    }
    if (uac_comm_err_switch == 0) goto LAB_00513d18;
    uVar3 = 0x33d;
    __format = "[UAC_COMM_ERR]%s()/line %d : get jsonrpc obj failed.\n";
  }
  printf(__format,"uac_com_get_site_id",uVar3);
LAB_00513d18:
  memcpy(param_1,"0",param_2 - 1);
  return 0;
}

