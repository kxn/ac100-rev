// func cw_capwap_local_ipv6_address_len_get @ 00571050 size=12

undefined4 cw_capwap_local_ipv6_address_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

