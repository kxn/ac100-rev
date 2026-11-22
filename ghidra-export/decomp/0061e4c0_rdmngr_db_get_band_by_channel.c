// func rdmngr_db_get_band_by_channel @ 0061e4c0 size=64

undefined4 rdmngr_db_get_band_by_channel(uint param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xffff;
  uVar1 = 1;
  if ((0xc < param_1 - 1) && (uVar1 = 2, 0x1c < param_1 - 0x24)) {
    uVar1 = 3;
    if (0x41 < param_1 - 100) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return uVar1;
}

