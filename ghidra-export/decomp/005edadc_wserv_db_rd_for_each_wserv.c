// func wserv_db_rd_for_each_wserv @ 005edadc size=1136

undefined4 wserv_db_rd_for_each_wserv(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  uint uVar12;
  uint local_48 [6];
  int local_30;
  
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[0] = 0xffffffff;
  local_48[0] = rdmngr_db_generate_ap_id();
  local_30 = apmngr_db_capacity_support(local_48[0] & 0xffff,1,0x3f);
  if (param_3 == 0) {
    uVar11 = 0;
    if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> cb is null!\r\n","wserv_db_rd_for_each_wserv",0xb82);
    }
  }
  else {
    uVar5 = rdmngr_db_generate_rd_idx_by_rd_id(param_1);
    if (-1 < (int)uVar5) {
      iVar6 = apmngr_db_get_ap_max();
      iVar7 = apmngr_db_get_template_max();
      iVar8 = apmngr_db_get_sensor_max();
      iVar9 = rdmngr_profile_get_max_rd_per_ap();
      if (uVar5 < (uint)((iVar6 + iVar7 + iVar8) * iVar9)) {
        local_48[1] = 0;
        iVar6 = uVar5 * 0xc;
        FUN_0051ad88(local_48 + 2);
        uVar12 = 0;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        if (*(char *)(DAT_007cbf04 + iVar6) == '\0') {
          uVar11 = 0xffffffff;
          if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> idx[%d] has not been used!\r\n",
                   "wserv_db_rd_for_each_wserv",0xb91,uVar5);
          }
        }
        else {
LAB_005edcc0:
          uVar5 = rdmngr_profile_get_max_wlan_per_rd();
          uVar11 = 0;
          if (uVar12 < uVar5) {
            iVar7 = uVar12 * 6;
            pcVar10 = (char *)(*(int *)(DAT_007cbf04 + iVar6 + 8) + iVar7);
            if (*pcVar10 == '\0') {
              uVar12 = uVar12 + 1;
              goto LAB_005edcc0;
            }
            uVar5 = (uint)*(short *)(pcVar10 + 2);
            if ((-1 < (int)uVar5) && (uVar5 < l_wserv_profile)) {
              if (param_2 != 0) {
                iVar8 = DAT_007cbefc + uVar5 * 0x21c;
                if (*(uint *)(iVar8 + 0xc) != 0) {
                  uVar3 = iVar8 + 299U & 3;
                  uVar4 = iVar8 + 0x12eU & 3;
                  if (((*(int *)((iVar8 + 299U) - uVar3) << uVar3 * 8 |
                       *(uint *)(iVar8 + 0xc) & 0xffffffffU >> (4 - uVar3) * 8) &
                      -1 << (uVar4 + 1) * 8) != 0 ||
                      *(uint *)((iVar8 + 0x12eU) - uVar4) >> (3 - uVar4) * 8 != 0)
                  goto LAB_005edd4c;
                }
                if (local_30 == 0) {
                  uVar12 = uVar12 + 1;
                  goto LAB_005edcc0;
                }
              }
LAB_005edd4c:
              iVar8 = wserv_calloc(1,0x220);
              if (iVar8 != 0) {
                *(undefined4 *)(iVar8 + 0x10) = param_1;
                uVar1 = *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar6 + 8) + iVar7 + 1);
                *(undefined4 *)(iVar8 + 0xc) = 0;
                iVar9 = DAT_007cbefc;
                *(undefined1 *)(iVar8 + 0x14) = uVar1;
                memcpy((void *)(iVar8 + 0x1a),(void *)(iVar9 + uVar5 * 0x21c + 0x10),0x205);
                if (param_2 - 1U < 2) {
                  sVar2 = *(short *)(*(int *)(DAT_007cbf04 + iVar6 + 8) + iVar7 + 4);
                  if (sVar2 != -1) {
                    *(short *)(iVar8 + 0x18) = sVar2;
                    local_48[0] = rdmngr_db_generate_ap_id(param_1);
                    iVar7 = sVar2 * 4;
                    FUN_00407fa0(*(undefined4 *)(DAT_007cbf08 + iVar7),local_48);
                    iVar7 = *(int *)(DAT_007cbf08 + iVar7);
                    if ((iVar7 != 0) && (iVar7 = FUN_00407fa0(iVar7,local_48), iVar7 != 0)) {
                      *(char *)(iVar7 + 4) = *(char *)(iVar7 + 4) + '\x01';
                    }
                  }
                  if (param_2 == 1) {
                    *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 5;
                  }
                  else {
                    if (param_2 != 2) goto LAB_005eddb4;
                    *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 10;
                  }
                }
                else {
LAB_005eddb4:
                  if (param_2 != 0) {
                    FUN_00407df0(iVar8);
                    uVar12 = uVar12 + 1;
                    goto LAB_005edcc0;
                  }
                }
                FUN_004086b0(local_48 + 2,iVar8);
                uVar12 = uVar12 + 1;
                goto LAB_005edcc0;
              }
              if (g_wserv_warning == 0) {
                uVar12 = uVar12 + 1;
              }
              else {
                iVar7 = is_target_debug_ap();
                if (iVar7 == 0) {
                  uVar12 = uVar12 + 1;
                }
                else {
                  printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","wserv_db_rd_for_each_wserv"
                         ,0xba8);
                  uVar12 = uVar12 + 1;
                }
              }
              goto LAB_005edcc0;
            }
            if (g_wserv_warning == 0) {
              uVar12 = uVar12 + 1;
            }
            else {
              iVar7 = is_target_debug_ap();
              if (iVar7 == 0) {
                uVar12 = uVar12 + 1;
              }
              else {
                printf("<wserv>[warning]%s(): %d  -> invalid wserv_id[%d]!\r\n",
                       "wserv_db_rd_for_each_wserv",0xb9c,uVar5);
                uVar12 = uVar12 + 1;
              }
            }
            goto LAB_005edcc0;
          }
        }
        FUN_00407f30(DAT_007cbef0);
        _wserv_db_do_evt(local_48 + 2,param_3,param_4);
        return uVar11;
      }
    }
    uVar11 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n","wserv_db_rd_for_each_wserv",
             0xb89,param_1);
    }
  }
  return uVar11;
}

