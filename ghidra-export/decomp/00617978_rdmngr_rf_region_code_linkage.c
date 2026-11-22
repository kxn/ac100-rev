// func rdmngr_rf_region_code_linkage @ 00617978 size=1268

undefined4 rdmngr_rf_region_code_linkage(undefined2 param_1,uint param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *__format;
  int iVar8;
  uint uVar9;
  int iVar10;
  byte local_3b0 [2];
  short local_3ae;
  undefined4 local_3ac;
  undefined4 local_3a8 [2];
  byte local_39e;
  short local_39c;
  undefined1 auStack_354 [10];
  byte local_34a;
  short local_348;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  param_2 = param_2 & 0xff;
  if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d enter rdmngr_rf_region_code_linkage.\n",
           "rdmngr_rf_region_code_linkage",0xa92);
  }
  memset(auStack_354,0,0x54);
  local_3ac = 0;
  local_3ae = 0;
  local_3b0[0] = 0;
  memset(auStack_300,0,0x2d8);
  iVar3 = apmngr_db_entry_get_by_id(param_1,auStack_300);
  if (iVar3 == -1) {
    if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d get ap entry by id failed.\n","rdmngr_rf_region_code_linkage",
             0xaa3);
      return 0xffffffff;
    }
  }
  else {
    iVar3 = rdmngr_db_get_ap_radio_cnt(local_2c0,auStack_e8,&local_3ac);
    if (iVar3 < 0) {
      if (rdmngr_err_switch != 0) {
        iVar10 = is_target_debug_ap();
        if (iVar10 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n";
        uVar7 = 0xaad;
LAB_00617dc8:
        printf(__format,"rdmngr_rf_region_code_linkage",uVar7,iVar3);
        return 0xffffffff;
      }
    }
    else {
      if ((rdmngr_debug_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d ap rd_cnt:%d.\n","rdmngr_rf_region_code_linkage",0xab0,iVar3);
      }
      iVar10 = 1;
      while( true ) {
        if (iVar3 < iVar10) {
          iVar3 = apmngr_get_linkage_support_160m(param_1,param_2);
          if (iVar3 == 0) {
            if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d region_code is %d, so 5g2 support 160M\n",
                     "rdmngr_rf_region_code_linkage",0xacc,param_2);
            }
            uVar7 = 1;
          }
          else if (rdmngr_debug_switch == 0) {
            uVar7 = 0;
          }
          else {
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              uVar7 = 0;
            }
            else {
              printf("[RDMNGR_DEBUG]%s()/%d region_code is %d, so 5g2 not support 160M\n",
                     "rdmngr_rf_region_code_linkage",0xad1,param_2);
              uVar7 = 0;
            }
          }
          apdb_set_supprt_160m_to_radio(local_2c0,auStack_e8,3,1,uVar7);
          return 0;
        }
        iVar4 = rdmngr_db_generate_rd_id(param_1,iVar10);
        memset(auStack_354,0,0x54);
        iVar5 = rdmngr_db_rd_entry_get(iVar4,auStack_354);
        if (iVar5 != 0) break;
        iVar8 = (int)local_348;
        uVar9 = (uint)local_34a;
        iVar5 = apmngr_get_linkage_chnl_bwMode(param_1,iVar4,param_2,iVar8,&local_3ae,local_3b0);
        if (iVar5 == 0) {
          iVar5 = (int)local_3ae;
          if (rdmngr_debug_switch != 0) {
            iVar6 = is_target_debug_ap();
            iVar5 = (int)local_3ae;
            if (iVar6 != 0) {
              printf("[RDMNGR_DEBUG]%s()/%d cur_chnl:%d cur_bwMode:%d linkage_chnl:%d linkage_bwMode:%d\n"
                     ,"rdmngr_rf_region_code_linkage",0xac1,iVar8,uVar9,iVar5,(uint)local_3b0[0]);
              iVar5 = (int)local_3ae;
            }
          }
          if ((iVar5 == iVar8) && (local_3b0[0] == uVar9)) {
            iVar10 = iVar10 + 1;
          }
          else {
            if ((rdmngr_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d send linkage packet.\n","rdmngr_rf_region_code_linkage",
                     0xac4);
            }
            sVar2 = local_3ae;
            bVar1 = local_3b0[0];
            iVar8 = (int)local_3ae;
            memset(local_3a8,0,0x54);
            iVar5 = rdmngr_db_rd_entry_get(iVar4,local_3a8);
            if (iVar5 == 0) {
              iVar5 = rdmngr_db_update_reinit_state(iVar4);
              if (iVar5 == 0) {
                local_39e = bVar1;
                local_39c = sVar2;
                uVar7 = rdmngr_db_generate_ap_id(local_3a8[0]);
                iVar5 = rdmngr_wtp_pkt_send(uVar7,local_3a8);
                if (iVar5 == 0) {
                  uVar7 = rdmngr_db_generate_ap_id(local_3a8[0]);
                  iVar5 = rdmngr_wtp_pkt_send(uVar7,local_3a8);
                  if (iVar5 == 0) {
                    rdmngr_callback_proc(1,iVar4,0,0);
                  }
                }
                rdmngr_db_rd_entry_region_code_linkage(iVar4,iVar8,bVar1);
                iVar10 = iVar10 + 1;
              }
              else if (rdmngr_err_switch == 0) {
                iVar10 = iVar10 + 1;
              }
              else {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  iVar10 = iVar10 + 1;
                }
                else {
                  printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n",
                         "rdmngr_rf_region_code_linkage_pkt_send",0xa79);
                  iVar10 = iVar10 + 1;
                }
              }
            }
            else if (rdmngr_err_switch == 0) {
              iVar10 = iVar10 + 1;
            }
            else {
              iVar5 = is_target_debug_ap();
              if (iVar5 == 0) {
                iVar10 = iVar10 + 1;
              }
              else {
                printf("[RDMNGR_ERROR]%s()/%d rf_id:%d, rdmngr_db_rd_entry_get() failed.\n",
                       "rdmngr_rf_region_code_linkage_pkt_send",0xa73,iVar4);
                iVar10 = iVar10 + 1;
              }
            }
          }
        }
        else {
          iVar10 = iVar10 + 1;
        }
      }
      if (rdmngr_err_switch != 0) {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n";
        uVar7 = 0xab8;
        iVar3 = iVar4;
        goto LAB_00617dc8;
      }
    }
  }
  return 0xffffffff;
}

