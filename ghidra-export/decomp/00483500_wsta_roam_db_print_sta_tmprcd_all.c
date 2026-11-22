// func wsta_roam_db_print_sta_tmprcd_all @ 00483500 size=104

void wsta_roam_db_print_sta_tmprcd_all(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  uVar1 = FUN_00407ed0(DAT_00767560);
  printf("Sta tmprcd list size: %d\n",uVar1);
  FUN_00408570(DAT_00767560,_wsta_roam_db_print_sta_tmprcd_cb,0);
  FUN_00407f30(l_wsta_roam_data);
  return;
}

