// func _child_arg_hash_key @ 005997f8 size=168

undefined4 _child_arg_hash_key(char *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (char *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","_child_arg_hash_key",0xb4,"key");
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,1,0);
  if (*param_1 == '\x01') {
    uVar1 = 4;
  }
  else {
    if (*param_1 != '\x02') goto LAB_00599838;
    uVar1 = 0x10;
  }
  uVar1 = FUN_004083d0(param_1 + 4,uVar1,0);
LAB_00599838:
  uVar1 = FUN_004083d0(param_1 + 0x14,2,uVar1);
  return uVar1;
}

