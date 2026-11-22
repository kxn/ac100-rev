// func wsta_roam_db_roam_strategy_get @ 00482c1c size=72

undefined4 wsta_roam_db_roam_strategy_get(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  uVar1 = l_wsta_roam_strategy;
  FUN_00407f30(l_wsta_roam_data);
  return uVar1;
}

