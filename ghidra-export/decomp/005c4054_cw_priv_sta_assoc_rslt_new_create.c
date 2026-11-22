// func cw_priv_sta_assoc_rslt_new_create @ 005c4054 size=896

int cw_priv_sta_assoc_rslt_new_create(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  char *__format;
  undefined4 uVar9;
  
  iVar3 = cw_protocol_clone(param_1,0x20);
  if (iVar3 == 0) {
    iVar4 = 0;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sta_assoc_rslt_new_create",
             0x19c);
    }
  }
  else {
    FUN_0051ad88(iVar3 + 0x14);
    for (iVar4 = FUN_004081b0(param_1 + 0x14); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
      iVar5 = cw_protocol_clone(iVar4,0x14);
      if (iVar5 == 0) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_005c42b8;
        __format = "[CW_ERROR]%32s():%4d failed to clone subelement\n";
        uVar9 = 0x1aa;
        goto LAB_005c41e0;
      }
      *(undefined4 *)(iVar5 + 0x10) = 0;
      FUN_004086b0(iVar3 + 0x14,iVar5);
      sVar1 = *(short *)(iVar4 + 0xc);
      sVar2 = *(short *)(iVar4 + 0xe);
      if (sVar1 == 1) {
        if ((sVar2 != 0) && (*(int *)(iVar4 + 0x10) != 0)) {
          puVar7 = (uint *)cw_protocol_clone(*(int *)(iVar4 + 0x10),8);
          *(uint **)(iVar5 + 0x10) = puVar7;
          if (puVar7 == (uint *)0x0) {
            if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
            goto LAB_005c42b8;
            __format = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar9 = 0x1cb;
            goto LAB_005c41e0;
          }
          iVar5 = *(int *)(iVar4 + 0x10);
          puVar7[1] = 0;
          if (*puVar7 != 0) {
            uVar8 = cw_protocol_clone(*(undefined4 *)(iVar5 + 4),*puVar7 & 0xffff);
            puVar7[1] = uVar8;
            if (uVar8 == 0) {
              if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
              goto LAB_005c42b8;
              __format = "[CW_ERROR]%32s():%4d failed to clone subelement data\n";
              uVar9 = 0x1d6;
              goto LAB_005c41e0;
            }
          }
        }
      }
      else if (sVar1 == 0) {
        if ((sVar2 != 0) && (*(int *)(iVar4 + 0x10) != 0)) {
          iVar6 = cw_protocol_clone(*(int *)(iVar4 + 0x10),2);
          *(int *)(iVar5 + 0x10) = iVar6;
          if (iVar6 == 0) {
            if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
            goto LAB_005c42b8;
            __format = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar9 = 0x1bc;
            goto LAB_005c41e0;
          }
        }
      }
      else if (sVar1 == 2) {
        if (((sVar2 != 0) && (capwap_warning_switch != 0)) &&
           (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[CW_WARNING]%32s():%4d Uncorrect sub ele len(%d)\n",
                 "cw_priv_sta_assoc_rslt_new_create",0x1df,(uint)*(ushort *)(iVar4 + 0xe));
        }
      }
      else if ((sVar2 != 0) && (*(int *)(iVar4 + 0x10) != 0)) {
        iVar6 = cw_protocol_clone();
        *(int *)(iVar5 + 0x10) = iVar6;
        if (iVar6 == 0) {
          if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005c42b8;
          __format = "[CW_ERROR]%32s():%4d failed to clone subelement data\n";
          uVar9 = 0x1ea;
          goto LAB_005c41e0;
        }
      }
    }
    iVar4 = cw_protocol_msg_ele_create(0x8b,*(int *)(iVar3 + 0x10) + 0x11U & 0xffff,iVar3);
    if (iVar4 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
        uVar9 = 0x1f6;
LAB_005c41e0:
        printf(__format,"cw_priv_sta_assoc_rslt_new_create",uVar9);
      }
LAB_005c42b8:
      cw_sta_assoc_rslt_sub_ele_free(iVar3);
      iVar4 = 0;
      FUN_00407df0(iVar3);
    }
  }
  return iVar4;
}

