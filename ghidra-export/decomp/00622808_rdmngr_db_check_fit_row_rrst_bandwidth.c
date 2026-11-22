// func rdmngr_db_check_fit_row_rrst_bandwidth @ 00622808 size=184

undefined4 rdmngr_db_check_fit_row_rrst_bandwidth(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 & 0xff) < 6) {
    uVar1 = 0;
    uVar3 = param_2 & 0xff;
    do {
      if (((uVar3 & 1) != 0) && (*(uint *)(&DAT_0070a894 + (param_1 & 0xff) * 4) == uVar1)) {
        return 1;
      }
      uVar1 = uVar1 + 1;
      uVar3 = (int)(param_2 & 0xff) >> (uVar1 & 0x1f);
    } while (uVar1 != 6);
  }
  else if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d invalid enum value APDB_RRST_BANDWIDTH\n",
           "rdmngr_db_check_fit_row_rrst_bandwidth",0x1445);
  }
  return 0;
}

