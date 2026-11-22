// func client_handle_hash_key @ 004976e4 size=92

undefined4 client_handle_hash_key(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d inputs error.\n","client_handle_hash_key",0x8f4);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,6,0);
  return uVar1;
}

