// func wserv_db_is_rd_entry_firm @ 005f46b0 size=252

bool wserv_db_is_rd_entry_firm(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  char *pcVar7;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      bVar6 = false;
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      pcVar7 = (char *)(DAT_007cbf04 + uVar1 * 0xc);
      if (*pcVar7 != '\0') {
        bVar6 = pcVar7[1] != '\0';
      }
      FUN_00407f30(DAT_007cbef0);
      return bVar6;
    }
  }
  if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[warning]%s(): %d  -> idx[%d] is invalid!\r\n","wserv_db_is_rd_entry_firm",0x1647
           ,uVar1);
  }
  return false;
}

