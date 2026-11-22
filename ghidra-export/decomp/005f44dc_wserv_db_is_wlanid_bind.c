// func wserv_db_is_wlanid_bind @ 005f44dc size=468

bool wserv_db_is_wlanid_bind(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  
  param_2 = param_2 & 0xff;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      if ((param_2 != 0) && (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), param_2 <= uVar6)) {
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        pcVar7 = (char *)(DAT_007cbf04 + uVar1 * 0xc);
        if (*pcVar7 == '\0') {
          bVar8 = false;
          if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> idx[%d] has not been used, rd_id[%d]!\r\n",
                   "wserv_db_is_wlanid_bind",0x1626,uVar1,param_1);
          }
        }
        else {
          bVar8 = *(char *)(*(int *)(pcVar7 + 8) + (param_2 - 1) * 6) != '\0';
        }
        FUN_00407f30(DAT_007cbef0);
        return bVar8;
      }
      if (g_wserv_warning == 0) {
        return false;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 != 0) {
        printf("<wserv>[warning]%s(): %d  -> wlan_id[%d] is invalid!\r\n","wserv_db_is_wlanid_bind",
               0x161e,param_2);
        return false;
      }
      return false;
    }
  }
  if (g_wserv_warning == 0) {
    return false;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 != 0) {
    printf("<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n",
           "wserv_db_is_wlanid_bind",0x1618,param_1,uVar1);
    return false;
  }
  return false;
}

