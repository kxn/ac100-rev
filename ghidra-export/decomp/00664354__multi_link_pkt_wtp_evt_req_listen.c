// func _multi_link_pkt_wtp_evt_req_listen @ 00664354 size=1336

undefined4 _multi_link_pkt_wtp_evt_req_listen(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  void *__s2;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined1 local_320 [4];
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  uint local_b0;
  int local_ac;
  undefined1 auStack_66 [62];
  
  memset(auStack_300,0,0x2d8);
  local_31c = 0;
  local_320[0] = 0;
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  piVar1 = (int *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x40);
  __s2 = (void *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x41);
  if (multi_link_ignore_chk != '\0') {
    return 0;
  }
  if ((piVar1 == (int *)0x0) && (__s2 == (void *)0x0)) {
    return 0;
  }
  iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_300);
  if (iVar2 == 0) {
    if (__s2 == (void *)0x0) {
LAB_00664468:
      if ((local_b0 & 0x10) == 0) goto LAB_00664470;
LAB_00664608:
      if (piVar1 != (int *)0x0) {
        if (multi_link_debug_switch != '\0') {
          if (*piVar1 == 0) {
            pcVar5 = "Standby";
          }
          else {
            pcVar5 = "Master";
          }
          printf("[MULTI_LINK_DEBUG]%s()/%d Receive an switch link message, will switch to %s.\n",
                 "_multi_link_pkt_wtp_evt_req_listen",0x177,pcVar5);
        }
        iVar8 = *piVar1;
        iVar3 = multi_link_status_get(local_2f0);
        iVar2 = g_multi_link_config_changed_array;
        uVar6 = 2;
        if (iVar8 != iVar3) {
          uVar7 = (uint)local_2f0;
          if (*piVar1 == 1) {
            uVar9 = uVar7;
            if (49999 < uVar7) {
              iVar3 = apmngr_db_get_ap_max();
              uVar9 = (uVar7 - 50000) + iVar3;
            }
            multi_link_status_switch
                      (uVar7,1,*(undefined1 *)(iVar2 + uVar9),*(undefined4 *)(param_2 + 0x2c),
                       *(undefined4 *)(param_2 + 0x30),*(undefined4 *)(param_2 + 0x28));
            iVar2 = g_multi_link_config_changed_array;
            uVar7 = (uint)local_2f0;
            if (49999 < uVar7) {
              iVar3 = apmngr_db_get_ap_max();
              uVar7 = (uVar7 - 50000) + iVar3;
            }
            uVar6 = 3;
            if (*(char *)(iVar2 + uVar7) != '\0') {
              uVar6 = 4;
              iVar2 = _multi_link_checksum_send(local_2f0);
              if (iVar2 != 0) {
                if (multi_link_err_switch == '\0') {
                  return 0xffffffff;
                }
                pcVar5 = 
                "[MULTI_LINK_ERROR]%s()/%d Failed to assemble config update req packet to send checksum to ap.\n"
                ;
                uVar6 = 0x186;
                goto LAB_006645e8;
              }
            }
          }
          else {
            multi_link_status_switch
                      (uVar7,0,0,*(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_2 + 0x30),
                       *(undefined4 *)(param_2 + 0x28));
            uVar6 = 2;
          }
        }
        FUN_0051ad88(&local_310);
        uVar10 = 0x40;
        puVar4 = &local_31c;
        local_31c = uVar6;
        goto LAB_00664550;
      }
    }
    else {
      if (multi_link_debug_switch != '\0') {
        printf("[MULTI_LINK_DEBUG]%s()/%d Received an MD5-Checksum.\n",
               "_multi_link_pkt_wtp_evt_req_listen",0x166);
      }
      iVar2 = memcmp(auStack_66,__s2,0x10);
      if (iVar2 != 0) {
        if (multi_link_debug_switch != '\0') {
          printf("[MULTI_LINK_DEBUG]%s()/%d Config is not matched.\n",
                 "_multi_link_pkt_wtp_evt_req_listen",0x169);
        }
        iVar2 = g_multi_link_config_changed_array;
        uVar7 = (uint)local_2f0;
        if (49999 < uVar7) {
          iVar3 = apmngr_db_get_ap_max();
          uVar7 = (uVar7 - 50000) + iVar3;
        }
        *(undefined1 *)(iVar2 + uVar7) = 1;
        goto LAB_00664468;
      }
      if (multi_link_debug_switch != '\0') {
        printf("[MULTI_LINK_DEBUG]%s()/%d Config matched, no need to submit.\n",
               "_multi_link_pkt_wtp_evt_req_listen",0x16e);
      }
      iVar2 = g_multi_link_config_changed_array;
      uVar7 = (uint)local_2f0;
      if (uVar7 < 50000) {
        *(undefined1 *)(g_multi_link_config_changed_array + uVar7) = 0;
      }
      else {
        iVar3 = apmngr_db_get_ap_max();
        *(undefined1 *)(iVar2 + (uVar7 - 50000) + iVar3) = 0;
      }
      if ((local_b0 & 0x10) != 0) goto LAB_00664608;
LAB_00664470:
      iVar2 = g_multi_link_config_changed_array;
      if (local_ac << 0xc < 0) {
        uVar9 = (uint)local_2f0;
        uVar7 = uVar9;
        if (49999 < uVar9) {
          iVar3 = apmngr_db_get_ap_max();
          uVar7 = (uVar9 - 50000) + iVar3;
        }
        multi_link_status_switch
                  (uVar9,1,*(undefined1 *)(iVar2 + uVar7),*(undefined4 *)(param_2 + 0x2c),
                   *(undefined4 *)(param_2 + 0x30),*(undefined4 *)(param_2 + 0x28));
        iVar2 = g_multi_link_config_changed_array;
        uVar7 = (uint)local_2f0;
        if (49999 < uVar7) {
          iVar3 = apmngr_db_get_ap_max();
          uVar7 = (uVar7 - 50000) + iVar3;
        }
        if ((*(char *)(iVar2 + uVar7) != '\0') &&
           (iVar2 = _multi_link_checksum_send(local_2f0), iVar2 != 0)) {
          if (multi_link_err_switch == '\0') {
            return 0xffffffff;
          }
          pcVar5 = 
          "[MULTI_LINK_ERROR]%s()/%d Failed to assemble config update req packet to send checksum to ap.\n"
          ;
          uVar6 = 0x1ab;
          goto LAB_006645e8;
        }
        FUN_0051ad88(&local_310);
        iVar2 = g_multi_link_config_changed_array;
        uVar7 = (uint)local_2f0;
        if (49999 < uVar7) {
          iVar3 = apmngr_db_get_ap_max();
          uVar7 = (uVar7 - 50000) + iVar3;
        }
        local_320[0] = *(undefined1 *)(iVar2 + uVar7);
        uVar10 = 0x85;
        puVar4 = (undefined4 *)local_320;
LAB_00664550:
        iVar3 = cw_service_msg_add(param_3,0x25,&local_318,1,uVar10,puVar4);
        iVar2 = g_multi_link_config_changed_array;
        uVar7 = (uint)local_2f0;
        if (iVar3 != 0) {
          if (49999 < uVar7) {
            iVar3 = apmngr_db_get_ap_max();
            uVar7 = (uVar7 - 50000) + iVar3;
          }
          *(undefined1 *)(iVar2 + uVar7) = 1;
          return 0xffffffff;
        }
      }
    }
    iVar2 = g_multi_link_config_changed_array;
    uVar7 = (uint)local_2f0;
    if (49999 < uVar7) {
      iVar3 = apmngr_db_get_ap_max();
      uVar7 = (uVar7 - 50000) + iVar3;
    }
    *(undefined1 *)(iVar2 + uVar7) = 1;
    uVar10 = 0;
  }
  else {
    if (multi_link_warning_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[MULTI_LINK_WARNING]%s()/%d Cannot find matched ap.\n";
    uVar6 = 0x15d;
LAB_006645e8:
    uVar10 = 0xffffffff;
    printf(pcVar5,"_multi_link_pkt_wtp_evt_req_listen",uVar6);
  }
  return uVar10;
}

