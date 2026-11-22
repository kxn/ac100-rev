// func cw_add_station_free @ 0056feb4 size=104

undefined4 cw_add_station_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) == 0) {
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    else {
      FUN_00407df0();
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar2);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

