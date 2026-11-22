// func wserv_db_rd_unbind_with_wlan_id @ 005eedbc size=1220

undefined4
wserv_db_rd_unbind_with_wlan_id(uint param_1,char param_2,uint param_3,undefined4 param_4)

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
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  local_48 = 0;
  local_44 = 0;
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
      if ((-1 < (int)param_3) && (param_3 < l_wserv_profile)) {
        iVar2 = uVar1 * 0xc;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        pcVar7 = (char *)(DAT_007cbf04 + iVar2);
        if (pcVar7[1] == '\0') {
          uVar9 = 0xffffffff;
          if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005eefc4;
          pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] has not firm yet!\r\n";
          uVar8 = 0xd6e;
          param_3 = param_1;
        }
        else {
          local_30 = param_3 * 0x21c;
          if (*(int *)(DAT_007cbefc + local_30 + 0xc) == 0) {
            uVar9 = 0xffffffff;
            if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005eefc4;
            pcVar7 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is not used!\r\n";
            uVar8 = 0xd74;
          }
          else {
            if (*pcVar7 != '\0') {
              uVar10 = (uint)(byte)(param_2 - 1);
              iVar3 = uVar10 * 6;
              if (*(char *)(*(int *)(pcVar7 + 8) + iVar3) == '\0') {
                uVar9 = 0xffffffff;
                if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005eefc4;
                pcVar7 = "<wserv>[warning]%s(): %d  -> wlan_id[%d] for idx[%d] is not used\r\n";
                uVar8 = 0xd81;
              }
              else {
                if ((int)*(short *)((char *)(*(int *)(pcVar7 + 8) + iVar3) + 2) != param_3) {
                  uVar9 = 0xffffffff;
                  if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                    printf("<wserv>[warning]%s(): %d  -> idx[%d] wlan_id[%d] wserv_id[%d] is not match wserv_id[%d]\r\n"
                           ,"wserv_db_rd_unbind_with_wlan_id",0xd87,uVar1,uVar10,
                           (int)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 2),param_3);
                  }
                  goto LAB_005eefc4;
                }
                local_44 = CONCAT13(param_2,local_44._1_3_);
                local_48 = param_1;
                iVar4 = FUN_00407fa0(*(undefined4 *)(DAT_007cbefc + local_30 + 0x218),&local_48);
                if (iVar4 != 0) {
                  local_40 = 0;
                  FUN_0051ad88(&local_3c);
                  _wserv_del_wlan_db_info_collect(iVar4,&local_40);
                  FUN_00407f40(*(undefined4 *)(DAT_007cbefc + local_30 + 0x218),iVar4);
                  FUN_00407df0(iVar4);
                }
                uVar10 = (uint)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 4);
                iVar4 = _wserv_db_vlan_ap_hash_op(uVar10,param_1,local_44._0_1_,0);
                if (iVar4 == 0) {
                  puVar6 = (undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3);
                  puVar6[1] = 0;
                  *puVar6 = 0;
                  puVar6[2] = 0;
                  puVar6[3] = 0;
                  puVar6[4] = 0;
                  puVar6[5] = 0;
                  *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 2) = 0xffff;
                  *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 4) = 0xffff;
                  *(char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 1) = param_2;
                  uVar9 = 0;
                  *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3) = 0;
                  goto LAB_005eefc4;
                }
                uVar9 = 0xffffffff;
                if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005eefc4;
                pcVar7 = 
                "<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                ;
                uVar8 = 0xd9b;
                uVar1 = param_1;
              }
              uVar9 = 0xffffffff;
              printf(pcVar7,"wserv_db_rd_unbind_with_wlan_id",uVar8,uVar10,uVar1);
              goto LAB_005eefc4;
            }
            uVar9 = 0xffffffff;
            if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005eefc4;
            pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
            uVar8 = 0xd7a;
            param_3 = uVar1;
          }
        }
        uVar9 = 0xffffffff;
        printf(pcVar7,"wserv_db_rd_unbind_with_wlan_id",uVar8,param_3);
LAB_005eefc4:
        FUN_00407f30(DAT_007cbef0);
        _wserv_db_do_evt(&local_3c,param_4,0);
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
      uVar9 = 0xd66;
      goto LAB_005eef84;
    }
  }
  if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
    return 0xffffffff;
  }
  pcVar7 = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
  uVar9 = 0xd60;
  param_3 = param_1;
LAB_005eef84:
  printf(pcVar7,"wserv_db_rd_unbind_with_wlan_id",uVar9,param_3);
  return 0xffffffff;
}

