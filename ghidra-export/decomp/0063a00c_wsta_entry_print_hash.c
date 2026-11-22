// func wsta_entry_print_hash @ 0063a00c size=1

void wsta_entry_print_hash(undefined4 param_1,undefined4 param_2)

{
  puts("\n");
  puts("################################################################");
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  func_0x004086d0(DAT_007cc6cc,param_1,param_2,wsta_db_print_entry,0);
  printf("wsta hash elem = %d\n",*(undefined4 *)(DAT_007cc6cc + 0x10));
  uac_mutex_give(DAT_007cc6bc);
  return;
}

