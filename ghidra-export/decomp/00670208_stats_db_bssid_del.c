// func stats_db_bssid_del @ 00670208 size=188

undefined4 stats_db_bssid_del(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d bssid is null!\n","stats_db_bssid_del",0x1159);
    }
  }
  else {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_007cc8f4,param_1);
    if (iVar1 != 0) {
      FUN_00407f40(DAT_007cc8f4,iVar1);
      FUN_00407df0(iVar1);
    }
    uVar2 = 0;
    FUN_00407f30(l_stats_data);
  }
  return uVar2;
}

