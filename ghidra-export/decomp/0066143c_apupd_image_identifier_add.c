// func apupd_image_identifier_add @ 0066143c size=228

undefined4 apupd_image_identifier_add(int param_1,undefined4 param_2,int param_3,ushort param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_18;
  int local_14;
  int local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (((param_1 == 0) || (param_3 == 0)) || (param_4 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0xa6;
  }
  else {
    local_14 = (uint)param_4 << 0x10;
    local_18 = param_2;
    local_10 = param_3;
    iVar1 = cw_service_msg_add(param_1,0x19,&local_18,0);
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
    __format = "[APUPD_ERROR]%32s() %05d: add image identifier failed.\r\n";
    uVar2 = 0xb3;
  }
  printf(__format,"apupd_image_identifier_add",uVar2);
  return 0xffffffff;
}

