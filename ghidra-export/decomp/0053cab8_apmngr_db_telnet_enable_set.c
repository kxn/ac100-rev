// func apmngr_db_telnet_enable_set @ 0053cab8 size=76

undefined4 apmngr_db_telnet_enable_set(undefined4 param_1)

{
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  g_apmngr_telnet_enable = param_1;
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

