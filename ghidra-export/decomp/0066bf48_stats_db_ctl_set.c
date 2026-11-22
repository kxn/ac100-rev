// func stats_db_ctl_set @ 0066bf48 size=136

undefined4 stats_db_ctl_set(void *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (void *)0x0) {
    FUN_004082d0(l_stats_data,0xffffffff);
    memcpy(&stats_ctl,param_1,10);
    stats_nbr_expire_time = (int)((uint)DAT_00758cfa * 3 + 1) >> 1;
    FUN_00407f30(l_stats_data);
    uVar1 = 0;
  }
  return uVar1;
}

