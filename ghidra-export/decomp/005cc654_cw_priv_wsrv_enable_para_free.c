// func cw_priv_wsrv_enable_para_free @ 005cc654 size=188

undefined4 cw_priv_wsrv_enable_para_free(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 0) {
    return 0;
  }
  if (*(int *)(iVar5 + 10) == 0) {
    iVar3 = *(int *)(iVar5 + 0x10);
  }
  else {
    FUN_00407df0();
    iVar3 = *(int *)(iVar5 + 0x10);
  }
  if (iVar3 == 0) goto LAB_005cc6c4;
  cVar1 = *(char *)(iVar5 + 0xf);
  if (cVar1 == '\x02') {
    uVar4 = iVar3 + 0x4aU & 3;
    uVar2 = iVar3 + 0x4dU & 3;
    uVar4 = (*(int *)((iVar3 + 0x4aU) - uVar4) << uVar4 * 8 | 0xffffffffU >> (4 - uVar4) * 8 & 2) &
            -1 << (uVar2 + 1) * 8 | *(uint *)((iVar3 + 0x4dU) - uVar2) >> (3 - uVar2) * 8;
LAB_005cc6f0:
    if (uVar4 == 0) {
      uVar4 = iVar5 + 0x10U & 3;
      iVar3 = *(int *)((iVar5 + 0x10U) - uVar4) << uVar4 * 8;
    }
    else {
      FUN_00407df0();
      iVar3 = *(int *)(iVar5 + 0x10);
    }
  }
  else {
    if (cVar1 == '\x04') {
      uVar4 = *(uint *)(iVar3 + 8);
      goto LAB_005cc6f0;
    }
    if (cVar1 == '\x01') {
      uVar4 = iVar3 + 8U & 3;
      uVar4 = *(int *)((iVar3 + 8U) - uVar4) << uVar4 * 8 | 0xffffffffU >> (4 - uVar4) * 8 & 1;
      goto LAB_005cc6f0;
    }
    iVar3 = *(int *)(iVar5 + 0x10);
  }
  FUN_00407df0(iVar3);
LAB_005cc6c4:
  FUN_00407df0(iVar5);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}

