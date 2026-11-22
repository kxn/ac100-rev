// func apdb_radio_count_by_id @ 00609fec size=260

undefined4 apdb_radio_count_by_id(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_178 [356];
  int local_14;
  
  memset(auStack_178,0,0x168);
  if (param_2 == 0) {
    uVar2 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : the fwid is NULL\n","apdb_radio_count_by_id",0x281f);
    }
  }
  else {
    memset(auStack_178,0,0x168);
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar1 = _apdb_get_ap_by_id(param_1,param_2,auStack_178);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(local_14 + 0x10);
      FUN_00407f30(l_apdb_mutex);
    }
    else {
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : get apdb failed\n","apdb_radio_count_by_id",0x2828);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(l_apdb_mutex);
    }
  }
  return uVar2;
}

