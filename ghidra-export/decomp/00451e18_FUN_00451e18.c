// func FUN_00451e18 @ 00451e18 size=68

void FUN_00451e18(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004082a0(param_1,4,0x88);
  if (iVar1 != 0) {
    g_mac_auth_mem_stat = param_1 * 4 + g_mac_auth_mem_stat;
  }
  return;
}

