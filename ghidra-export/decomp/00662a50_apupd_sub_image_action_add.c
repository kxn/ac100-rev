// func apupd_sub_image_action_add @ 00662a50 size=360

undefined4
apupd_sub_image_action_add(int param_1,byte param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_sub_image_action_add. type:%d\r\n",
           "apupd_sub_image_action_add",0x388,(uint)param_2);
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_38 = 0;
  local_34 = 0;
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0x38f;
  }
  else {
    local_38 = (uint)CONCAT11(param_2,param_3) << 0x10;
    local_34 = param_4;
    FUN_0051ad88(&local_28);
    iVar1 = cw_service_msg_add(param_1,0x25,&local_30,1,0xb1,&local_38);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: add vendor specifal payload failed.\r\n";
    uVar2 = 0x39b;
  }
  printf(__format,"apupd_sub_image_action_add",uVar2);
  return 0xffffffff;
}

