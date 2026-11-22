// func wserv_db_rd_unbind @ 005efec0 size=1076

undefined4 wserv_db_rd_unbind(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint local_40;
  uint local_3c;
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
      if ((-1 < (int)param_2) && (param_2 < l_wserv_profile)) {
        iVar2 = uVar1 * 0xc;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        if (((char *)(DAT_007cbf04 + iVar2))[1] == '\0') {
          uVar9 = 0xffffffff;
          if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005f00c0;
          pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] has not firm yet!\r\n";
          uVar8 = 0x109a;
          param_2 = param_1;
        }
        else {
          iVar3 = param_2 * 0x21c;
          if (*(int *)(DAT_007cbefc + iVar3 + 0xc) == 0) {
            uVar9 = 0xffffffff;
            if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005f00c0;
            pcVar7 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is not used!\r\n";
            uVar8 = 0x10a0;
          }
          else {
            uVar10 = 0;
            if (*(char *)(DAT_007cbf04 + iVar2) != '\0') {
              do {
                uVar1 = rdmngr_profile_get_max_wlan_per_rd();
                uVar9 = 0;
                if (uVar1 <= uVar10) goto LAB_005f00c0;
                iVar4 = uVar10 * 6;
                pcVar7 = (char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4);
                uVar10 = uVar10 + 1;
              } while ((*pcVar7 == '\0') || ((int)*(short *)(pcVar7 + 2) != param_2));
              local_3c = CONCAT13((char)uVar10,local_3c._1_3_);
              local_40 = param_1;
              iVar5 = FUN_00407fa0(*(undefined4 *)(DAT_007cbefc + iVar3 + 0x218),&local_40);
              if (iVar5 != 0) {
                local_38 = 0;
                FUN_0051ad88(&local_34);
                _wserv_del_wlan_db_info_collect(iVar5,&local_38);
                FUN_00407f40(*(undefined4 *)(DAT_007cbefc + iVar3 + 0x218),iVar5);
                FUN_00407df0(iVar5);
              }
              iVar5 = (int)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4 + 4);
              iVar3 = _wserv_db_vlan_ap_hash_op(iVar5,param_1,local_3c._0_1_,0);
              if (iVar3 == 0) {
                puVar6 = (undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4);
                puVar6[1] = 0;
                *puVar6 = 0;
                puVar6[2] = 0;
                puVar6[3] = 0;
                puVar6[4] = 0;
                puVar6[5] = 0;
                *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4 + 2) = 0xffff;
                *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4 + 4) = 0xffff;
                *(char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4 + 1) = (char)uVar10;
                *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar4) = 0;
                uVar9 = 0;
              }
              else {
                uVar9 = 0xffffffff;
                if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                         ,"wserv_db_rd_unbind",0x10bd,iVar5,param_1,local_3c >> 0x18);
                }
              }
              goto LAB_005f00c0;
            }
            uVar9 = 0xffffffff;
            if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005f00c0;
            pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
            uVar8 = 0x10a6;
            param_2 = uVar1;
          }
        }
        uVar9 = 0xffffffff;
        printf(pcVar7,"wserv_db_rd_unbind",uVar8,param_2);
LAB_005f00c0:
        FUN_00407f30(DAT_007cbef0);
        _wserv_db_do_evt(&local_34,param_3,0);
        return uVar9;
      }
      if (g_wserv_warning == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n";
      uVar9 = 0x1092;
      goto LAB_005f0084;
    }
  }
  if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
    return 0xffffffff;
  }
  pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
  uVar9 = 0x108c;
  param_2 = param_1;
LAB_005f0084:
  printf(pcVar7,"wserv_db_rd_unbind",uVar9,param_2);
  return 0xffffffff;
}

