// func rb_augment_erase_end @ 0051f774 size=1

void rb_augment_erase_end(uint *param_1,code *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (param_1 != (uint *)0x0) {
    while( true ) {
      (*param_2)(param_1,param_3);
      puVar3 = (uint *)(*param_1 & 0xfffffffc);
      if (puVar3 == (uint *)0x0) break;
      puVar1 = (uint *)puVar3[2];
      if (((param_1 == puVar1) && (puVar2 = (uint *)puVar3[1], (uint *)puVar3[1] != (uint *)0x0)) ||
         (puVar2 = puVar1, param_1 = puVar3, puVar1 != (uint *)0x0)) {
        (*param_2)(puVar2,param_3);
        param_1 = puVar3;
      }
    }
    return;
  }
  return;
}

