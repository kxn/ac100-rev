// func stats_db_sta_for_each_range_for_specify_ap @ 0066d640 size=232

undefined4 stats_db_sta_for_each_range_for_specify_ap(code *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar1 = 0xffffffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if (param_1 != (code *)0x0) {
    FUN_0051ad88(&local_28);
    FUN_004082d0(l_stats_data,0xffffffff);
    FUN_00408570(DAT_007cc8e0,_stats_sta_copy_to_list,&local_28);
    FUN_00407f30(l_stats_data);
    iVar2 = FUN_004081b0(&local_28);
    while (uVar1 = 0, iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      if (param_3 == *(ushort *)(iVar2 + 0x18)) {
        (*param_1)(iVar2 + 0x10,param_2);
      }
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
  }
  return uVar1;
}

