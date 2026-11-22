// func cw_priv_lldp_report_free @ 005b4fd0 size=72

undefined4 cw_priv_lldp_report_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
  }
  return 0;
}

