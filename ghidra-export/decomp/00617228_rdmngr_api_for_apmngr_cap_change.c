// func rdmngr_api_for_apmngr_cap_change @ 00617228 size=672

undefined4 rdmngr_api_for_apmngr_cap_change(undefined4 param_1,int param_2)

{
  undefined2 uVar4;
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar5;
  char cVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  if (param_2 == 0) {
    uVar10 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[RDMNGR_ERROR]%s()/%d Invalid ap entry.\n";
    uVar8 = 0x180;
  }
  else if (*(short *)(param_2 + 0x18) == -1) {
    uVar10 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar7 = "[RDMNGR_DEBUG]%s()/%d Nothing to do.\n";
    uVar8 = 0x185;
  }
  else {
    if (rdmngr_debug_switch == 0) {
      uVar4 = *(undefined2 *)(param_2 + 0x44);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar4 = *(undefined2 *)(param_2 + 0x44);
      }
      else {
        printf("[RDMNGR_DEBUG]%s()/%d in rdmngr_api_for_apmngr_cap_change(), ap_firm is %d.\n",
               "rdmngr_api_for_apmngr_cap_change",0x188,*(undefined4 *)(param_2 + 0x3c));
        uVar4 = *(undefined2 *)(param_2 + 0x44);
      }
    }
    iVar9 = 1;
    local_28 = CONCAT22(uVar4,*(undefined2 *)(param_2 + 0x46));
    iVar1 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_2 + 0x40),param_2 + 0x218,&local_28);
    if (iVar1 < 0) {
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar9 = is_target_debug_ap();
      if (iVar9 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n";
      uVar10 = 400;
LAB_006173e8:
      printf(pcVar7,"rdmngr_api_for_apmngr_cap_change",uVar10,iVar1);
      return 0xffffffff;
    }
    for (; iVar9 <= iVar1; iVar9 = iVar9 + 1) {
      iVar2 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_2 + 0x10),iVar9);
      iVar3 = rdmngr_db_get_freq_band_idx(iVar2,&local_2c,&local_30);
      if (iVar3 != 0) {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar7 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_freq_band_idx() of %d fail.\n";
        uVar10 = 0x198;
        iVar1 = iVar2;
        goto LAB_006173e8;
      }
      cVar5 = rdmngr_db_get_rd_status(iVar2);
      iVar3 = rdmngr_db_get_closet_freq_band_rd_id
                        ((int)*(short *)(param_2 + 0x18),local_2c,local_30);
      cVar6 = '\x01';
      if (iVar3 != -1) {
        cVar6 = rdmngr_db_get_rd_status(iVar3);
      }
      if (cVar5 != cVar6) {
        rdmngr_rf_state_set(iVar2,cVar6 == '\x01',0);
      }
    }
    if (*(char *)(param_2 + 0x1c5) == '\0') {
      return 0;
    }
    iVar1 = reset_ap_cloud_config_id_in_mem_db(*(undefined2 *)(param_2 + 0x10));
    if (iVar1 == 0) {
      return 0;
    }
    uVar10 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[RDMNGR_ERROR]%s()/%d reset ap cloud_config_id error in mem or db\n";
    uVar8 = 0x1a9;
  }
  printf(pcVar7,"rdmngr_api_for_apmngr_cap_change",uVar8);
  return uVar10;
}

