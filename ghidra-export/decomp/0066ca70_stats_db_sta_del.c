// func stats_db_sta_del @ 0066ca70 size=1

undefined4 stats_db_sta_del(int param_1)

{
  undefined2 *__s;
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d invalid mac!\n","stats_db_sta_del",0x90d);
    }
  }
  else {
    FUN_004082d0(l_stats_data,0xffffffff);
    __s = (undefined2 *)FUN_00407fa0(DAT_007cc8e0,param_1);
    if (__s != (undefined2 *)0x0) {
      FUN_00407f40(DAT_007cc8e0,__s);
      FUN_004080f0(DAT_007cc8dc,*__s);
      memset(__s,0,0x1c0);
    }
    uVar1 = 0;
    FUN_00407f30(l_stats_data);
  }
  return uVar1;
}

