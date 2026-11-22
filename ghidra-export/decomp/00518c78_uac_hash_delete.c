// func uac_hash_delete @ 00518c78 size=244

void uac_hash_delete(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0x14); uVar2 = uVar2 + 1) {
      iVar1 = *(int *)(param_1 + 0x1c);
      while (iVar1 = uac_list_first(iVar1 + uVar2 * 0xc), iVar1 != 0) {
        uac_list_remove(iVar1);
        uac_mem_free_my(iVar1);
        iVar1 = *(int *)(param_1 + 0x1c);
      }
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    uac_mem_free_my(*(undefined4 *)(param_1 + 0x1c));
    uac_mem_free_my(param_1);
    return;
  }
  return;
}

