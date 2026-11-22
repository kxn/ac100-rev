// func apdb_support_new_ap_trunk_by_id @ 00609ae4 size=260

bool apdb_support_new_ap_trunk_by_id(undefined4 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_178 [356];
  int local_14;
  
  memset(auStack_178,0,0x168);
  if (param_2 == 0) {
    bVar2 = false;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : the fwid is NULL\n","apdb_support_new_ap_trunk_by_id",
             0x275e);
    }
  }
  else {
    memset(auStack_178,0,0x168);
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar1 = _apdb_get_ap_by_id(param_1,param_2,auStack_178);
    if (iVar1 == 0) {
      bVar2 = *(int *)(local_14 + 0x2c) != 0;
      FUN_00407f30(l_apdb_mutex);
    }
    else {
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : get apdb failed\n","apdb_support_new_ap_trunk_by_id",
               0x2766);
      }
      bVar2 = false;
      FUN_00407f30(l_apdb_mutex);
    }
  }
  return bVar2;
}

