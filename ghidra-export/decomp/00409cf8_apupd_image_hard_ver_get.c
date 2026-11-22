// func apupd_image_hard_ver_get @ 00409cf8 size=416

undefined4 apupd_image_hard_ver_get(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint local_a18;
  int local_a14;
  undefined1 auStack_a10 [512];
  undefined1 auStack_810 [2048];
  
  local_a14 = 0;
  local_a18 = 0;
  memset(auStack_810,0,0x800);
  memset(auStack_a10,0,0x200);
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (undefined4 *)0x0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0x579;
  }
  else if (param_2 < 0x1814) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: size of buffer isn\'t enough.\r\n";
    uVar2 = 0x580;
  }
  else {
    *param_3 = 0;
    memcpy(auStack_810,(void *)(param_1 + 0x1014),0x800);
    iVar1 = apupd_ptn_infor_get(auStack_810,"support-list",&local_a14,&local_a18);
    if (((iVar1 != -1) && (local_a14 != -1)) && (local_a18 < 0x201)) {
      memcpy(auStack_a10,(void *)(param_1 + local_a14),local_a18);
      uVar2 = apupd_image_hard_ver_get_from_str(auStack_a10,param_3);
      return uVar2;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get support list pattern information failed.\r\n";
    uVar2 = 0x58c;
  }
  printf(__format,"apupd_image_hard_ver_get",uVar2);
  return 0xffffffff;
}

