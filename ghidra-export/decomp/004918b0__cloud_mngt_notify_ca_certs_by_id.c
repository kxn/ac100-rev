// func _cloud_mngt_notify_ca_certs_by_id @ 004918b0 size=252

undefined4 _cloud_mngt_notify_ca_certs_by_id(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  iVar2 = apmngr_is_support_capacity(0x54);
  if (iVar2 == 0) {
    uVar1 = *(undefined2 *)(param_1 + 0x10);
  }
  else {
    if (*(int *)(param_1 + 600) << 0xb < 0) {
      if (cloud_mngt_debug_switch == '\0') {
        return 0;
      }
      __format = "[CLOUD_MNGT_DEBUG]%s()/%d don\'t need to send ssl certs to ap:%d\n";
      uVar3 = 0x1bae;
      goto LAB_00491984;
    }
    uVar1 = *(undefined2 *)(param_1 + 0x10);
  }
  iVar2 = tdcp_send_request_to_ap_by_id(0,"security_manage",param_2,5,uVar1);
  if (iVar2 != 0) {
    if (cloud_mngt_err_switch == '\0') {
      return 1;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d send ssl certs to ap all failed!\n",
           "_cloud_mngt_notify_ca_certs_by_id",0x1bb4);
    return 1;
  }
  if (cloud_mngt_debug_switch == '\0') {
    return 0;
  }
  __format = "[CLOUD_MNGT_DEBUG]%s()/%d send ssl certs to ap:%d\n";
  uVar3 = 0x1bb8;
LAB_00491984:
  printf(__format,"_cloud_mngt_notify_ca_certs_by_id",uVar3,(uint)*(ushort *)(param_1 + 0x10));
  return 0;
}

