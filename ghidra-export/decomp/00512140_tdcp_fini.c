// func tdcp_fini @ 00512140 size=184

void tdcp_fini(void)

{
  int iVar1;
  
  tdcp_mutex_fini();
  tdcp_thread_fini();
  while (iVar1 = FUN_004081b0(&g_tdcp_to_ap_list), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  while (iVar1 = FUN_004081b0(&g_tdcp_from_ap_list), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  while (iVar1 = FUN_004081b0(&g_tdcp_waitting_response_list), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return;
}

