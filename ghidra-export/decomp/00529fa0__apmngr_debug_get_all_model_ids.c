// func _apmngr_debug_get_all_model_ids @ 00529fa0 size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _apmngr_debug_get_all_model_ids(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _g_apmngr_debug_model_count * 4;
  _g_apmngr_debug_model_count = _g_apmngr_debug_model_count + 1;
  *(undefined4 *)(param_2 + iVar1) = *(undefined4 *)(param_1 + 0x10);
  return 0;
}

