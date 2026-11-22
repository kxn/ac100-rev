// func nms_callback_wtp_leave @ 0049f1f4 size=596

undefined4 nms_callback_wtp_leave(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  char acStack_318 [40];
  undefined1 auStack_2f0 [732];
  
  memset(acStack_318,0,0x24);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d %s %d \r\n\n","nms_callback_wtp_leave",0x232,
           "nms_callback_wtp_leave",0x232);
  }
  if (((param_1 != 0) && (*(int *)(param_1 + 0x2ac) - 2U < 2)) && (*(int *)(param_1 + 0x14) != 7)) {
    if (cloud_mngt_debug_switch == '\0') {
      uVar1 = *(undefined2 *)(param_1 + 0x10);
    }
    else {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d %s %d ap_id:%d\r\n\n","nms_callback_wtp_leave",0x237,
             "nms_callback_wtp_leave",0x237,(uint)*(ushort *)(param_1 + 0x10));
      uVar1 = *(undefined2 *)(param_1 + 0x10);
    }
    iVar2 = apmngr_db_entry_get_by_id(uVar1,auStack_2f0);
    if (iVar2 == 0) {
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d %s %d ap_id:%d\r\n\n","nms_callback_wtp_leave",0x23b,
               "nms_callback_wtp_leave",0x23b,(uint)*(ushort *)(param_1 + 0x10));
      }
      iVar2 = json_object_new_object();
      if (iVar2 == 0) {
        if (cloud_mngt_err_switch == '\0') {
          return 0xffffffff;
        }
        printf("[CLOUD_MNGT_ERROR]%s()/%d malloc obj failed.\n\n","nms_callback_wtp_leave",0x23f);
        return 0xffffffff;
      }
      sprintf(acStack_318,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48),
              (uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
              (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
              (uint)*(byte *)(param_1 + 0x4d));
      uVar3 = json_object_new_string(acStack_318);
      json_object_object_add(iVar2,"devMac",uVar3);
      uVar3 = json_object_to_json_string_ext(iVar2,0);
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d %s %d ap_id:%d event_param:%s\r\n\n",
               "nms_callback_wtp_leave",0x247,"nms_callback_wtp_leave",0x247,
               (uint)*(ushort *)(param_1 + 0x10),uVar3);
      }
      nms_event_notify(0x989a6c);
      json_object_put(iVar2);
    }
    unset_cloud_mngt_ap_nms_support(*(undefined2 *)(param_1 + 0x10),0,0);
  }
  return 0;
}

