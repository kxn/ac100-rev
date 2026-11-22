// func cw_priv_roaming_trigger_parse @ 005bd644 size=952

undefined4 cw_priv_roaming_trigger_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  uint uVar2;
  undefined4 uVar3;
  void *__s_00;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0xc,0x99);
  if (__s == (undefined1 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_trigger_parse",0x9c);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar4 = cw_protocol_retrieve8(param_1);
  *__s = uVar4;
  uVar4 = cw_protocol_retrieve8(param_1);
  __s[1] = uVar4;
  uVar4 = cw_protocol_retrieve8(param_1);
  __s[2] = uVar4;
  uVar2 = cw_protocol_retrieve32(param_1);
  *(uint *)(__s + 4) = uVar2;
  if (uVar2 < 0xc9) {
    if (uVar2 != 0) {
      __s_00 = (void *)FUN_00408450(uVar2 << 4,0xb1);
      *(void **)(__s + 8) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_trigger_parse",0xb4);
        }
        goto LAB_005bd9a0;
      }
      uVar2 = 0;
      memset(__s_00,0,*(int *)(__s + 4) << 4);
      while (uVar2 < *(uint *)(__s + 4)) {
        iVar8 = uVar2 * 0x10;
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + iVar8,6);
        iVar6 = *(int *)(__s + 8);
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar8 + 6) = uVar4;
        iVar6 = *(int *)(__s + 8);
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar8 + 7) = uVar4;
        iVar6 = *(int *)(__s + 8);
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar8 + 8) = uVar4;
        iVar6 = *(int *)(__s + 8);
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar8 + 9) = uVar4;
        iVar6 = *(int *)(__s + 8);
        uVar5 = (uint)*(byte *)(iVar6 + iVar8 + 9);
        if (0xc < uVar5) {
          iVar6 = *(int *)(__s + 8);
LAB_005bd92c:
          uVar2 = 0;
          if (iVar6 != 0) {
            do {
              uVar5 = *(uint *)(__s + 4);
              while( true ) {
                if (uVar5 <= uVar2) {
                  FUN_00407df0();
                  goto LAB_005bd9a0;
                }
                iVar6 = uVar2 * 0x10;
                uVar2 = uVar2 + 1;
                if (*(int *)(*(int *)(__s + 8) + iVar6 + 0xc) == 0) break;
                FUN_00407df0();
                uVar5 = *(uint *)(__s + 4);
              }
            } while( true );
          }
          goto LAB_005bd9a0;
        }
        if (uVar5 == 0) {
          uVar2 = uVar2 + 1;
        }
        else {
          uVar3 = FUN_00408450(uVar5 * 9,200);
          *(undefined4 *)(iVar6 + iVar8 + 0xc) = uVar3;
          if (*(int *)(__s + 8) == 0) {
            if (capwap_err_switch == 0) {
              iVar6 = *(int *)(__s + 8);
            }
            else {
              iVar6 = is_target_debug_ap();
              if (iVar6 == 0) {
                iVar6 = *(int *)(__s + 8);
              }
              else {
                printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_trigger_parse",0xcb);
                iVar6 = *(int *)(__s + 8);
              }
            }
            goto LAB_005bd92c;
          }
          iVar6 = 0;
          while( true ) {
            iVar9 = iVar6 * 9;
            if ((int)(uint)*(byte *)(*(int *)(__s + 8) + iVar8 + 9) <= iVar6) break;
            iVar6 = iVar6 + 1;
            cw_protocol_retrieve_bytes(param_1,*(int *)(*(int *)(__s + 8) + iVar8 + 0xc) + iVar9,6);
            iVar7 = *(int *)(*(int *)(__s + 8) + iVar8 + 0xc);
            uVar4 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar7 + iVar9 + 6) = uVar4;
            iVar7 = *(int *)(*(int *)(__s + 8) + iVar8 + 0xc);
            uVar4 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar7 + iVar9 + 7) = uVar4;
            iVar7 = *(int *)(*(int *)(__s + 8) + iVar8 + 0xc);
            uVar4 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar7 + iVar9 + 8) = uVar4;
          }
          uVar2 = uVar2 + 1;
        }
      }
    }
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_roaming_trigger_parse",0xa9,
             *(undefined4 *)(__s + 4));
    }
LAB_005bd9a0:
    FUN_00407df0(__s);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

