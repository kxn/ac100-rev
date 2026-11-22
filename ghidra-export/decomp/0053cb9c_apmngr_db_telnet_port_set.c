// func apmngr_db_telnet_port_set @ 0053cb9c size=76

undefined4 apmngr_db_telnet_port_set(undefined2 param_1)

{
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  g_apmngr_telnet_port = param_1;
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

