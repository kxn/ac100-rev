// func wportal_sta_access_check_reg @ 00426260 size=400

undefined4 wportal_sta_access_check_reg(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  if (*(int *)((int)param_1 + 0x24) == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d reg\'s cb is null.\n";
    uVar4 = 0x3866;
  }
  else {
    iVar1 = FUN_00408450(0x38,0x386a);
    if (iVar1 != 0) {
      memcpy((void *)(iVar1 + 0xc),param_1,0x2c);
      if ((*(int *)((int)param_1 + 0x20) < 0) ||
         (iVar2 = FUN_004081b0(&l_wportal_sta_access_check_reg), iVar2 == 0)) {
LAB_004262e8:
        FUN_004086b0(&l_wportal_sta_access_check_reg,iVar1);
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x2c);
        while (*(int *)((int)param_1 + 0x20) < iVar3) {
          iVar2 = FUN_00408680();
          if (iVar2 == 0) goto LAB_004262e8;
          iVar3 = *(int *)(iVar2 + 0x2c);
        }
        FUN_00408170(iVar2,iVar1);
      }
      if (wportal_info_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("[WPORTAL_INFO]%s()/%d wportal sta access check reg : name[%s] prio[%d]. l_wportal_sta_access_check_reg.size=%d.\n"
             ,"wportal_sta_access_check_reg",0x388a,param_1,*(undefined4 *)((int)param_1 + 0x20),
             DAT_007cca38);
      return 0;
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d no memory\n";
    uVar4 = 0x386d;
  }
  printf(__format,"wportal_sta_access_check_reg",uVar4);
  return 0xffffffff;
}

