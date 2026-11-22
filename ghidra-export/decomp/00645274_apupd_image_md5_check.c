// func apupd_image_md5_check @ 00645274 size=512

undefined4 apupd_image_md5_check(uint param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint unaff_s1;
  uint uVar5;
  void *__src;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar4 = 0x366;
  }
  else {
    if (param_2 < 0x1a) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[APUPD_ERROR]%32s() %05d: size of image file(%d) is wrong.\r\n",
             "apupd_image_md5_check",0x36d,param_2);
      return 0xffffffff;
    }
    uVar5 = param_1 & 3;
    uVar1 = param_1 + 3 & 3;
    uVar5 = (*(int *)(param_1 - uVar5) << uVar5 * 8 | unaff_s1 & 0xffffffffU >> (4 - uVar5) * 8) &
            -1 << (uVar1 + 1) * 8 | *(uint *)((param_1 + 3) - uVar1) >> (3 - uVar1) * 8;
    if (param_2 == uVar5) {
      bVar2 = false;
    }
    else {
      if (param_2 != uVar5 + 0x80) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        printf("[APUPD_ERROR]%32s() %05d: image file size(%d) isn\'t equal to size(%d) in file header.\r\n"
               ,"apupd_image_md5_check",0x379,param_2,uVar5);
        return 0xffffffff;
      }
      bVar2 = true;
    }
    __src = (void *)(param_1 + 4);
    memcpy(&local_20,__src,0x10);
    memcpy(__src,&DAT_007136c8,0x10);
    iVar3 = param_2 - 4;
    if (bVar2) {
      iVar3 = param_2 - 0x84;
    }
    apupd_md5_calc(__src,iVar3,&local_30,5);
    iVar3 = memcmp(&local_30,&local_20,0x10);
    if (iVar3 == 0) {
      memcpy(__src,&local_20,0x10);
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: md5 is not correct.\r\n";
    uVar4 = 0x390;
  }
  printf(__format,"apupd_image_md5_check",uVar4);
  return 0xffffffff;
}

