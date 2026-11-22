// func _sensor_test_temp_alloc_hash_cb @ 004eb5a0 size=344

void _sensor_test_temp_alloc_hash_cb(int param_1,int *param_2)

{
  byte bVar1;
  void *__src;
  int iVar2;
  int iVar3;
  int iVar4;
  void *__src_00;
  undefined4 local_30 [3];
  
  local_30[0] = 0;
  if (((param_1 != 0) && (param_2 != (int *)0x0)) && (param_2[2] < param_2[1])) {
    *(int *)(*param_2 + param_2[2] * 4) = param_1;
    if (*(byte *)(param_1 + 7) < 6) {
      bVar1 = *(byte *)(param_1 + 7);
    }
    else {
      *(undefined1 *)(param_1 + 7) = 5;
      bVar1 = *(byte *)(param_1 + 7);
    }
    iVar4 = 0;
    if (1 < bVar1) {
      for (; iVar3 = 0, iVar2 = param_1, iVar4 < (int)(*(byte *)(param_1 + 7) - 1);
          iVar4 = iVar4 + 1) {
        while (iVar3 < (int)(((uint)*(byte *)(param_1 + 7) - iVar4) + -1)) {
          iVar3 = iVar3 + 1;
          if (*(char *)(iVar2 + 10) < *(char *)(iVar2 + 0xe)) {
            __src_00 = (void *)(param_1 + 8 + (iVar2 - param_1));
            __src = (void *)(param_1 + 8 + iVar3 * 4);
            memcpy(local_30,__src_00,4);
            memcpy(__src_00,__src,4);
            memcpy(__src,local_30,4);
            iVar2 = iVar2 + 4;
          }
          else {
            iVar2 = iVar2 + 4;
          }
        }
      }
    }
    param_2[2] = param_2[2] + 1;
  }
  return;
}

