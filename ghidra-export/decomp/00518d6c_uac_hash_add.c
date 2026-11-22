// func uac_hash_add @ 00518d6c size=344

int uac_hash_add(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar1 = -1;
  if (((param_1 != (undefined4 *)0x0) && (param_2 != 0)) && (uVar2 = param_1[5], uVar2 != 0)) {
    if (param_1[6] == 1) {
      if (uVar2 == 0) {
        trap(7);
      }
      if ((uint)((param_1[4] + 1) * 100) / uVar2 < 0x65) {
        pcVar4 = (code *)*param_1;
      }
      else {
        iVar1 = uac_hash_resize(param_1,1);
        if (iVar1 != 0) {
          return iVar1;
        }
        pcVar4 = (code *)*param_1;
      }
    }
    else {
      pcVar4 = (code *)*param_1;
    }
    uVar2 = (*pcVar4)(param_2);
    if (param_1[5] == 0) {
      trap(7);
    }
    pcVar4 = uac_list_first;
    iVar3 = (uVar2 % (uint)param_1[5]) * 0xc;
    iVar1 = param_1[7] + iVar3;
    do {
      iVar1 = (*pcVar4)(iVar1);
      if (iVar1 == 0) {
        iVar1 = uac_mem_malloc_my(0x10,300);
        if (iVar1 == 0) {
          return -2;
        }
        *(int *)(iVar1 + 0xc) = param_2;
        uac_list_insert_last(param_1[7] + iVar3);
        param_1[4] = param_1[4] + 1;
        return 0;
      }
      pcVar4 = uac_list_next;
    } while (param_2 != *(int *)(iVar1 + 0xc));
    iVar1 = -4;
  }
  return iVar1;
}

