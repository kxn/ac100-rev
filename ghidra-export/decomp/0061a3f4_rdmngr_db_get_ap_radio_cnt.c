// func rdmngr_db_get_ap_radio_cnt @ 0061a3f4 size=116

int rdmngr_db_get_ap_radio_cnt(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = apdb_radio_count_by_id();
  if (((iVar1 == -1) && (rdmngr_err_switch != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d apdb_radio_count_by_id() fail.\n","rdmngr_db_get_ap_radio_cnt",
           0x676);
  }
  return iVar1;
}

