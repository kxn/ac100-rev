// func uac_com_update_config_id @ 00514614 size=188

undefined4 uac_com_update_config_id(char *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uVar1 = 0xffffffff;
    if (uac_comm_err_switch != 0) {
      printf("[UAC_COMM_ERR]%s()/line %d : param is null.\n\n","uac_com_update_config_id",0x43e);
    }
  }
  else {
    memset(&g_config_id,0,0x81);
    uVar1 = 0;
    strncpy(&g_config_id,param_1,0x80);
  }
  return uVar1;
}

