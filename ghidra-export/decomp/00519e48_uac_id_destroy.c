// func uac_id_destroy @ 00519e48 size=108

void uac_id_destroy(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    uac_mem_free_my(param_1[1]);
    uac_mem_free_my(*param_1);
    uac_mem_free_my(param_1);
    return;
  }
  return;
}

