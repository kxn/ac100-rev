// func wserv_db_is_wserv_bind_to_rd @ 005f39f4 size=620

uint wserv_db_is_wserv_bind_to_rd(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      if (((int)param_2 < 0) || (l_wserv_profile <= param_2)) {
        if (g_wserv_warning == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 != 0) {
          printf("<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n",
                 "wserv_db_is_wserv_bind_to_rd",0x154c,param_2);
          return 0;
        }
        return 0;
      }
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      if (*(char *)(DAT_007cbf04 + uVar1 * 0xc) == '\0') {
        uVar8 = 0;
        if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> idx[%d] has not been used, rd_id[%d]!\r\n",
                 "wserv_db_is_wserv_bind_to_rd",0x1553,uVar1,param_1);
        }
      }
      else {
        uVar8 = 0;
        if (*(int *)(DAT_007cbefc + param_2 * 0x21c + 0xc) == 0) {
          if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n",
                   "wserv_db_is_wserv_bind_to_rd",0x1559,param_2);
          }
        }
        else {
          while (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar8 < uVar6) {
            pcVar7 = (char *)(*(int *)(DAT_007cbf04 + uVar1 * 0xc + 8) + uVar8 * 6);
            if (*pcVar7 == '\0') {
              uVar8 = uVar8 + 1;
            }
            else {
              if ((int)*(short *)(pcVar7 + 2) == param_2) {
                uVar8 = 1;
                goto LAB_005f3bd0;
              }
              uVar8 = uVar8 + 1;
            }
          }
          uVar8 = 0;
        }
      }
LAB_005f3bd0:
      FUN_00407f30(DAT_007cbef0);
      return uVar8;
    }
  }
  if (g_wserv_warning == 0) {
    return 0;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 != 0) {
    printf("<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n",
           "wserv_db_is_wserv_bind_to_rd",0x1546,param_1,uVar1);
    return 0;
  }
  return 0;
}

