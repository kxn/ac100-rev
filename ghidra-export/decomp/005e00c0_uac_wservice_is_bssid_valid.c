// func uac_wservice_is_bssid_valid @ 005e00c0 size=1

undefined4 uac_wservice_is_bssid_valid(undefined4 param_1,undefined1 param_2,char *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  uint uVar12;
  char acStack_50 [44];
  
  uVar3 = rdmngr_db_generate_rd_id(param_1,param_2);
  uVar11 = 0;
  memset(acStack_50,0,0x21);
  iVar4 = _wserv_is_rd_enable(uVar3);
  if (iVar4 != 0) {
    uVar5 = rdmngr_db_generate_rd_idx_by_rd_id(uVar3);
    if (-1 < (int)uVar5) {
      iVar4 = apmngr_db_get_ap_max();
      iVar6 = apmngr_db_get_template_max();
      iVar7 = apmngr_db_get_sensor_max();
      iVar8 = rdmngr_profile_get_max_rd_per_ap();
      if (uVar5 < (uint)((iVar4 + iVar6 + iVar7) * iVar8)) {
        uVar12 = 0;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        if (*(char *)(DAT_007cbf04 + uVar5 * 0xc) == '\0') {
          if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n",
                   "wserv_db_rd_is_bssid_enable",0x16b0,uVar5);
          }
        }
        else {
code_r0x005f4ac8:
          uVar9 = rdmngr_profile_get_max_wlan_per_rd();
          if (uVar12 < uVar9) {
            pcVar10 = (char *)(*(int *)(DAT_007cbf04 + uVar5 * 0xc + 8) + uVar12 * 6);
            if (*pcVar10 == '\0') {
              uVar12 = uVar12 + 1;
              goto code_r0x005f4ac8;
            }
            uVar9 = (uint)*(short *)(pcVar10 + 2);
            if ((-1 < (int)uVar9) && (uVar9 < l_wserv_profile)) {
              iVar4 = DAT_007cbefc + uVar9 * 0x21c;
              if (*(int *)(iVar4 + 0xc) != 0) {
                uVar1 = iVar4 + 299U & 3;
                uVar2 = iVar4 + 0x12eU & 3;
                if (((*(int *)((iVar4 + 299U) - uVar1) << uVar1 * 8 |
                     g_wserv_warning & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8) != 0
                    || *(uint *)((iVar4 + 0x12eU) - uVar2) >> (3 - uVar2) * 8 != 0) {
                  pcVar10 = (char *)(iVar4 + 0x140);
                  if (*(int *)(iVar4 + 0x13c) == 2) {
                    iVar4 = wserv_db_ssid_utf8_to_gbk(pcVar10,acStack_50);
                    if (iVar4 != 0) {
                      uVar11 = 0;
                      if ((g_wserv_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                        printf("<wserv>[error]%s(): %d  -> wserv_db_ssid_utf8_to_gbk() fail!\r\n",
                               "wserv_db_rd_is_bssid_enable",0x16c8);
                      }
                      goto code_r0x005f4b84;
                    }
                    pcVar10 = acStack_50;
                  }
                  iVar4 = strncmp(pcVar10,param_3,0x20);
                  if (iVar4 == 0) {
                    uVar11 = 1;
                    goto code_r0x005f4b84;
                  }
                  uVar12 = uVar12 + 1;
                  goto code_r0x005f4ac8;
                }
              }
              if (g_wserv_warning == 0) {
                uVar12 = uVar12 + 1;
              }
              else {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  uVar12 = uVar12 + 1;
                }
                else {
                  pcVar10 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is disable!\r\n";
                  uVar3 = 0x16c0;
code_r0x005f4bbc:
                  printf(pcVar10,"wserv_db_rd_is_bssid_enable",uVar3,uVar9);
                  uVar12 = uVar12 + 1;
                }
              }
              goto code_r0x005f4ac8;
            }
            if (g_wserv_warning == 0) {
              uVar12 = uVar12 + 1;
            }
            else {
              iVar4 = is_target_debug_ap();
              if (iVar4 != 0) {
                uVar3 = 0x16bb;
                pcVar10 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n";
                goto code_r0x005f4bbc;
              }
              uVar12 = uVar12 + 1;
            }
            goto code_r0x005f4ac8;
          }
          uVar11 = 0;
        }
code_r0x005f4b84:
        FUN_00407f30(DAT_007cbef0);
        return uVar11;
      }
    }
    if (g_wserv_warning != 0) {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0;
      }
      printf("<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n","wserv_db_rd_is_bssid_enable",
             0x16a9,uVar3);
      return 0;
    }
  }
  return 0;
}

