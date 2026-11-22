// func wportal_db_ssid_rdt_add @ 00432030 size=244

undefined4 wportal_db_ssid_rdt_add(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  void *__dest;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  if ((((param_1 != (void *)0x0) && (-1 < *(int *)((int)param_1 + 0x134))) &&
      (uVar3 = wserv_profile_get_max_wservice(), *(uint *)((int)param_1 + 0x134) < uVar3)) &&
     (__dest = (void *)FUN_004082a0(1,0x16c,0x1881), __dest != (void *)0x0)) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    iVar2 = wportal_wserv_node;
    if (*(int *)(wportal_wserv_node + *(int *)((int)param_1 + 0x134) * 8 + 4) == 0) {
      memcpy(__dest,param_1,0x16c);
      uVar1 = wportal_rdt_mutex;
      uVar4 = 0;
      *(void **)(iVar2 + *(int *)((int)param_1 + 0x134) * 8 + 4) = __dest;
      FUN_00407f30(uVar1);
    }
    else {
      FUN_00407df0();
      FUN_00407f30(wportal_rdt_mutex);
    }
  }
  return uVar4;
}

