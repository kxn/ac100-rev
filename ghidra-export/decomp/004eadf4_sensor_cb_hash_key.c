// func sensor_cb_hash_key @ 004eadf4 size=168

undefined4 sensor_cb_hash_key(int *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if (param_1 == (int *)0x0) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d inputs error.\n","sensor_cb_hash_key",0x83);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,4,0);
  sVar2 = 4;
  if (*param_1 != 0) {
    sVar2 = strlen((char *)(param_1 + 1));
  }
  uVar1 = FUN_004083d0(param_1 + 1,sVar2,uVar1);
  return uVar1;
}

