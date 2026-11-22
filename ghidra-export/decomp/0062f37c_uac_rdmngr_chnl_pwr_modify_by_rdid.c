// func uac_rdmngr_chnl_pwr_modify_by_rdid @ 0062f37c size=1964

int uac_rdmngr_chnl_pwr_modify_by_rdid
              (uint param_1,short param_2,int param_3,undefined4 param_4,uint param_5,int param_6,
              int param_7)

{
  int iVar1;
  undefined2 uVar6;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar7;
  char cVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint local_3f0;
  int local_3ec;
  int local_3e8;
  undefined1 auStack_3a0 [12];
  short local_394;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  char local_33c [84];
  undefined2 local_2e8;
  int local_2e4;
  undefined4 local_2b8;
  char local_133;
  undefined1 auStack_e0 [192];
  
  memset(&local_34c,0,0x54);
  memset(auStack_3a0,0,0x54);
  memset(local_33c + 0x44,0,0x2d8);
  iVar1 = rdmngr_db_rd_entry_get(param_1,&local_34c);
  if (iVar1 != 0) {
    if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      return -1;
    }
    pcVar9 = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n";
    uVar10 = 0xabd;
LAB_0062f494:
    printf(pcVar9,"uac_rdmngr_chnl_pwr_modify_by_rdid",uVar10,param_1);
    return -1;
  }
  uVar6 = rdmngr_db_generate_ap_id(param_1);
  iVar1 = apmngr_db_entry_get_by_id(uVar6,local_33c + 0x44);
  if (iVar1 != 0) {
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar9 = "[RDMNGR_ERROR]%s()/%d rd_id:%d, apmngr_db_entry_get_by_id() failed.\n";
    uVar10 = 0xac3;
    goto LAB_0062f494;
  }
  local_3f0 = param_5;
  local_3ec = param_6;
  local_3e8 = param_7;
  rdmngr_db_datasync_rd_chnl_bw_pwr(param_1,(int)param_2,param_3,param_4);
  memcpy(auStack_3a0,&local_34c,0x54);
  if (param_3 == 0) {
LAB_0062f4f0:
    if (param_5 == 0) goto LAB_0062f4f8;
LAB_0062f70c:
    uVar3 = param_1 & 0xf;
    iVar1 = (int)local_344._0_1_;
    local_344._2_2_ = CONCAT11((char)param_4,(undefined1)local_344);
    iVar1 = apdb_support_160M_by_id(local_2b8,auStack_e0,uVar3,iVar1);
    iVar2 = apdb_support_11ac_by_id(local_2b8,auStack_e0,uVar3,(int)local_344._0_1_);
    iVar4 = apdb_support_11ax_by_id(local_2b8,auStack_e0,uVar3,(int)local_344._0_1_);
    iVar5 = apdb_support_11be_by_id(local_2b8,auStack_e0,uVar3,(int)local_344._0_1_);
    if (local_344._1_1_ == '\t') {
      cVar8 = local_344._0_1_;
      if (iVar2 == 0) {
        local_344._1_3_ = CONCAT12(7,local_344._2_2_);
        goto LAB_0062f77c;
      }
    }
    else {
LAB_0062f77c:
      cVar8 = local_344._0_1_;
    }
    cVar7 = local_344._1_1_;
    if (cVar8 != '\0') {
      if (cVar8 != '\x01') goto LAB_0062f4f8;
      if (cVar7 == '\0') {
        if (local_344._2_1_ == '\0') {
          local_344._2_2_ = CONCAT11(2,(undefined1)local_344);
          goto LAB_0062f95c;
        }
        if (local_344._2_1_ == '\x01') {
          if (iVar5 == 0) {
            if (iVar4 != 0) goto LAB_0062fa30;
            if (iVar2 == 0) goto LAB_0062fa9c;
            goto LAB_0062fa5c;
          }
          goto LAB_0062faa4;
        }
      }
      else {
        if (local_344._2_1_ == '\x03') {
          if ((iVar4 == 0 && iVar2 == 0) && iVar5 == 0) {
LAB_0062fa98:
            local_344 = CONCAT22(local_344._0_2_,CONCAT11(1,(undefined1)local_344));
LAB_0062fa9c:
            local_344._1_3_ = CONCAT12(7,local_344._2_2_);
            goto LAB_0062f95c;
          }
        }
        else {
          if (local_344._2_1_ != '\x05') goto LAB_0062f960;
          if (iVar1 == 0) {
            if ((iVar4 == 0 && iVar2 == 0) && iVar5 == 0) goto LAB_0062fa98;
            local_344._2_2_ = CONCAT11(3,(undefined1)local_344);
          }
        }
        if (iVar5 == 0) {
          if (iVar4 == 0) {
LAB_0062fa5c:
            local_344._1_3_ = CONCAT12(9,local_344._2_2_);
          }
          else {
LAB_0062fa30:
            local_344._1_3_ = CONCAT12(0xb,local_344._2_2_);
          }
        }
        else {
LAB_0062faa4:
          local_344._1_3_ = CONCAT12(0xd,local_344._2_2_);
        }
LAB_0062f95c:
        cVar7 = local_344._1_1_;
      }
LAB_0062f960:
      if (((cVar7 == '\0') || (local_344._2_1_ == '\0')) || (local_340._0_2_ != 0xa5))
      goto LAB_0062f4f8;
      local_340 = CONCAT22(0xffff,local_340._2_2_);
      if (param_7 == 0) goto LAB_0062f514;
      goto LAB_0062f504;
    }
    if ((1 < ((int)cVar7 - 1U & 0xff)) && (cVar7 != 5)) goto LAB_0062f4f8;
    if (local_344._2_1_ != '\0') {
      if (local_344._2_1_ != '\x01') goto LAB_0062f4f8;
      cVar8 = '\f';
      if ((iVar5 == 0) && (cVar8 = '\n', iVar4 == 0)) {
        local_344._1_1_ = '\x06';
        cVar8 = local_344._1_1_;
      }
      local_344 = CONCAT13(local_344._0_1_,CONCAT12(cVar8,local_344._2_2_));
      if (param_7 != 0) goto LAB_0062f504;
      iVar1 = (int)cVar8;
      goto LAB_0062f518;
    }
    local_344._2_2_ = CONCAT11(2,(undefined1)local_344);
    if (param_7 != 0) goto LAB_0062f504;
LAB_0062f514:
    iVar1 = (int)local_344._1_1_;
  }
  else {
    local_340 = CONCAT22(param_2,local_340._2_2_);
    iVar1 = _uac_rdmngr_check_rd_chnl(local_2b8,auStack_e0,param_1 & 0xf,&local_348);
    if (iVar1 != 1) {
      if ((rdmngr_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        local_3ec = (int)local_394;
        local_3f0 = param_1;
        printf("[RDMNGR_WARNING]%s()/%d channel(%d) of radioId(%d) is Invalid, remains as old value(%d).\n"
               ,"uac_rdmngr_chnl_pwr_modify_by_rdid",0xad1,(int)local_340._0_2_);
      }
      local_340 = CONCAT22(local_394,local_340._2_2_);
    }
    iVar1 = apdb_is_hdap_by_id(local_2b8,auStack_e0);
    if (((iVar1 == 0) || (0xb < (int)local_340._0_2_ - 2U)) || (local_340._0_2_ == 0xb))
    goto LAB_0062f4f0;
    local_340 = CONCAT22(0xffff,local_340._2_2_);
    if (param_5 != 0) goto LAB_0062f70c;
LAB_0062f4f8:
    iVar1 = (int)local_344._1_1_;
    if (param_7 != 0) {
LAB_0062f504:
      if (param_6 - 1U < 10) {
        local_33c[9] = (char)param_6;
      }
      else if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
        local_33c[9] = 1;
      }
      else {
        printf("[RDMNGR_ERROR]%s()/%d invalid pwr_level: %d. Will set min:1\n",
               "uac_rdmngr_chnl_pwr_modify_by_rdid",0xb75,param_6);
        local_33c[9] = 1;
      }
      goto LAB_0062f514;
    }
  }
LAB_0062f518:
  if (((((1 < (iVar1 - 3U & 0xff)) && (iVar1 != 6)) && (iVar1 != 7)) &&
      (((iVar1 != 8 && (iVar1 != 9)) && ((iVar1 != 10 && ((iVar1 != 0xb && (iVar1 != 0xc)))))))) &&
     (iVar1 != 0xd)) {
    local_344._2_2_ = CONCAT11(2,(undefined1)local_344);
  }
  iVar1 = rdmngr_db_rd_entry_set(&local_34c);
  if ((iVar1 == 0) && (iVar2 = memcmp(auStack_3a0,&local_34c,0x54), iVar2 != 0)) {
    rdmngr_db_rd_update(param_1,2);
    rdmngr_callback_proc(2,param_1,auStack_3a0,&local_34c);
    if ((local_133 != '\0') && (iVar2 = reset_ap_cloud_config_id_in_mem_db(local_2e8), iVar2 != 0))
    {
      if (rdmngr_err_switch == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      pcVar9 = "[RDMNGR_ERROR]%s()/%d reset ap cloud_config_id error in mem or db\n";
      uVar10 = 0xb9e;
      goto LAB_0062f608;
    }
  }
  if (local_33c[0x38] != '\0') {
    iVar2 = rdmngr_db_update_reinit_state(param_1);
    if (iVar2 != 0) {
      if (rdmngr_err_switch == 0) {
        return iVar1;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return iVar1;
      }
      pcVar9 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
      uVar10 = 0xba9;
      goto LAB_0062f608;
    }
    iVar2 = apmngr_checksum_update(local_33c + 0x44,0);
    if (iVar2 != 0) {
      if (rdmngr_err_switch == 0) {
        return iVar1;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return iVar1;
      }
      pcVar9 = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
      uVar10 = 0xbaf;
      goto LAB_0062f608;
    }
    uVar10 = rdmngr_db_generate_ap_id(param_1);
    iVar2 = rdmngr_wtp_pkt_send(uVar10,&local_34c);
    if (iVar2 == 0) {
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n","uac_rdmngr_chnl_pwr_modify_by_rdid",
               0xbb4,param_1);
      }
      rdmngr_callback_proc(0,param_1,0,0);
      uVar10 = rdmngr_db_generate_ap_id(param_1);
      iVar2 = rdmngr_wtp_pkt_send(uVar10,&local_34c);
      if (iVar2 == 0) {
        if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(1), iVar2 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n","uac_rdmngr_chnl_pwr_modify_by_rdid",
                 3000,param_1);
        }
        rdmngr_callback_proc(1,param_1,0,0);
      }
    }
  }
  for (uVar3 = 0; uVar3 < 0x44; uVar3 = uVar3 + 1) {
    *(char *)((int)&local_3f0 + uVar3) = local_33c[uVar3];
  }
  iVar2 = FUN_006270b4(local_34c,local_348,local_344,local_340);
  if (iVar2 == 0) {
    if (((local_2e4 != 1) && (local_2e4 != 3)) && (local_2e4 != 2)) {
      return iVar1;
    }
    _mesh_sync_rf_entry_to_re_handle(local_2e8);
    return iVar1;
  }
  if (rdmngr_err_switch == 0) {
    return iVar1;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return iVar1;
  }
  pcVar9 = "[RDMNGR_ERROR]%s()/%d _uac_rdmngr_linked_modify() failed.\n";
  uVar10 = 0xbc0;
LAB_0062f608:
  printf(pcVar9,"uac_rdmngr_chnl_pwr_modify_by_rdid",uVar10);
  return iVar1;
}

