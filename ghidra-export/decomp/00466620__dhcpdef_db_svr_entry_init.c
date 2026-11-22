// func _dhcpdef_db_svr_entry_init @ 00466620 size=92

undefined4 _dhcpdef_db_svr_entry_init(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  memset(param_1 + 1,0,0x97);
  *(undefined1 *)((int)param_1 + 0x9b) = 0xff;
  memset(param_1 + 0x27,0,0x10);
  return 0;
}

