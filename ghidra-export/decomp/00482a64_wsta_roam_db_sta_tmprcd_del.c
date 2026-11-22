// func wsta_roam_db_sta_tmprcd_del @ 00482a64 size=140

undefined4 wsta_roam_db_sta_tmprcd_del(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_00767560,param_1);
    if (iVar1 != 0) {
      uVar2 = 0;
      FUN_00407f40(DAT_00767560,iVar1);
      FUN_00407df0(iVar1);
    }
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar2;
}

