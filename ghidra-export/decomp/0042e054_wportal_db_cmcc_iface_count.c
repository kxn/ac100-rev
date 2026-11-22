// func wportal_db_cmcc_iface_count @ 0042e054 size=72

undefined4 wportal_db_cmcc_iface_count(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  uVar1 = cmcc_iface_list_count;
  FUN_00407f30(wportal_rdt_mutex);
  return uVar1;
}

