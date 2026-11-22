// func rrc_11a_supported_rate_set_get @ 0055ec48 size=32

undefined4 rrc_11a_supported_rate_set_get(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = rrc_rate_set_get(param_1 + 0x44);
    return uVar1;
  }
  return 0xffffffff;
}

