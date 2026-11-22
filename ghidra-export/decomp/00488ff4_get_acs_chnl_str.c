// func get_acs_chnl_str @ 00488ff4 size=1

undefined * get_acs_chnl_str(byte param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 < 2) {
    puVar1 = (&PTR_s_1_6_11_00696d90)[(char)param_1];
  }
  return puVar1;
}

