// func rb_insert_color @ 0051f168 size=440

void rb_insert_color(uint *param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  code *pcVar6;
  
LAB_0051f1bc:
  uVar2 = *param_1;
  do {
    puVar3 = (uint *)(uVar2 & 0xfffffffc);
    if (puVar3 == (uint *)0x0) {
      puVar3 = (uint *)*param_2;
LAB_0051f2b4:
      *puVar3 = *puVar3 | 1;
      return;
    }
    if ((*puVar3 & 1) != 0) {
      puVar3 = (uint *)*param_2;
      goto LAB_0051f2b4;
    }
    puVar5 = (uint *)(*puVar3 & 0xfffffffc);
    puVar1 = (uint *)puVar5[2];
    if (puVar3 == puVar1) {
      puVar1 = (uint *)puVar5[1];
      if (puVar1 == (uint *)0x0) {
        puVar1 = (uint *)puVar3[1];
      }
      else {
        uVar2 = *puVar1;
        if ((uVar2 & 1) == 0) break;
        puVar1 = (uint *)puVar3[1];
      }
      puVar4 = puVar3;
      if (puVar1 == param_1) {
        __rb_rotate_left(puVar3,param_2);
        puVar4 = puVar1;
        param_1 = puVar3;
      }
      pcVar6 = __rb_rotate_right;
      *puVar4 = *puVar4 | 1;
      *puVar5 = *puVar5 & 0xfffffffe;
    }
    else {
      if (puVar1 == (uint *)0x0) {
        puVar1 = (uint *)puVar3[2];
      }
      else {
        uVar2 = *puVar1;
        if ((uVar2 & 1) == 0) break;
        puVar1 = (uint *)puVar3[2];
      }
      puVar4 = puVar3;
      if (puVar1 == param_1) {
        __rb_rotate_right(puVar3,param_2);
        puVar4 = puVar1;
        param_1 = puVar3;
      }
      pcVar6 = __rb_rotate_left;
      *puVar4 = *puVar4 | 1;
      *puVar5 = *puVar5 & 0xfffffffe;
    }
    (*pcVar6)(puVar5,param_2);
    uVar2 = *param_1;
  } while( true );
  *puVar1 = uVar2 | 1;
  *puVar3 = *puVar3 | 1;
  *puVar5 = *puVar5 & 0xfffffffe;
  param_1 = puVar5;
  goto LAB_0051f1bc;
}

