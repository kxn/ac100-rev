// func _mdUpdate @ 00660fa0 size=336

void _mdUpdate(int param_1,void *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint __n;
  
  uVar2 = (uint)(*(int *)(param_1 + 0x10) << 0x17) >> 0x1a;
  uVar1 = param_3 * 8 + *(int *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x10) = uVar1;
  if (uVar1 < param_3 * 8) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  __n = 0x40 - uVar2;
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar1 = 0;
  if (__n <= param_3) {
    memcpy((void *)(param_1 + uVar2 + 0x18),param_2,__n);
    if (param_4 == 4) {
      _md4Transform(param_1,param_1 + 0x18);
      for (uVar1 = __n; uVar1 + 0x3f < param_3; uVar1 = uVar1 + 0x40) {
        _md4Transform(param_1,(int)param_2 + uVar1);
      }
      uVar2 = 0;
    }
    else if (param_4 == 5) {
      _md5Transform(param_1,param_1 + 0x18);
      for (; __n + 0x3f < param_3; __n = __n + 0x40) {
        _md5Transform(param_1,(int)param_2 + __n);
      }
      uVar2 = 0;
      uVar1 = __n;
    }
    else {
      uVar2 = 0;
      uVar1 = uVar2;
    }
  }
  memcpy((void *)(param_1 + uVar2 + 0x18),(void *)((int)param_2 + uVar1),param_3 - uVar1);
  return;
}

