// func ac_passthrough_time_stamp_sync_to_ap_all @ 0050efa8 size=156

undefined4 ac_passthrough_time_stamp_sync_to_ap_all(void)

{
  int iVar1;
  undefined1 auStack_408 [1024];
  
  memset(auStack_408,0,0x400);
  iVar1 = FUN_0050c5f0(auStack_408,1);
  if ((iVar1 == 0) &&
     (iVar1 = send_tdcp_request_to_ap_all(0,0xffffffff,auStack_408,0,0), iVar1 == 0)) {
    return 0;
  }
  if (ac_passthrough_err_switch != '\0') {
    printf("[AC_PASSTHROUGH_ERROR]%s()/%d Generate/Send time set packet failed.\n",
           "ac_passthrough_time_stamp_sync_to_ap_all",0x8a7);
  }
  return 0xffffffff;
}

