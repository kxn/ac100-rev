// func stats_db_bssid_get @ 00670158 size=176

undefined4 stats_db_bssid_get(void *param_1)

{
  void *__src;
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d entry is null!\n","stats_db_bssid_get",0x1138);
    }
  }
  else {
    FUN_004082d0(l_stats_data,0xffffffff);
    uVar1 = 0xffffffff;
    __src = (void *)FUN_00407fa0(DAT_007cc8f4,param_1);
    if (__src != (void *)0x0) {
      uVar1 = 0;
      memcpy(param_1,__src,10);
    }
    FUN_00407f30(l_stats_data);
  }
  return uVar1;
}

