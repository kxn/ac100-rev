// func wserv_db_rd_bind @ 005ef7f4 size=1692

undefined4 wserv_db_rd_bind(uint param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      if (((int)param_2 < 0) || (l_wserv_profile <= param_2)) {
        if (g_wserv_warning == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar7 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n";
        uVar8 = 0xe35;
        goto LAB_005ef94c;
      }
      if (0x1000 < param_3) {
        if (g_wserv_warning == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar7 = "<wserv>[warning]%s(): %d  -> vlan_id[%d] is invalid!\r\n";
        uVar8 = 0xe3b;
        param_2 = param_3;
        goto LAB_005ef94c;
      }
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      if (*(int *)(DAT_007cbefc + param_2 * 0x21c + 0xc) == 0) {
        uVar8 = 0xffffffff;
        if (g_wserv_warning != 0) {
          iVar2 = is_target_debug_ap();
          if (iVar2 != 0) {
            pcVar7 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is not used!\r\n";
            uVar9 = 0xe42;
            uVar1 = param_2;
            goto LAB_005efa58;
          }
          uVar8 = 0xffffffff;
        }
      }
      else {
        iVar2 = uVar1 * 0xc;
        if (((char *)(DAT_007cbf04 + iVar2))[1] == '\0') {
          uVar8 = 0xffffffff;
          if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] has not firm yet!\r\n";
            uVar9 = 0xe48;
            uVar1 = param_1;
LAB_005efa58:
            uVar8 = 0xffffffff;
            printf(pcVar7,"wserv_db_rd_bind",uVar9,uVar1);
          }
        }
        else {
          uVar11 = 0;
          if (*(char *)(DAT_007cbf04 + iVar2) == '\0') {
            uVar8 = 0xffffffff;
            if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
              uVar9 = 0xe4e;
              goto LAB_005efa58;
            }
          }
          else {
            while( true ) {
              uVar1 = rdmngr_profile_get_max_wlan_per_rd();
              if (uVar1 <= uVar11) break;
              iVar3 = uVar11 * 6;
              pcVar7 = (char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3);
              if (*pcVar7 == '\0') {
                uVar11 = uVar11 + 1;
              }
              else {
                if ((int)*(short *)(pcVar7 + 2) == param_2) {
                  if ((int)*(short *)(pcVar7 + 4) == param_3) {
                    uVar8 = 0;
                    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                      printf("<wserv>[warning]%s(): %d  -> wserv_id[%d], vlan_id[%d] has bind to rd_id[%d] already!\r\n"
                             ,"wserv_db_rd_bind",0xe59,param_2,param_3,param_1);
                      uVar8 = 0;
                    }
                    goto LAB_005ef9dc;
                  }
                  if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                    printf("<wserv>[warning]%s(): %d  -> rd_id[%d], wserv_id[%d] change vlan[%d] to [%d]!\r\n"
                           ,"wserv_db_rd_bind",0xe5f,param_1,param_2,
                           (int)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 4),param_3);
                  }
                  iVar3 = *(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3;
                  uVar10 = (uint)*(short *)(iVar3 + 4);
                  uVar1 = (uint)*(byte *)(iVar3 + 1);
                  *(short *)(iVar3 + 4) = (short)param_3;
                  puVar6 = &local_40;
                  local_3c = CONCAT13((char)uVar11 + '\x01',local_3c._1_3_);
                  local_40 = param_1;
                  goto LAB_005efb8c;
                }
                uVar11 = uVar11 + 1;
              }
            }
            for (uVar1 = 0; uVar11 = rdmngr_profile_get_max_wlan_per_rd(), uVar1 < uVar11;
                uVar1 = uVar1 + 1) {
              iVar3 = uVar1 * 6;
              pcVar7 = (char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3);
              if (*pcVar7 == '\0') {
                *(short *)(pcVar7 + 2) = (short)param_2;
                *(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 4) = (short)param_3;
                *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3) = 1;
                break;
              }
            }
            uVar11 = rdmngr_profile_get_max_wlan_per_rd();
            if (uVar1 < uVar11) {
              puVar6 = (uint *)wserv_malloc(8);
              if (puVar6 == (uint *)0x0) {
                uVar8 = 0xffffffff;
                if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar7 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                  uVar9 = 0xe7f;
LAB_005efd40:
                  uVar8 = 0xffffffff;
                  printf(pcVar7,"wserv_db_rd_bind",uVar9);
                }
              }
              else {
                *puVar6 = param_1;
                *(char *)(puVar6 + 1) = (char)uVar1 + '\x01';
                iVar2 = FUN_00408380(*(undefined4 *)(DAT_007cbefc + param_2 * 0x21c + 0x218),puVar6)
                ;
                uVar1 = 0xff;
                if (iVar2 == 0) {
                  uVar10 = 0xffffffff;
LAB_005efb8c:
                  local_38 = 0;
                  FUN_0051ad88(&local_34);
                  _wserv_add_wlan_db_info_collect(puVar6,&local_38);
                  iVar2 = _wserv_db_vlan_ap_hash_op(param_3,param_1,*(undefined1 *)(puVar6 + 1),1);
                  if (iVar2 == 0) {
                    uVar8 = 0;
                    if ((((uVar10 == 0xffffffff) ||
                         (iVar2 = _wserv_db_vlan_ap_hash_op(uVar10,param_1,uVar1,0), iVar2 == 0)) ||
                        (g_wserv_error == 0)) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                    goto LAB_005ef9e4;
                    uVar9 = 0xe9d;
                    param_3 = uVar10;
                    uVar11 = uVar1;
                  }
                  else {
                    uVar8 = 0;
                    if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                    goto LAB_005ef9e4;
                    uVar9 = 0xe93;
                    uVar11 = (uint)*(byte *)(puVar6 + 1);
                  }
                  uVar8 = 0;
                  printf("<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                         ,"wserv_db_rd_bind",uVar9,param_3,param_1,uVar11);
                  goto LAB_005ef9e4;
                }
                uVar8 = 0xffffffff;
                if (g_wserv_error != 0) {
                  iVar2 = is_target_debug_ap();
                  uVar10 = 0xffffffff;
                  if (iVar2 == 0) goto LAB_005ef9e4;
                  pcVar7 = "<wserv>[error]%s(): %d  -> uac_hash_add() fail!\r\n";
                  uVar9 = 0xe87;
                  goto LAB_005efd40;
                }
              }
            }
            else {
              uVar8 = 0xffffffff;
              if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] can\'t bind wserv any more!\r\n";
                uVar9 = 0xe78;
                uVar1 = param_1;
                goto LAB_005efa58;
              }
            }
          }
        }
      }
LAB_005ef9dc:
      uVar1 = 0xff;
      uVar10 = 0xffffffff;
LAB_005ef9e4:
      FUN_00407f30(DAT_007cbef0);
      if (uVar10 != 0xffffffff) {
        _wserv_do_bind_event(1,param_1,param_2,uVar10);
        _wserv_do_status_event(3,param_1,uVar1);
      }
      _wserv_db_do_evt(&local_34,param_4,0);
      return uVar8;
    }
  }
  if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
    return 0xffffffff;
  }
  pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
  uVar8 = 0xe2f;
  param_2 = param_1;
LAB_005ef94c:
  printf(pcVar7,"wserv_db_rd_bind",uVar8,param_2);
  return 0xffffffff;
}

