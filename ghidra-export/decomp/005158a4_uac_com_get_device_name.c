// func uac_com_get_device_name @ 005158a4 size=292

undefined4 uac_com_get_device_name(char *param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_38 [40];
  
  if ((param_1 == (char *)0x0) || (param_2 < 1)) {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x414;
    __format = "[UAC_COMM_ERR]%s()/line %d : param is null.\n\n";
  }
  else {
    memcpy(auStack_38,PTR_DAT_007591ac + 0x1df4,0x24);
    if ((dev_name != '\0') ||
       (iVar1 = uac_com_uci_parse_req("system",&DAT_00699be8,auStack_38,1), iVar1 == 0)) {
      strncpy(param_1,&dev_name,param_2 - 1);
      param_1[param_2 + -1] = '\0';
      return 0;
    }
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x421;
    __format = "[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n";
  }
  printf(__format,"uac_com_get_device_name",uVar2);
  return 0xffffffff;
}

