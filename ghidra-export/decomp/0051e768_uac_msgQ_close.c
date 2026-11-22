// func uac_msgQ_close @ 0051e768 size=1

void uac_msgQ_close(int param_1)

{
  int in_t9;
  
  if (-1 < param_1) {
                    /* WARNING: Could not recover jumptable at 0x0051e780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(in_t9 + 0x23ae8c))();
    return;
  }
  return;
}

