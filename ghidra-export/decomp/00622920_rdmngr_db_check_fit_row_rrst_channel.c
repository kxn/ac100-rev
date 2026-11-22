// func rdmngr_db_check_fit_row_rrst_channel @ 00622920 size=68

undefined4 rdmngr_db_check_fit_row_rrst_channel(short param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (*(short *)(param_2 + iVar1) == 0) {
      return 0;
    }
    if (param_1 == *(short *)(param_2 + iVar1)) break;
    iVar1 = iVar1 + 2;
    if (iVar1 == 0x66) {
      return 0;
    }
  }
  return 1;
}

