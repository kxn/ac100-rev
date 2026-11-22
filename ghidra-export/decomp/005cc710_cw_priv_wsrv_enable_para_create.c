// func cw_priv_wsrv_enable_para_create @ 005cc710 size=1416

int cw_priv_wsrv_enable_para_create(uint param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *__format;
  uint uVar8;
  
  uVar6 = param_1;
  iVar2 = cw_protocol_clone(param_1,0x14);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_wsrv_enable_para_create",0x180);
    return 0;
  }
  if (*(short *)(param_1 + 8) == 0) {
    uVar8 = iVar2 + 0x10U & 3;
    puVar1 = (uint *)((iVar2 + 0x10U) - uVar8);
    *puVar1 = *puVar1 & -1 << (4 - uVar8) * 8 | 0U >> uVar8 * 8;
  }
  else {
    uVar6 = *(uint *)(param_1 + 10);
    if (uVar6 == 0) {
      uVar8 = iVar2 + 0x10U & 3;
      puVar1 = (uint *)((iVar2 + 0x10U) - uVar8);
      *puVar1 = *puVar1 & -1 << (4 - uVar8) * 8 | 0U >> uVar8 * 8;
    }
    else {
      iVar5 = cw_protocol_clone();
      *(int *)(iVar2 + 10) = iVar5;
      if (iVar5 == 0) {
        if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(iVar2), iVar5 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone ssid_id\n","cw_priv_wsrv_enable_para_create",
                 0x18a);
        }
        goto LAB_005cc7b4;
      }
      *(undefined4 *)(iVar2 + 0x10) = 0;
    }
  }
  switch(*(undefined1 *)(param_1 + 0xf)) {
  case 0:
switchD_005cc7d4_caseD_0:
    uVar3 = cw_priv_wsrv_enable_para_len_get(iVar2);
    iVar5 = cw_protocol_msg_ele_create(0x94,uVar3,iVar2);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (capwap_err_switch == 0) {
      uVar6 = (uint)*(byte *)(param_1 + 0xf);
    }
    else {
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        uVar6 = (uint)*(byte *)(param_1 + 0xf);
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_wsrv_enable_para_create",0x200);
        uVar6 = (uint)*(byte *)(param_1 + 0xf);
      }
    }
    if (uVar6 == 2) {
      uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x4a);
LAB_005cca44:
      FUN_00407df0(uVar3);
    }
    else {
      uVar8 = 1;
      if ((uVar6 < 3) || (uVar8 = 4, uVar6 != 3)) {
        if (uVar6 != uVar8) {
          uVar3 = *(undefined4 *)(iVar2 + 10);
          goto LAB_005cc9e0;
        }
        uVar8 = iVar2 + 0x10U & 3;
        uVar7 = iVar2 + 0x13U & 3;
        uVar3 = *(undefined4 *)
                 (((*(int *)((iVar2 + 0x10U) - uVar8) << uVar8 * 8 |
                   uVar6 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar7 + 1) * 8 |
                  *(uint *)((iVar2 + 0x13U) - uVar7) >> (3 - uVar7) * 8) + 8);
        goto LAB_005cca44;
      }
    }
    FUN_00407df0(*(undefined4 *)(iVar2 + 0x10));
    uVar3 = *(undefined4 *)(iVar2 + 10);
LAB_005cc9e0:
    FUN_00407df0(uVar3);
    FUN_00407df0(iVar2);
    return 0;
  case 1:
  case 4:
    uVar8 = *(uint *)(param_1 + 0x10);
    if ((uVar8 == 0) || (*(int *)(uVar8 + 8) == 0)) {
      if (capwap_err_switch == 0) {
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          uVar8 = iVar2 + 10U & 3;
          uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                  uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
        }
        else {
          __format = "[CW_ERROR]%32s():%4d psk is null or psk\'s key is null\n";
          uVar3 = 0x19f;
LAB_005ccad4:
          printf(__format,"cw_priv_wsrv_enable_para_create",uVar3);
          uVar6 = *(uint *)(iVar2 + 10);
        }
      }
    }
    else {
      uVar6 = uVar8;
      iVar5 = cw_protocol_clone(uVar8,0xc);
      if (iVar5 != 0) {
        *(undefined4 *)(iVar5 + 8) = 0;
        *(int *)(iVar2 + 0x10) = iVar5;
        uVar6 = *(uint *)(uVar8 + 8);
        iVar4 = cw_protocol_clone(uVar6,*(undefined2 *)(uVar8 + 6));
        if (iVar4 == 0) {
          if (capwap_err_switch == 0) {
            uVar6 = *(uint *)(iVar2 + 10);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              uVar8 = iVar2 + 10U & 3;
              uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                      uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
            }
            else {
              printf("[CW_ERROR]%32s():%4d faield to clone key\n","cw_priv_wsrv_enable_para_create",
                     0x1b1);
              uVar6 = *(uint *)(iVar2 + 10);
            }
          }
          FUN_00407df0(uVar6);
          FUN_00407df0(iVar2);
          iVar2 = iVar5;
          goto LAB_005cc7b4;
        }
        *(int *)(iVar5 + 8) = iVar4;
        goto switchD_005cc7d4_caseD_0;
      }
      if (capwap_err_switch == 0) {
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 != 0) {
          __format = "[CW_ERROR]%32s():%4d failed to clone psk\n";
          uVar3 = 0x1a7;
          goto LAB_005ccad4;
        }
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
    }
    break;
  case 2:
    uVar8 = *(uint *)(param_1 + 0x10);
    if ((uVar8 == 0) || (*(int *)(uVar8 + 0x4a) == 0)) {
      if (capwap_err_switch == 0) {
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 != 0) {
          __format = "[CW_ERROR]%32s():%4d wpa is null or wpa\'s key is null\n";
          uVar3 = 0x1c1;
          goto LAB_005ccad4;
        }
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
    }
    else {
      uVar7 = uVar8;
      uVar6 = cw_protocol_clone(uVar8,0x4e);
      if (uVar6 == 0) {
        if (capwap_err_switch == 0) {
          uVar6 = iVar2 + 10U & 3;
          uVar6 = *(int *)((iVar2 + 10U) - uVar6) << uVar6 * 8 |
                  uVar7 & 0xffffffffU >> (4 - uVar6) * 8;
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 != 0) {
            __format = "[CW_ERROR]%32s():%4d failed to clone wpa\n";
            uVar3 = 0x1c9;
            goto LAB_005ccad4;
          }
          uVar6 = iVar2 + 10U & 3;
          uVar6 = *(int *)((iVar2 + 10U) - uVar6) << uVar6 * 8 |
                  uVar7 & 0xffffffffU >> (4 - uVar6) * 8;
        }
      }
      else {
        *(undefined4 *)(uVar6 + 0x4a) = 0;
        *(uint *)(iVar2 + 0x10) = uVar6;
        uVar7 = *(uint *)(uVar8 + 0x4a);
        iVar5 = cw_protocol_clone(uVar7,*(undefined2 *)(uVar8 + 0x48));
        if (iVar5 != 0) {
          *(int *)(uVar6 + 0x4a) = iVar5;
          goto switchD_005cc7d4_caseD_0;
        }
        if (capwap_err_switch == 0) {
          uVar8 = *(uint *)(iVar2 + 10);
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            uVar8 = iVar2 + 10U & 3;
            uVar8 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                    uVar7 & 0xffffffffU >> (4 - uVar8) * 8;
          }
          else {
            printf("[CW_ERROR]%32s():%4d failed to clone wpa\n","cw_priv_wsrv_enable_para_create",
                   0x1d3);
            uVar8 = *(uint *)(iVar2 + 10);
          }
        }
        FUN_00407df0(uVar8);
      }
    }
    break;
  case 3:
    uVar6 = *(uint *)(param_1 + 0x10);
    if (uVar6 == 0) {
      if (capwap_err_switch == 0) {
        uVar6 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar6) << uVar6 * 8;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 != 0) {
          __format = "[CW_ERROR]%32s():%4d wep is null\n";
          uVar3 = 0x1e2;
          goto LAB_005ccad4;
        }
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
    }
    else {
      iVar5 = cw_protocol_clone(uVar6,0x86);
      if (iVar5 != 0) {
        *(int *)(iVar2 + 0x10) = iVar5;
        goto switchD_005cc7d4_caseD_0;
      }
      if (capwap_err_switch == 0) {
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 != 0) {
          __format = "[CW_ERROR]%32s():%4d failed to clone wep\n";
          uVar3 = 0x1ea;
          goto LAB_005ccad4;
        }
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
    }
    break;
  default:
    if (capwap_err_switch == 0) {
      uVar6 = *(uint *)(iVar2 + 10);
    }
    else {
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        uVar8 = iVar2 + 10U & 3;
        uVar6 = *(int *)((iVar2 + 10U) - uVar8) << uVar8 * 8 |
                uVar6 & 0xffffffffU >> (4 - uVar8) * 8;
      }
      else {
        printf("[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n",
               "cw_priv_wsrv_enable_para_create",500,(uint)*(byte *)(param_1 + 0xf));
        uVar6 = *(uint *)(iVar2 + 10);
      }
    }
  }
  FUN_00407df0(uVar6);
LAB_005cc7b4:
  FUN_00407df0(iVar2);
  return 0;
}

