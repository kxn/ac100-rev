// func cloud_mngt_AC_notice_param_add @ 0048bddc size=92

void cloud_mngt_AC_notice_param_add(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = json_object_new_string(&device_type);
  json_object_object_add(param_1,"deviceType",uVar1);
  uVar1 = json_object_new_string(&firmware_id);
  json_object_object_add(param_1,"firmwareId",uVar1);
  return;
}

