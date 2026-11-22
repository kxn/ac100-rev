// func uac_sqlite_store_int32_key_to_array @ 005225a4 size=52

undefined4 uac_sqlite_store_int32_key_to_array(undefined4 param_1,int param_2,int *param_3)

{
  if ((param_2 != 0) && (param_3 != (int *)0x0)) {
    *(undefined4 *)(param_2 + *param_3 * 4) = param_1;
    *param_3 = *param_3 + 1;
  }
  return 0;
}

