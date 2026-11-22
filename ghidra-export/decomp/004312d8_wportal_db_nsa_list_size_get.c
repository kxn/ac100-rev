// func wportal_db_nsa_list_size_get @ 004312d8 size=80

undefined4 wportal_db_nsa_list_size_get(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  uVar1 = FUN_00407fe0(nsa_list);
  FUN_00407f30(wportal_nsa_mutex);
  return uVar1;
}

