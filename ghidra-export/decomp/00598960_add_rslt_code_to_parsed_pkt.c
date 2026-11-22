// func add_rslt_code_to_parsed_pkt @ 00598960 size=56

undefined4 add_rslt_code_to_parsed_pkt(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  iVar1 = cw_service_msg_add(param_1,0x21,local_10,0);
  uVar2 = 0xffffffff;
  if (iVar1 != -1) {
    uVar2 = 0;
  }
  return uVar2;
}

