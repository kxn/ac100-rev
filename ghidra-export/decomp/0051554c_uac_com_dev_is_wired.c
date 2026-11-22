// func uac_com_dev_is_wired @ 0051554c size=200

bool uac_com_dev_is_wired(void)

{
  int iVar1;
  char local_30 [4];
  undefined4 local_2c;
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  char *local_10;
  undefined4 local_c;
  
  local_28 = "radio_count";
  local_30[0] = '\0';
  local_2c = 0;
  local_18 = 10;
  local_24 = 0;
  local_14 = 1;
  local_12 = 1;
  local_10 = local_30;
  local_20 = 0;
  local_1c = 0;
  local_c = 0;
  iVar1 = uac_com_uci_parse_req("device_info","info",&local_2c,1);
  if (iVar1 != 0) {
    if (uac_comm_err_switch == 0) {
      local_30[0] = '\0';
    }
    else {
      printf("[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n","uac_com_dev_is_wired",0x4cf);
      local_30[0] = '\0';
    }
  }
  return local_30[0] == '\0';
}

