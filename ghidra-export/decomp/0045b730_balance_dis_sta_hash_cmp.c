// func balance_dis_sta_hash_cmp @ 0045b730 size=120

bool balance_dis_sta_hash_cmp(void *param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_dis_sta_hash_cmp",0xe0);
    }
  }
  else {
    iVar1 = memcmp(param_1,param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

