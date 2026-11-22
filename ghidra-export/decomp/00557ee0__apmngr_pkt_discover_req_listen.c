// func _apmngr_pkt_discover_req_listen @ 00557ee0 size=3680

undefined4 _apmngr_pkt_discover_req_listen(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *__src;
  int iVar5;
  uint uVar6;
  undefined4 extraout_v1;
  char *pcVar7;
  ushort *puVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  ushort local_ae8 [2];
  int local_ae4;
  undefined4 local_ae0;
  undefined4 local_adc;
  undefined4 local_ad8;
  undefined2 local_ad4;
  uint local_ad0;
  undefined2 local_acc;
  undefined4 local_ac8;
  undefined2 local_ac4;
  undefined4 local_ac0;
  undefined4 local_abc;
  undefined4 local_ab8;
  undefined4 local_ab4;
  undefined4 local_ab0;
  undefined4 local_aac;
  char local_aa8 [20];
  undefined4 local_a94;
  undefined4 local_a90;
  undefined4 local_a8c;
  undefined4 local_a88;
  undefined4 local_a84;
  undefined1 auStack_a80 [100];
  int local_a1c;
  undefined1 auStack_a18 [124];
  int local_99c;
  uint local_998;
  char acStack_8b0 [18];
  undefined2 local_89e;
  undefined2 local_898;
  undefined2 local_888;
  int local_874;
  undefined4 local_870;
  undefined4 local_86c;
  uint local_868;
  undefined2 local_864;
  undefined1 auStack_5d8 [16];
  undefined2 local_5c8;
  undefined2 local_5c6;
  int local_5c4;
  undefined1 auStack_300 [16];
  ushort local_2f0 [12];
  ushort local_2d8;
  int local_2c4;
  int local_2bc;
  
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d  enter _apmngr_pkt_discover_req_listen\n",
           "_apmngr_pkt_discover_req_listen",0x500);
  }
  local_abc = 0;
  local_a94 = 0;
  local_a90 = 0;
  local_a8c = 0;
  local_a88 = 0;
  local_a84 = 0;
  local_ac0 = 0x2000000;
  uVar1 = cw_priv_radio_role_table_control_tlv_ele_create(2);
  local_abc = uVar1;
  FUN_0051ad88(&local_a8c);
  iVar2 = cw_service_msg_add(param_3,0x25,&local_a94,1,0x90,&local_ac0);
  if (iVar2 != 0) {
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d add msg element failed.\n","_apmngr_pkt_discover_req_listen",
             0x50d);
    }
    cw_priv_radio_role_table_control_tlv_ele_free(uVar1,2);
    return 0xffffffff;
  }
  cw_priv_radio_role_table_control_tlv_ele_free(uVar1,2);
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d got a discover req packet.\n","_apmngr_pkt_discover_req_listen",
           0x513);
  }
  memset(auStack_300,0,0x2d8);
  memset(auStack_5d8,0,0x2d8);
  local_adc = 0;
  local_ae0 = 0;
  local_ae8[0] = 0xffff;
  local_ac8 = 0;
  local_ac4 = 0;
  memset(auStack_a18,0,0x168);
  memset(auStack_a80,0,0x68);
  local_ad8 = 0;
  local_ad4 = 0;
  piVar3 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {
    uVar1 = 0xffffffff;
    if (apmngr_debug_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[APMNGR_DEBUG]%s()/%d Failed to join for formal callback return failed result code.\n"
    ;
    uVar9 = 0x52e;
LAB_00558050:
    printf(pcVar7,"_apmngr_pkt_discover_req_listen",uVar9);
    return uVar1;
  }
  iVar2 = cw_sub_msg_ele_get(param_1,0x27,0);
  iVar4 = cw_sub_msg_ele_get(param_1,0x26,0);
  __src = (void *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x5b);
  if (__src == (void *)0x0) {
    local_ab8 = 0xffffffff;
    local_ab4 = 0xffffffff;
    local_ab0 = 0xffffffff;
    local_aac = 0xffffffff;
  }
  else {
    memcpy(&local_ab8,__src,0x10);
  }
  if ((((iVar4 == 0) || (iVar2 == 0)) || (*(short *)(iVar4 + 0xe) != 4)) ||
     (*(ushort *)(iVar2 + 0x12) < 4)) {
    uVar1 = 0;
    if (apmngr_warning_switch == '\0') {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar7 = 
    "[APMNGR_WARNING]%s()/%d Failed to find element that desribe AP\'s model or hardware version, maybe ac detection\n"
    ;
    uVar9 = 0x541;
    goto LAB_00558050;
  }
  iVar5 = apmngr_db_sync_device_ready();
  if (iVar5 == 0) {
    if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_005584c4;
    pcVar7 = 
    "[APMNGR_WARNING]%s()/%d Not allowed to join when device is synchronizing configuration.\n";
    uVar1 = 0x546;
  }
  else {
    uVar1 = **(undefined4 **)(iVar4 + 0x10);
    local_ae0 = **(undefined4 **)(iVar2 + 0x14);
    local_adc = **(undefined4 **)(iVar2 + 0x14);
    iVar2 = apdb_get_ap_by_id(uVar1,&local_ab8,auStack_a18);
    if (iVar2 != 0) {
      if (apmngr_debug_switch == '\0') {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      printf("[APMNGR_DEBUG]%s()/%d Cannot find apdb of model %d. maybe not need authorize\n",
             "_apmngr_pkt_discover_req_listen",0x553,uVar1);
      return 0;
    }
    if (*(char *)(param_2 + 0xc) == '\0') {
      if (((1 < local_998) && (local_998 != 3)) && (local_998 != 2)) {
        if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_005584c4;
        pcVar7 = "[APMNGR_ERROR]%s()/%d Illegal product type %d for root device.\n";
        uVar1 = 0x56e;
LAB_0055884c:
        printf(pcVar7,"_apmngr_pkt_discover_req_listen",uVar1,local_998);
        goto LAB_005584c4;
      }
      if (local_99c == 0) {
        iVar2 = 0;
        uVar10 = 0xffff;
        uVar11 = 0;
      }
      else {
        iVar2 = 3;
        if ((local_998 != 1) && (iVar2 = 2, local_998 != 3)) {
          iVar2 = 1;
        }
        iVar4 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
        local_ae4 = 0;
        if ((iVar4 == 0) ||
           (pcVar7 = (char *)cw_priv_mesh_private_control_get(iVar4,0x10), pcVar7 == (char *)0x0)) {
          uVar1 = 0;
          if (apmngr_debug_switch == '\0') {
            return 0;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0;
          }
          pcVar7 = "[APMNGR_DEBUG]%s()/%d no role info, maybe old device\n";
          uVar9 = 0x5a7;
          goto LAB_00558050;
        }
        if (*pcVar7 == '\x01') {
          iVar4 = mesh_db_mesh_enable_get(&local_ae4);
          if ((((iVar4 != 0) || (local_ae4 == 0)) ||
              (iVar4 = apmngr_db_entry_get_by_mac(pcVar7 + 1,auStack_5d8), iVar4 != 0)) ||
             (((local_5c4 != 1 && (local_5c4 != 3)) && (local_5c4 != 2)))) {
            if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d Join failed because can not find parent AP(%02X-%02X-%02X-%02X-%02X-%02X) or role not match or mesh(%d) is closed.\n"
                     ,"_apmngr_pkt_discover_req_listen",0x58b,(uint)(byte)pcVar7[1],
                     (uint)(byte)pcVar7[2],(uint)(byte)pcVar7[3],(uint)(byte)pcVar7[4],
                     (uint)(byte)pcVar7[5],(uint)(byte)pcVar7[6],local_ae4);
            }
            goto LAB_005584c4;
          }
          uVar10 = local_5c8;
          uVar11 = local_5c6;
          if (local_998 == 1) {
            iVar2 = 6;
          }
          else if (local_998 == 0) {
            iVar2 = 4;
          }
          else if (local_998 == 3) {
            iVar2 = 8;
          }
        }
        else {
          if (*pcVar7 != '\0') {
            if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005584c4;
            local_998 = (uint)*pcVar7;
            pcVar7 = "[APMNGR_WARNING]%s()/%d Illegal role %d\n";
            uVar1 = 0x5a0;
            goto LAB_0055884c;
          }
          uVar10 = 0xffff;
          uVar11 = 0;
        }
      }
    }
    else if (local_998 == 1) {
      iVar2 = 5;
      uVar10 = 0xffff;
      uVar11 = 0;
    }
    else {
      if (local_998 != 3) {
        if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_005584c4;
        pcVar7 = "[APMNGR_ERROR]%s()/%d Illegal product type %d for child.\n";
        uVar1 = 0x564;
        goto LAB_0055884c;
      }
      iVar2 = 8;
      uVar10 = 0xffff;
      uVar11 = 0;
    }
    iVar4 = cw_sub_msg_ele_get(param_1,0x26,4);
    if (iVar4 == 0) {
      if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_005584c4;
      pcVar7 = "[APMNGR_ERROR]%s()/%d get mac failed\n";
      uVar1 = 0x5b2;
    }
    else {
      memcpy(&local_ad0,*(void **)(iVar4 + 0x10),6);
      if (((iVar2 == 2) && (iVar4 = FUN_005135a8(&local_ad8), iVar4 == 0)) &&
         (iVar4 = memcmp(&local_ad8,&local_ad0,6), iVar4 == 0)) {
        return 0;
      }
      if (1 < iVar2 - 2U) {
        iVar2 = apmngr_db_entry_get_by_mac(&local_ad0,auStack_300);
        if (iVar2 != 0) {
          return 0;
        }
        if ((local_2d8 & 1) == 0) {
          return 0;
        }
        if (local_2c4 != 0) {
          return 0;
        }
        if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d authorize entry\'s role changed, not need authorize, allow access %d\n"
                 ,"_apmngr_pkt_discover_req_listen",0x635,(uint)local_2f0[0]);
        }
        apmngr_db_entry_delete(local_2f0[0]);
        apmngr_db_id_free(1,local_2f0[0]);
        apmngr_db_sync_ap_entry_del(local_2f0,1,1);
        puVar8 = local_2f0;
        goto LAB_00558350;
      }
      iVar4 = apmngr_db_entry_get_by_mac(&local_ad0,auStack_300);
      if (iVar4 == 0) {
        if (local_2bc == 0) {
          iVar2 = apdb_hwver_exist_by_id(uVar1,&local_ae0);
          if (iVar2 != 1) {
            if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005584c4;
            pcVar7 = "[APMNGR_WARNING]%s()/%d Join failed because hardware type does not matched.\n"
            ;
            uVar1 = 0x5c9;
            goto LAB_005585dc;
          }
          apmngr_db_ap_hwver_update(local_2f0[0],&local_adc,0);
          apmngr_db_sync_ap_hwver(local_2f0[0],&local_adc,0);
          apmngr_db_datasync_ap_hwver(local_2f0[0],&local_adc,0);
        }
        local_ae8[0] = local_2f0[0];
        if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d Matched exist ap entry(%u).\n",
                 "_apmngr_pkt_discover_req_listen",0x5d8,(uint)local_ae8[0]);
        }
        piVar3 = (int *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x9a);
        if (((piVar3 != (int *)0x0) && (*piVar3 == 0)) && (local_2c4 != 0)) {
          apmngr_evt_notify(3,auStack_300);
          apmngr_db_entry_delete(local_ae8[0]);
          apmngr_db_id_free(1,local_ae8[0]);
          apmngr_db_sync_ap_entry_del(local_ae8,1,1);
          apmngr_db_datasync_ap_entry_del(local_ae8,1,1);
          uVar1 = 0x17;
          goto LAB_00558574;
        }
        iVar2 = mesh_db_discover_state_get();
        if (((iVar2 == 1) &&
            (iVar2 = mesh_db_discover_entry_get(&local_ad0,auStack_a80), iVar2 == 0)) &&
           (local_a1c == 1)) {
          if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar7 = "[APMNGR_DEBUG]%s()/%d discovery entry exist ,allow access %d\n";
            uVar1 = 0x5e6;
LAB_005588c8:
            printf(pcVar7,"_apmngr_pkt_discover_req_listen",uVar1,(uint)local_ae8[0]);
          }
        }
        else {
          if (((local_2d8 & 2) == 0) || (local_2c4 != 0)) {
            if (((local_2d8 & 4) != 0) && (local_2c4 == 0)) {
              if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[APMNGR_DEBUG]%s()/%d reject access %d\n","_apmngr_pkt_discover_req_listen",
                       0x5f7,(uint)local_ae8[0]);
              }
              apmngr_db_entry_delete(local_ae8[0]);
              apmngr_db_id_free(1,local_ae8[0]);
              apmngr_db_sync_ap_entry_del(local_ae8,1,1);
              apmngr_db_datasync_ap_entry_del(local_ae8,1,1);
              uVar1 = 0x18;
              goto LAB_00558574;
            }
            if ((local_2d8 & 1) == 0) {
              return 0;
            }
            if ((apmngr_debug_switch != '\0') &&
               (iVar2 = is_target_debug_ap(local_ae8[0]), iVar2 != 0)) {
              pcVar7 = "[APMNGR_DEBUG]%s()/%d wait access %d\n";
              uVar1 = 0x601;
              goto LAB_00558750;
            }
            goto LAB_00558600;
          }
          if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar7 = "[APMNGR_DEBUG]%s()/%d allow access %d\n";
            uVar1 = 0x5ef;
            goto LAB_005588c8;
          }
        }
        apmngr_db_entry_delete(local_ae8[0]);
        apmngr_db_id_free(1,local_ae8[0]);
        apmngr_db_sync_ap_entry_del(local_ae8,1,1);
        puVar8 = local_ae8;
LAB_00558350:
        apmngr_db_datasync_ap_entry_del(puVar8,1,1);
        return 0;
      }
      iVar4 = apmngr_db_is_ap_exceed(1,0);
      if (iVar4 != 0) {
        if ((apmngr_warning_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[APMNGR_WARNING]%s()/%d Failed to join authorize device.\n",
                 "_apmngr_pkt_discover_req_listen",0x609);
        }
        FUN_00407e70();
        apmngr_exceed_time_set(extraout_v1);
        _apmngr_pkt_result_code_set_err(param_3,1);
        memset(acStack_8b0,0,0x40);
        FUN_00408190(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                     *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                     *(undefined4 *)(param_2 + 0x20),acStack_8b0,0x40,"---");
        local_aa8[0] = '\0';
        local_aa8[1] = '\0';
        local_aa8[2] = '\0';
        local_aa8[3] = '\0';
        local_aa8[4] = '\0';
        local_aa8[5] = '\0';
        local_aa8[6] = '\0';
        local_aa8[7] = '\0';
        local_aa8[8] = '\0';
        local_aa8[9] = '\0';
        local_aa8[10] = '\0';
        local_aa8[0xb] = '\0';
        local_aa8[0xc] = '\0';
        local_aa8[0xd] = '\0';
        local_aa8[0xe] = '\0';
        local_aa8[0xf] = '\0';
        local_aa8[0x10] = '\0';
        local_aa8[0x11] = '\0';
        local_aa8[0x12] = '\0';
        local_aa8[0x13] = '\0';
        snprintf(local_aa8,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",local_ad0 >> 0x18,
                 local_ad0 >> 0x10 & 0xff,local_ad0 >> 8 & 0xff,local_ad0 & 0xff,
                 (uint)local_acc._0_1_,(uint)(byte)local_acc);
        uVar1 = apmngr_db_product_type_str_by_ap_role(iVar2);
        pcVar7 = "---";
        if (*(char *)(param_2 + 0xc) == '\0') {
          pcVar7 = acStack_8b0;
        }
        loggerk_reg(0x53,0x3d01,1,"AP",1,uVar1,1,pcVar7,1,local_aa8,0);
        return 0xffffffff;
      }
      iVar4 = mesh_db_discover_state_get();
      if (((iVar4 == 1) && (iVar4 = mesh_db_discover_entry_get(&local_ad0,auStack_a80), iVar4 == 0))
         && (local_a1c == 1)) {
        return 0;
      }
      memset(acStack_8b0,0,0x2d8);
      apmngr_db_entry_init(acStack_8b0,&local_ab8,uVar1,iVar2);
      local_888 = 1;
      local_868 = local_ad0;
      local_874 = 0;
      local_864 = local_acc;
      local_86c = local_adc;
      local_89e = uVar11;
      local_898 = uVar10;
      local_870 = uVar1;
      FUN_00407e80("_apmngr_try_create_authorize_ap_entry");
      iVar2 = apdb_is_hdap_by_id(uVar1,&local_ab8);
      if (iVar2 == 0) {
        uVar6 = apmngr_ap_add(acStack_8b0,&local_ab8,1,0,0);
      }
      else {
        uVar6 = apmngr_hdap_add(acStack_8b0,&local_ab8,&local_ac8,1);
      }
      FUN_004082b0(uVar6 != 0xffff && local_874 != 0,"_apmngr_try_create_authorize_ap_entry");
      local_ae8[0] = (ushort)uVar6;
      if (uVar6 != 0xffff) {
        uVar6 = uVar6 & 0xffff;
        if (apmngr_debug_switch != '\0') {
          iVar2 = is_target_debug_ap(uVar6);
          if (iVar2 == 0) {
            uVar6 = (uint)local_ae8[0];
          }
          else {
            printf("[APMNGR_DEBUG]%s()/%d Create an ap entry(%u).\n\n",
                   "_apmngr_pkt_discover_req_listen",0x627,(uint)local_ae8[0]);
            uVar6 = (uint)local_ae8[0];
          }
        }
        apmngr_db_entry_get_by_id(uVar6,auStack_300);
        if ((local_2d8 & 1) == 0) {
          return 0;
        }
        if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(local_ae8[0]), iVar2 != 0))
        {
          pcVar7 = "[APMNGR_DEBUG]%s()/%d first wait access %d\n";
          uVar1 = 0x62b;
LAB_00558750:
          printf(pcVar7,"_apmngr_pkt_discover_req_listen",uVar1,(uint)local_ae8[0]);
        }
LAB_00558600:
        apmngr_entry_timer_start(local_ae8[0],0,0x3c);
        uVar1 = 0x17;
LAB_00558574:
        _apmngr_pkt_result_code_set_err(param_3,uVar1);
        return 0;
      }
      if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_005584c4;
      pcVar7 = 
      "[APMNGR_WARNING]%s()/%d Cannot find or create an entry, maybe an unsupported device or join check failed.\n"
      ;
      uVar1 = 0x623;
    }
  }
LAB_005585dc:
  printf(pcVar7,"_apmngr_pkt_discover_req_listen",uVar1);
LAB_005584c4:
  _apmngr_pkt_result_code_set_err(param_3,1);
  return 0xffffffff;
}

