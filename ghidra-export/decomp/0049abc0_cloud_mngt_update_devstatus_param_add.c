// func cloud_mngt_update_devstatus_param_add @ 0049abc0 size=380

void cloud_mngt_update_devstatus_param_add(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_118 [132];
  undefined1 auStack_94 [136];
  
  memset(auStack_94,0,0x81);
  memset(auStack_118,0,0x81);
  uVar1 = json_object_new_string(site_id);
  json_object_object_add(param_1,"projectId",uVar1);
  uVar1 = json_object_new_string(device_mac);
  json_object_object_add(param_1,"deviceMac",uVar1);
  FUN_00408520(auStack_94,0x81);
  FUN_00408550(auStack_118,0x81);
  uVar1 = json_object_new_string(auStack_94);
  json_object_object_add(param_1,"configId",uVar1);
  uVar1 = json_object_new_string(auStack_118);
  json_object_object_add(param_1,&DAT_00677c24,uVar1);
  uVar1 = json_object_new_string(&device_type);
  json_object_object_add(param_1,"deviceType",uVar1);
  iVar2 = FUN_00408350(&g_device_name,0x81);
  if (iVar2 == 0) {
    uVar1 = json_object_new_string(&g_device_name);
    json_object_object_add(param_1,"deviceName",uVar1);
    uVar1 = json_object_new_boolean(cloud_config_switch);
    json_object_object_add(param_1,"syncConfig",uVar1);
  }
  else if (cloud_mngt_err_switch != '\0') {
    printf("[CLOUD_MNGT_ERROR]%s()/%d get devcie name failed\n",
           "cloud_mngt_update_devstatus_param_add",0x6cb);
  }
  return;
}

