// func _sensor_test_build_bssid_alloc_list @ 004f80f0 size=408

void * _sensor_test_build_bssid_alloc_list(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  void *__s;
  int iVar2;
  void *__dest;
  void *pvVar3;
  int iVar4;
  
  pvVar3 = (void *)0x0;
  __s = pvVar3;
  if ((((param_2 != 0) && (param_3 != (int *)0x0)) && (0 < *(int *)(param_2 + 4))) &&
     ((__s = (void *)0x0, *(int *)(param_2 + 8) != 0 && (*(int *)(param_2 + 0xc) != 0)))) {
    iVar1 = FUN_00407ed0();
    *param_3 = iVar1;
    __s = pvVar3;
    if (0 < iVar1) {
      __s = (void *)FUN_00408450(iVar1 * 0x24,0x781);
      if (__s == (void *)0x0) {
        if (sensor_test_err_switch == '\0') {
          *param_3 = 0;
        }
        else {
          printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
                 "_sensor_test_build_bssid_alloc_list",0x784);
          *param_3 = 0;
        }
      }
      else {
        iVar1 = 0;
        memset(__s,0,*param_3 * 0x24);
        for (iVar4 = 0; iVar4 < *(int *)(param_2 + 4); iVar4 = iVar4 + 1) {
          for (pvVar3 = (void *)FUN_004081b0(*(int *)(param_2 + 8) + iVar4 * 0x14 + 8);
              pvVar3 != (void *)0x0; pvVar3 = (void *)FUN_00408680(pvVar3)) {
            iVar2 = iVar1 * 0x24;
            if (iVar1 < *param_3) {
              iVar1 = iVar1 + 1;
              __dest = (void *)((int)__s + iVar2);
              memcpy(__dest,pvVar3,0x24);
              memset(__dest,0,0xc);
            }
          }
        }
      }
    }
  }
  return __s;
}

