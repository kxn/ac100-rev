// func uac_hash_add_unexamined @ 005196a0 size=300

int uac_hash_add_unexamined(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  
  iVar1 = -1;
  if (((param_1 != (undefined4 *)0x0) && (param_2 != 0)) && (uVar3 = param_1[5], uVar3 != 0)) {
    if (param_1[6] == 1) {
      if (uVar3 == 0) {
        trap(7);
      }
      if ((uint)((param_1[4] + 1) * 100) / uVar3 < 0x65) {
        pcVar5 = (code *)*param_1;
      }
      else {
        iVar1 = uac_hash_resize(param_1,1);
        if (iVar1 != 0) {
          return iVar1;
        }
        pcVar5 = (code *)*param_1;
      }
    }
    else {
      pcVar5 = (code *)*param_1;
    }
    uVar3 = (*pcVar5)(param_2);
    uVar4 = param_1[5];
    iVar2 = uac_mem_malloc_my(0x10,0x290);
    iVar1 = -2;
    if (iVar2 != 0) {
      if (uVar4 == 0) {
        trap(7);
      }
      *(int *)(iVar2 + 0xc) = param_2;
      uac_list_insert_last(param_1[7] + (uVar3 % uVar4) * 0xc);
      param_1[4] = param_1[4] + 1;
      iVar1 = 0;
    }
  }
  return iVar1;
}

