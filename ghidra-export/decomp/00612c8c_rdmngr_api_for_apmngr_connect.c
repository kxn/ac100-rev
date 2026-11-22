// func rdmngr_api_for_apmngr_connect @ 00612c8c size=508

undefined4 rdmngr_api_for_apmngr_connect(int param_1)

{
  undefined2 uVar3;
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar4;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  if (param_1 == 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d Invalid ap entry.\n";
    uVar4 = 0x70;
  }
  else {
    if (rdmngr_debug_switch == 0) {
      uVar3 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = *(undefined2 *)(param_1 + 0x44);
      }
      else {
        printf("[RDMNGR_DEBUG]%s()/%d in rdmngr_api_for_apmngr_connect(), ap_firm is %d.\n",
               "rdmngr_api_for_apmngr_connect",0x74,*(undefined4 *)(param_1 + 0x3c));
        uVar3 = *(undefined2 *)(param_1 + 0x44);
      }
    }
    local_14 = CONCAT22(uVar3,*(undefined2 *)(param_1 + 0x46));
    iVar1 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_14);
    if (iVar1 < 0) {
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
             "rdmngr_api_for_apmngr_connect",0x7c,iVar1);
      return 0xffffffff;
    }
    rdmngr_db_ap_connect(param_1,iVar1,*(undefined4 *)(param_1 + 0x40));
    iVar1 = mesh_db_bh_work_mode_get(&local_18);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x14);
      if ((((iVar1 != 4) && (iVar1 != 8)) && (iVar1 != 6)) && (iVar1 != 5)) {
        return 0;
      }
      iVar1 = mesh_set_rd_cfg_to_re_handle(param_1,local_18,0);
      if (iVar1 == 0) {
        return 0;
      }
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[RDMNGR_ERROR]%s()/%d cap rf config sync to re failed\n";
      uVar4 = 0x8c;
    }
    else {
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[RDMNGR_ERROR]%s()/%d get bh_work_mode failed\n";
      uVar4 = 0x84;
    }
  }
  printf(__format,"rdmngr_api_for_apmngr_connect",uVar4);
  return 0xffffffff;
}

