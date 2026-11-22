// func apupd_update_model_hash_obj @ 0064ff98 size=112

undefined4 apupd_update_model_hash_obj(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_update_model_hash_obj",0x27f);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0xc,4,0);
  return uVar1;
}

