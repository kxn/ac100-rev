// func balance_dis_sta_hash_obj @ 0045bdec size=108

undefined4 balance_dis_sta_hash_obj(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_dis_sta_hash_obj",0xb0);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,6,0);
  return uVar1;
}

