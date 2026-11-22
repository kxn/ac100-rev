// func register_sub_device_report_handle @ 0050c8f8 size=144

undefined4 register_sub_device_report_handle(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_1 != 0) && (param_2 - 1U < 4)) {
    uVar1 = FUN_00407fe0(&g_reg_sub_device_report_handle + param_2 * 0xc);
    if ((uVar1 < 5) && (iVar2 = FUN_00408450(0x10,0xc2), iVar2 != 0)) {
      uVar3 = 0;
      *(int *)(iVar2 + 0xc) = param_1;
      FUN_004086b0(&g_reg_sub_device_report_handle + param_2 * 0xc,iVar2);
    }
  }
  return uVar3;
}

