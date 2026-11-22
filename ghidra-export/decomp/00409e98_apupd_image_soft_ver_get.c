// func apupd_image_soft_ver_get @ 00409e98 size=572

undefined4 apupd_image_soft_ver_get(int param_1,uint param_2,ushort *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *__format;
  int *piVar7;
  undefined4 uVar8;
  uint local_820;
  int local_81c;
  uint local_818;
  uint local_814;
  undefined1 auStack_810 [2048];
  
  local_81c = 0;
  local_820 = 0;
  memset(auStack_810,0,0x800);
  local_818 = 0;
  local_814 = 0;
  if (((param_1 == 0) || (param_3 == (ushort *)0x0)) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar8 = 0x4dd;
  }
  else if (param_2 < 0x1814) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: size of buffer isn\'t enough.\r\n";
    uVar8 = 0x4e4;
  }
  else {
    memcpy(auStack_810,(void *)(param_1 + 0x1014),0x800);
    piVar7 = &local_81c;
    iVar6 = apupd_ptn_infor_get(auStack_810,"soft-version",piVar7,&local_820);
    if (((iVar6 != -1) && (local_81c != -1)) && (0xb < local_820)) {
      param_1 = param_1 + local_81c;
      uVar3 = param_1 + 4U & 3;
      iVar6 = *(int *)((param_1 + 4U) - uVar3);
      uVar8 = *(undefined4 *)(param_1 + 8);
      bVar1 = *(byte *)(param_1 + 2);
      bVar2 = *(byte *)(param_1 + 3);
      uVar4 = param_1 + 7U & 3;
      uVar5 = *(uint *)((param_1 + 7U) - uVar4);
      *param_3 = (ushort)*(byte *)(param_1 + 1);
      param_3[1] = (ushort)bVar1;
      param_3[2] = (ushort)bVar2;
      sprintf((char *)&local_818,"%08x",
              (iVar6 << uVar3 * 8 | (uint)piVar7 & 0xffffffffU >> (4 - uVar3) * 8) &
              -1 << (uVar4 + 1) * 8 | uVar5 >> (3 - uVar4) * 8);
      *(undefined4 *)(param_3 + 6) = uVar8;
      *(uint *)(param_3 + 4) =
           ((local_818 >> 0x18) * 1000 + (local_818 >> 0x10 & 0xff) * 100 +
            (local_818 >> 8 & 0xff) * 10 + ((local_818 & 0xff) - 0xd050)) * 0x10000 +
           ((local_814 >> 0x18) * 10 + (local_814 >> 0x10 & 0xff) + -0x210) * 0x100 +
           (local_814 >> 8 & 0xff) * 10 + (local_814 & 0xff) + -0x210;
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get software version pattern information failed.\r\n";
    uVar8 = 0x4ed;
  }
  printf(__format,"apupd_image_soft_ver_get",uVar8);
  return 0xffffffff;
}

