// func uac_cfg_trigger_save @ 00513048 size=172

void uac_cfg_trigger_save(int param_1)

{
  char acStack_70 [104];
  
  memset(acStack_70,0,100);
  if (param_1 < 0) {
    if (uac_cfg_err_switch != 0) {
      printf("[UAC_CFG_ERROR]%s()/line %d : Input error\n","uac_cfg_trigger_save",0x1c5);
    }
  }
  else {
    snprintf(acStack_70,100,"cfgSave -d %d >/dev/null",param_1);
    system(acStack_70);
  }
  return;
}

