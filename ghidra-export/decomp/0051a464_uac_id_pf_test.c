// func uac_id_pf_test @ 0051a464 size=380

void uac_id_pf_test(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (param_1 < 1) {
    param_1 = 100000;
  }
  iVar1 = uac_id_new(param_1);
  if (iVar1 != 0) {
    iVar2 = 0;
    uVar4 = uac_time_usecs();
    do {
      iVar2 = iVar2 + 1;
      uac_id_alloc(iVar1);
    } while (iVar2 < param_1);
    uVar5 = uac_time_usecs();
    printf("Alloc %d times cost: %llu us\n",param_1,
           ((int)((ulonglong)uVar5 >> 0x20) - (int)((ulonglong)uVar4 >> 0x20)) -
           (uint)((uint)uVar5 < (uint)uVar5 - (int)uVar4));
    uVar4 = uac_time_usecs();
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      uac_id_free(iVar1,iVar2);
      iVar2 = iVar3;
    } while (iVar3 < param_1);
    uVar5 = uac_time_usecs();
    printf("Free %d times cost: %llu us\n",param_1,
           ((int)((ulonglong)uVar5 >> 0x20) - (int)((ulonglong)uVar4 >> 0x20)) -
           (uint)((uint)uVar5 < (uint)uVar5 - (int)uVar4));
    uac_id_destroy(iVar1);
    return;
  }
  return;
}

