// func stats_db_sta_get @ 0066cb40 size=220

undefined4 stats_db_sta_get(int param_1,void *param_2,int param_3)

{
  void *__src;
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d invalid para\n","stats_db_sta_get",0x932);
    }
  }
  else {
    FUN_004082d0(l_stats_data,0xffffffff);
    uVar1 = 1;
    __src = (void *)FUN_00407fa0(DAT_007cc8e0,param_1);
    if ((__src != (void *)0x0) && ((param_3 == 1 || ((*(byte *)((int)__src + 0xc) & 2) != 0)))) {
      uVar1 = 0;
      memcpy(param_2,__src,0x128);
    }
    FUN_00407f30(l_stats_data);
  }
  return uVar1;
}

