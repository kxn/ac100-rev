// func cw_priv_roaming_calculate_result_parse @ 005bc118 size=1108

undefined4 cw_priv_roaming_calculate_result_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar6;
  undefined4 uVar2;
  uint uVar3;
  void *__s_00;
  int iVar4;
  int iVar5;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0x14,0xb1);
  if (__s == (undefined1 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_calculate_result_parse",0xb4);
    return 0xffffffff;
  }
  memset(__s,0,0x14);
  uVar6 = cw_protocol_retrieve8(param_1);
  *__s = uVar6;
  uVar6 = cw_protocol_retrieve8(param_1);
  __s[1] = uVar6;
  uVar2 = cw_protocol_retrieve32(param_1);
  *(undefined4 *)(__s + 4) = uVar2;
  uVar3 = cw_protocol_retrieve32(param_1);
  *(uint *)(__s + 8) = uVar3;
  if ((*(uint *)(__s + 4) < 0x81) && (uVar3 < 0x81)) {
    if (uVar3 == 0) {
      iVar5 = *(int *)(__s + 4);
    }
    else {
      uVar7 = 0;
      iVar5 = FUN_00408450(uVar3 * 6,0xcc);
      *(int *)(__s + 0xc) = iVar5;
      if (iVar5 == 0) {
        if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_calculate_result_parse",
                 0xcf);
        }
        goto LAB_005bc504;
      }
      for (; uVar7 < *(uint *)(__s + 8); uVar7 = uVar7 + 1) {
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 0xc) + uVar7 * 6,6);
      }
      iVar5 = *(int *)(__s + 4);
    }
    if (iVar5 != 0) {
      __s_00 = (void *)FUN_00408450(iVar5 * 0x1c,0xde);
      *(void **)(__s + 0x10) = __s_00;
      if (__s_00 == (void *)0x0) {
        if (capwap_err_switch == 0) {
          iVar5 = *(int *)(__s + 0xc);
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            iVar5 = *(int *)(__s + 0xc);
          }
          else {
            printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_calculate_result_parse",
                   0xe1);
LAB_005bc47c:
            iVar5 = *(int *)(__s + 0xc);
          }
        }
LAB_005bc480:
        if (iVar5 == 0) {
          iVar5 = *(int *)(__s + 0x10);
        }
        else {
          FUN_00407df0();
          iVar5 = *(int *)(__s + 0x10);
        }
        uVar3 = 0;
        if (iVar5 != 0) {
          do {
            uVar7 = *(uint *)(__s + 4);
            while( true ) {
              if (uVar7 <= uVar3) {
                FUN_00407df0();
                goto LAB_005bc504;
              }
              iVar5 = uVar3 * 0x1c;
              uVar3 = uVar3 + 1;
              if (*(int *)(*(int *)(__s + 0x10) + iVar5 + 0x18) == 0) break;
              FUN_00407df0();
              uVar7 = *(uint *)(__s + 4);
            }
          } while( true );
        }
        goto LAB_005bc504;
      }
      uVar3 = 0;
      memset(__s_00,0,*(int *)(__s + 4) * 0x1c);
      while (uVar3 < *(uint *)(__s + 4)) {
        iVar8 = uVar3 * 0x1c;
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 0x10) + iVar8,6);
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 0x10) + iVar8 + 6,0x10);
        iVar5 = *(int *)(__s + 0x10);
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar5 + iVar8 + 0x16) = uVar6;
        iVar5 = *(int *)(__s + 0x10);
        uVar7 = (uint)*(byte *)(iVar5 + iVar8 + 0x16);
        if (6 < uVar7) {
          iVar5 = *(int *)(__s + 0xc);
          goto LAB_005bc480;
        }
        if (uVar7 == 0) {
          uVar3 = uVar3 + 1;
        }
        else {
          uVar2 = FUN_00408450(uVar7 * 10,0xf2);
          *(undefined4 *)(iVar5 + iVar8 + 0x18) = uVar2;
          iVar5 = 0;
          if (*(int *)(*(int *)(__s + 0x10) + iVar8 + 0x18) == 0) goto LAB_005bc47c;
          iVar4 = *(int *)(__s + 0x10);
          while( true ) {
            iVar9 = iVar5 * 10;
            if ((int)(uint)*(byte *)(iVar4 + iVar8 + 0x16) <= iVar5) break;
            iVar4 = *(int *)(iVar4 + iVar8 + 0x18);
            uVar6 = cw_protocol_retrieve8(param_1);
            iVar5 = iVar5 + 1;
            *(undefined1 *)(iVar4 + iVar9) = uVar6;
            iVar4 = *(int *)(*(int *)(__s + 0x10) + iVar8 + 0x18);
            uVar6 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar4 + iVar9 + 1) = uVar6;
            iVar4 = *(int *)(*(int *)(__s + 0x10) + iVar8 + 0x18);
            uVar6 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar4 + iVar9 + 2) = uVar6;
            cw_protocol_retrieve_bytes
                      (param_1,*(int *)(*(int *)(__s + 0x10) + iVar8 + 0x18) + iVar9 + 3,6);
            iVar4 = *(int *)(*(int *)(__s + 0x10) + iVar8 + 0x18);
            uVar6 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar4 + iVar9 + 9) = uVar6;
            iVar4 = *(int *)(__s + 0x10);
          }
          uVar3 = uVar3 + 1;
        }
      }
    }
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u:%u]\n",
             "cw_priv_roaming_calculate_result_parse",0xc4,*(undefined4 *)(__s + 4),
             *(undefined4 *)(__s + 8));
    }
LAB_005bc504:
    FUN_00407df0(__s);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

