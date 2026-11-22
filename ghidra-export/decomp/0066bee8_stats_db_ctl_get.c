// func stats_db_ctl_get @ 0066bee8 size=96

undefined4 stats_db_ctl_get(void *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (void *)0x0) {
    FUN_004082d0(l_stats_data,0xffffffff);
    memcpy(param_1,&stats_ctl,10);
    FUN_00407f30(l_stats_data);
    uVar1 = 0;
  }
  return uVar1;
}

