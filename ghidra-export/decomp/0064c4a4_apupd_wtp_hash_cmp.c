// func apupd_wtp_hash_cmp @ 0064c4a4 size=124

bool apupd_wtp_hash_cmp(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_wtp_hash_cmp",0x263);
    }
  }
  else {
    iVar1 = memcmp((void *)(param_1 + 0x2e),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

