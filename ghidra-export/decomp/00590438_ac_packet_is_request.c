// func ac_packet_is_request @ 00590438 size=108

undefined4 ac_packet_is_request(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_packet_is_request",0x56,"packet");
    uVar1 = 0;
  }
  else if (*(uint *)(param_1 + 0x10) < 0x10) {
    uVar1 = 1;
    if ((1 << (*(uint *)(param_1 + 0x10) & 0x1f) & 0xaa28U) == 0) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

