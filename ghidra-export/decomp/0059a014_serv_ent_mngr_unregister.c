// func serv_ent_mngr_unregister @ 0059a014 size=1

undefined4 serv_ent_mngr_unregister(uint param_1,short param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if (((param_1 & 0xffff) < 4) && ((&g_serv_ent_mngr)[param_1 & 0xffff] != 0)) {
    iVar2 = FUN_004081b0((&g_serv_ent_mngr)[param_1 & 0xffff] + 4);
    while (iVar2 != 0) {
      if ((*(short *)(iVar2 + 0xc) == param_2) && (*(int *)(iVar2 + 0x10) == param_3)) {
        FUN_00408500(iVar2);
        FUN_00407df0(iVar2);
        return 0;
      }
      iVar2 = FUN_00408680();
    }
    uVar1 = 0;
  }
  return uVar1;
}

