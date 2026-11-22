// func cw_session_id_length @ 00580810 size=12

undefined4 cw_session_id_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

