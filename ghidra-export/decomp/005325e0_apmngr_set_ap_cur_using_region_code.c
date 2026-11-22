// func apmngr_set_ap_cur_using_region_code @ 005325e0 size=1072

/* WARNING: Type propagation algorithm not settling */

undefined4 apmngr_set_ap_cur_using_region_code(uint param_1,byte param_2)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint local_8c8 [178];
  uint local_600;
  int local_5f0 [6];
  undefined4 local_5d8;
  undefined4 local_5d4;
  undefined4 local_5d0;
  undefined4 local_5cc;
  undefined1 local_5c8 [584];
  uint local_380;
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  int local_2ec;
  byte local_2f;
  
  param_1 = param_1 & 0xffff;
  uVar8 = (uint)param_2;
  memset(auStack_300,0,0x2d8);
  local_5f0[0] = 0;
  local_5f0[1] = 0;
  local_5f0[2] = 0;
  local_5f0[3] = 0;
  local_5f0[4] = 0;
  iVar1 = serv_wtp_address_arg_init(local_5f0 + 1);
  if (iVar1 != 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d serv_wtp_address_arg_init error\n",
           "apmngr_set_ap_cur_using_region_code",0xe6d);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_300);
  if (iVar1 == 0) {
    if (local_2f == uVar8) {
      uVar9 = 0;
      if ((apmngr_debug_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_00532718;
      pcVar5 = "[APMNGR_DEBUG]%s()/%d ap_id:%d, region_code don\'t change, so don\'t need send\n";
      uVar7 = 0xe7a;
    }
    else {
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(uVar8), iVar1 != 0)) {
        local_8c8[0] = uVar8;
        printf("[APMNGR_DEBUG]%s()/%d set %d\'s region code to %d\n",
               "apmngr_set_ap_cur_using_region_code",0xe7f,param_1);
      }
      local_2f = param_2;
      apmngr_db_set_cur_using_region_code(uVar8,param_1);
      rdmngr_rf_region_code_linkage(param_1,uVar8,1);
      local_8c8[0] = 0xffffffff;
      local_8c8[1] = 1;
      local_8c8[2] = 0x41;
      uVar9 = 0;
      iVar1 = apmngr_db_get_addr_by_capacity(local_2f0,local_5f0 + 1,1,1);
      if (iVar1 != 0) goto LAB_00532718;
      iVar1 = apmngr_pkt_region_code_pkt_send(local_5f0 + 1,uVar8);
      if (iVar1 != 0) {
        uVar9 = 0xffffffff;
        if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d Failed to send set region code packet.\n",
                 "apmngr_set_ap_cur_using_region_code",0xe90);
        }
        goto LAB_00532718;
      }
      if ((((local_2ec == 1) || (local_2ec == 3)) || (local_2ec == 2)) &&
         (puVar2 = (ushort *)mesh_db_child_list_get_by_cap_id(param_1,local_5f0),
         iVar1 = local_5f0[0], local_5f0[0] != 0)) {
        iVar10 = 0;
        memset(&local_5d8,0,0x2d8);
        while (iVar10 < iVar1) {
          iVar3 = apmngr_db_entry_get_by_id(*puVar2,&local_5d8);
          if (iVar3 == 0) {
            uVar4 = 0;
            uVar6 = uVar8;
            if ((local_380 & 2) == 0) {
              if ((apmngr_debug_switch == '\0') || (iVar3 = is_target_debug_ap(), iVar3 == 0))
              goto LAB_00532908;
              uVar9 = 0xe59;
              pcVar5 = "[APMNGR_DEBUG]%s()/%d ap(%d) not support region code\n";
LAB_00532930:
              printf(pcVar5,"apmngr_set_re_region_code",uVar9,(uint)*puVar2);
              iVar10 = iVar10 + 1;
              puVar2 = puVar2 + 1;
            }
            else {
              for (; local_600 = uVar6, uVar4 < 0x2c8; uVar4 = uVar4 + 1) {
                *(undefined1 *)((int)local_8c8 + uVar4) = local_5c8[uVar4];
                uVar6 = local_600;
              }
              iVar3 = is_support_region_code(local_5d8,local_5d4,local_5d0,local_5cc);
              uVar6 = uVar8;
              if (iVar3 == 0) {
                uVar6 = 0;
              }
              iVar10 = iVar10 + 1;
              apmngr_set_ap_cur_using_region_code(*puVar2,uVar6);
              puVar2 = puVar2 + 1;
            }
          }
          else {
            if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              uVar9 = 0xe47;
              pcVar5 = "[APMNGR_ERROR]%s()/%d get re ap entry failed id:%d\n";
              goto LAB_00532930;
            }
LAB_00532908:
            iVar10 = iVar10 + 1;
            puVar2 = puVar2 + 1;
          }
        }
      }
      iVar1 = apmngr_checksum_update(auStack_300,0);
      if (iVar1 == 0) {
        uVar9 = apmngr_db_timer_md5_send_interval_default_get();
        iVar1 = apmngr_entry_timer_start(local_2f0,1,uVar9);
        if (iVar1 == 0) {
          serv_wtp_address_arg_destroy(local_5f0 + 1);
          return 0;
        }
      }
      uVar9 = 0xffffffff;
      if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_00532718;
      pcVar5 = "[APMNGR_ERROR]%s()/%d update ap:%d md5 failed.\n";
      uVar7 = 0xea2;
    }
  }
  else {
    uVar9 = 0xffffffff;
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00532718;
    pcVar5 = "[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n";
    uVar7 = 0xe73;
  }
  printf(pcVar5,"apmngr_set_ap_cur_using_region_code",uVar7,param_1);
LAB_00532718:
  serv_wtp_address_arg_destroy(local_5f0 + 1);
  return uVar9;
}

