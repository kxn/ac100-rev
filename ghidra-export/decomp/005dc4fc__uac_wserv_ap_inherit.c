// func _uac_wserv_ap_inherit @ 005dc4fc size=584

undefined4 _uac_wserv_ap_inherit(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 local_28;
  undefined2 local_26;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ap_inherit() begin.\r\n","_uac_wserv_ap_inherit",
           0x1188);
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar4 = 0xffffffff;
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> invalid args!\r\n";
    uVar3 = 0x118c;
  }
  else if (*(int *)(param_1 + 0x40) == *(int *)(param_2 + 0x40)) {
    local_28 = *(undefined2 *)(param_1 + 0x44);
    iVar5 = 1;
    local_26 = *(undefined2 *)(param_1 + 0x46);
    iVar1 = uac_wservice_get_ap_radio_cnt(*(int *)(param_1 + 0x40),param_1 + 0x218,&local_28);
    if (iVar1 < 0) {
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
             "_uac_wserv_ap_inherit",0x119c,iVar1);
      return 0xffffffff;
    }
    while (iVar5 <= iVar1) {
      uVar4 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_2 + 0x10),iVar5);
      uVar3 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar5);
      iVar2 = rdmngr_db_get_rd_status(uVar4);
      if (iVar2 == 0) {
        iVar5 = iVar5 + 1;
      }
      else {
        iVar2 = wserv_db_rd_inherit(uVar4,uVar3);
        if (iVar2 != 0) {
          uVar4 = 0xffffffff;
          if (g_wserv_error == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "<wserv>[error]%s(): %d  -> wserv_db_rd_inherit() fail.\r\n";
          uVar3 = 0x11aa;
          goto LAB_005dc60c;
        }
        iVar5 = iVar5 + 1;
      }
    }
    uVar4 = 0;
    if (g_wserv_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wserv>[debug]%s(): %d  -> _uac_wserv_ap_inherit() finish.\r\n";
    uVar3 = 0x11af;
  }
  else {
    uVar4 = 0xffffffff;
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> model not match!!!\r\n";
    uVar3 = 0x1192;
  }
LAB_005dc60c:
  printf(__format,"_uac_wserv_ap_inherit",uVar3);
  return uVar4;
}

