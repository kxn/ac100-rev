// func cw_priv_sta_assoc_req_new_create @ 005c24fc size=816

int cw_priv_sta_assoc_req_new_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  void *__src;
  uint uVar6;
  int iVar7;
  char *__format;
  undefined4 uVar8;
  
  iVar1 = cw_protocol_clone(param_1,0x20);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sta_assoc_req_new_create",0x198
            );
    }
  }
  else {
    FUN_0051ad88(iVar1 + 0x14);
    iVar2 = FUN_004081b0(param_1 + 0x14);
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    else {
      do {
        iVar3 = cw_protocol_clone(iVar2,0x14);
        if (iVar3 == 0) {
          if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005c2644;
          __format = "[CW_ERROR]%32s():%4d failed to clone subelement\n";
          uVar8 = 0x1a6;
          goto LAB_005c275c;
        }
        *(undefined4 *)(iVar3 + 0x10) = 0;
        FUN_004086b0(iVar1 + 0x14,iVar3);
        if ((*(short *)(iVar2 + 0xe) != 0) && (iVar7 = *(int *)(iVar2 + 0x10), iVar7 != 0)) {
          if (*(short *)(iVar2 + 0xc) == 0) {
            puVar4 = (uint *)cw_protocol_clone(iVar7,8);
            *(uint **)(iVar3 + 0x10) = puVar4;
            if (puVar4 == (uint *)0x0) {
              if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005c2644;
              __format = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar8 = 0x1b6;
              goto LAB_005c275c;
            }
            iVar3 = *(int *)(iVar2 + 0x10);
            puVar4[1] = 0;
            if (*puVar4 != 0) {
              uVar6 = cw_protocol_clone(*(undefined4 *)(iVar3 + 4),*puVar4 & 0xffff);
              puVar4[1] = uVar6;
              if (uVar6 == 0) {
                if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005c2644;
                __format = "[CW_ERROR]%32s():%4d failed to clone subelement data\n";
                uVar8 = 0x1c1;
                goto LAB_005c275c;
              }
            }
          }
          else if (*(short *)(iVar2 + 0xc) == 1) {
            piVar5 = (int *)cw_protocol_clone(iVar7,0x10);
            *(int **)(iVar3 + 0x10) = piVar5;
            if (piVar5 == (int *)0x0) {
              if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005c2644;
              __format = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar8 = 0x1cc;
              goto LAB_005c275c;
            }
            if (*piVar5 != 0) {
              __src = (void *)cw_protocol_clone(*(int *)(iVar2 + 0x10) + 4,0xc);
              memcpy(piVar5 + 1,__src,0xc);
            }
          }
          else {
            iVar7 = cw_protocol_clone();
            *(int *)(iVar3 + 0x10) = iVar7;
            if (iVar7 == 0) {
              if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005c2644;
              __format = "[CW_ERROR]%32s():%4d failed to clone subelement data\n";
              uVar8 = 0x1e3;
              goto LAB_005c275c;
            }
          }
        }
        iVar2 = FUN_00408680(iVar2);
      } while (iVar2 != 0);
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    iVar2 = cw_protocol_msg_ele_create(0x8a,iVar2 + 0x11U & 0xffff,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
        uVar8 = 0x1f0;
LAB_005c275c:
        printf(__format,"cw_priv_sta_assoc_req_new_create",uVar8);
      }
LAB_005c2644:
      cw_sta_assoc_req_sub_ele_free(iVar1);
      iVar2 = 0;
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

