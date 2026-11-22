// func _child_arg_hash_obj @ 005998a0 size=76

undefined4 _child_arg_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = _child_arg_hash_key(param_1 + 0xc);
    return uVar1;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","_child_arg_hash_obj",200,"node");
  return 0;
}

