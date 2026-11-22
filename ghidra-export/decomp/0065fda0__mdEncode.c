// func _mdEncode @ 0065fda0 size=72

void _mdEncode(undefined1 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 4) {
    *param_1 = (char)*param_2;
    param_1[1] = (char)((uint)*param_2 >> 8);
    param_1[2] = (char)*(undefined2 *)param_2;
    uVar1 = *(undefined1 *)param_2;
    param_2 = param_2 + 1;
    param_1[3] = uVar1;
    param_1 = param_1 + 4;
  }
  return;
}

