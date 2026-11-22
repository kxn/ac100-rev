// func uac_com_get_dev_extra_sales_method @ 0051696c size=1004

undefined4 uac_com_get_dev_extra_sales_method(char *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *local_2e0;
  undefined4 local_2dc;
  char *local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined2 local_2c4;
  undefined2 local_2c2;
  char *local_2c0;
  int local_2bc;
  char local_2b8 [656];
  
  memset(local_2b8,0,0x28a);
  uVar1 = dev_extra_sales_method_count;
  local_2e0 = (char *)0x0;
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_3 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_2 < 2) {
    return 0xffffffff;
  }
  if (DAT_00781b1c == 0) {
    if (uac_comm_dbg_switch != 0) {
      printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n",
             "uac_com_get_dev_extra_sales_method",0x12d);
    }
    local_2d8 = "extra_sales_method";
    dev_extra_sales_method_count = 0;
    local_2dc = 0;
    local_2d4 = 1;
    local_2c4 = 1;
    local_2d0 = 0;
    local_2cc = 0;
    local_2c8 = 0;
    local_2c2 = 0x28a;
    local_2bc = 0;
    local_2c0 = local_2b8;
    iVar4 = uac_com_uci_parse_req("device_info","info",&local_2dc,1);
    if (iVar4 == 0) {
      if ((local_2bc == 0) || (local_2b8[0] == '\0')) {
        if (uac_comm_dbg_switch != 0) {
          printf("[UAC_COMM_DBG]%s()/line %d : Read fields \'%s.%s.%s\' failed.\'.\n",
                 "uac_com_get_dev_extra_sales_method",0x13c,"device_info","info",
                 "extra_sales_method");
        }
      }
      else {
        pcVar2 = strtok_r(local_2b8,",",&local_2e0);
        while (pcVar2 != (char *)0x0) {
          if (4 < (int)dev_extra_sales_method_count) {
            if (uac_comm_err_switch != 0) {
              printf("[UAC_COMM_ERR]%s()/line %d : Extra sales method count can not exceed %d.\n",
                     "uac_com_get_dev_extra_sales_method",0x145,5);
              dev_extra_sales_method_count = 0;
              return 0xffffffff;
            }
            dev_extra_sales_method_count = 0;
            return 0xffffffff;
          }
          strncpy(&dev_extra_sales_method + dev_extra_sales_method_count * 0x81,pcVar2,0x80);
          pcVar2 = strtok_r((char *)0x0,",",&local_2e0);
          dev_extra_sales_method_count = dev_extra_sales_method_count + 1;
        }
      }
      uVar1 = dev_extra_sales_method_count;
      iVar4 = 0;
      DAT_00781b1c = 1;
      *param_3 = dev_extra_sales_method_count;
      iVar5 = (int)&dev_extra_sales_method - (int)param_1;
      while( true ) {
        if ((int)uVar1 <= iVar4) {
          return 0;
        }
        if (param_1 == (char *)0x0) break;
        strncpy(param_1,param_1 + iVar5,0x80);
        iVar4 = iVar4 + 1;
        param_1[0x80] = '\0';
        param_1 = param_1 + 0x81;
      }
      if (uac_comm_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x155;
      pcVar2 = "[UAC_COMM_ERR]%s()/line %d : Input error.\n";
    }
    else {
      if (uac_comm_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x137;
      pcVar2 = "[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n";
    }
  }
  else if (param_2 < dev_extra_sales_method_count) {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar3 = 0x11d;
    pcVar2 = "[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n";
  }
  else {
    iVar4 = 0;
    iVar5 = (int)&dev_extra_sales_method - (int)param_1;
    while( true ) {
      if ((int)uVar1 <= iVar4) {
        return 0;
      }
      if (param_1 == (char *)0x0) break;
      strncpy(param_1,param_1 + iVar5,0x80);
      iVar4 = iVar4 + 1;
      param_1[0x80] = '\0';
      param_1 = param_1 + 0x81;
    }
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar3 = 0x124;
    pcVar2 = "[UAC_COMM_ERR]%s()/line %d : Input error.\n";
  }
  printf(pcVar2,"uac_com_get_dev_extra_sales_method",uVar3);
  return 0xffffffff;
}

