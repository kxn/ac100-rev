// func cw_ac_pkt_retransmit_para_fixed @ 00592480 size=188

undefined4 cw_ac_pkt_retransmit_para_fixed(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_pkt_retransmit_para_fixed",0x6b0,
           "pkt && session");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if (param_1[1] == 0) {
      param_1[1] = (int)*(short *)(param_2 + 0xf0);
      iVar2 = *param_1;
      if (*(char *)(param_2 + 0xf2) == '\0') {
        if (iVar2 == 3) {
          *param_1 = 1;
        }
        else if (iVar2 == 4) {
          *param_1 = 2;
        }
      }
      else if (iVar2 == 1) {
        *param_1 = 3;
      }
      else if (iVar2 == 2) {
        *param_1 = 4;
      }
    }
  }
  return uVar1;
}

