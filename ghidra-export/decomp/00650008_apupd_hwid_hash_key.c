// func apupd_hwid_hash_key @ 00650008 size=108

undefined4 apupd_hwid_hash_key(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_hwid_hash_key",0x1ff);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,0x10,0);
  return uVar1;
}

