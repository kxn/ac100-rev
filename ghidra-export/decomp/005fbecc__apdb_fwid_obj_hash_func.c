// func _apdb_fwid_obj_hash_func @ 005fbecc size=92

undefined4 _apdb_fwid_obj_hash_func(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : inputs error.\n","_apdb_fwid_obj_hash_func",0x35b);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,0x10,0);
  return uVar1;
}

