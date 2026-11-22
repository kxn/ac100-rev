// func get_svr_addr_by_id @ 00460034 size=120

int get_svr_addr_by_id(undefined4 param_1,undefined1 *param_2,void *param_3)

{
  int iVar1;
  undefined1 auStack_c0 [155];
  undefined1 local_25;
  undefined1 auStack_24 [20];
  
  memset(auStack_c0,0,0xac);
  iVar1 = dhcpdef_db_svr_entry_get(param_1,auStack_c0);
  if (iVar1 == 0) {
    memcpy(param_3,auStack_24,0x10);
    *param_2 = local_25;
  }
  return iVar1;
}

