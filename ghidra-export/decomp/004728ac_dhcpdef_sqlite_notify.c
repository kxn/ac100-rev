// func dhcpdef_sqlite_notify @ 004728ac size=496

undefined4 dhcpdef_sqlite_notify(undefined4 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void *__dest;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if ((param_2 == (void *)0x0) || ((int)param_3 < 1)) {
    uVar4 = 0;
    if (g_dhcpdef_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar5 = "(data && len > 0)";
    uVar3 = 0x366;
  }
  else {
    iVar1 = FUN_00408450(0x14,0x368);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0xc) = param_1;
      __dest = (void *)FUN_00408450(param_3,0x36c);
      *(void **)(iVar1 + 0x10) = __dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_2,param_3);
        FUN_00407e80("dhcpdef_sqlite_notify");
        FUN_004082d0(DAT_007670c8,0xffffffff);
        FUN_004086b0(&DAT_007670bc,iVar1);
        FUN_004084b0(DAT_007670cc);
        FUN_00407f30(DAT_007670c8);
        FUN_004082b0(1,"dhcpdef_sqlite_notify");
        return 0;
      }
      if (g_dhcpdef_error == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 0x10);
        }
        else {
          printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_sqlite_notify",0x36f);
          iVar2 = *(int *)(iVar1 + 0x10);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      FUN_00407df0(iVar1);
      return 0xffffffff;
    }
    uVar4 = 0xffffffff;
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "msg";
    uVar3 = 0x369;
  }
  printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
         "dhcpdef_sqlite_notify",uVar3,pcVar5);
  return uVar4;
}

