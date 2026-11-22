// func _wportal_rds_hash_obj_func @ 0042c8e8 size=56

undefined4 _wportal_rds_hash_obj_func(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x120) == '\x01') {
    uVar1 = 4;
  }
  else {
    if (*(char *)(param_1 + 0x120) != '\x02') {
      return 0;
    }
    uVar1 = 0x10;
  }
  uVar1 = FUN_004083d0(param_1 + 0x124,uVar1,0);
  return uVar1;
}

