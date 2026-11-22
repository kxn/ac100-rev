// func tdcp_init @ 00512488 size=192

undefined4 tdcp_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = tdcp_mutex_init();
  if ((((iVar1 == 0) && (iVar1 = apmngr_support_capacity_register(0x4b), iVar1 == 0)) &&
      (iVar1 = apmngr_support_capacity_register(0x4c), iVar1 == 0)) &&
     (iVar1 = tdcp_thread_init(), iVar1 == 0)) {
    FUN_0051ad88(&g_tdcp_to_ap_list);
    FUN_0051ad88(&g_tdcp_from_ap_list);
    FUN_0051ad88(&g_tdcp_waitting_response_list);
    scan_waitting_response_list_timer =
         FUN_00408340(0x1e,0,scan_waitting_response_list,0,0,"tdcp_init",0x484);
    uVar2 = 0;
  }
  else {
    tdcp_fini();
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

