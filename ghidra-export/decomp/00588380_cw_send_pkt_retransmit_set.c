// func cw_send_pkt_retransmit_set @ 00588380 size=24

undefined4 cw_send_pkt_retransmit_set(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = 0;
    *param_1 = param_2;
  }
  return uVar1;
}

