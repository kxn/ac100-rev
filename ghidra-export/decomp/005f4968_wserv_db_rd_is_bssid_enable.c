// func wserv_db_rd_is_bssid_enable @ 005f4968 size=1

undefined4 wserv_db_rd_is_bssid_enable(undefined4 param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  char acStack_50 [40];
  
  uVar10 = 0;
  memset(acStack_50,0,0x21);
  iVar3 = _wserv_is_rd_enable(param_1);
  if (iVar3 != 0) {
    uVar4 = rdmngr_db_generate_rd_idx_by_rd_id(param_1);
    if (-1 < (int)uVar4) {
      iVar3 = apmngr_db_get_ap_max();
      iVar5 = apmngr_db_get_template_max();
      iVar6 = apmngr_db_get_sensor_max();
      iVar7 = rdmngr_profile_get_max_rd_per_ap();
      if (uVar4 < (uint)((iVar3 + iVar5 + iVar6) * iVar7)) {
        uVar11 = 0;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        if (*(char *)(DAT_007cbf04 + uVar4 * 0xc) == '\0') {
          if ((g_wserv_warning != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n",
                   "wserv_db_rd_is_bssid_enable",0x16b0,uVar4);
          }
        }
        else {
code_r0x005f4ac8:
          uVar8 = rdmngr_profile_get_max_wlan_per_rd();
          if (uVar11 < uVar8) {
            pcVar9 = (char *)(*(int *)(DAT_007cbf04 + uVar4 * 0xc + 8) + uVar11 * 6);
            if (*pcVar9 == '\0') {
              uVar11 = uVar11 + 1;
              goto code_r0x005f4ac8;
            }
            uVar8 = (uint)*(short *)(pcVar9 + 2);
            if ((-1 < (int)uVar8) && (uVar8 < l_wserv_profile)) {
              iVar3 = DAT_007cbefc + uVar8 * 0x21c;
              if (*(int *)(iVar3 + 0xc) != 0) {
                uVar1 = iVar3 + 299U & 3;
                uVar2 = iVar3 + 0x12eU & 3;
                if (((*(int *)((iVar3 + 299U) - uVar1) << uVar1 * 8 |
                     g_wserv_warning & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8) != 0
                    || *(uint *)((iVar3 + 0x12eU) - uVar2) >> (3 - uVar2) * 8 != 0) {
                  pcVar9 = (char *)(iVar3 + 0x140);
                  if (*(int *)(iVar3 + 0x13c) == 2) {
                    iVar3 = wserv_db_ssid_utf8_to_gbk(pcVar9,acStack_50);
                    if (iVar3 != 0) {
                      uVar10 = 0;
                      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                        printf("<wserv>[error]%s(): %d  -> wserv_db_ssid_utf8_to_gbk() fail!\r\n",
                               "wserv_db_rd_is_bssid_enable",0x16c8);
                      }
                      goto code_r0x005f4b84;
                    }
                    pcVar9 = acStack_50;
                  }
                  iVar3 = strncmp(pcVar9,param_2,0x20);
                  if (iVar3 == 0) {
                    uVar10 = 1;
                    goto code_r0x005f4b84;
                  }
                  uVar11 = uVar11 + 1;
                  goto code_r0x005f4ac8;
                }
              }
              if (g_wserv_warning == 0) {
                uVar11 = uVar11 + 1;
              }
              else {
                iVar3 = is_target_debug_ap();
                if (iVar3 == 0) {
                  uVar11 = uVar11 + 1;
                }
                else {
                  pcVar9 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is disable!\r\n";
                  uVar10 = 0x16c0;
code_r0x005f4bbc:
                  printf(pcVar9,"wserv_db_rd_is_bssid_enable",uVar10,uVar8);
                  uVar11 = uVar11 + 1;
                }
              }
              goto code_r0x005f4ac8;
            }
            if (g_wserv_warning == 0) {
              uVar11 = uVar11 + 1;
            }
            else {
              iVar3 = is_target_debug_ap();
              if (iVar3 != 0) {
                uVar10 = 0x16bb;
                pcVar9 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n";
                goto code_r0x005f4bbc;
              }
              uVar11 = uVar11 + 1;
            }
            goto code_r0x005f4ac8;
          }
          uVar10 = 0;
        }
code_r0x005f4b84:
        FUN_00407f30(DAT_007cbef0);
        return uVar10;
      }
    }
    if (g_wserv_warning != 0) {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      printf("<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n","wserv_db_rd_is_bssid_enable",
             0x16a9,param_1);
      return 0;
    }
  }
  return 0;
}

