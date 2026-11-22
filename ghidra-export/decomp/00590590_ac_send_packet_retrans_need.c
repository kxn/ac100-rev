// func ac_send_packet_retrans_need @ 00590590 size=180

uint ac_send_packet_retrans_need(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x94;
    pcVar3 = "session";
  }
  else {
    if (param_2 != (uint *)0x0) {
      uVar1 = *param_2;
      if (uVar1 == 2) {
        return 1;
      }
      if (uVar1 < 3) {
        if (uVar1 != 1) {
          return 0;
        }
      }
      else if (uVar1 != 3) {
        if (uVar1 == 4) {
          return 1;
        }
        return 0;
      }
      return (uint)(*(int *)(param_1 + 0xdc) << 0x14) >> 0x1f;
    }
    uVar2 = 0x95;
    pcVar3 = "send_pkt";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_send_packet_retrans_need",uVar2,pcVar3);
  return 0;
}

