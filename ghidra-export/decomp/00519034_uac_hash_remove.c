// func uac_hash_remove @ 00519034 size=316

undefined4 uac_hash_remove(undefined4 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  uVar3 = 0xffffffff;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = (*(code *)*param_1)(param_2);
    if (param_1[5] == 0) {
      trap(7);
    }
    pcVar4 = uac_list_first;
    iVar2 = param_1[7] + (uVar1 % (uint)param_1[5]) * 0xc;
    while (iVar2 = (*pcVar4)(iVar2), iVar2 != 0) {
      if (*(int *)(iVar2 + 0xc) == param_2) {
        uac_list_remove();
        uac_mem_free_my(iVar2);
        iVar2 = param_1[4];
        param_1[4] = iVar2 + -1;
        if (param_1[6] != 1) {
          return 0;
        }
        uVar1 = param_1[5];
        if (uVar1 < 0x1e) {
          return 0;
        }
        if (uVar1 == 0) {
          trap(7);
        }
        if (9 < (uint)((iVar2 + -1) * 100) / uVar1) {
          return 0;
        }
        uac_hash_resize(param_1,0);
        return 0;
      }
      pcVar4 = uac_list_next;
    }
    uVar3 = 0xfffffffb;
  }
  return uVar3;
}

