// func _sensor_join @ 004e2544 size=132

undefined4 _sensor_join(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((*(int *)(param_1 + 0x14) == 7) &&
     (iVar1 = sensor_db_get(*(undefined2 *)(param_1 + 0x10),&local_28,0), iVar1 != 0)) {
    local_28 = CONCAT22(*(undefined2 *)(param_1 + 0x10),local_28._2_2_);
    uVar2 = sensor_db_add(&local_28);
  }
  return uVar2;
}

