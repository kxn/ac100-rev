// func _stats_sta_free_entry @ 00668c28 size=144

void _stats_sta_free_entry(ushort *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00407f40(DAT_007cc8e0,param_1);
  if ((iVar1 != 0) && (stats_err_switch != '\0')) {
    printf("[STATISTICS_ERROR]%s()/%d uac_hash_remove() fail, sta_entry_array->id=%d, ret = %d!\n",
           "_stats_sta_free_entry",0x1b7,(uint)*param_1,iVar1);
  }
  FUN_004080f0(DAT_007cc8dc,*param_1);
  memset(param_1,0,0x1c0);
  return;
}

