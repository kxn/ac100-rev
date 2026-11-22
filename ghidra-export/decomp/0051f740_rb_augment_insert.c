// func rb_augment_insert @ 0051f740 size=1

void rb_augment_insert(uint *param_1,code *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar3 = (uint *)param_1[2];
  if (((uint *)param_1[2] == (uint *)0x0) && (puVar3 = param_1, (uint *)param_1[1] != (uint *)0x0))
  {
    puVar3 = (uint *)param_1[1];
  }
  while( true ) {
    (*param_2)(puVar3,param_3);
    puVar4 = (uint *)(*puVar3 & 0xfffffffc);
    if (puVar4 == (uint *)0x0) break;
    puVar1 = (uint *)puVar4[2];
    if (((puVar3 == puVar1) && (puVar2 = (uint *)puVar4[1], (uint *)puVar4[1] != (uint *)0x0)) ||
       (puVar2 = puVar1, puVar3 = puVar4, puVar1 != (uint *)0x0)) {
      (*param_2)(puVar2,param_3);
      puVar3 = puVar4;
    }
  }
  return;
}

