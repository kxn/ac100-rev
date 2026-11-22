// func apmngr_db_get_cur_using_rrst_idx @ 005416f0 size=144

uint apmngr_db_get_cur_using_rrst_idx(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0xffff;
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  if (49999 < param_1) {
    param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  uVar1 = g_apmngr_entry_array + param_1 * 0x2d8;
  if (uVar1 != 0) {
    uVar1 = (uint)*(byte *)(uVar1 + 0x2d0);
  }
  FUN_00407f30(apmngr_db_mutex);
  return uVar1;
}

