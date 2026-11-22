// func wserv_db_entry_set_ignp_query_switch @ 005ed3c4 size=1

undefined4 wserv_db_entry_set_ignp_query_switch(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_007cbefc + param_1 * 0x21c;
  if (*(int *)(iVar1 + 0xc) == 0) {
    uVar2 = 0xffffffff;
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> wserv(id=%d) is null\r\n",
             "wserv_db_entry_set_ignp_query_switch",0xa80,param_1);
    }
  }
  else {
    *(undefined1 *)(iVar1 + 0x214) = param_2;
    uVar2 = 0;
  }
  return uVar2;
}

