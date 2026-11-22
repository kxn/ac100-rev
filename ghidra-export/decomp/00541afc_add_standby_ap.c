// func add_standby_ap @ 00541afc size=284

undefined4 add_standby_ap(int param_1)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(apmngr_standby_list_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(g_apmngr_standby_hash,(void *)(param_1 + 0x48));
    if (iVar1 == 0) {
      __s = (void *)FUN_00408450(0x10,0x10e0);
      if (__s == (void *)0x0) {
        FUN_00407f30(apmngr_standby_list_mutex);
        return 0xffffffff;
      }
      memset(__s,0,0x10);
      memcpy(__s,(void *)(param_1 + 0x48),6);
      *(undefined2 *)((int)__s + 6) = *(undefined2 *)(param_1 + 0x10);
      uVar3 = FUN_00407e70();
      uVar2 = g_apmngr_standby_hash;
      *(undefined8 *)((int)__s + 8) = uVar3;
      FUN_00408380(uVar2,__s);
      FUN_004084b0(apmngr_standby_list_cond);
    }
    else {
      uVar3 = FUN_00407e70();
      *(undefined8 *)(iVar1 + 8) = uVar3;
      *(undefined2 *)(iVar1 + 6) = *(undefined2 *)(param_1 + 0x10);
    }
    uVar2 = 0;
    FUN_00407f30(apmngr_standby_list_mutex);
  }
  return uVar2;
}

