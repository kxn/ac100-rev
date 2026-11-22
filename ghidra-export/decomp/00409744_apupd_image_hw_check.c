// func apupd_image_hw_check @ 00409744 size=540

undefined4 apupd_image_hw_check(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  char *pcVar5;
  uint *puVar6;
  char *__s2;
  uint uVar7;
  undefined1 auStack_190 [218];
  char acStack_b6 [65];
  char local_75 [77];
  
  memset(auStack_190,0,0x168);
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_image_hw_check",0x3ac);
    }
  }
  else {
    iVar1 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x58),param_1 + 0x1d8,auStack_190);
    if (iVar1 == 0) {
      uVar7 = 0;
      puVar6 = param_2;
      while (uVar7 < *param_2) {
        __s2 = (char *)((int)param_2 + uVar7 * 0x46 + 4);
        iVar1 = strcmp(acStack_b6,__s2);
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1 + 0xa0);
LAB_00409840:
          iVar3 = 0;
          iVar2 = param_1;
          if (iVar1 != 0) {
            do {
              if ((*(short *)((int)puVar6 + 0x46) == *(short *)(iVar2 + 0xa4)) &&
                 (*(short *)(puVar6 + 0x12) == *(short *)(iVar2 + 0xa6))) {
                return 0;
              }
              iVar3 = iVar3 + 1;
              iVar2 = iVar2 + 4;
            } while (iVar3 != iVar1);
          }
          if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            uVar4 = 0x3c8;
            __format = 
            "[APUPD_DEBUG]%32s() %05d: model name(%s) doesn\'t support the support-list ver(%d.%d)\r\n"
            ;
            pcVar5 = __s2;
            __s2 = (char *)(uint)*(ushort *)((int)puVar6 + 0x46);
            goto LAB_00409950;
          }
LAB_00409838:
          uVar7 = uVar7 + 1;
          puVar6 = (uint *)((int)puVar6 + 0x46);
        }
        else {
          if ((local_75[0] != '\0') && (iVar1 = strcmp(local_75,__s2), iVar1 == 0)) {
            iVar1 = *(int *)(param_1 + 0xa0);
            goto LAB_00409840;
          }
          if ((g_apupd_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00409838;
          uVar4 = 0x3ba;
          pcVar5 = (char *)(param_1 + 0x5c);
          __format = 
          "[APUPD_DEBUG]%32s() %05d: model name(%s) doesn\'t matches the support-list name(%s)\r\n";
LAB_00409950:
          uVar7 = uVar7 + 1;
          printf(__format,"apupd_image_hw_check",uVar4,pcVar5,__s2);
          puVar6 = (uint *)((int)puVar6 + 0x46);
        }
      }
    }
  }
  return 0xffffffff;
}

