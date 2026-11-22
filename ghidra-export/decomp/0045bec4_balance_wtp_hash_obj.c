// func balance_wtp_hash_obj @ 0045bec4 size=112

undefined4 balance_wtp_hash_obj(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_wtp_hash_obj",99);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 8,6,0);
  return uVar1;
}

