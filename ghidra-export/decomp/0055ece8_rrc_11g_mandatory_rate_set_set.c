// func rrc_11g_mandatory_rate_set_set @ 0055ece8 size=32

undefined4 rrc_11g_mandatory_rate_set_set(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = rrc_rate_set_set(param_1 + 0x10c);
    return uVar1;
  }
  return 0xffffffff;
}

