// func remove_standby_ap @ 00541c80 size=140

undefined4 remove_standby_ap(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(apmngr_standby_list_mutex,0xffffffff);
    iVar2 = FUN_00407fa0(g_apmngr_standby_hash,param_1);
    if (iVar2 != 0) {
      FUN_00407f40(g_apmngr_standby_hash,iVar2);
      FUN_00407df0(iVar2);
    }
    FUN_00407f30(apmngr_standby_list_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

