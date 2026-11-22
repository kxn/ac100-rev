// func wsta_roam_db_print_global_stats @ 00483228 size=1

void wsta_roam_db_print_global_stats(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0076755c;
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  printf("%s = %llu\n","smaller_than_500ms",*puVar1,puVar1[1]);
  printf("%s = %llu\n","between_500ms_and_1s",puVar1[2],puVar1[3]);
  printf("%s = %llu\n","between_1s_and_3s",puVar1[4],puVar1[5]);
  printf("%s = %llu\n","larger_than_3s",puVar1[6],puVar1[7]);
  printf("%s = %llu\n","target_match",puVar1[8],puVar1[9]);
  printf("%s = %llu\n","target_mismatch",puVar1[10],puVar1[0xb]);
  printf("%s = %llu\n","_2g_to_5g.smaller_than_0db",puVar1[0xc],puVar1[0xd]);
  printf("%s = %llu\n","_2g_to_5g.between_1_and_4db",puVar1[0xe],puVar1[0xf]);
  printf("%s = %llu\n","_2g_to_5g.larger_than_4db",puVar1[0x10],puVar1[0x11]);
  printf("%s = %llu\n","_5g_to_2g.smaller_than_0db",puVar1[0x12],puVar1[0x13]);
  printf("%s = %llu\n","_5g_to_2g.between_1_and_4db",puVar1[0x14],puVar1[0x15]);
  printf("%s = %llu\n","_5g_to_2g.larger_than_4db",puVar1[0x16],puVar1[0x17]);
  printf("%s = %llu\n","same_freq.smaller_than_0db",puVar1[0x18],puVar1[0x19]);
  printf("%s = %llu\n","same_freq.between_1_and_4db",puVar1[0x1a],puVar1[0x1b]);
  printf("%s = %llu\n","same_freq.larger_than_4db",puVar1[0x1c],puVar1[0x1d]);
  uac_mutex_give(l_wsta_roam_data);
  return;
}

