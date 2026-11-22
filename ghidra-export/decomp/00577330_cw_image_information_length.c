// func cw_image_information_length @ 00577330 size=12

undefined4 cw_image_information_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x14;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

