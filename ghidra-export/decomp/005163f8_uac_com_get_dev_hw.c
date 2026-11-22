// func uac_com_get_dev_hw @ 005163f8 size=464

undefined4 uac_com_get_dev_hw(void *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_c0;
  char *local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined2 local_a8;
  undefined2 local_a6;
  char *local_a4;
  undefined4 local_a0;
  char acStack_9c [136];
  
  memset(acStack_9c,0,0x81);
  if (param_1 != (void *)0x0) {
    if (DAT_00781e4c != 0) {
LAB_00516588:
      memcpy(param_1,&dev_hw_ver,8);
      return 0;
    }
    if (uac_comm_dbg_switch != 0) {
      printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n","uac_com_get_dev_hw",
             0x1d1);
    }
    local_bc = "hw_version";
    local_c0 = 0;
    local_b8 = 1;
    local_b4 = 1;
    local_b0 = 0;
    local_ac = 0;
    local_a8 = 1;
    local_a6 = 0x81;
    local_a0 = 0;
    local_a4 = acStack_9c;
    iVar1 = uac_com_uci_parse_req("device_info","info",&local_c0,1);
    if (iVar1 == 0) {
      iVar1 = sscanf(acStack_9c,"%d.%d",&dev_hw_ver,&DAT_00781e54);
      if (iVar1 == 2) {
        DAT_00781e4c = 1;
        goto LAB_00516588;
      }
      if (uac_comm_err_switch != 0) {
        uVar2 = 0x1e3;
        __format = "[UAC_COMM_ERR]%s()/line %d : get hwver failed.\n";
        goto LAB_0051654c;
      }
    }
    else if (uac_comm_err_switch != 0) {
      uVar2 = 0x1da;
      __format = "[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n";
LAB_0051654c:
      printf(__format,"uac_com_get_dev_hw",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

