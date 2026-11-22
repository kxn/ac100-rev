// func scan_waitting_response_list @ 00510978 size=340

void scan_waitting_response_list(void)

{
  int iVar1;
  int iVar2;
  int extraout_v1;
  
  scan_waitting_response_list_timer = 0xffffffff;
  FUN_004082d0(tdcp_waiting_response_mutex,0xffffffff);
  FUN_00407e70();
  iVar2 = FUN_004081b0(&g_tdcp_waitting_response_list);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    if (((0 < *(int *)(iVar1 + 0xc)) && (0 < *(int *)(iVar1 + 0x10))) &&
       (0xb3 < extraout_v1 - *(int *)(iVar1 + 0x10))) {
      if (tdcp_debug_switch != 0) {
        printf("[TDCP_DEBUG]%s()/%d the waiting response node is up to date,id:%d\n",
               "scan_waitting_response_list",0x16f);
      }
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
  }
  FUN_00407f30(tdcp_waiting_response_mutex);
  scan_waitting_response_list_timer =
       FUN_00408340(0x1e,0,scan_waitting_response_list,0,0,"scan_waitting_response_list",0x176);
  return;
}

