// func _wserv_rd_add @ 005e8dd0 size=352

undefined4 _wserv_rd_add(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      iVar2 = uVar1 * 0xc;
      pcVar6 = (char *)(DAT_007cbf04 + iVar2);
      if (*pcVar6 == '\0') {
        DAT_007cbf00 = DAT_007cbf00 + 1;
        *pcVar6 = '\0';
        pcVar6[1] = '\0';
        _wserv_init_rd(pcVar6 + 4);
        *(uint *)(DAT_007cbf04 + iVar2 + 4) = param_1;
        *(undefined1 *)(DAT_007cbf04 + iVar2) = 1;
        return 0;
      }
      uVar9 = 0;
      if (g_wserv_warning == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      pcVar6 = "<wserv>[warning]%s(): %d  -> idx[%d] has been used, rf_id[%d]!\r\n";
      uVar7 = 0x642;
      uVar8 = uVar1;
      goto LAB_005e8ee0;
    }
  }
  uVar9 = 0xffffffff;
  if (g_wserv_warning == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  pcVar6 = "<wserv>[warning]%s(): %d  -> invalid rf_id[0x%08x] fail,idx[0x%08x]!\r\n";
  uVar7 = 0x63c;
  uVar8 = param_1;
  param_1 = uVar1;
LAB_005e8ee0:
  printf(pcVar6,"_wserv_rd_add",uVar7,uVar8,param_1);
  return uVar9;
}

