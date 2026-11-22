// func __rb_rotate_right @ 0051f054 size=116

void __rb_rotate_right(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)param_1[2];
  uVar2 = *param_1 & 0xfffffffc;
  uVar3 = puVar1[1];
  param_1[2] = uVar3;
  if (uVar3 != 0) {
    *(uint *)puVar1[1] = (uint)param_1 | *(uint *)puVar1[1] & 3;
  }
  puVar1[1] = (uint)param_1;
  *puVar1 = *puVar1 & 3 | uVar2;
  if (uVar2 == 0) {
    *param_2 = (uint)puVar1;
  }
  else if (param_1 == *(uint **)(uVar2 + 4)) {
    *(uint **)(uVar2 + 4) = puVar1;
  }
  else {
    *(uint **)(uVar2 + 8) = puVar1;
  }
  *param_1 = (uint)puVar1 | *param_1 & 3;
  return;
}

