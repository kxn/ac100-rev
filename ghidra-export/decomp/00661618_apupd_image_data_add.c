// func apupd_image_data_add @ 00661618 size=164

undefined4 apupd_image_data_add(int param_1,int param_2,int param_3,byte param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_c = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_image_data_add",0xf8);
    }
  }
  else {
    local_10 = (uint)param_4 << 0x18;
    local_10 = CONCAT22(local_10._0_2_,(short)param_3);
    uVar2 = 0xffffffff;
    local_c = param_2;
    iVar1 = cw_service_msg_add(param_1,0x18,&local_10,0);
    if (iVar1 != -1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

