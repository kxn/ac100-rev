// func __rb_rotate_left @ 0051efe0 size=116

void __rb_rotate_left(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)param_1[1];
  uVar2 = *param_1 & 0xfffffffc;
  uVar3 = puVar1[2];
  param_1[1] = uVar3;
  if (uVar3 != 0) {
    *(uint *)puVar1[2] = (uint)param_1 | *(uint *)puVar1[2] & 3;
  }
  puVar1[2] = (uint)param_1;
  *puVar1 = *puVar1 & 3 | uVar2;
  if (uVar2 == 0) {
    *param_2 = (uint)puVar1;
  }
  else if (param_1 == *(uint **)(uVar2 + 8)) {
    *(uint **)(uVar2 + 8) = puVar1;
  }
  else {
    *(uint **)(uVar2 + 4) = puVar1;
  }
  *param_1 = (uint)puVar1 | *param_1 & 3;
  return;
}

