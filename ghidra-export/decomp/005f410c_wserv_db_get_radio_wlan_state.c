// func wserv_db_get_radio_wlan_state @ 005f410c size=680

undefined4 wserv_db_get_radio_wlan_state(undefined4 param_1,int param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_get_radio_wlan_state() begin, ap_id=%d, rd_cnt=%d.\r\n"
           ,"wserv_db_get_radio_wlan_state",0x15b6,param_1,param_2);
  }
  if ((param_3 == (void *)0x0) || (param_2 < 1)) {
    uVar2 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> invalid para!\r\n","wserv_db_get_radio_wlan_state",0x15b9
            );
    }
  }
  else {
    iVar1 = rdmngr_profile_get_max_wlan_per_rd();
    iVar10 = 1;
    memset(param_3,0,iVar1 * param_2);
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    do {
      uVar2 = rdmngr_db_generate_rd_id(param_1,iVar10);
      uVar3 = rdmngr_db_generate_rd_idx_by_rd_id(uVar2);
      if ((int)uVar3 < 0) {
LAB_005f4338:
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n",
                 "wserv_db_get_radio_wlan_state",0x15c7,uVar2,uVar3);
        }
      }
      else {
        iVar1 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        iVar5 = apmngr_db_get_sensor_max();
        iVar6 = rdmngr_profile_get_max_rd_per_ap();
        if ((uint)((iVar1 + iVar4 + iVar5) * iVar6) <= uVar3) goto LAB_005f4338;
        if (*(char *)(DAT_007cbf04 + uVar3 * 0xc) != '\0') {
          uVar9 = 0;
LAB_005f4210:
          do {
            uVar7 = rdmngr_profile_get_max_wlan_per_rd();
            if (uVar7 <= uVar9) break;
            pcVar8 = (char *)(*(int *)(DAT_007cbf04 + uVar3 * 0xc + 8) + uVar9 * 6);
            if (*pcVar8 == '\0') {
              uVar9 = uVar9 + 1;
              goto LAB_005f4210;
            }
            uVar7 = (uint)*(short *)(pcVar8 + 2);
            if (-1 < (int)uVar7) {
              if (l_wserv_profile <= uVar7) {
                uVar9 = uVar9 + 1;
                goto LAB_005f4210;
              }
              if (*(int *)(DAT_007cbefc + uVar7 * 0x21c + 299) != 0) {
                iVar1 = rdmngr_profile_get_max_wlan_per_rd();
                *(undefined1 *)((int)param_3 + iVar1 * (iVar10 + -1) + uVar9) = 1;
                uVar9 = uVar9 + 1;
                goto LAB_005f4210;
              }
            }
            uVar9 = uVar9 + 1;
          } while( true );
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 <= param_2);
    uVar2 = 0;
    FUN_00407f30(DAT_007cbef0);
  }
  return uVar2;
}

