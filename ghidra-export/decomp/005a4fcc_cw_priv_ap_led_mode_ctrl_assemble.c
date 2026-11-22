// func cw_priv_ap_led_mode_ctrl_assemble @ 005a4fcc size=96

undefined4 cw_priv_ap_led_mode_ctrl_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,**(undefined4 **)(param_2 + 0x10));
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

