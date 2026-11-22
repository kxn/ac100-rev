// func apmngr_db_template_id_allocator_get @ 00536410 size=80

undefined4 apmngr_db_template_id_allocator_get(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  uVar1 = FUN_004082f0(g_apmngr_template_id_allocator);
  FUN_00407f30(apmngr_db_mutex);
  return uVar1;
}

