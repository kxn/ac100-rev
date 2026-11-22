// func acpdt_wtp_radio_information_list_add @ 0040a0d4 size=412

undefined4 acpdt_wtp_radio_information_list_add(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint local_c8;
  int local_c4;
  undefined4 local_c0;
  byte local_bc [32];
  undefined4 local_9c [33];
  
  memset(local_bc,0,0x20);
  memset(local_9c,0,0x80);
  local_c8 = 0;
  if (param_1 == 0) {
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
    uVar2 = 0x166;
  }
  else {
    iVar1 = apdb_get_multi_radios_stat_by_id(param_2,param_3,local_bc,local_9c,&local_c8);
    if (iVar1 == -1) {
      if (g_acpdt_error == 0) {
        return 0xffffffff;
      }
      __format = "[ACPDT_ERROR] %32s() %05d: get radio from apdb failed.\r\n";
      uVar2 = 0x16d;
    }
    else {
      puVar3 = local_9c;
      uVar4 = 0;
      while( true ) {
        if (local_c8 <= uVar4) {
          return 0;
        }
        local_c0 = *puVar3;
        puVar3 = puVar3 + 1;
        local_c4 = (uint)local_bc[uVar4] << 0x18;
        iVar1 = cw_service_msg_add(param_1,0x418,&local_c4,0);
        if (iVar1 == -1) break;
        uVar4 = uVar4 + 1;
      }
      if (g_acpdt_error != 0) {
        printf("[ACPDT_ERROR] %32s() %05d: add wtp radio information to parsed packet failed.\r\n",
               "acpdt_wtp_radio_information_add",0x154);
      }
      if (g_acpdt_error == 0) {
        return 0xffffffff;
      }
      __format = "[ACPDT_ERROR] %32s() %05d: add radio information failed.\r\n";
      uVar2 = 0x176;
    }
  }
  printf(__format,"acpdt_wtp_radio_information_list_add",uVar2);
  return 0xffffffff;
}

