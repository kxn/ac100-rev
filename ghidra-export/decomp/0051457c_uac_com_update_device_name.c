// func uac_com_update_device_name @ 0051457c size=152

undefined4 uac_com_update_device_name(char *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uVar1 = 0xffffffff;
    if (uac_comm_err_switch != 0) {
      printf("[UAC_COMM_ERR]%s()/line %d : param is null.\n\n","uac_com_update_device_name",0x431);
    }
  }
  else {
    strncpy(&dev_name,param_1,0x80);
    param_1[0x80] = '\0';
    uVar1 = 0;
  }
  return uVar1;
}

