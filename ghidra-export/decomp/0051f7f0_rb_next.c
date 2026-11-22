// func rb_next @ 0051f7f0 size=104

uint * rb_next(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar1 = (uint *)0x0;
  if (param_1 != (uint *)(*param_1 & 0xfffffffc)) {
    puVar1 = (uint *)param_1[1];
    if (puVar1 == (uint *)0x0) {
      uVar3 = *param_1;
      while( true ) {
        puVar1 = (uint *)(uVar3 & 0xfffffffc);
        if (puVar1 == (uint *)0x0) break;
        if (param_1 != (uint *)puVar1[1]) {
          return puVar1;
        }
        uVar3 = *puVar1;
        param_1 = puVar1;
      }
    }
    else {
      for (puVar2 = (uint *)puVar1[2]; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[2]) {
        puVar1 = puVar2;
      }
    }
  }
  return puVar1;
}

