// func cw_send_pkt_retransmit_interval_set @ 00588398 size=24

undefined4 cw_send_pkt_retransmit_interval_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 4) = param_2;
  }
  return uVar1;
}

