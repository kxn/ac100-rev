// func local_serv_packet_send @ 0059a474 size=2092

int local_serv_packet_send(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *local_dc;
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  void *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [16];
  undefined4 local_58;
  undefined1 auStack_4c [28];
  int local_30;
  uint **local_2c;
  
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  memset(auStack_68,0,0x38);
  local_80 = 0;
  local_7c = (void *)0x0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  FUN_0051ad88(&local_c0);
  local_30 = cw_ac_data_size_get();
  if (local_30 == 0) {
LAB_0059a6d0:
    iVar9 = 0;
    if ((capwap_err_switch == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0059a740;
    pcVar6 = "[CW_ERROR]%32s():%4d Arg list generate failed\n";
    uVar7 = 0x1fe;
  }
  else {
    bVar1 = 10 < *(uint *)(param_1 + 0xc);
    if (*(uint *)(param_1 + 0xc) == 0) {
      uVar11 = 0;
    }
    else {
      iVar9 = 0;
      if ((bVar1) &&
         (iVar9 = FUN_004080a0(_child_arg_hash_obj,_child_arg_hash_key,_child_arg_hash_cmp),
         iVar9 == 0)) {
        if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
          printf("[CW_ERROR]%32s():%4d Failed to create child node hash.\n",
                 "local_serv_child_arg_list_generate",0x19d);
        }
        goto LAB_0059a6d0;
      }
      local_2c = &local_dc;
      uVar11 = 0;
      for (iVar10 = 0; iVar10 < local_30; iVar10 = iVar10 + 1) {
        for (iVar2 = FUN_004081b0(*(int *)(param_1 + 4) + iVar10 * 0xc); iVar2 != 0;
            iVar2 = FUN_00408680(iVar2)) {
          if (bVar1) {
            pvVar3 = (void *)FUN_00407fa0(iVar9,(undefined4 *)(iVar2 + 0xc));
            if (pvVar3 == (void *)0x0) goto LAB_0059a660;
          }
          else {
            for (pvVar3 = (void *)FUN_004081b0(&local_c0); pvVar3 != (void *)0x0;
                pvVar3 = (void *)FUN_00408680(pvVar3)) {
              for (uVar4 = 0; uVar4 < 0x14; uVar4 = uVar4 + 1) {
                *(undefined1 *)((int)local_2c + uVar4) = *(undefined1 *)((int)pvVar3 + uVar4 + 0xc);
              }
              iVar5 = FUN_004085c0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),
                                   *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),
                                   *(undefined4 *)(iVar2 + 0x1c));
              if ((iVar5 != 0) && (*(short *)(iVar2 + 0x20) == *(short *)((int)pvVar3 + 0x20)))
              goto LAB_0059a578;
            }
LAB_0059a660:
            pvVar3 = (void *)FUN_00408450(0x34,0x1b0);
            if (pvVar3 == (void *)0x0) goto LAB_0059a6d0;
            memset(pvVar3,0,0x34);
            FUN_0051ad88((int)pvVar3 + 0x28);
            memcpy((void *)((int)pvVar3 + 0xc),(void *)(iVar2 + 0xc),0x1c);
            FUN_004086b0(&local_c0,pvVar3);
            if ((bVar1) && (iVar5 = FUN_00408380(iVar9,pvVar3), iVar5 != 0)) {
              FUN_00408310(iVar9);
              goto LAB_0059a6d0;
            }
          }
LAB_0059a578:
          iVar5 = FUN_00408450(0x14,0x161);
          if (iVar5 == 0) goto LAB_0059a6d0;
          iVar8 = (int)pvVar3 + 0x28;
          memcpy((void *)(iVar5 + 0xc),(void *)(iVar2 + 0x28),6);
          FUN_004086b0(iVar8,iVar5);
          uVar4 = FUN_00407fe0(iVar8);
          if (uVar11 < uVar4) {
            uVar11 = FUN_00407fe0(iVar8);
          }
        }
      }
      if (bVar1) {
        FUN_00408310(iVar9);
      }
    }
    iVar9 = 0;
    iVar10 = FUN_00407fe0(&local_c0);
    if (iVar10 == 0) {
      uVar11 = *(uint *)(param_1 + 8);
    }
    else {
      serv_wtp_address_arg_init(&local_b4);
      local_a0 = 0xffffffff;
      local_9c = 0xffffffff;
      local_98 = 0xffffffff;
      local_a4 = 0xffffffff;
      FUN_0051ad88(auStack_4c);
      pvVar3 = (void *)FUN_00408450(uVar11 * 6,0x206);
      if (pvVar3 == (void *)0x0) {
        iVar9 = 0;
        if ((capwap_err_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
          printf("[CW_ERROR]%32s():%4d mac list is NULL\n","local_serv_packet_send",0x209);
        }
      }
      else {
        memset(pvVar3,0,uVar11 * 6);
        iVar9 = capwap_packet_parse(param_2,auStack_68,0,0,&local_a4);
        if (iVar9 == 0) {
          *(undefined2 *)(param_2 + 6) = 0;
          FUN_0051ad88(&local_74);
          for (iVar9 = FUN_004081b0(auStack_4c); iVar9 != 0; iVar9 = FUN_00408680(iVar9)) {
            iVar10 = cw_priv_mesh_public_control_add
                               (&local_80,*(undefined2 *)(iVar9 + 0xc),*(undefined4 *)(iVar9 + 0x10)
                                ,0);
            if (iVar10 != 0) {
              iVar9 = -1;
              if ((capwap_err_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
                printf("[CW_ERROR]%32s():%4d Generate public val failed\n","local_serv_packet_send",
                       0x218);
              }
              goto LAB_0059a8b0;
            }
          }
          iVar9 = 0;
          local_7c = pvVar3;
          for (iVar10 = FUN_004081b0(&local_c0); iVar10 != 0; iVar10 = FUN_00408680(iVar10)) {
            local_94 = 0;
            local_90 = 0;
            local_8c = 0;
            local_88 = 0;
            local_84 = 0;
            iVar2 = cw_pkt_buf_create(0xfa);
            if (iVar2 == 0) {
LAB_0059aaec:
              iVar9 = -1;
              if ((capwap_err_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
                printf("[CW_ERROR]%32s():%4d Buffer recreate failed\n","local_serv_packet_send",
                       0x223);
                iVar9 = -1;
              }
              break;
            }
            iVar5 = cw_parsed_pkt_create(local_58);
            if (iVar5 == 0) {
LAB_0059aad0:
              cw_pkt_buf_destroy(iVar2);
              if (iVar5 != 0) {
                cw_parsed_pkt_destroy(iVar5);
              }
              goto LAB_0059aaec;
            }
            local_80 = local_80 & 0xffff;
            for (iVar8 = FUN_004081b0(iVar10 + 0x28); iVar8 != 0; iVar8 = FUN_00408680(iVar8)) {
              uVar11 = (uint)local_80._0_2_;
              local_80 = CONCAT22(local_80._0_2_ + 1,local_80._2_2_);
              memcpy((void *)((int)local_7c + uVar11 * 6),(void *)(iVar8 + 0xc),6);
            }
            FUN_0051ad88(&local_8c);
            local_dc = &local_80;
            iVar8 = cw_service_msg_add(iVar5,0x25,&local_94,1,0x75);
            if (iVar8 != 0) {
              if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
                pcVar6 = "[CW_ERROR]%32s():%4d Add mesh public val failed\n";
                uVar7 = 0x13a;
LAB_0059ab9c:
                printf(pcVar6,"local_serv_child_send_buf_recreate",uVar7);
              }
              goto LAB_0059aad0;
            }
            iVar8 = capwap_packet_assemble(iVar2,iVar5);
            if (iVar8 != 0) {
              if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
                pcVar6 = "[CW_ERROR]%32s():%4d Assemble child parsed pkt failed\n";
                uVar7 = 0x13f;
                goto LAB_0059ab9c;
              }
              goto LAB_0059aad0;
            }
            cw_parsed_pkt_destroy(iVar5);
            local_d8 = (uint)*(ushort *)(iVar10 + 0x20);
            local_d4 = 0;
            local_d0 = 0;
            local_dc = *(uint **)(iVar10 + 0x1c);
            iVar5 = serv_wtp_address_arg_add
                              (&local_b4,*(undefined4 *)(iVar10 + 0xc),
                               *(undefined4 *)(iVar10 + 0x10),*(undefined4 *)(iVar10 + 0x14),
                               *(undefined4 *)(iVar10 + 0x18));
            if ((iVar5 != 0) ||
               (iVar5 = local_serv_packet_send_single(&local_b4,iVar2,param_3,param_4,1), iVar5 != 0
               )) {
              if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(&local_b4), iVar9 != 0)) {
                printf("[CW_ERROR]%32s():%4d serv_wtp_address_arg_add or local_serv_packet_send_single failed\n"
                       ,"local_serv_packet_send",0x22b);
              }
              iVar9 = -1;
              serv_wtp_address_arg_clear(&local_b4);
            }
            cw_pkt_buf_destroy(iVar2);
            if (iVar9 != 0) break;
          }
        }
        else {
          if (capwap_err_switch == 0) {
            *(undefined2 *)(param_2 + 6) = 0;
          }
          else {
            iVar9 = is_target_debug_ap();
            if (iVar9 == 0) {
              *(undefined2 *)(param_2 + 6) = 0;
            }
            else {
              printf("[CW_ERROR]%32s():%4d Parse buffer failed\n","local_serv_packet_send",0x20f);
              *(undefined2 *)(param_2 + 6) = 0;
            }
          }
          iVar9 = -1;
        }
LAB_0059a8b0:
        FUN_00407df0(pvVar3);
      }
      cw_priv_mesh_public_control_sub_ele_free(&local_80);
      capwap_parsed_packet_free(auStack_68);
      serv_wtp_address_arg_destroy(&local_b4);
      uVar11 = *(uint *)(param_1 + 8);
    }
    if ((((uVar11 <= *(uint *)(param_1 + 0xc)) ||
         (iVar10 = local_serv_packet_send_single(param_1,param_2,param_3,param_4,0), iVar10 == 0))
        || (iVar9 = -1, capwap_err_switch == 0)) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
    goto LAB_0059a740;
    pcVar6 = "[CW_ERROR]%32s():%4d local_serv_packet_send_single() failed\n";
    uVar7 = 0x249;
  }
  printf(pcVar6,"local_serv_packet_send",uVar7);
LAB_0059a740:
  while (iVar10 = FUN_004081b0(&local_c0), iVar10 != 0) {
    FUN_00408500(iVar10);
    while (iVar2 = FUN_004081b0(iVar10 + 0x28), iVar2 != 0) {
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
    }
    FUN_00407df0(iVar10);
  }
  return iVar9;
}

