// func ac_passthrough_node_hash_hash_obj @ 0050c590 size=96

undefined4 ac_passthrough_node_hash_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n","ac_passthrough_node_hash_hash_obj",
             0x3b0);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0x10,6,0);
  return uVar1;
}

