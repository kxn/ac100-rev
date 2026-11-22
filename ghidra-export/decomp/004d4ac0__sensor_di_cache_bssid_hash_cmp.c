// func _sensor_di_cache_bssid_hash_cmp @ 004d4ac0 size=140

undefined4 _sensor_di_cache_bssid_hash_cmp(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_1 == 0) || (iVar1 = 0, iVar3 = param_1, param_2 == 0)) {
    uVar4 = 0;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_cache_bssid_hash_cmp",0x17b
            );
    }
  }
  else {
    do {
      pcVar2 = (char *)(param_2 + iVar1);
      iVar1 = iVar1 + 1;
      if (*(char *)(iVar3 + 0xe) != *pcVar2) {
        return 0;
      }
      iVar3 = param_1 + iVar1;
    } while (iVar1 != 6);
    uVar4 = 1;
  }
  return uVar4;
}

