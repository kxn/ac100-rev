// func apupd_image_information_add @ 00661520 size=248

undefined4 apupd_image_information_add(int param_1,undefined4 param_2,void *param_3,uint param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (((param_1 == 0) || (param_3 == (void *)0x0)) || ((param_4 & 0xffff) == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0xcf;
  }
  else {
    local_20 = param_2;
    memcpy(&local_1c,param_3,param_4 & 0xffff);
    iVar1 = cw_service_msg_add(param_1,0x1a,&local_20,0);
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
    __format = "[APUPD_ERROR]%32s() %05d: add image information failed.\r\n";
    uVar2 = 0xdc;
  }
  printf(__format,"apupd_image_information_add",uVar2);
  return 0xffffffff;
}

