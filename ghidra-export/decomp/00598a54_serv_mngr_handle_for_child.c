// func serv_mngr_handle_for_child @ 00598a54 size=2324

undefined4 serv_mngr_handle_for_child(int param_1,void *param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *__src;
  int *piVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  byte local_60;
  byte local_5f;
  byte local_5e;
  byte local_5d;
  byte local_5c;
  byte local_5b;
  undefined1 auStack_5a [6];
  undefined1 local_54;
  
  memset(&local_60,0,0x34);
  local_a8 = 0;
  local_a4 = 0;
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","serv_mngr_handle_for_child",0x4e,
           "(NULL != parsed_pkt) && (NULL != basic)");
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x10) == 9) {
    iVar3 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_78 = 0;
    local_74 = (undefined4 *)0x0;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    if (iVar3 == 0) goto LAB_00598ac8;
    __src = (void *)cw_priv_mesh_private_control_get(iVar3,4);
    if (__src == (void *)0x0) {
      pcVar8 = (char *)cw_priv_mesh_private_control_get(iVar3,7);
      if ((pcVar8 != (char *)0x0) && (*pcVar8 == '\x01')) {
        memcpy(&local_60,param_2,0x34);
        memcpy(auStack_5a,param_2,6);
        local_54 = 1;
        for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(pcVar8 + 2); iVar3 = iVar3 + 1) {
          memcpy(&local_60,(void *)(*(int *)(pcVar8 + 4) + iVar3 * 0x40),6);
          serv_ent_handle(2,&local_60,0,0);
        }
      }
      goto LAB_00598ac8;
    }
    FUN_0051ad88(&local_84);
    FUN_0051ad88(&local_70);
    FUN_0051ad88(&local_a0);
    iVar3 = serv_msg_mngr_get(3);
    if (iVar3 == 0) {
      iVar4 = 0;
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
        iVar10 = 0;
      }
      else {
        printf("[CW_ERROR]%32s():%4d get message manager of message type[%d] failed\n",
               "serv_mngr_handle_for_child",99,3);
        iVar10 = 0;
      }
    }
    else {
      iVar10 = cw_parsed_pkt_create(3);
      if (iVar10 == 0) {
        iVar4 = 0;
        if (capwap_err_switch != 0) {
          iVar3 = is_target_debug_ap();
          iVar4 = 0;
          if (iVar3 != 0) {
            pcVar8 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar9 = 0x69;
            goto LAB_00598f30;
          }
        }
      }
      else {
        iVar4 = cw_parsed_pkt_create(4);
        if (iVar4 == 0) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar8 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar9 = 0x6f;
            goto LAB_00598f30;
          }
        }
        else {
          iVar5 = add_rslt_code_to_parsed_pkt(iVar4);
          if (iVar5 == -1) {
            if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar8 = "[CW_ERROR]%32s():%4d add result code failed\n";
              uVar9 = 0x74;
              goto LAB_00598f30;
            }
          }
          else {
            for (iVar5 = FUN_004081b0((int)__src + 8); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
              iVar6 = cw_service_msg_add(iVar10,*(undefined2 *)(iVar5 + 0xc),
                                         *(undefined4 *)(iVar5 + 0x10),0);
              if (iVar6 != 0) {
                if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Add msg element(%d) failed\n",
                         "serv_mngr_handle_for_child",0x7c,(uint)*(ushort *)(iVar5 + 0xc));
                }
                goto LAB_00598da4;
              }
            }
            memcpy(&local_60,param_2,0x34);
            memcpy(auStack_5a,param_2,6);
            local_54 = 1;
            memcpy(&local_60,__src,6);
            for (iVar3 = FUN_004081b0(iVar3 + 4); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
              if (*(code **)(iVar3 + 0x10) != (code *)0x0) {
                (**(code **)(iVar3 + 0x10))(iVar10,&local_60,iVar4);
              }
            }
            piVar7 = (int *)cw_msg_ele_val_get(iVar4,0x21);
            if (piVar7 == (int *)0x0) {
              if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                pcVar8 = "[CW_ERROR]%32s():%4d Get result code failed\n";
                uVar9 = 0x91;
                goto LAB_00598f30;
              }
            }
            else {
              if (*piVar7 == 0) {
                if ((capwap_debug_switch != 0) && (iVar3 = is_target_debug_ap(1), iVar3 != 0)) {
                  printf("[CW_DEBUG]%32s():%4d Child AP[%02X-%02X-%02X-%02X-%02X-%02X] joined,trigger enter run event\n"
                         ,"serv_mngr_handle_for_child",0x97,(uint)local_60,(uint)local_5f,
                         (uint)local_5e,(uint)local_5d,(uint)local_5c,(uint)local_5b);
                }
                serv_ent_handle(1,&local_60,iVar10,iVar4);
              }
              memcpy(&local_78,__src,6);
              FUN_004082c0(&local_70,iVar4 + 0x1c);
              iVar3 = cw_priv_mesh_private_control_add(&local_a0,5,&local_78);
              if (iVar3 == -1) {
                if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  pcVar8 = "[CW_ERROR]%32s():%4d Add mesh join result failed\n";
                  uVar9 = 0x9e;
LAB_00598f30:
                  printf(pcVar8,"serv_mngr_handle_for_child",uVar9);
                }
              }
              else {
                iVar3 = cw_service_msg_add(param_3,0x25,&local_8c,1,0x76,&local_a0);
                if (((iVar3 == -1) && (capwap_err_switch != 0)) &&
                   (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  pcVar8 = "[CW_ERROR]%32s():%4d Add vendor specific payload failed\n";
                  uVar9 = 0xa3;
                  goto LAB_00598f30;
                }
              }
            }
          }
        }
      }
    }
LAB_00598da4:
    cw_priv_mesh_private_control_sub_ele_free(&local_a0);
    cw_priv_mesh_private_control_join_sub_ele_free(&local_78);
    if (iVar10 != 0) {
      cw_parsed_pkt_destroy(iVar10);
    }
    if (iVar4 == 0) {
      uVar1 = *(uint *)(param_1 + 0x10);
    }
    else {
      cw_parsed_pkt_destroy(iVar4);
      uVar1 = *(uint *)(param_1 + 0x10);
    }
  }
  else {
LAB_00598ac8:
    iVar4 = 0;
    iVar10 = 0;
    uVar1 = *(uint *)(param_1 + 0x10);
  }
  if (uVar1 < 7) {
    return 0;
  }
  puVar2 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x75);
  local_78 = 0;
  local_74 = (undefined4 *)0x0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  if (puVar2 == (ushort *)0x0) {
    return 0;
  }
  iVar3 = serv_msg_mngr_get(*(undefined4 *)(param_1 + 0x10));
  if (iVar3 == 0) {
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d get message manager of message type[%d] failed\n",
             "serv_mngr_handle_for_child",0xcb,*(undefined4 *)(param_1 + 0x10));
    }
    if (iVar10 == 0) goto LAB_00598e18;
  }
  else {
    iVar10 = cw_parsed_pkt_create(*(undefined4 *)(param_1 + 0x10));
    if (iVar10 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d Malloc failed\n","serv_mngr_handle_for_child",0xd1);
      }
      goto LAB_00598e18;
    }
    if (param_3 != 0) {
      FUN_0051ad88(&local_6c);
      local_78 = CONCAT22(1,local_78._2_2_);
      local_74 = &local_a8;
      iVar4 = cw_parsed_pkt_create(*(undefined4 *)(param_3 + 0x10));
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d Malloc failed\n","serv_mngr_handle_for_child",0xdc);
        }
        goto LAB_00598e10;
      }
    }
    for (iVar5 = FUN_004081b0(puVar2 + 6); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
      iVar6 = cw_service_msg_add(iVar10,*(undefined2 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10),0
                                );
      if (iVar6 != 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d Add msg element(%d) failed\n","serv_mngr_handle_for_child",
                 0xe5,(uint)*(ushort *)(iVar5 + 0xc));
        }
        goto LAB_00598e10;
      }
    }
    memcpy(&local_60,param_2,0x34);
    memcpy(auStack_5a,param_2,6);
    iVar5 = 0;
    local_54 = 1;
    while (iVar5 < (int)(uint)*puVar2) {
      memcpy(&local_60,(void *)(*(int *)(puVar2 + 2) + iVar5 * 6),6);
      memcpy(&local_a8,(void *)(*(int *)(puVar2 + 2) + iVar5 * 6),6);
      for (iVar6 = FUN_004081b0(iVar3 + 4); iVar6 != 0; iVar6 = FUN_00408680(iVar6)) {
        if (*(code **)(iVar6 + 0x10) != (code *)0x0) {
          (**(code **)(iVar6 + 0x10))(iVar10,&local_60,iVar4);
        }
      }
      if (iVar4 == 0) {
        iVar5 = iVar5 + 1;
      }
      else {
        FUN_004082c0(&local_6c,iVar4 + 0x1c);
        iVar6 = cw_service_msg_add(param_3,0x25,&local_a0,1,0x75,&local_78);
        if (iVar6 == -1) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Add vendor specific payload failed\n",
                   "serv_mngr_handle_for_child",0xff);
          }
          cw_priv_mesh_public_control_sub_ele_free(&local_78);
          break;
        }
        cw_priv_mesh_public_control_sub_ele_free(&local_78);
        iVar5 = iVar5 + 1;
      }
    }
  }
LAB_00598e10:
  cw_parsed_pkt_destroy(iVar10);
LAB_00598e18:
  if (iVar4 == 0) {
    return 0;
  }
  cw_parsed_pkt_destroy(iVar4);
  return 0;
}

