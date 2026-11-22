// func _uac_rdmngr_rd_cfg_changed_by_mesh @ 0062feb4 size=820

int _uac_rdmngr_rd_cfg_changed_by_mesh(undefined4 *param_1,int param_2)

{
  undefined2 uVar2;
  int iVar1;
  char cVar3;
  char *__format;
  undefined4 uVar4;
  undefined1 auStack_340 [88];
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  char local_123;
  
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_340,0,0x54);
  if (param_1 == (undefined4 *)0x0) {
    return -1;
  }
  uVar2 = rdmngr_db_generate_ap_id(*param_1);
  iVar1 = apmngr_db_entry_get_by_id(uVar2,auStack_2e8);
  if ((iVar1 != 0) || (iVar1 = rdmngr_db_rd_entry_get(*param_1,auStack_340), iVar1 != 0)) {
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    printf("[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n",
           "_uac_rdmngr_rd_cfg_changed_by_mesh",0xc1f,*param_1);
    return -1;
  }
  iVar1 = rdmngr_db_rd_entry_set(param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 == 0) {
    iVar1 = apmngr_checksum_update(auStack_2e8,0);
    if (iVar1 == 0) {
      return 0;
    }
    if (rdmngr_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
    uVar4 = 0xc29;
  }
  else {
    iVar1 = memcmp(auStack_340,param_1,0x54);
    if (iVar1 == 0) {
      return 0;
    }
    rdmngr_callback_proc(2,*param_1,auStack_340,param_1);
    if (local_123 == '\0') {
      cVar3 = *(char *)(param_1 + 0x12);
    }
    else {
      iVar1 = reset_ap_cloud_config_id_in_mem_db(local_2d8);
      if (iVar1 != 0) {
        if (rdmngr_err_switch == 0) {
          return -1;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return -1;
        }
        __format = "[RDMNGR_ERROR]%s()/%d reset ap cloud_config_id error in mem or db\n";
        uVar4 = 0xc36;
        goto LAB_00630000;
      }
      cVar3 = *(char *)(param_1 + 0x12);
    }
    if (cVar3 == '\0') {
      return 0;
    }
    iVar1 = rdmngr_db_update_reinit_state(*param_1);
    if (iVar1 == 0) {
      iVar1 = apmngr_checksum_update(auStack_2e8,0);
      if (iVar1 == 0) {
        uVar4 = rdmngr_db_generate_ap_id(*param_1);
        iVar1 = rdmngr_wtp_pkt_send(uVar4,param_1);
        if (iVar1 != 0) {
          return 0;
        }
        if (rdmngr_debug_switch == 0) {
          uVar4 = *param_1;
        }
        else {
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            uVar4 = *param_1;
          }
          else {
            printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n",
                   "_uac_rdmngr_rd_cfg_changed_by_mesh",0xc48,*param_1);
            uVar4 = *param_1;
          }
        }
        rdmngr_callback_proc(0,uVar4,0,0);
        uVar4 = rdmngr_db_generate_ap_id(*param_1);
        iVar1 = rdmngr_wtp_pkt_send(uVar4,param_1);
        if (iVar1 != 0) {
          return 0;
        }
        if (rdmngr_debug_switch == 0) {
          uVar4 = *param_1;
        }
        else {
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            uVar4 = *param_1;
          }
          else {
            printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n","_uac_rdmngr_rd_cfg_changed_by_mesh",
                   0xc4c,*param_1);
            uVar4 = *param_1;
          }
        }
        rdmngr_callback_proc(1,uVar4,0,0);
        return 0;
      }
      if (rdmngr_err_switch == 0) {
        return -1;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return -1;
      }
      __format = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
      uVar4 = 0xc43;
    }
    else {
      if (rdmngr_err_switch == 0) {
        return -1;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return -1;
      }
      __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
      uVar4 = 0xc3e;
    }
  }
LAB_00630000:
  printf(__format,"_uac_rdmngr_rd_cfg_changed_by_mesh",uVar4);
  return -1;
}

