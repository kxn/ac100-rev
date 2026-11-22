// func _wips_get_timeout_counter_wips @ 004c5e68 size=272

void _wips_get_timeout_counter_wips(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  void *__src;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_2;
  iVar3 = param_2[1];
  iVar1 = wips_local_time_get();
  if (600 < iVar1 - *(int *)(param_1 + 0x2c)) {
    for (iVar1 = FUN_004081b0(param_1 + 8); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      __src = *(void **)(g_wips_id2entry + *(int *)(iVar1 + 0xc) * 4);
      iVar2 = iVar3 * 0xb0;
      if (__src == (void *)0x0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d wips[id=%d] not found\n","_wips_get_timeout_counter_wips",
                 0xd22);
        }
      }
      else {
        iVar3 = iVar3 + 1;
        memcpy((void *)(iVar4 + iVar2),__src,0xb0);
      }
    }
  }
  param_2[1] = iVar3;
  return;
}

