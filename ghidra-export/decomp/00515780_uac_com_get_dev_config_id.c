// func uac_com_get_dev_config_id @ 00515780 size=292

undefined4 uac_com_get_dev_config_id(char *param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_38 [40];
  
  if ((param_1 == (char *)0x0) || (param_2 < 1)) {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x44d;
    __format = "[UAC_COMM_ERR]%s()/line %d : param is null.\n\n";
  }
  else {
    memcpy(auStack_38,PTR_DAT_007591ac + 0x1dd0,0x24);
    if ((g_config_id != '\0') ||
       (iVar1 = uac_com_uci_parse_req("cloud_sync","config_id",auStack_38,1), iVar1 == 0)) {
      strncpy(param_1,&g_config_id,param_2 - 1);
      param_1[param_2 + -1] = '\0';
      return 0;
    }
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x45a;
    __format = "[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n";
  }
  printf(__format,"uac_com_get_dev_config_id",uVar2);
  return 0xffffffff;
}

