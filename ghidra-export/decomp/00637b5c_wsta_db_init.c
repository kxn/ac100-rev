// func wsta_db_init @ 00637b5c size=1988

undefined4 wsta_db_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *__format;
  int iVar7;
  int iVar8;
  uint uVar9;
  char local_48 [16];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\0';
  local_48[0xb] = '\0';
  local_48[0xc] = '\0';
  local_48[0xd] = '\0';
  local_48[0xe] = '\0';
  local_48[0xf] = '\0';
  if (l_wsta_data != 0) {
    if (g_wsta_warning == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("<wsta>[warning]%s(): %d  -> wstation data has been inited before!\r\n","wsta_db_init",
           0x4b5);
    return 0;
  }
  FUN_0051ad88(&wsta_mem_record);
  iVar1 = FUN_0051eb48("apmng_client","max_wstation",&l_wsta_profile);
  if (iVar1 == -1) {
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> get profile[wstation_mngr->max_wstation] fail.\r\n",
             "wsta_db_init",0x4bf);
    }
    l_wsta_profile = 100000;
  }
  DAT_007cc6bc = FUN_00407f00("wsta_mutex",1);
  if (DAT_007cc6bc == 0) {
    if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00637e40;
    __format = "<wsta>[error]%s(): %d  -> Create database mutex failed.\r\n";
    uVar2 = 0x4c6;
  }
  else {
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    snprintf((char *)&local_38,0x10,"%d",0x989a7c);
    iVar1 = getUciOptionSpecifyPath
                      ("event_params",&local_38,"threshold",local_48,"/etc/nms_report/");
    if ((iVar1 == 0) && (local_48[0] != '\0')) {
      nms_ap_overload_threshold = atoi(local_48);
    }
    DAT_007cc6c0 = FUN_004080e0(l_wsta_profile);
    if (DAT_007cc6c0 == 0) {
      if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00637e40;
      __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
      uVar2 = 0x4d5;
    }
    else {
      DAT_007cc6c8 = wsta_calloc(l_wsta_profile,0x80,0,0);
      if (DAT_007cc6c8 == 0) {
        if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00637e40;
        __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
        uVar2 = 0x4dc;
      }
      else {
        iVar1 = 0;
        uVar2 = apmngr_db_get_ap_max();
        DAT_007cc6e4 = wsta_calloc(uVar2,4,0,0);
        if (DAT_007cc6e4 == 0) {
          if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00637e40;
          __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
          uVar2 = 0x4e3;
        }
        else {
          for (; iVar3 = apmngr_db_get_ap_max(), iVar8 = DAT_007cc6e4, iVar1 < iVar3;
              iVar1 = iVar1 + 1) {
            iVar3 = iVar1 * 4;
            uVar2 = rdmngr_profile_get_max_rd_per_ap();
            uVar2 = wsta_calloc(uVar2,4,0,0);
            *(undefined4 *)(iVar8 + iVar3) = uVar2;
            if (*(int *)(DAT_007cc6e4 + iVar3) == 0) {
              if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_00637e40;
              __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
              uVar2 = 0x4ec;
              goto LAB_00637e8c;
            }
            iVar8 = 0;
            for (uVar9 = 1; uVar4 = rdmngr_profile_get_max_rd_per_ap(), uVar9 <= uVar4;
                uVar9 = uVar9 + 1) {
              iVar7 = *(int *)(DAT_007cc6e4 + iVar3);
              uVar2 = rdmngr_profile_get_max_wlan_per_rd();
              uVar2 = wsta_calloc(uVar2,0xc,0,0);
              *(undefined4 *)(iVar7 + iVar8) = uVar2;
              if (*(int *)(*(int *)(DAT_007cc6e4 + iVar3) + iVar8) == 0) {
                if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                goto LAB_00637e40;
                __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
                uVar2 = 0x4f5;
                goto LAB_00637e8c;
              }
              iVar7 = 0;
              for (uVar4 = 1; uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar4 <= uVar5;
                  uVar4 = uVar4 + 1) {
                iVar6 = *(int *)(*(int *)(DAT_007cc6e4 + iVar3) + iVar8) + iVar7;
                iVar7 = iVar7 + 0xc;
                FUN_0051ad88(iVar6);
              }
              iVar8 = iVar8 + 4;
            }
          }
          DAT_007cc6cc = FUN_004080a0(_wsta_mac_obj,_wsta_mac_key,_wsta_mac_cmp,l_wsta_profile);
          if (DAT_007cc6cc == 0) {
            if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00637e40;
            __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
            uVar2 = 0x505;
          }
          else {
            DAT_007cc6d0 = FUN_004080a0(_wsta_ip_obj,_wsta_ip_key,_wsta_ip_cmp,l_wsta_profile);
            if (DAT_007cc6d0 == 0) {
              if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_00637e40;
              __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
              uVar2 = 0x50f;
            }
            else {
              DAT_007cc6d4 = FUN_004080a0(_wsta_ipv6_obj,_wsta_ipv6_key,_wsta_ipv6_cmp,
                                          l_wsta_profile);
              if (DAT_007cc6d4 == 0) {
                if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                goto LAB_00637e40;
                __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
                uVar2 = 0x519;
              }
              else {
                DAT_007cc718 = FUN_004080a0(_wsta_tmp_mac_obj,_wsta_tmp_mac_key,_wsta_tmp_mac_cmp,
                                            l_wsta_profile);
                if (DAT_007cc718 == 0) {
                  if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                  goto LAB_00637e40;
                  __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
                  uVar2 = 0x524;
                }
                else {
                  FUN_0051ad88(&DAT_007cc71c);
                  DAT_007cc728 = FUN_004080a0(_wsta_mld_mac_obj,_wsta_mld_mac_key,_wsta_mld_mac_cmp,
                                              l_wsta_profile);
                  if (DAT_007cc728 == 0) {
                    if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                    goto LAB_00637e40;
                    __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
                    uVar2 = 0x52e;
                  }
                  else {
                    DAT_007cc72c = FUN_004080a0(_wsta_peer_mac_obj,_wsta_peer_mac_key,
                                                _wsta_peer_mac_cmp,l_wsta_profile << 1);
                    if (DAT_007cc72c == 0) {
                      if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                      goto LAB_00637e40;
                      __format = "<wsta>[error]%s(): %d  -> no memory!\r\n";
                      uVar2 = 0x537;
                    }
                    else {
                      DAT_007cc70c = FUN_00408340(300,0,_wsta_idle_timer_handle,0,0,"wsta_db_init",
                                                  0x53c);
                      if (DAT_007cc70c != -1) {
                        FUN_0051ad88(&DAT_007cc6d8);
                        DAT_007cc710 = FUN_004081b0(&DAT_007cc6d8);
                        FUN_0051ad88(&DAT_007cc6e8);
                        FUN_0051ad88(&DAT_007cc6f4);
                        FUN_0051ad88(&DAT_007cc700);
                        l_wsta_data = 1;
                        if (g_wsta_debug == 0) {
                          l_wsta_data = 1;
                          return 0;
                        }
                        iVar1 = is_target_debug_ap();
                        if (iVar1 == 0) {
                          return 0;
                        }
                        printf("<wsta>[debug]%s(): %d  -> l_wsta_mem_stat=%d.\r\n","wsta_db_init",
                               0x54c,l_wsta_mem_stat);
                        return 0;
                      }
                      if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                      goto LAB_00637e40;
                      __format = "<wsta>[error]%s(): %d  -> uac_timer_add() fail!\r\n";
                      uVar2 = 0x53f;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00637e8c:
  printf(__format,"wsta_db_init",uVar2);
LAB_00637e40:
  wsta_db_uninit();
  l_wsta_data = 0;
  return 0xffffffff;
}

