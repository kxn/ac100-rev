// func apupd_model_hash_cmp @ 0064c2b8 size=124

bool apupd_model_hash_cmp(int param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    bVar2 = false;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_model_hash_cmp",0x1cc);
    }
  }
  else {
    bVar2 = *(int *)(param_1 + 0x58) == *param_2;
  }
  return bVar2;
}

