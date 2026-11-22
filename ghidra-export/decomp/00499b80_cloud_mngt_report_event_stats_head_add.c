// func cloud_mngt_report_event_stats_head_add @ 00499b80 size=92

void cloud_mngt_report_event_stats_head_add(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = json_object_new_string(site_id);
  json_object_object_add(param_1,"projectId",uVar1);
  uVar1 = json_object_new_string(device_mac);
  json_object_object_add(param_1,"deviceMac",uVar1);
  return;
}

