// func apupd_hwid_hash_cmp @ 0064c42c size=120

bool apupd_hwid_hash_cmp(void *param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_hwid_hash_cmp",0x217);
    }
  }
  else {
    iVar1 = memcmp(param_1,param_2,0x10);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

