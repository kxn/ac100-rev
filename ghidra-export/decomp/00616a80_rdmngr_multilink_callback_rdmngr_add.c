// func rdmngr_multilink_callback_rdmngr_add @ 00616a80 size=944

undefined4 rdmngr_multilink_callback_rdmngr_add(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  int local_354 [18];
  char local_30c;
  undefined1 local_306;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined2 local_2bc;
  undefined2 local_2ba;
  undefined1 auStack_e8 [192];
  
  param_1 = param_1 & 0xffff;
  local_368 = 0;
  memset(local_354,0,0x54);
  local_364 = 0;
  local_360 = 0;
  local_35c = 0;
  local_358 = 0;
  memset(auStack_300,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_300);
  if (iVar1 == -1) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[RDMNGR_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar5 = 0x815;
  }
  else {
    local_368 = CONCAT22(local_2bc,local_2ba);
    iVar1 = apdb_get_radio_extend_capability(local_2c0,auStack_e8,1,0xffffffff,&local_364,0x10);
    if (iVar1 == 0) {
      iVar6 = 1;
      iVar1 = rdmngr_db_get_ap_radio_cnt(local_2c0,auStack_e8,&local_368);
      if (iVar1 < 0) {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0xffffffff;
        }
        printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
               "rdmngr_multilink_callback_rdmngr_add",0x826,iVar1);
        return 0xffffffff;
      }
LAB_00616bfc:
      do {
        while( true ) {
          if (iVar1 < iVar6) {
            return 0;
          }
          uVar5 = rdmngr_db_generate_rd_id(param_1,iVar6);
          rdmngr_db_check_11ax_feature(uVar5,&local_364);
          memset(local_354,0,0x54);
          iVar2 = rdmngr_db_rd_entry_get(uVar5,local_354);
          if (iVar2 == 0) break;
          if (rdmngr_err_switch == 0) {
            iVar6 = iVar6 + 1;
          }
          else {
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              iVar6 = iVar6 + 1;
            }
            else {
              uVar5 = 0x834;
              pcVar4 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n";
LAB_00616c78:
              iVar6 = iVar6 + 1;
              printf(pcVar4,"rdmngr_multilink_callback_rdmngr_add",uVar5);
            }
          }
        }
        if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d rd_id is %d\n","rdmngr_multilink_callback_rdmngr_add",0x838,
                 local_354[0]);
        }
        if (local_354[0] != -1) {
          if (param_2 == 0) {
            if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d ap_id(%d)\'s rdmngr config not changed.\n",
                     "rdmngr_multilink_callback_rdmngr_add",0x844,param_1);
            }
            if (local_30c == '\x01') {
              uVar3 = 4;
LAB_00616cc4:
              local_306 = uVar3;
            }
            else {
              uVar3 = 3;
              if (local_30c == '\0') goto LAB_00616cc4;
            }
            iVar2 = rdmngr_db_rd_entry_set(local_354);
            if (iVar2 == 0) {
              iVar6 = iVar6 + 1;
            }
            else if (rdmngr_err_switch == 0) {
              iVar6 = iVar6 + 1;
            }
            else {
              iVar2 = is_target_debug_ap();
              if (iVar2 != 0) {
                pcVar4 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_set() failed.\n";
                uVar5 = 0x84f;
                goto LAB_00616c78;
              }
              iVar6 = iVar6 + 1;
            }
          }
          else {
            iVar2 = rdmngr_wtp_pkt_send(param_1,local_354);
            if (iVar2 == -1) {
              if (rdmngr_err_switch == 0) {
                iVar6 = iVar6 + 1;
              }
              else {
                iVar2 = is_target_debug_ap();
                if (iVar2 != 0) {
                  pcVar4 = "[RDMNGR_ERROR]%s()/%d add wtp, then send packet failed.\n";
                  uVar5 = 0x857;
                  goto LAB_00616c78;
                }
                iVar6 = iVar6 + 1;
              }
            }
            else {
              iVar6 = iVar6 + 1;
            }
          }
          goto LAB_00616bfc;
        }
        if (rdmngr_debug_switch == 0) {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 != 0) {
            pcVar4 = "[RDMNGR_DEBUG]%s()/%d Invalid rd entry.\n";
            uVar5 = 0x83c;
            goto LAB_00616c78;
          }
          iVar6 = iVar6 + 1;
        }
      } while( true );
    }
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[RDMNGR_ERROR]%s()/%d get extend_capability failed.\n";
    uVar5 = 0x81e;
  }
  printf(pcVar4,"rdmngr_multilink_callback_rdmngr_add",uVar5);
  return 0xffffffff;
}

