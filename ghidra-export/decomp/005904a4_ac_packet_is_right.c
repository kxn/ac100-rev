// func ac_packet_is_right @ 005904a4 size=164

undefined4 ac_packet_is_right(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_packet_is_right",0x72,"packet");
    uVar1 = 0;
  }
  else {
    *param_2 = 0;
    if (*(uint *)(param_1 + 0x10) < 0x11) {
      if ((1 << (*(uint *)(param_1 + 0x10) & 0x1f) & 0x10810U) == 0) {
        uVar1 = 1;
      }
      else {
        piVar2 = (int *)cw_msg_ele_val_get(param_1,0x21);
        uVar1 = 1;
        if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
          *param_2 = *piVar2;
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

