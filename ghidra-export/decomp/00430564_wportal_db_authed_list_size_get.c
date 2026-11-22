// func wportal_db_authed_list_size_get @ 00430564 size=80

undefined4 wportal_db_authed_list_size_get(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  uVar1 = FUN_00407fe0(aut_list);
  FUN_00407f30(wportal_aut_mutex);
  return uVar1;
}

