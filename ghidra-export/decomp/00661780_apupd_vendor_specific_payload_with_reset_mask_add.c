// func apupd_vendor_specific_payload_with_reset_mask_add @ 00661780 size=272

undefined4
apupd_vendor_specific_payload_with_reset_mask_add
          (int param_1,undefined4 param_2,ushort param_3,undefined4 param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_28 = 0;
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0x146;
  }
  else {
    local_20 = (uint)param_3 << 0x10;
    local_24 = param_2;
    FUN_0051ad88(&local_1c);
    local_28 = param_4;
    iVar1 = cw_service_msg_add(param_1,0x25,&local_24,1,0x23,&local_28);
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
    uVar2 = 0x154;
  }
  printf(__format,"apupd_vendor_specific_payload_with_reset_mask_add",uVar2);
  return 0xffffffff;
}

