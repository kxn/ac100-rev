// func stats_db_print_sta_all @ 0067177c size=104

void stats_db_print_sta_all(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_stats_data,0xffffffff);
  uVar1 = FUN_00407ed0(DAT_007cc8e0);
  printf("Sta list size: %d\n",uVar1);
  FUN_00408570(DAT_007cc8e0,_stats_db_print_sta_cb,0);
  FUN_00407f30(l_stats_data);
  return;
}

