// func apupd_callback_model_image_total_size_get @ 00641c4c size=776

int apupd_callback_model_image_total_size_get(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = -1;
  if (param_1 != 0) {
    iVar1 = FUN_004081b0(param_1 + 0x14);
    while (iVar6 = iVar1, iVar6 != 0) {
      iVar1 = FUN_00408680(iVar6);
      iVar7 = *(int *)(iVar6 + 0x24);
      iVar8 = *(int *)(iVar7 + 0x50);
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: tmp_update_wtp mac:%02x:%02x:%02x:%02x:%02x:%02x\n\r\n",
               "apupd_callback_model_image_total_size_get",0x20f,(uint)*(byte *)(iVar7 + 0x2e),
               (uint)*(byte *)(iVar7 + 0x2f),(uint)*(byte *)(iVar7 + 0x30),
               (uint)*(byte *)(iVar7 + 0x31),(uint)*(byte *)(iVar7 + 0x32),
               (uint)*(byte *)(iVar7 + 0x33));
      }
      if (iVar8 != 0) {
        iVar7 = *(int *)(iVar8 + 0x7ec);
        if (iVar7 == 2) {
          *param_2 = *param_2 + *(int *)(iVar8 + 0x1ac);
          if (g_apupd_debug == 0) {
            return 0;
          }
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            return 0;
          }
          uVar5 = *(undefined4 *)(iVar8 + 0x1ac);
          uVar4 = 0x213;
LAB_00641e88:
          printf("[APUPD_DEBUG]%32s() %05d: file_size:%d\n\r\n",
                 "apupd_callback_model_image_total_size_get",uVar4,uVar5);
          return 0;
        }
        if ((iVar7 == 1) || ((iVar7 == 3 && (*(int *)(*(int *)(iVar6 + 0x24) + 0x54) == 1)))) {
          iVar6 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar6 + 0x28) + 0x2c),
                               *(int *)(iVar6 + 0x24) + 0x58);
          if (iVar6 != 0) {
            *param_2 = *param_2 + *(int *)(iVar6 + 0x44);
            if (g_apupd_debug == 0) {
              return 0;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0;
            }
            uVar5 = *(undefined4 *)(iVar6 + 0x44);
            uVar4 = 0x220;
            goto LAB_00641e88;
          }
          if (g_apupd_error == 0) {
            return -1;
          }
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            return -1;
          }
          __format = "[APUPD_ERROR]%32s() %05d: get wtp list from hash failed\r\n";
          uVar4 = 0x21c;
          goto LAB_00641ec8;
        }
      }
      if (g_apupd_debug == 0) {
        piVar2 = *(int **)(iVar6 + 0x2c);
      }
      else {
        iVar7 = is_target_debug_ap();
        if (iVar7 == 0) {
          piVar2 = *(int **)(iVar6 + 0x2c);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: enter tmp_update_wtp->image_info\r\n",
                 "apupd_callback_model_image_total_size_get",0x225);
          piVar2 = *(int **)(iVar6 + 0x2c);
        }
      }
      if (piVar2 == (int *)0x0) {
        if (g_apupd_error == 0) {
          return -1;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return -1;
        }
        __format = "[APUPD_ERROR]%32s() %05d: image info is NULL\r\n";
        uVar4 = 0x228;
LAB_00641ec8:
        printf(__format,"apupd_callback_model_image_total_size_get",uVar4);
        return -1;
      }
      *param_2 = *param_2 + *piVar2;
      if ((g_apupd_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: file_size:%d\n\r\n",
               "apupd_callback_model_image_total_size_get",0x22c,**(undefined4 **)(iVar6 + 0x2c));
      }
    }
  }
  return iVar6;
}

