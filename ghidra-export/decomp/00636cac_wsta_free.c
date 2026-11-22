// func wsta_free @ 00636cac size=160

void wsta_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (g_wsta_mem_record_sw != 0) {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    iVar1 = FUN_004081b0(&wsta_mem_record);
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) goto LAB_00636d38;
      iVar1 = FUN_00408680(iVar2);
    } while (param_1 != *(int *)(iVar2 + 0xc));
    FUN_00408500(iVar2);
    FUN_00407df0(iVar2);
LAB_00636d38:
    FUN_00407f30(DAT_007cc6bc);
  }
  FUN_00407df0(param_1);
  return;
}

