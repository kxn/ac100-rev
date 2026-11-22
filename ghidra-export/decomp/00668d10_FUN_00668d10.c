// func FUN_00668d10 @ 00668d10 size=136

undefined4 FUN_00668d10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  uVar2 = 0;
  iVar1 = FUN_004081b0(&g_sample_time_changed_callback_list + param_1 * 0xc);
  if (iVar1 != 0) {
    pcVar3 = *(code **)(iVar1 + 0x18);
    while( true ) {
      uVar2 = 0;
      if (pcVar3 != (code *)0x0) {
        uVar2 = (*pcVar3)(param_1);
      }
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      pcVar3 = *(code **)(iVar1 + 0x18);
    }
  }
  return uVar2;
}

