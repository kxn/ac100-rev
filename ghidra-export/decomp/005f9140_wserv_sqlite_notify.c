// func wserv_sqlite_notify @ 005f9140 size=392

undefined4 wserv_sqlite_notify(undefined4 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void *__dest;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_2 != (void *)0x0) && (0 < (int)param_3)) {
    iVar1 = FUN_00408450(0x14,0x5ba);
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n","wserv_sqlite_notify",0x5bd);
      }
    }
    else {
      *(undefined4 *)(iVar1 + 0xc) = param_1;
      __dest = (void *)FUN_00408450(param_3,0x5c1);
      *(void **)(iVar1 + 0x10) = __dest;
      if (__dest == (void *)0x0) {
        if (g_wserv_error == 0) {
          iVar2 = *(int *)(iVar1 + 0x10);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = *(int *)(iVar1 + 0x10);
          }
          else {
            printf("<wserv>[error]%s(): %d  -> no memory!\r\n","wserv_sqlite_notify",0x5c4);
            iVar2 = *(int *)(iVar1 + 0x10);
          }
        }
        if (iVar2 != 0) {
          FUN_00407df0();
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        FUN_00407df0(iVar1);
        uVar3 = 0xffffffff;
      }
      else {
        memcpy(__dest,param_2,param_3);
        FUN_00407e80("wserv_sqlite_notify");
        FUN_004082d0(DAT_007cbf98,0xffffffff);
        FUN_004086b0(&DAT_007cbf8c,iVar1);
        FUN_004084b0(DAT_007cbf9c);
        FUN_00407f30(DAT_007cbf98);
        FUN_004082b0(1,"wserv_sqlite_notify");
      }
    }
  }
  return uVar3;
}

