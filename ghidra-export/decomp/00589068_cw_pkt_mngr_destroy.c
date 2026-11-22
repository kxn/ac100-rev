// func cw_pkt_mngr_destroy @ 00589068 size=36

void cw_pkt_mngr_destroy(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  FUN_00407df0();
  return;
}

