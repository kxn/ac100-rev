// func cw_fsm_stat_dec @ 0059cd98 size=112

void cw_fsm_stat_dec(int param_1)

{
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_stat_dec",0x107,"session");
    return;
  }
  if ((*(int *)(param_1 + 0xb4) - 7U < 7) &&
     (*(int *)(*(int *)(param_1 + 0xc) + 0x5c) = *(int *)(*(int *)(param_1 + 0xc) + 0x5c) + -1,
     *(int *)(param_1 + 0xb4) == 0xd)) {
    *(int *)(*(int *)(param_1 + 0xc) + 0x60) = *(int *)(*(int *)(param_1 + 0xc) + 0x60) + -1;
    return;
  }
  return;
}

