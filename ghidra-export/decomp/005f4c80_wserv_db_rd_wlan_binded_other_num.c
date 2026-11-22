// func wserv_db_rd_wlan_binded_other_num @ 005f4c80 size=444

int wserv_db_rd_wlan_binded_other_num(undefined4 param_1,int param_2)

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
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      iVar2 = 0;
      if (*(char *)(DAT_007cbf04 + uVar1 * 0xc) == '\0') {
        iVar2 = -1;
        if ((g_wserv_warning != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> idx[%d] has not been used, rd_id[%d]!\r\n",
                 "wserv_db_rd_wlan_binded_other_num",0x16fc,uVar1,param_1);
        }
      }
      else {
        uVar8 = 0;
        while (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar8 < uVar6) {
          pcVar7 = (char *)(*(int *)(DAT_007cbf04 + uVar1 * 0xc + 8) + uVar8 * 6);
          uVar8 = uVar8 + 1;
          if (*pcVar7 != '\0') {
            iVar2 = iVar2 + (uint)(*(short *)(pcVar7 + 2) != param_2);
          }
        }
      }
      FUN_00407f30(DAT_007cbef0);
      return iVar2;
    }
  }
  if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n",
           "wserv_db_rd_wlan_binded_other_num",0x16f5,param_1,uVar1);
  }
  return -1;
}

