// func apupd_db_system_time_change_confirm @ 00658028 size=336

undefined4 apupd_db_system_time_change_confirm(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_004081b0(apupd_model_list);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x140);
    while( true ) {
      if (iVar2 == 1) {
        if (*(int *)(iVar1 + 0x13c) == -1) {
          if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: some error occured.\r\n",
                   "apupd_db_system_time_change_confirm",0x2661);
          }
        }
        else {
          FUN_00408060();
          *(undefined4 *)(iVar1 + 0x13c) = 0xffffffff;
        }
        iVar2 = apupd_model_entry_timer_add(iVar1);
        if (((iVar2 == -1) && (g_apupd_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: add timer failed.\r\n",
                 "apupd_db_system_time_change_confirm",0x2666);
        }
      }
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      iVar2 = *(int *)(iVar1 + 0x140);
    }
  }
  FUN_00407f30(apupd_db_mutex);
  return 0;
}

