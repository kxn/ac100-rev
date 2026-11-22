// func cloud_mngt_notify_all_update_token @ 0048c25c size=480

undefined4 cloud_mngt_notify_all_update_token(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char local_28 [16];
  
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  iVar1 = json_object_new_object();
  uVar2 = json_object_new_object();
  uVar3 = json_object_new_object();
  snprintf(local_28,10,"%d",param_2);
  uVar4 = json_object_new_string(&DAT_00697f28);
  json_object_object_add(iVar1,"method",uVar4);
  uVar4 = json_object_new_string("all");
  json_object_object_add(uVar3,"service_id",uVar4);
  uVar4 = json_object_new_string("public");
  json_object_object_add(uVar3,"cloud_type",uVar4);
  uVar4 = json_object_new_string(param_1);
  json_object_object_add(uVar3,"token",uVar4);
  uVar4 = json_object_new_string(local_28);
  json_object_object_add(uVar3,"expires",uVar4);
  json_object_object_add(uVar2,"report_set_token",uVar3);
  json_object_object_add(iVar1,"cloud_status",uVar2);
  uVar2 = json_object_to_json_string_ext(iVar1,0);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d get send tdcp_msg:%s\n","cloud_mngt_notify_all_update_token",
           0x1b5f,uVar2);
  }
  iVar5 = tdcp_send_request_to_ap_all(0,"report_set_token",uVar2,5);
  uVar2 = 0;
  if ((iVar5 != 0) && (uVar2 = 0xffffffff, cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d send online or offline to ap all failed!\n",
           "cloud_mngt_notify_all_update_token",0x1b63);
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return uVar2;
}

