// func _sensor_test_temp_alloc_hash_cmp @ 004f4b38 size=140

undefined4 _sensor_test_temp_alloc_hash_cmp(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if ((param_1 == (char *)0x0) || (iVar1 = 0, pcVar3 = param_1, param_2 == 0)) {
    uVar4 = 0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d inputs error.\n","_sensor_test_temp_alloc_hash_cmp",0xe4);
    }
  }
  else {
    do {
      pcVar2 = (char *)(param_2 + iVar1);
      iVar1 = iVar1 + 1;
      if (*pcVar3 != *pcVar2) {
        return 0;
      }
      pcVar3 = param_1 + iVar1;
    } while (iVar1 != 6);
    uVar4 = 1;
  }
  return uVar4;
}

