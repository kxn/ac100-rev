// func wserv_db_ip_checksum_calc @ 005eec9c size=288

undefined4 wserv_db_ip_checksum_calc(undefined2 param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_ip_checksum_calc begin\r\n",
           "wserv_db_ip_checksum_calc",0xd3f);
  }
  iVar1 = apmngr_db_capacity_support(param_1,1,0x2b);
  iVar2 = 0;
  if (iVar1 != 0) {
    do {
      if (*(char *)(DAT_007cbf14 + iVar2) != '\0') {
        (*param_2)(param_3,(char *)(DAT_007cbf14 + iVar2) + 4,0x1c);
      }
      iVar2 = iVar2 + 0x20;
    } while (iVar2 != 0x400);
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> wserv_db_ip_checksum_calc end\r\n",
             "wserv_db_ip_checksum_calc",0xd51);
    }
  }
  return 0;
}

