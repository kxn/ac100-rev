// func print_standby_ap_list @ 00541c18 size=1

void print_standby_ap_list(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(apmngr_standby_list_mutex,0xffffffff);
  uVar1 = FUN_00407ed0(g_apmngr_standby_hash);
  printf("standby ap size: %d \r\n",uVar1);
  FUN_00408570(g_apmngr_standby_hash,print_standby_ap_list_node,0);
  uac_mutex_give(apmngr_standby_list_mutex);
  return;
}

