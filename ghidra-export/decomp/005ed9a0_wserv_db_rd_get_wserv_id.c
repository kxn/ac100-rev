// func wserv_db_rd_get_wserv_id @ 005ed9a0 size=316

int wserv_db_rd_get_wserv_id(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  param_2 = param_2 & 0xff;
  if ((param_2 == 0) || (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 < param_2)) {
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar3 = "<wserv>[warning]%s(): %d  -> invalid wlan_id[%d]!\r\n";
      uVar4 = 0xb52;
      param_1 = param_2;
      goto LAB_005eda94;
    }
  }
  else {
    iVar1 = rdmngr_db_generate_rd_idx_by_rd_id(param_1);
    if (iVar1 != -1) {
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      pcVar3 = (char *)(*(int *)(DAT_007cbf04 + iVar1 * 0xc + 8) + (param_2 - 1) * 6);
      iVar1 = -1;
      if (*pcVar3 != '\0') {
        iVar1 = (int)*(short *)(pcVar3 + 2);
      }
      FUN_00407f30(DAT_007cbef0);
      return iVar1;
    }
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return -1;
      }
      pcVar3 = "<wserv>[error]%s(): %d  -> invalid rd_id[%d]!\r\n";
      uVar4 = 0xb59;
LAB_005eda94:
      printf(pcVar3,"wserv_db_rd_get_wserv_id",uVar4,param_1);
      return -1;
    }
  }
  return -1;
}

