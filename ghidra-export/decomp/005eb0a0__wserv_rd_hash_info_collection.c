// func _wserv_rd_hash_info_collection @ 005eb0a0 size=188

void _wserv_rd_hash_info_collection(void *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = wserv_calloc(1,0x21c);
  if (iVar1 != 0) {
    memcpy((void *)(iVar1 + 0x214),param_1,8);
    FUN_004086b0(param_2,iVar1);
    return;
  }
  if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","_wserv_rd_hash_info_collection",0x584);
    return;
  }
  return;
}

