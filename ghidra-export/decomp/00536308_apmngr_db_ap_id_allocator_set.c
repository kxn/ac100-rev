// func apmngr_db_ap_id_allocator_set @ 00536308 size=92

undefined4 apmngr_db_ap_id_allocator_set(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    FUN_00408070(g_apmngr_ap_id_allocator,param_1);
    FUN_00407f30(apmngr_db_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

