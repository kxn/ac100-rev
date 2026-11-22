// func cw_capwap_control_ipv6_address_len_get @ 005709c0 size=12

undefined4 cw_capwap_control_ipv6_address_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x12;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

