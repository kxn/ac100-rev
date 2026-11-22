// func wips_counter_dev_dump @ 004cea90 size=1

void wips_counter_dev_dump(void)

{
  undefined4 uVar1;
  
  puts("==========================");
  uVar1 = wips_local_time_get();
  printf("wips_counter_dev_dump(current_time: %d):\n",uVar1);
  FUN_004082d0(wips_global_mutex,0xffffffff);
  FUN_00408570(g_counter_info_hash,_wips_print_counter_info,0);
  FUN_00407f30(wips_global_mutex);
  (*(code *)PTR_puts_00758f90)("==========================");
  return;
}

