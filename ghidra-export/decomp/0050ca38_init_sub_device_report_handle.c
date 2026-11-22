// func init_sub_device_report_handle @ 0050ca38 size=132

undefined4 init_sub_device_report_handle(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00768970 != 1) {
    iVar2 = 0;
    iVar1 = 0;
    while( true ) {
      iVar2 = iVar2 + 1;
      FUN_0051ad88(&g_reg_sub_device_report_handle + iVar1);
      if (iVar2 == 5) break;
      iVar1 = iVar2 * 0xc;
    }
    DAT_00768970 = 1;
  }
  return 0;
}

