// func uac_sqlite_uninit_int32_key_array @ 00522698 size=84

undefined4 uac_sqlite_uninit_int32_key_array(int *param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (*param_1 != 0) {
    uac_mem_free_my();
    *param_1 = 0;
  }
  return 0;
}

