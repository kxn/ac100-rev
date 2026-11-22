// func _wportal_rds_hash_key_func @ 0042c694 size=96

undefined4 _wportal_rds_hash_key_func(void *param_1)

{
  undefined4 uVar1;
  char local_20 [4];
  undefined1 auStack_1c [24];
  
  memcpy(local_20,param_1,0x14);
  if (local_20[0] == '\x01') {
    uVar1 = 4;
  }
  else {
    if (local_20[0] != '\x02') {
      return 0;
    }
    uVar1 = 0x10;
  }
  uVar1 = FUN_004083d0(auStack_1c,uVar1,0);
  return uVar1;
}

