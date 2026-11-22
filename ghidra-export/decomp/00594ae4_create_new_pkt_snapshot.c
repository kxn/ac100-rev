// func create_new_pkt_snapshot @ 00594ae4 size=336

void * create_new_pkt_snapshot(byte param_1,int param_2)

{
  void *__s;
  void *pvVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  if (param_2 == 0) {
    return (void *)0x0;
  }
  __s = (void *)FUN_00408450(0x60,0x126);
  if (__s == (void *)0x0) {
    return (void *)0x0;
  }
  memset(__s,0,0x60);
  if (snapshot_store_debug_switch != 0) {
    printf("[SNAPSHOT_STORE_DEBUG]%s()/%d pkt_type %d\n","create_new_pkt_snapshot",0x12e,uVar2);
  }
  if ((uVar2 - 1 < 2) || (uVar2 == 5)) {
    pvVar1 = (void *)FUN_00408450(0x10,0x132);
    if (pvVar1 != (void *)0x0) {
      memset(pvVar1,0,0x10);
      *(void **)((int)__s + 0x54) = pvVar1;
      goto LAB_00594bbc;
    }
  }
  else if ((uVar2 - 3 < 2) && (pvVar1 = (void *)FUN_00408450(0xc,0x13c), pvVar1 != (void *)0x0)) {
    memset(pvVar1,0,0xc);
    *(void **)((int)__s + 0x58) = pvVar1;
LAB_00594bbc:
    FUN_0051ad88((int)__s + 0x3c);
    FUN_0051ad88((int)__s + 0x48);
    *(byte *)((int)__s + 0x38) = param_1;
    FUN_004086b0(param_2 + 0x94,__s);
    check_snapshot_list(param_2);
    return __s;
  }
  FUN_00407df0(__s);
  return (void *)0x0;
}

