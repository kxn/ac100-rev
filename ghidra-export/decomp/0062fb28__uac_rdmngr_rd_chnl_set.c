// func _uac_rdmngr_rd_chnl_set @ 0062fb28 size=908

int _uac_rdmngr_rd_chnl_set(undefined4 param_1,short param_2)

{
  undefined2 uVar3;
  int iVar1;
  int iVar2;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_390 [12];
  short local_384;
  undefined4 local_33c [3];
  short local_330;
  char local_2f4;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  char local_123;
  
  memset(auStack_2e8,0,0x2d8);
  memset(local_33c,0,0x54);
  memset(auStack_390,0,0x54);
  uVar3 = rdmngr_db_generate_ap_id(param_1);
  iVar1 = apmngr_db_entry_get_by_id(uVar3,auStack_2e8);
  if ((iVar1 != 0) || (iVar1 = rdmngr_db_rd_entry_get(param_1,local_33c), iVar1 != 0)) {
    iVar1 = -1;
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return -1;
    }
    pcVar4 = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n";
    uVar5 = 0xbd4;
LAB_0062fc60:
    printf(pcVar4,"_uac_rdmngr_rd_chnl_set",uVar5,param_1);
    return iVar1;
  }
  rdmngr_db_datasync_rd_chnl(param_1,(int)param_2);
  memcpy(auStack_390,local_33c,0x54);
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d, setChnl%d.\n","_uac_rdmngr_rd_chnl_set",0xbd9,param_1,
           (int)param_2);
  }
  local_330 = param_2;
  iVar1 = memcmp(auStack_390,local_33c,0x54);
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
    uVar5 = 0xbdd;
    goto LAB_0062fc60;
  }
  iVar1 = rdmngr_db_rd_entry_set(local_33c);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_330 != local_384) {
    rdmngr_db_rd_update(param_1,2);
    rdmngr_callback_proc(2,param_1,auStack_390,local_33c);
    if ((local_123 != '\0') && (iVar1 = reset_ap_cloud_config_id_in_mem_db(local_2d8), iVar1 != 0))
    {
      if (rdmngr_err_switch == 0) {
        return -1;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return -1;
      }
      pcVar4 = "[RDMNGR_ERROR]%s()/%d reset ap cloud_config_id error in mem or db\n";
      uVar5 = 0xbec;
      goto LAB_0062fd04;
    }
  }
  if (local_2f4 == '\0') {
    return 0;
  }
  iVar1 = rdmngr_db_update_reinit_state(local_33c[0]);
  if (iVar1 == 0) {
    iVar1 = apmngr_checksum_update(auStack_2e8,0);
    if (iVar1 == 0) {
      uVar5 = rdmngr_db_generate_ap_id(local_33c[0]);
      iVar1 = rdmngr_wtp_pkt_send(uVar5,local_33c);
      if (iVar1 != 0) {
        return 0;
      }
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n","_uac_rdmngr_rd_chnl_set",0xbff,
               local_33c[0]);
      }
      rdmngr_callback_proc(0,local_33c[0],0,0);
      uVar5 = rdmngr_db_generate_ap_id(local_33c[0]);
      iVar1 = rdmngr_wtp_pkt_send(uVar5,local_33c);
      if (iVar1 != 0) {
        return 0;
      }
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n","_uac_rdmngr_rd_chnl_set",0xc03,
               local_33c[0]);
      }
      rdmngr_callback_proc(1,local_33c[0],0,0);
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
    uVar5 = 0xbfa;
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
    uVar5 = 0xbf5;
  }
LAB_0062fd04:
  printf(pcVar4,"_uac_rdmngr_rd_chnl_set",uVar5);
  return -1;
}

