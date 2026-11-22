// func sensor_cb_hash_cmp @ 004ead48 size=172

bool sensor_cb_hash_cmp(int *param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    bVar2 = false;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d inputs error.\n","sensor_cb_hash_cmp",0xa7);
    }
  }
  else {
    iVar1 = *param_1;
    bVar2 = false;
    if (iVar1 == *param_2) {
      if (iVar1 == 0) {
        bVar2 = param_2[1] == param_1[1];
      }
      else if (iVar1 == 1) {
        iVar1 = strncmp((char *)(param_2 + 1),(char *)(param_1 + 1),0x33);
        bVar2 = iVar1 == 0;
      }
    }
  }
  return bVar2;
}

