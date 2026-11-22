// func uac_sqlite_dbg_switch_enable @ 00521b90 size=1

void uac_sqlite_dbg_switch_enable(void)

{
  int in_t9;
  
  **(undefined4 **)(in_t9 + 0x23790c) = 1;
  return;
}

