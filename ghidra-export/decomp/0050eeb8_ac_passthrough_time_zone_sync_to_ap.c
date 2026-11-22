// func ac_passthrough_time_zone_sync_to_ap @ 0050eeb8 size=1

undefined4 ac_passthrough_time_zone_sync_to_ap(undefined2 param_1)

{
  int iVar1;
  undefined1 auStack_408 [1024];
  
  memset(auStack_408,0,0x400);
  iVar1 = FUN_0050c5f0(auStack_408,0);
  if ((iVar1 == 0) &&
     (iVar1 = send_tdcp_request_to_ap_by_id(0,param_1,0xffffffff,auStack_408,0,0), iVar1 == 0)) {
    return 0;
  }
  if (ac_passthrough_err_switch != '\0') {
    printf("[AC_PASSTHROUGH_ERROR]%s()/%d Generate/Send timer type set packet failed.\n",
           "ac_passthrough_time_zone_sync_to_ap",0x893);
  }
  return 0xffffffff;
}

