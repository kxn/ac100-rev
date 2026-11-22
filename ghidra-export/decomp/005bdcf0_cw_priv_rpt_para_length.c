// func cw_priv_rpt_para_length @ 005bdcf0 size=12

undefined4 cw_priv_rpt_para_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xd;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

