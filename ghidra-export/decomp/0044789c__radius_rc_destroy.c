// func _radius_rc_destroy @ 0044789c size=232

void _radius_rc_destroy(int *param_1)

{
  int iVar1;
  int iVar2;
  
  uac_hash_delete(param_1[6]);
  uac_hash_delete(param_1[4]);
  uac_hash_delete(param_1[7]);
  uac_hash_delete(param_1[5]);
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[5] = 0;
  if (*param_1 != 0) {
    iVar2 = 0;
    iVar1 = *param_1;
    while( true ) {
      if (*(int *)(iVar1 + iVar2 + 0x48) != 0) {
        uac_mem_free_my();
      }
      iVar2 = iVar2 + 0x4c;
      if (iVar2 == 0xe4) break;
      iVar1 = *param_1;
    }
    uac_mem_free_my(*param_1);
    *param_1 = 0;
  }
  uac_mem_free_my(param_1);
  return;
}

