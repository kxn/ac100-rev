// func rb_replace_node @ 0051f950 size=1

void rb_replace_node(uint *param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_1 & 0xfffffffc;
  if (uVar1 == 0) {
    *param_3 = param_2;
  }
  else if (param_1 == *(uint **)(uVar1 + 8)) {
    *(uint **)(uVar1 + 8) = param_2;
  }
  else {
    *(uint **)(uVar1 + 4) = param_2;
  }
  puVar2 = (uint *)param_1[2];
  if (puVar2 == (uint *)0x0) {
    puVar2 = (uint *)param_1[1];
  }
  else {
    *puVar2 = (uint)param_2 | *puVar2 & 3;
    puVar2 = (uint *)param_1[1];
  }
  if (puVar2 == (uint *)0x0) {
    uVar1 = *param_1;
  }
  else {
    *puVar2 = (uint)param_2 | *puVar2 & 3;
    uVar1 = *param_1;
  }
  *param_2 = uVar1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  return;
}

