// func _sensor_firm @ 004e30cc size=32

undefined4 _sensor_firm(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) != 7) {
    return 0;
  }
  uVar1 = sensor_db_firm(*(undefined2 *)(param_1 + 0x10));
  return uVar1;
}

