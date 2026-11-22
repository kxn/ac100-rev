// func _mesh_pkt_wtp_event_req_listen @ 004c2520 size=3216

/* WARNING: Type propagation algorithm not settling */

undefined4 _mesh_pkt_wtp_event_req_listen(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char cVar12;
  int iVar11;
  int iVar13;
  char *pcVar14;
  undefined4 *__src;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  void *pvVar19;
  byte *pbVar20;
  uint uVar21;
  ushort uVar22;
  byte *__s1;
  undefined4 uVar23;
  undefined4 uVar24;
  int local_be0;
  int local_bdc [2];
  undefined2 local_bd4;
  undefined4 local_bd0;
  undefined4 local_bcc;
  undefined4 local_bc8;
  undefined4 local_bc4;
  undefined4 local_bc0;
  undefined4 local_bbc;
  undefined4 local_bb8;
  undefined4 local_bb4;
  undefined4 local_bb0;
  undefined4 local_bac;
  undefined4 local_ba8;
  undefined4 local_ba4;
  undefined4 local_ba0;
  undefined4 local_b9c;
  undefined4 local_b98;
  undefined4 local_b94;
  undefined4 local_b90;
  undefined4 local_b8c;
  undefined4 local_b88;
  undefined4 local_b84;
  undefined4 local_b80;
  undefined4 local_b7c;
  undefined4 local_b78;
  undefined4 local_b74;
  undefined4 local_b70;
  undefined4 local_b6c;
  undefined4 local_b68;
  undefined4 local_b64;
  undefined4 local_b60;
  undefined4 local_b5c;
  undefined4 local_b58;
  undefined4 local_b54;
  undefined4 local_b50;
  undefined4 local_b4c;
  undefined1 auStack_b48 [52];
  char local_b14;
  undefined1 auStack_b0c [300];
  undefined1 auStack_9e0 [304];
  undefined1 auStack_8b0 [16];
  ushort local_8a0;
  int local_89c;
  ushort local_898;
  char local_6a9;
  undefined4 local_644;
  undefined4 local_640;
  undefined4 local_63c;
  undefined4 local_638;
  undefined4 local_634;
  undefined1 auStack_5d8 [16];
  undefined2 local_5c8;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  int local_2ec;
  short local_2e8;
  
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
  local_bb8 = 0;
  local_bb4 = 0;
  local_bb0 = 0;
  local_b5c = 0;
  local_b58 = 0;
  local_b54 = 0;
  local_b50 = 0;
  local_b4c = 0;
  local_bc4 = 0;
  local_bc0 = 0;
  local_bbc = 0;
  memset(auStack_300,0,0x2d8);
  memset(auStack_5d8,0,0x2d8);
  memset(auStack_8b0,0,0x2d8);
  local_bd0 = 0;
  local_bcc = 0;
  local_bc8 = 0;
  local_b70 = 0;
  local_b6c = 0;
  local_b68 = 0;
  local_b64 = 0;
  local_b60 = 0;
  local_b84 = 0;
  local_b80 = 0;
  local_b7c = 0;
  local_b78 = 0;
  local_b74 = 0;
  local_b98 = 0;
  local_b94 = 0;
  local_b90 = 0;
  local_b8c = 0;
  local_b88 = 0;
  local_bdc[0] = 0;
  local_be0 = 0;
  local_bdc[1] = 0;
  local_bd4 = 0;
  memset(auStack_b48,0,0x3c);
  memset(auStack_9e0,0,300);
  memset(auStack_b0c,0,300);
  if (iVar1 == 0) {
    return 0;
  }
  mesh_pkt_dump(param_1);
  iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_8b0);
  if (iVar2 != 0) {
    if (mesh_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_WARNING]%s()/%d Find cap entry[[%02x:%02x:%02x:%02x:%02x:%02x]] failed\n",
           "_mesh_pkt_wtp_event_req_listen",0x247,(uint)*param_2,(uint)param_2[1],(uint)param_2[2],
           (uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
    return 0xffffffff;
  }
  iVar2 = mesh_db_mesh_enable_get(&local_be0);
  if (iVar2 != 0) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d mesh_db_mesh_enable_get failed\n","_mesh_pkt_wtp_event_req_listen",
           0x24c);
    return 0xffffffff;
  }
  if ((local_be0 == 0) ||
     (pcVar14 = (char *)cw_priv_mesh_private_control_get(iVar1,7), pcVar14 == (char *)0x0)) {
LAB_004c26d0:
    if ((local_be0 == 0) ||
       (puVar3 = (ushort *)cw_priv_mesh_private_control_get(iVar1,6), puVar3 == (ushort *)0x0)) {
      pbVar20 = (byte *)0x0;
      uVar21 = 0;
    }
    else {
      uVar21 = (uint)*puVar3;
      pbVar20 = *(byte **)(puVar3 + 2);
    }
  }
  else {
    if (*pcVar14 == '\0') {
      uVar22 = *(ushort *)(pcVar14 + 2);
    }
    else {
      if (*pcVar14 != '\x02') goto LAB_004c26d0;
      uVar22 = *(ushort *)(pcVar14 + 2);
    }
    uVar21 = (uint)uVar22;
    pbVar20 = *(byte **)(pcVar14 + 4);
  }
  if ((((local_89c == 1) || (local_89c == 3)) || (local_89c == 2)) &&
     ((uVar21 != 0 && (pbVar20 != (byte *)0x0)))) {
    iVar2 = 0;
    while (iVar2 < (int)uVar21) {
      iVar5 = apmngr_db_entry_get_by_mac(pbVar20,auStack_300);
      if ((iVar5 == 0) &&
         ((((local_2ec == 4 || (local_2ec == 8)) || ((local_2ec == 6 || (local_2ec == 5)))) &&
          (((int)local_2e8 == (uint)local_8a0 &&
           (iVar5 = apmngr_db_entry_get_by_mac(pbVar20 + 0x38,auStack_5d8), iVar5 == 0)))))) {
        if ((local_2ec != 1) &&
           ((((local_2ec != 3 && (local_2ec != 2)) && (local_2ec != 4)) &&
            ((local_2ec != 8 && (local_2ec != 6)))))) {
          if (local_2ec != 5) goto LAB_004c2890;
          iVar5 = FUN_00407eb0(local_644,local_640,local_63c,local_638,local_634);
          cw_protocol_ip_to_common_ip(pbVar20 + 8,&local_b70);
          cw_protocol_ip_to_common_ip(pbVar20 + 8,&local_b84);
          iVar11 = FUN_00407eb0(local_b70,local_b6c,local_b68,local_b64,local_b60);
          iVar13 = FUN_00407eb0(local_b84,local_b80,local_b7c,local_b78,local_b74);
          uVar15 = local_b98;
          uVar16 = local_b94;
          uVar18 = local_b90;
          uVar23 = local_b8c;
          uVar24 = local_b88;
          if (((iVar13 != 0 || iVar11 != 0) && (iVar5 != 0)) &&
             ((uVar15 = local_b84, uVar16 = local_b80, uVar18 = local_b7c, uVar23 = local_b78,
              uVar24 = local_b74, iVar11 != 0 &&
              (uVar15 = local_b70, uVar16 = local_b6c, uVar18 = local_b68, uVar23 = local_b64,
              uVar24 = local_b60, iVar13 != 0)))) {
            __src = &local_b70;
            if (local_644._0_1_ != '\x01') {
              __src = &local_b84;
            }
            memcpy(&local_bac,__src,0x14);
            uVar15 = local_bac;
            uVar16 = local_ba8;
            uVar18 = local_ba4;
            uVar23 = local_ba0;
            uVar24 = local_b9c;
          }
          _mesh_re_ip_update(auStack_300,uVar15,uVar16,uVar18,uVar23,uVar24);
        }
        local_bd0 = CONCAT22(local_8a0,local_5c8);
        local_bcc = CONCAT13(pbVar20[0x31],local_bcc._1_3_);
        local_bc8 = *(undefined4 *)(pbVar20 + 0x34);
        iVar5 = mesh_db_ap_entry_add(local_2f0,0,&local_bd0,1);
        if ((iVar5 != 0) && (mesh_warning_switch != '\0')) {
          printf("[MESH_WARNING]%s()/%d Add or update mesh ap entry(%d) failed\n",
                 "_mesh_pkt_wtp_event_req_listen",0x284,(uint)local_2f0);
          goto LAB_004c2c0c;
        }
LAB_004c289c:
        iVar2 = iVar2 + 1;
        pbVar20 = pbVar20 + 0x40;
      }
      else {
LAB_004c2890:
        if (mesh_warning_switch == '\0') goto LAB_004c289c;
        printf("[MESH_WARNING]%s()/%d Find ap entry[[%02x:%02x:%02x:%02x:%02x:%02x]] or pap entry[[%02x:%02x:%02x:%02x:%02x:%02x]] failed\n"
               ,"_mesh_pkt_wtp_event_req_listen",0x262,(uint)*pbVar20,(uint)pbVar20[1],
               (uint)pbVar20[2],(uint)pbVar20[3],(uint)pbVar20[4],(uint)pbVar20[5],
               (uint)pbVar20[0x38],(uint)pbVar20[0x39],(uint)pbVar20[0x3a],(uint)pbVar20[0x3b],
               (uint)pbVar20[0x3c],(uint)pbVar20[0x3d]);
LAB_004c2c0c:
        iVar2 = iVar2 + 1;
        pbVar20 = pbVar20 + 0x40;
      }
    }
  }
  if ((local_be0 != 0) &&
     ((((local_89c == 1 || (local_89c == 3)) || (local_89c == 2)) &&
      ((iVar2 = mesh_db_discover_state_get(), iVar2 == 1 &&
       (puVar3 = (ushort *)cw_priv_mesh_private_control_get(iVar1,1), puVar3 != (ushort *)0x0))))))
  {
    puVar4 = (ushort *)cw_priv_mesh_private_control_get(iVar1,0x16);
    iVar2 = 0;
LAB_004c2764:
    uVar22 = *puVar3;
    do {
      if ((int)(uint)uVar22 <= iVar2) goto LAB_004c299c;
      pbVar20 = (byte *)(*(int *)(puVar3 + 2) + iVar2 * 0x51);
      iVar5 = apmngr_db_entry_get_by_mac(pbVar20,auStack_5d8);
      if (iVar5 == 0) {
        __s1 = pbVar20 + 8;
        if ((__s1 == (byte *)0x0) || (iVar5 = 0, puVar4 == (ushort *)0x0)) {
          if (mesh_warning_switch == '\0') {
            iVar2 = iVar2 + 1;
            goto LAB_004c2764;
          }
          uVar21 = (uint)pbVar20[9];
          uVar17 = (uint)pbVar20[8];
          pcVar14 = 
          "[MESH_WARNING]%s()/%d Find product type and mode of entry[[%02x:%02x:%02x:%02x:%02x:%02x]]\n"
          ;
          uVar7 = (uint)pbVar20[10];
          uVar15 = 0x298;
          uVar8 = (uint)pbVar20[0xb];
          uVar9 = (uint)pbVar20[0xc];
          uVar10 = (uint)pbVar20[0xd];
        }
        else {
          for (; iVar5 < (int)(uint)*puVar4; iVar5 = iVar5 + 1) {
            pvVar19 = (void *)(*(int *)(puVar4 + 2) + iVar5 * 0x10);
            iVar11 = memcmp(__s1,pvVar19,6);
            if (iVar11 == 0) {
              uVar7 = (uint)*(byte *)((int)pvVar19 + 6);
              uVar21 = 0xffffffff;
              if (uVar7 < 4) {
                uVar21 = uVar7;
              }
              uVar9 = *(uint *)((int)pvVar19 + 8) & 1;
              uVar8 = 1;
              if (uVar9 == 0) {
                uVar8 = *(uint *)((int)pvVar19 + 8) & 2;
              }
              if (uVar7 == 1) {
                uVar9 = 1;
              }
              else if ((uVar7 != 0) && (uVar7 != 3)) {
                uVar9 = 0;
              }
              goto LAB_004c2f3c;
            }
          }
          uVar8 = 2;
          uVar21 = 1;
          uVar9 = 1;
LAB_004c2f3c:
          local_bd0 = CONCAT22(local_8a0,local_5c8);
          local_bcc._1_3_ = CONCAT12(pbVar20[7],local_bcc._2_2_);
          local_bcc = CONCAT13(pbVar20[6],local_bcc._1_3_);
          iVar5 = mesh_db_discover_list_add
                            (__s1,pbVar20 + 0xe,pbVar20 + 0x4f,uVar21,uVar8,uVar9,&local_bd0);
          if (iVar5 == 0) {
            iVar2 = iVar2 + 1;
            goto LAB_004c2764;
          }
          if (mesh_warning_switch == '\0') {
            iVar2 = iVar2 + 1;
            goto LAB_004c2764;
          }
          uVar21 = (uint)pbVar20[9];
          uVar17 = (uint)pbVar20[8];
          pcVar14 = 
          "[MESH_WARNING]%s()/%d Add or update mesh discover ap entry[[%02x:%02x:%02x:%02x:%02x:%02x]] failed\n"
          ;
          uVar7 = (uint)pbVar20[10];
          uVar15 = 0x2a1;
          uVar8 = (uint)pbVar20[0xb];
          uVar9 = (uint)pbVar20[0xc];
          uVar10 = (uint)pbVar20[0xd];
        }
      }
      else {
        if (mesh_warning_switch == '\0') goto code_r0x004c27a0;
        uVar21 = (uint)pbVar20[1];
        uVar17 = (uint)*pbVar20;
        uVar15 = 0x293;
        uVar7 = (uint)pbVar20[2];
        uVar8 = (uint)pbVar20[3];
        uVar9 = (uint)pbVar20[4];
        uVar10 = (uint)pbVar20[5];
        pcVar14 = "[MESH_WARNING]%s()/%d Find pap entry[[%02x:%02x:%02x:%02x:%02x:%02x]] failed\n";
      }
      iVar2 = iVar2 + 1;
      printf(pcVar14,"_mesh_pkt_wtp_event_req_listen",uVar15,uVar17,uVar21,uVar7,uVar8,uVar9,uVar10)
      ;
      uVar22 = *puVar3;
    } while( true );
  }
  if (((local_be0 != 0) && (((local_89c == 1 || (local_89c == 3)) || (local_89c == 2)))) &&
     (puVar3 = (ushort *)cw_priv_mesh_private_control_get(iVar1,0x16), puVar3 != (ushort *)0x0)) {
    iVar5 = 0;
    iVar2 = 0;
    iVar11 = 0;
LAB_004c28fc:
    do {
      uVar21 = (uint)*puVar3;
      while( true ) {
        while( true ) {
          if ((int)uVar21 <= iVar11) {
            if (iVar2 != 0) {
              mesh_pkt_re_operation_request_send(local_8a0,iVar2,auStack_9e0,0);
            }
            if (iVar5 != 0) {
              mesh_pkt_re_operation_request_send(local_8a0,iVar5,auStack_b0c,1);
            }
            goto LAB_004c299c;
          }
          pvVar19 = (void *)(*(int *)(puVar3 + 2) + iVar11 * 0x10);
          uVar21 = 1;
          cVar12 = *(char *)((int)pvVar19 + 6);
          if (((cVar12 != '\x01') && (uVar21 = *(uint *)((int)pvVar19 + 8) & 1, cVar12 != '\0')) &&
             (uVar21 = 0, cVar12 == '\x03')) {
            uVar21 = *(uint *)((int)pvVar19 + 8) & 1;
          }
          if (*(char *)((int)pvVar19 + 7) != '\0') break;
          cVar12 = *(char *)((int)pvVar19 + 0xc);
          if (uVar21 == 0) goto LAB_004c2cd8;
          if (1 < (byte)(cVar12 - 1U)) {
            iVar11 = iVar11 + 1;
            goto LAB_004c28fc;
          }
          iVar11 = iVar11 + 1;
          if (0x31 < iVar2) goto LAB_004c28fc;
          iVar13 = iVar2 * 6;
          iVar2 = iVar2 + 1;
          memcpy(auStack_9e0 + iVar13,pvVar19,6);
          uVar21 = (uint)*puVar3;
        }
        if (uVar21 != 0) break;
        cVar12 = *(char *)((int)pvVar19 + 0xc);
LAB_004c2cd8:
        if (cVar12 != '\x03') {
          iVar11 = iVar11 + 1;
          goto LAB_004c28fc;
        }
        if (0x31 < iVar5) {
          iVar11 = iVar11 + 1;
          goto LAB_004c28fc;
        }
        iVar13 = iVar5 * 6;
        iVar5 = iVar5 + 1;
        iVar11 = iVar11 + 1;
        memcpy(auStack_b0c + iVar13,pvVar19,6);
        uVar21 = (uint)*puVar3;
      }
      iVar11 = iVar11 + 1;
    } while( true );
  }
LAB_004c299c:
  if ((local_be0 != 0) &&
     ((((local_89c == 1 || (local_89c == 3)) ||
       ((local_89c == 2 || (((local_89c == 4 || (local_89c == 8)) || (local_89c == 6)))))) &&
      (pvVar19 = (void *)cw_priv_mesh_private_control_get(iVar1,0xc), pvVar19 != (void *)0x0)))) {
    uVar22 = local_8a0;
    if (((local_89c != 1) && (local_89c != 3)) && (local_89c != 2)) {
      uVar22 = local_898;
    }
    iVar2 = apmngr_db_entry_get_by_mac(pvVar19,auStack_300);
    uVar15 = 1;
    if ((iVar2 == 0) &&
       ((*(char *)((int)pvVar19 + 6) == '\x01' ||
        ((iVar2 = mesh_db_re_auto_switch_get(local_bdc), iVar2 == 0 &&
         ((local_bdc[0] != 0 ||
          ((iVar2 = mesh_db_ap_entry_get(uVar22,auStack_b48), iVar2 == 0 && (local_b14 != '\0'))))))
        )))) {
      memcpy(local_bdc + 1,pvVar19,6);
      mesh_pkt_re_add_tmp_request_send(local_8a0,1,local_bdc + 1,0x3c);
      if ((local_89c == 4) || ((local_89c == 8 || (uVar15 = 0, local_89c == 6)))) {
        uVar15 = 0;
        mesh_pkt_re_add_tmp_request_send((int)(short)local_898,1,local_bdc + 1,0x3c);
      }
    }
    memcpy(&local_bb8,pvVar19,6);
    local_bb0 = uVar15;
    FUN_0051ad88(&local_bc4);
    FUN_0051ad88(&local_b54);
    iVar2 = cw_priv_mesh_private_control_add(&local_bc4,0xd,&local_bb8);
    if ((iVar2 != 0) ||
       (iVar2 = cw_service_msg_add(param_3,0x25,&local_b5c,1,0x76,&local_bc4), iVar2 != 0)) {
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d Add pair query result failed\n","_mesh_pkt_wtp_event_req_listen"
               ,0x2e8);
      }
      goto LAB_004c2cbc;
    }
    cw_priv_mesh_private_control_sub_ele_free(&local_bc4);
  }
  if ((((local_89c == 1) || (local_89c == 3)) || (local_89c == 2)) &&
     (psVar6 = (short *)cw_priv_mesh_private_control_get(iVar1,0x15), psVar6 != (short *)0x0)) {
    if (*psVar6 == 0) {
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d Illegal mesh enable:%d\n","_mesh_pkt_wtp_event_req_listen",0x30f
               ,0);
      }
LAB_004c2cbc:
      cw_priv_mesh_private_control_sub_ele_free(&local_bc4);
      return 0xffffffff;
    }
    if (local_be0 == *psVar6) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d cap_entry mesh_switch %d\n","_mesh_pkt_wtp_event_req_listen",
               0x303,(int)local_6a9);
      }
      if (local_6a9 == '\0') {
        apmngr_set_ap_mesh_switch(local_8a0,1);
        mesh_pkt_enable_request_send(local_8a0,1);
      }
      if (mesh_warning_switch != '\0') {
        printf("[MESH_WARNING]%s()/%d Mesh enable is same\n","_mesh_pkt_wtp_event_req_listen",0x30a)
        ;
      }
    }
  }
  mesh_pkt_dump(param_3);
  return 0;
code_r0x004c27a0:
  iVar2 = iVar2 + 1;
  goto LAB_004c2764;
}

