// func cloud_mngt_radio_type_get @ 0048baf4 size=68

undefined * cloud_mngt_radio_type_get(uint param_1)

{
  uint uVar1;
  
  if ((0xd < param_1) || (uVar1 = (uint)(char)(&DAT_0069b8a8)[param_1], 0xc < uVar1)) {
    uVar1 = 0;
  }
  return (&radio_map)[uVar1];
}

