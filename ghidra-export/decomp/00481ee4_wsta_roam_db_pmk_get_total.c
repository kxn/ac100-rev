// func wsta_roam_db_pmk_get_total @ 00481ee4 size=1

undefined4 wsta_roam_db_pmk_get_total(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  uVar1 = DAT_00767550;
  FUN_00407f30(l_wsta_roam_data);
  return uVar1;
}

