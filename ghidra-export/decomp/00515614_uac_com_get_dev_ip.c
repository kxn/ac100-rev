// func uac_com_get_dev_ip @ 00515614 size=364

int uac_com_get_dev_ip(char *param_1,int param_2)

{
  int iVar1;
  undefined4 local_b8;
  char *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  char *local_9c;
  undefined4 local_98;
  char acStack_94 [132];
  
  memset(acStack_94,0,0x81);
  local_b8 = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_98 = 0;
  local_b4 = "ipaddr";
  local_b0 = 1;
  local_ac = 1;
  local_a0 = 1;
  local_9e = 0x81;
  local_9c = acStack_94;
  if ((param_1 == (char *)0x0) || (param_2 < 1)) {
    iVar1 = -1;
    if (uac_comm_err_switch != 0) {
      printf("[UAC_COMM_ERR]%s()/line %d : invalid params.\n\n","uac_com_get_dev_ip",0x473);
    }
  }
  else if ((g_ac_ip == '\0') || (iVar1 = uac_com_update_dev_ip(), iVar1 != 0)) {
    iVar1 = uac_com_uci_parse_req("network","default",&local_b8,1);
    if (iVar1 == 0) {
      strncpy(param_1,acStack_94,param_2 - 1);
      param_1[param_2 + -1] = '\0';
    }
  }
  else {
    iVar1 = 0;
    strncpy(param_1,&g_ac_ip,param_2 - 1);
    param_1[param_2 + -1] = '\0';
  }
  return iVar1;
}

