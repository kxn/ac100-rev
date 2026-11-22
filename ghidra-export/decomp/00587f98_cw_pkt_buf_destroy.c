// func cw_pkt_buf_destroy @ 00587f98 size=76

void cw_pkt_buf_destroy(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return;
  }
  if (*param_1 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(param_1);
  return;
}

