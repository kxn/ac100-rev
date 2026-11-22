// func cw_priv_ap_log_parse @ 005a5c08 size=760

undefined4 cw_priv_ap_log_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort *__s;
  uint uVar2;
  undefined4 uVar3;
  void *__s_00;
  undefined1 uVar6;
  undefined2 uVar4;
  ushort uVar5;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = *(ushort *)(param_1 + 6);
  __s = (ushort *)FUN_00408450(8,0x86);
  if (__s == (ushort *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_log_parse",0x89);
    }
  }
  else {
    memset(__s,0,8);
    uVar2 = cw_protocol_retrieve16(param_1);
    *__s = (ushort)uVar2;
    if (uVar2 < 0x21) {
      if (uVar2 == 0) {
        uVar1 = *(ushort *)(param_2 + 0xe);
      }
      else {
        __s_00 = (void *)FUN_00408450(uVar2 << 3,0x98);
        *(void **)(__s + 2) = __s_00;
        if (__s_00 == (void *)0x0) {
          if (capwap_err_switch == 0) {
            uVar5 = *__s;
          }
          else {
            iVar9 = is_target_debug_ap();
            if (iVar9 == 0) {
              uVar5 = *__s;
            }
            else {
              printf("[CW_ERROR]%32s():%4d malloc log info list failed\n","cw_priv_ap_log_parse",
                     0x9b);
              uVar5 = *__s;
            }
          }
LAB_005a5e0c:
          if ((uVar5 != 0) && (iVar9 = 0, *(int *)(__s + 2) != 0)) {
            while (iVar9 < (int)(uint)*__s) {
              iVar7 = iVar9 * 8;
              iVar9 = iVar9 + 1;
              if (*(int *)(*(int *)(__s + 2) + iVar7 + 4) != 0) {
                FUN_00407df0();
                *(undefined4 *)(*(int *)(__s + 2) + iVar7 + 4) = 0;
              }
            }
            FUN_00407df0();
            __s[2] = 0;
            __s[3] = 0;
          }
          FUN_00407df0(__s);
          return 0xffffffff;
        }
        iVar9 = 0;
        memset(__s_00,0,(uint)*__s << 3);
        while (iVar9 < (int)(uint)*__s) {
          iVar7 = *(int *)(__s + 2);
          iVar8 = iVar9 * 8;
          uVar6 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar7 + iVar8) = uVar6;
          iVar7 = *(int *)(__s + 2);
          uVar6 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar7 + iVar8 + 1) = uVar6;
          iVar7 = *(int *)(__s + 2);
          uVar4 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar7 + iVar8 + 2) = uVar4;
          iVar7 = *(int *)(__s + 2);
          uVar1 = *(ushort *)(iVar7 + iVar8 + 2);
          if (0x400 < uVar1) {
            if (capwap_err_switch == 0) {
              uVar5 = *__s;
            }
            else {
              iVar9 = is_target_debug_ap();
              if (iVar9 == 0) {
                uVar5 = *__s;
              }
              else {
                printf("[CW_ERROR]%32s():%4d log\'s len(%d) is too large\n","cw_priv_ap_log_parse",
                       0xa7,(uint)*(ushort *)(*(int *)(__s + 2) + iVar8 + 2));
                uVar5 = *__s;
              }
            }
            goto LAB_005a5e0c;
          }
          if (uVar1 == 0) {
            iVar9 = iVar9 + 1;
          }
          else {
            uVar3 = cw_protocol_retrieve_raw_bytes(param_1);
            *(undefined4 *)(iVar7 + iVar8 + 4) = uVar3;
            if (*(int *)(*(int *)(__s + 2) + iVar8 + 4) == 0) {
              uVar5 = *__s;
              goto LAB_005a5e0c;
            }
            iVar9 = iVar9 + 1;
          }
        }
        uVar1 = *(ushort *)(param_2 + 0xe);
      }
      *(ushort **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar5 == (uint)uVar1) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
        printf("[CW_ERROR]%32s():%4d log_num(%d) is too large\n","cw_priv_ap_log_parse",0x92,
               (uint)*__s);
      }
    }
  }
  return uVar3;
}

