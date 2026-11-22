// func _uac_rdmngr_rd_chnl_bw_set @ 006301e8 size=976

int _uac_rdmngr_rd_chnl_bw_set(undefined4 param_1,short param_2,short param_3)

{
  undefined2 uVar3;
  int iVar1;
  int iVar2;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_398 [12];
  short local_38c;
  undefined4 local_344 [2];
  undefined1 local_33a;
  short local_338;
  char local_2fc;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  char local_12b;
  
  memset(auStack_2f0,0,0x2d8);
  memset(local_344,0,0x54);
  memset(auStack_398,0,0x54);
  memset(auStack_2f0,0,0x2d8);
  memset(local_344,0,0x54);
  memset(auStack_398,0,0x54);
  uVar3 = rdmngr_db_generate_ap_id(param_1);
  iVar1 = apmngr_db_entry_get_by_id(uVar3,auStack_2f0);
  if ((iVar1 != 0) || (iVar1 = rdmngr_db_rd_entry_get(param_1,local_344), iVar1 != 0)) {
    iVar1 = -1;
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return -1;
    }
    pcVar4 = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n";
    uVar5 = 0xc69;
LAB_00630364:
    printf(pcVar4,"_uac_rdmngr_rd_chnl_bw_set",uVar5,param_1);
    return iVar1;
  }
  rdmngr_db_datasync_rd_chnl_bw(param_1,(int)param_2,(int)param_3);
  memcpy(auStack_398,local_344,0x54);
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d, setChnl%d.\n","_uac_rdmngr_rd_chnl_bw_set",0xc6f,param_1
           ,(int)param_2);
  }
  local_33a = (undefined1)param_3;
  local_338 = param_2;
  iVar1 = memcmp(auStack_398,local_344,0x54);
  if (iVar1 == 0) {
    iVar1 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar4 = "[RDMNGR_DEBUG]%s()/%d rd_id[%d] cfg no change\n";
    uVar5 = 0xc74;
    goto LAB_00630364;
  }
  iVar1 = rdmngr_db_rd_entry_set(local_344);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_338 != local_38c) {
    rdmngr_db_rd_update(param_1,2);
    rdmngr_callback_proc(2,param_1,auStack_398,local_344);
    if ((local_12b != '\0') && (iVar1 = reset_ap_cloud_config_id_in_mem_db(local_2e0), iVar1 != 0))
    {
      if (rdmngr_err_switch == 0) {
        return -1;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return -1;
      }
      pcVar4 = "[RDMNGR_ERROR]%s()/%d reset ap cloud_config_id error in mem or db\n";
      uVar5 = 0xc83;
      goto LAB_00630408;
    }
  }
  if (local_2fc == '\0') {
    return 0;
  }
  iVar1 = rdmngr_db_update_reinit_state(local_344[0]);
  if (iVar1 == 0) {
    iVar1 = apmngr_checksum_update(auStack_2f0,0);
    if (iVar1 == 0) {
      uVar5 = rdmngr_db_generate_ap_id(local_344[0]);
      iVar1 = rdmngr_wtp_pkt_send(uVar5,local_344);
      if (iVar1 != 0) {
        return 0;
      }
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n","_uac_rdmngr_rd_chnl_bw_set",0xc96,
               local_344[0]);
      }
      rdmngr_callback_proc(0,local_344[0],0,0);
      uVar5 = rdmngr_db_generate_ap_id(local_344[0]);
      iVar1 = rdmngr_wtp_pkt_send(uVar5,local_344);
      if (iVar1 != 0) {
        return 0;
      }
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n","_uac_rdmngr_rd_chnl_bw_set",0xc9a,
               local_344[0]);
      }
      rdmngr_callback_proc(1,local_344[0],0,0);
      return 0;
    }
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar4 = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
    uVar5 = 0xc91;
  }
  else {
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar4 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
    uVar5 = 0xc8c;
  }
LAB_00630408:
  printf(pcVar4,"_uac_rdmngr_rd_chnl_bw_set",uVar5);
  return -1;
}

