// func apmngr_global_config_show @ 00531fa4 size=520

void apmngr_global_config_show(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [68];
  
  puts("=====apmngr global settings=====");
  if (g_apmngr_status == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("global status: %s\n",pcVar1 + 4);
  if (g_apmngr_auto_reboot == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("auto reboot : %s\n",pcVar1 + 4);
  uVar2 = apmngr_db_date_str(g_apmngr_reboot_date);
  printf("\treboot date : %s\n",uVar2);
  printf("\treboot time : %.2d:%.2d:%.2d\n",(uint)g_apmngr_reboot_time._0_1_,
         (uint)(byte)g_apmngr_reboot_time,(uint)DAT_007c582e);
  if (g_apmngr_auto_firm == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("auto firm : %s\n",pcVar1 + 4);
  puts("================================");
  puts("=====aplog settings=====");
  if (g_apmngr_ac_log_switch == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("ac log switch : %s\n",pcVar1 + 4);
  printf("\tac log level : %d\n",g_apmngr_ac_log_level);
  if (g_apmngr_remote_server_switch == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("remote server switch : %s\n",pcVar1 + 4);
  printf("\tremote log level : %d\n",g_apmngr_remote_log_level);
  printf("\tremote report interval : %d\n",g_apmngr_remote_report_interval);
  memset(auStack_50,0,0x40);
  FUN_00408190(g_apmngr_remote_server,DAT_007c5840,DAT_007c5844,DAT_007c5848,DAT_007c584c,auStack_50
               ,0x40,"---");
  printf("\tremote server : %s\n",auStack_50);
  puts("================================");
  return;
}

