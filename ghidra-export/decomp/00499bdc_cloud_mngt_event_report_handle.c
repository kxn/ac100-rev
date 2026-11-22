// func cloud_mngt_event_report_handle @ 00499bdc size=164

undefined4 cloud_mngt_event_report_handle(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = json_object_new_object();
  cloud_mngt_report_event_stats_head_add(iVar1);
  json_object_object_add(iVar1,"devEventList",param_1);
  iVar2 = cloud_mngt_obj_send_to_cloud(8,iVar1);
  uVar3 = 0;
  if ((iVar2 != 0) && (uVar3 = 0xffffffff, cloud_mngt_debug_switch != '\0')) {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_obj_send_to_cloud failed\n",
           "cloud_mngt_event_report_handle",0x8d2);
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return uVar3;
}

