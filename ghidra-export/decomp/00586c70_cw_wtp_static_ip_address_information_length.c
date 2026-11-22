// func cw_wtp_static_ip_address_information_length @ 00586c70 size=12

undefined4 cw_wtp_static_ip_address_information_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xd;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

