// func _ap_union_hash_add @ 00486064 size=272

uint _ap_union_hash_add(void *param_1,undefined4 param_2,int param_3,uint *param_4,
                       undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_00407fa0(param_2,param_1);
  *param_5 = 0;
  if (iVar1 == 0) {
    if (0x7f < *param_4) {
      return 0xffffffff;
    }
    memcpy((void *)(param_3 + *param_4 * 6),param_1,6);
    iVar1 = FUN_00408380(param_2,param_3 + *param_4 * 6);
    uVar2 = *param_4;
    if (iVar1 != 0) {
      puVar3 = (undefined1 *)(param_3 + uVar2 * 6);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      return 0xffffffff;
    }
    *param_4 = uVar2 + 1;
    *param_5 = 1;
  }
  else {
    uVar2 = (iVar1 - param_3 >> 1) * -0x55555555;
  }
  if (0x7f < uVar2) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

