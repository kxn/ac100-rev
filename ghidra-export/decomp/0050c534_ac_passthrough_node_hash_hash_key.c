// func ac_passthrough_node_hash_hash_key @ 0050c534 size=92

undefined4 ac_passthrough_node_hash_hash_key(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n","ac_passthrough_node_hash_hash_key",
             0x3be);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,6,0);
  return uVar1;
}

