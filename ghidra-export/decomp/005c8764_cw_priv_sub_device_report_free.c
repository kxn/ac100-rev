// func cw_priv_sub_device_report_free @ 005c8764 size=72

undefined4 cw_priv_sub_device_report_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
  }
  return 0;
}

