// func serv_retransmit_packet_send @ 0059af98 size=56

void serv_retransmit_packet_send
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_4 != 0 || param_3 != 0) {
    uVar1 = 4;
    if (param_3 == 0) {
      if (param_4 != 0) {
        uVar1 = 3;
      }
    }
    else if (param_4 == 0) {
      uVar1 = 2;
    }
  }
  local_serv_packet_send(param_1,param_2,uVar1,param_5);
  return;
}

