// func unregister_sub_device_report_handle @ 0050c988 size=176

undefined4 unregister_sub_device_report_handle(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 - 1U < 4) {
    iVar1 = FUN_00407fe0(&g_reg_sub_device_report_handle + param_2 * 0xc);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_004081b0(&g_reg_sub_device_report_handle + param_2 * 0xc);
    while (iVar1 != 0) {
      if (*(int *)(iVar1 + 0xc) == param_1) {
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
        return 0;
      }
      iVar1 = FUN_00408680();
    }
  }
  return 0xffffffff;
}

