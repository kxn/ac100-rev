// func cloud_mngt_jcs_notify_unbind @ 0048c128 size=308

void cloud_mngt_jcs_notify_unbind(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = json_object_new_object();
  uVar2 = json_object_new_object();
  uVar3 = json_object_new_string(&DAT_00697f28);
  json_object_object_add(iVar1,"method",uVar3);
  uVar3 = json_object_new_string(&DAT_00688af8);
  json_object_object_add(uVar2,"notify_unbind",uVar3);
  json_object_object_add(iVar1,"cloud_status",uVar2);
  uVar2 = json_object_to_json_string_ext(iVar1,0);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d get send tdcp_msg:%s\n","cloud_mngt_jcs_notify_unbind",0x1efa,
           uVar2);
  }
  iVar4 = tdcp_send_request_to_ap_all(0,"notify_unbind",uVar2,5);
  if ((iVar4 != 0) && (cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d send notify unbind to ap all failed!\n",
           "cloud_mngt_jcs_notify_unbind",0x1efe);
  }
  if (iVar1 == 0) {
    return;
  }
  json_object_put(iVar1);
  return;
}

