// func client_handle_hash_cmp @ 004975b4 size=104

bool client_handle_hash_cmp(void *param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d inputs error.\n","client_handle_hash_cmp",0x901);
    }
  }
  else {
    iVar1 = memcmp(param_1,param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

