// func serv_msg_mngr_unregister @ 00599be0 size=152

undefined4 serv_msg_mngr_unregister(undefined4 param_1,short param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = serv_msg_mngr_get();
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    iVar1 = FUN_004081b0(iVar1 + 4);
    while (iVar1 != 0) {
      if ((*(short *)(iVar1 + 0xc) == param_2) && (*(int *)(iVar1 + 0x10) == param_3)) {
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
        return 0;
      }
      iVar1 = FUN_00408680();
    }
    uVar2 = 0;
  }
  return uVar2;
}

