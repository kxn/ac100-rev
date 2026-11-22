// func rb_augment_erase_begin @ 0051f858 size=144

uint * rb_augment_erase_begin(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)param_1[2];
  if ((uint *)param_1[1] == (uint *)0x0) {
    puVar1 = puVar2;
    if (puVar2 == (uint *)0x0) {
      puVar1 = (uint *)(*param_1 & 0xfffffffc);
    }
  }
  else {
    puVar1 = (uint *)param_1[1];
    if ((((puVar2 != (uint *)0x0) &&
         (puVar2 = (uint *)rb_next(), puVar1 = puVar2, puVar2 != (uint *)0x0)) &&
        (puVar1 = (uint *)puVar2[1], (uint *)puVar2[1] == (uint *)0x0)) &&
       (puVar1 = puVar2, param_1 != (uint *)(*puVar2 & 0xfffffffc))) {
      puVar1 = (uint *)(*puVar2 & 0xfffffffc);
    }
  }
  return puVar1;
}

