// func cw_ipstr_to_protocol_ip @ 005727e0 size=108

undefined4 cw_ipstr_to_protocol_ip(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar2 = 0xffffffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = FUN_0051a7a8(param_1,&local_28);
    if (iVar1 == 0) {
      uVar2 = cw_common_ip_to_protocol_ip(param_2,&local_28);
    }
  }
  return uVar2;
}

