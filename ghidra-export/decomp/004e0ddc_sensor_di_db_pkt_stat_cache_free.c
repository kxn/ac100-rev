// func sensor_di_db_pkt_stat_cache_free @ 004e0ddc size=280

void sensor_di_db_pkt_stat_cache_free(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = 0;
    *param_1 = 0xffffffff;
    memset(param_1 + 0xb,0,0x4b0);
    while (iVar1 = FUN_004081b0(param_1 + 2), iVar1 != 0) {
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    while (iVar1 = FUN_004081b0(param_1 + 5), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (param_1[0x137] != 0) {
        FUN_00407f40(param_1[0x137],iVar1);
      }
      FUN_00407df0(iVar1);
    }
    while (iVar1 = FUN_004081b0(param_1 + 8), iVar1 != 0) {
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    FUN_0051ad88(param_1 + 2);
    FUN_0051ad88(param_1 + 5);
    FUN_0051ad88(param_1 + 8);
    return;
  }
  return;
}

