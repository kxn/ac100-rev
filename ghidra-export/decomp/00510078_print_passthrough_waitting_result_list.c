// func print_passthrough_waitting_result_list @ 00510078 size=1

undefined4 print_passthrough_waitting_result_list(void)

{
  int iVar1;
  int iVar2;
  
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_wairting_result_list_ock\n",
           "print_passthrough_waitting_result_list",0x9ba);
  }
  pthread_mutex_lock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
  iVar1 = FUN_004081b0(&g_ac_passthrough_waitting_result_list);
  while (iVar1 != 0) {
    puts("\r");
    iVar2 = FUN_00408680(iVar1);
    printf("\t\tid:%d time:%d \r\n",*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
    iVar1 = iVar2;
  }
  puts("\r");
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_wairting_result_list_ock\n",
           "print_passthrough_waitting_result_list",0x9c6);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
  return 0;
}

