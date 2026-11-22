// func apdb_id_valid @ 00608920 size=104

bool apdb_id_valid(undefined4 param_1)

{
  int iVar1;
  
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  iVar1 = _apdb_ap_item_get_index_by_id(param_1);
  if (iVar1 == -1) {
    FUN_00407f30(l_apdb_mutex);
  }
  else {
    FUN_00407f30(l_apdb_mutex);
  }
  return iVar1 != -1;
}

