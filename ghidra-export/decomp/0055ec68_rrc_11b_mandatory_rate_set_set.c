// func rrc_11b_mandatory_rate_set_set @ 0055ec68 size=32

undefined4 rrc_11b_mandatory_rate_set_set(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = rrc_rate_set_set(param_1 + 0x88);
    return uVar1;
  }
  return 0xffffffff;
}

