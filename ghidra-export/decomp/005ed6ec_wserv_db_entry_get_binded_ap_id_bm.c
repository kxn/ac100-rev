// func wserv_db_entry_get_binded_ap_id_bm @ 005ed6ec size=620

undefined4
wserv_db_entry_get_binded_ap_id_bm(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  int local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (((int)param_1 < 0) || (l_wserv_profile <= param_1)) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n",
             "wserv_db_entry_get_binded_ap_id_bm",0xb08,param_1);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if ((param_2 == 0) || (param_3 == 0)) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("<wserv>[warning]%s(): %d  -> ap_id_bm is null!\r\n","wserv_db_entry_get_binded_ap_id_bm"
           ,0xb0e);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = apmngr_db_get_ap_max();
  if (param_3 < (int)((iVar1 >> 5) + (uint)((uVar2 & 0x1f) != 0))) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      iVar1 = apmngr_db_get_ap_max();
      uVar2 = apmngr_db_get_ap_max();
      printf("<wserv>[warning]%s(): %d  -> bm len[%d] too short, %d at least.\r\n",
             "wserv_db_entry_get_binded_ap_id_bm",0xb14,param_3,
             (iVar1 >> 5) + (uint)((uVar2 & 0x1f) != 0));
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  local_20 = param_2;
  local_1c = param_4;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  iVar1 = DAT_007cbefc + param_1 * 0x21c;
  if (*(int *)(iVar1 + 0xc) == 0) {
    if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005ed8c4;
    __format = "<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n";
    uVar3 = 0xb1e;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x218);
    if (iVar1 != 0) {
      FUN_00408570(iVar1,_wserv_db_set_ap_id_bm_by_rd,&local_20);
    }
    if ((g_wserv_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005ed8c4;
    __format = "<wserv>[debug]%s(): %d  -> @ wserv_id=%d\n\r\n";
    uVar3 = 0xb26;
  }
  printf(__format,"wserv_db_entry_get_binded_ap_id_bm",uVar3,param_1);
LAB_005ed8c4:
  FUN_00407f30(DAT_007cbef0);
  return 0;
}

