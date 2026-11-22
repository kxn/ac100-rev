// func wserv_db_rd_bind_with_wlan_id @ 005ef280 size=1396

undefined4
wserv_db_rd_bind_with_wlan_id
          (uint param_1,byte param_2,uint param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  uVar11 = (uint)param_2;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      if ((uVar11 == 0) || (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar6 < uVar11)) {
        if (g_wserv_warning == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar8 = "<wserv>[warning]%s(): %d  -> wlan_id[%d] is invalid!\r\n";
        uVar9 = 0xdbd;
        param_3 = uVar11;
        goto LAB_005ef3b4;
      }
      if (((int)param_3 < 0) || (l_wserv_profile <= param_3)) {
        if (g_wserv_warning == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar8 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n";
        uVar9 = 0xdc3;
        goto LAB_005ef3b4;
      }
      if (0x1000 < param_4) {
        if (g_wserv_warning == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar8 = "<wserv>[warning]%s(): %d  -> vlan_id[%d] is invalid!\r\n";
        uVar9 = 0xdc9;
        param_3 = param_4;
        goto LAB_005ef3b4;
      }
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      local_30 = param_3 * 0x21c;
      if (*(int *)(DAT_007cbefc + local_30 + 0xc) == 0) {
        uVar9 = 0xffffffff;
        if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005ef4b8;
        pcVar8 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is not used!\r\n";
        uVar10 = 0xdd2;
        param_1 = param_3;
      }
      else {
        iVar2 = uVar1 * 0xc;
        pcVar8 = (char *)(DAT_007cbf04 + iVar2);
        if (pcVar8[1] == '\0') {
          uVar9 = 0xffffffff;
          if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005ef4b8;
          pcVar8 = "<wserv>[warning]%s(): %d  -> rd_id[%d] has not firm yet!\r\n";
          uVar10 = 0xdd8;
        }
        else {
          if (*pcVar8 != '\0') {
            iVar3 = (uVar11 - 1 & 0xff) * 6;
            pcVar8 = (char *)(*(int *)(pcVar8 + 8) + iVar3);
            if (*pcVar8 == '\0') {
              *(short *)(pcVar8 + 2) = (short)param_3;
              *(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 4) = (short)param_4;
              *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3) = 1;
              puVar7 = (uint *)wserv_malloc(8);
              if (puVar7 == (uint *)0x0) {
                uVar9 = 0xffffffff;
                if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005ef4b8;
                pcVar8 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                uVar10 = 0xdf8;
              }
              else {
                *puVar7 = param_1;
                *(byte *)(puVar7 + 1) = param_2;
                iVar2 = FUN_00408380(*(undefined4 *)(DAT_007cbefc + local_30 + 0x218),puVar7);
                if (iVar2 == 0) {
                  local_40 = 0;
                  uVar9 = 0;
                  FUN_0051ad88(&local_3c);
                  _wserv_add_wlan_db_info_collect(puVar7,&local_40);
                  iVar2 = _wserv_db_vlan_ap_hash_op(param_4,param_1,*(undefined1 *)(puVar7 + 1),1);
                  if (((iVar2 == 0) || (g_wserv_error == 0)) ||
                     (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005ef4b8;
                  uVar1 = (uint)*(byte *)(puVar7 + 1);
                  pcVar8 = 
                  "<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                  ;
                  uVar10 = 0xe0b;
                  param_3 = param_4;
                  param_4 = param_1;
                  goto LAB_005ef72c;
                }
                uVar9 = 0xffffffff;
                if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005ef4b8;
                pcVar8 = "<wserv>[error]%s(): %d  -> uac_hash_add() fail!\r\n";
                uVar10 = 0xe00;
              }
              uVar9 = 0xffffffff;
              printf(pcVar8,"wserv_db_rd_bind_with_wlan_id",uVar10);
            }
            else {
              if (((int)*(short *)(pcVar8 + 2) != param_3) ||
                 ((int)*(short *)(pcVar8 + 4) != param_4)) {
                uVar9 = 0xffffffff;
                if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  iVar3 = *(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3;
                  printf("<wserv>[warning]%s(): %d  -> rd_id[%d], wserv_id[%d] or vlan[%d] can not changed to [%d] and [%d]!\r\n"
                         ,"wserv_db_rd_bind_with_wlan_id",0xdec,param_1,(int)*(short *)(iVar3 + 2),
                         (int)*(short *)(iVar3 + 4),param_3,param_4);
                }
                goto LAB_005ef4b8;
              }
              uVar9 = 0;
              if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005ef4b8;
              pcVar8 = 
              "<wserv>[warning]%s(): %d  -> wserv_id[%d], vlan_id[%d] has bind to rd_id[%d] already!\r\n"
              ;
              uVar10 = 0xde6;
              uVar1 = param_1;
LAB_005ef72c:
              uVar9 = 0;
              printf(pcVar8,"wserv_db_rd_bind_with_wlan_id",uVar10,param_3,param_4,uVar1);
            }
            goto LAB_005ef4b8;
          }
          uVar9 = 0xffffffff;
          if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005ef4b8;
          pcVar8 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
          uVar10 = 0xdde;
          param_1 = uVar1;
        }
      }
      uVar9 = 0xffffffff;
      printf(pcVar8,"wserv_db_rd_bind_with_wlan_id",uVar10,param_1);
LAB_005ef4b8:
      FUN_00407f30(DAT_007cbef0);
      _wserv_db_do_evt(&local_3c,param_5,0);
      return uVar9;
    }
  }
  if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
    return 0xffffffff;
  }
  pcVar8 = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
  uVar9 = 0xdb7;
  param_3 = param_1;
LAB_005ef3b4:
  printf(pcVar8,"wserv_db_rd_bind_with_wlan_id",uVar9,param_3);
  return 0xffffffff;
}

