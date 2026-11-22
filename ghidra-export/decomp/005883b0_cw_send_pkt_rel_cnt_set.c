// func cw_send_pkt_rel_cnt_set @ 005883b0 size=1

undefined4 cw_send_pkt_rel_cnt_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 8) = param_2;
  }
  return uVar1;
}

