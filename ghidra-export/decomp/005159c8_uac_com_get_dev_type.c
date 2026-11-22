// func uac_com_get_dev_type @ 005159c8 size=324

undefined4 uac_com_get_dev_type(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_38 [40];
  
  uVar2 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (1 < param_2)) {
    if (DAT_00781f70 == 0) {
      if (uac_comm_dbg_switch != 0) {
        printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n",
               "uac_com_get_dev_type",0x27a);
      }
      memcpy(auStack_38,PTR_DAT_007591ac + 0x1e18,0x24);
      iVar1 = uac_com_uci_parse_req("device_info","info",auStack_38,1);
      if (iVar1 != 0) {
        if (uac_comm_err_switch == 0) {
          return 0xffffffff;
        }
        printf("[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n","uac_com_get_dev_type",0x283);
        return 0xffffffff;
      }
      DAT_00781f70 = 1;
    }
    uVar2 = 0;
    strncpy(param_1,&dev_type,param_2 - 1);
    param_1[param_2 + -1] = '\0';
  }
  return uVar2;
}

