// func rb_prev @ 0051f8e8 size=1

uint * rb_prev(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar1 = (uint *)0x0;
  if (param_1 != (uint *)(*param_1 & 0xfffffffc)) {
    puVar1 = (uint *)param_1[2];
    if (puVar1 == (uint *)0x0) {
      uVar2 = *param_1;
      while (puVar3 = (uint *)(uVar2 & 0xfffffffc), puVar3 != (uint *)0x0) {
        if (param_1 != (uint *)puVar3[2]) {
          return puVar3;
        }
        param_1 = puVar3;
        uVar2 = *puVar3;
      }
    }
    else {
      for (puVar3 = (uint *)puVar1[1]; puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[1]) {
        puVar1 = puVar3;
      }
    }
  }
  return puVar1;
}

