// func wsta_assoc_check_reg @ 0063651c size=400

undefined4 wsta_assoc_check_reg(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  if (*(int *)((int)param_1 + 0x24) == 0) {
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> reg\'s cb is null.\r\n";
    uVar4 = 0x40a;
  }
  else {
    iVar1 = FUN_00408450(0x38,0x40e);
    if (iVar1 != 0) {
      memcpy((void *)(iVar1 + 0xc),param_1,0x2c);
      if ((*(int *)((int)param_1 + 0x20) < 0) ||
         (iVar2 = FUN_004081b0(&l_wsta_assoc_check_reg), iVar2 == 0)) {
LAB_006365a4:
        FUN_004086b0(&l_wsta_assoc_check_reg,iVar1);
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x2c);
        while (*(int *)((int)param_1 + 0x20) < iVar3) {
          iVar2 = FUN_00408680();
          if (iVar2 == 0) goto LAB_006365a4;
          iVar3 = *(int *)(iVar2 + 0x2c);
        }
        FUN_00408170(iVar2,iVar1);
      }
      if (g_wsta_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("<wsta>[debug]%s(): %d  -> wsta assoc check reg : name[%s] prio[%d]. l_wsta_assoc_check_reg.size=%d.\r\n"
             ,"wsta_assoc_check_reg",0x42e,param_1,*(undefined4 *)((int)param_1 + 0x20),DAT_007cca9c
            );
      return 0;
    }
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> no memory\r\n";
    uVar4 = 0x411;
  }
  printf(__format,"wsta_assoc_check_reg",uVar4);
  return 0xffffffff;
}

