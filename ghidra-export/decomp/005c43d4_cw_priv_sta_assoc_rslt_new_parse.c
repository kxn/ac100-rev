// func cw_priv_sta_assoc_rslt_new_parse @ 005c43d4 size=1412

undefined4 cw_priv_sta_assoc_rslt_new_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  byte bVar8;
  void *__s_00;
  undefined2 uVar7;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  void *__s_01;
  char *pcVar9;
  short sVar10;
  undefined4 uVar11;
  undefined2 *puVar12;
  uint *puVar13;
  
  __s = (byte *)FUN_00408450(0x20,0x8c);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_assoc_rslt_new_parse",0x8f);
    return 0xffffffff;
  }
  memset(__s,0,0x20);
  FUN_0051ad88(__s + 0x14);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar3;
    if (uVar3 < 0x11) {
      cw_protocol_retrieve_bytes(param_1,__s + 2,6);
      uVar11 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 8) = uVar11;
      bVar8 = cw_protocol_retrieve8(param_1);
      __s[0xc] = bVar8;
      iVar6 = cw_protocol_retrieve32(param_1);
      *(int *)(__s + 0x10) = iVar6;
      if ((uint)*(ushort *)(param_2 + 0xe) == iVar6 + 0x11U) {
        iVar6 = iVar6 + (uint)*(ushort *)(param_1 + 6);
LAB_005c4590:
        do {
          uVar3 = (uint)*(ushort *)(param_1 + 6);
LAB_005c4594:
          if (iVar6 <= (int)uVar3) {
            *(byte **)(param_2 + 0x10) = __s;
            return 0;
          }
          __s_00 = (void *)FUN_00408450(0x14,0xb4);
          if (__s_00 == (void *)0x0) {
            if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(__s), iVar6 != 0)) {
              pcVar9 = "[CW_ERROR]%32s():%4d out of memory\n";
              uVar11 = 0xb7;
LAB_005c4818:
              printf(pcVar9,"cw_priv_sta_assoc_rslt_new_parse",uVar11);
            }
            break;
          }
          memset(__s_00,0,0x14);
          FUN_004086b0(__s + 0x14,__s_00);
          if ((int)(iVar6 - (uint)*(ushort *)(param_1 + 6)) < 4) {
            if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(__s), iVar6 != 0)) {
              pcVar9 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
              uVar11 = 0xc0;
              goto LAB_005c4818;
            }
            break;
          }
          uVar7 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)((int)__s_00 + 0xc) = uVar7;
          iVar4 = cw_protocol_retrieve16(param_1);
          sVar10 = *(short *)((int)__s_00 + 0xc);
          *(short *)((int)__s_00 + 0xe) = (short)iVar4;
          if (((0x3ff < iVar4 - 1U) || ((int)(iVar6 - (uint)*(ushort *)(param_1 + 6)) < iVar4)) &&
             (sVar10 != 2)) {
            if ((capwap_err_switch == 0) || (iVar6 = is_target_debug_ap(__s), iVar6 == 0)) break;
            uVar3 = (uint)*(ushort *)((int)__s_00 + 0xe);
            pcVar9 = "[CW_ERROR]%32s():%4d length of subelement(%d) is wrong\n";
            uVar11 = 0xce;
            goto LAB_005c4690;
          }
          if (sVar10 == 1) {
            if (iVar4 == 0) {
              if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(__s), iVar6 != 0)) {
                uVar1 = *(ushort *)((int)__s_00 + 0xc);
                uVar2 = *(ushort *)((int)__s_00 + 0xe);
                uVar11 = 0xe9;
LAB_005c48d0:
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_sta_assoc_rslt_new_parse",uVar11,(uint)uVar2,(uint)uVar1);
              }
              break;
            }
            __s_01 = (void *)FUN_00408450(8,0xec);
            *(void **)((int)__s_00 + 0x10) = __s_01;
            if (__s_01 != (void *)0x0) {
              memset(__s_01,0,8);
              puVar13 = *(uint **)((int)__s_00 + 0x10);
              *puVar13 = (uint)*(ushort *)((int)__s_00 + 0xe);
              uVar3 = cw_protocol_retrieve_raw_bytes(param_1);
              puVar13[1] = uVar3;
              goto LAB_005c4590;
            }
            if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(__s), iVar6 != 0)) {
              pcVar9 = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar11 = 0xef;
              goto LAB_005c4818;
            }
            break;
          }
          if (sVar10 == 0) {
            if (iVar4 != 2) {
              if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(__s), iVar6 != 0)) {
                uVar1 = *(ushort *)((int)__s_00 + 0xc);
                uVar2 = *(ushort *)((int)__s_00 + 0xe);
                uVar11 = 0xd7;
                goto LAB_005c48d0;
              }
              break;
            }
            puVar5 = (undefined1 *)FUN_00408450(2,0xda);
            *(undefined1 **)((int)__s_00 + 0x10) = puVar5;
            if (puVar5 != (undefined1 *)0x0) {
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar12 = *(undefined2 **)((int)__s_00 + 0x10);
              uVar7 = cw_protocol_retrieve16(param_1);
              *puVar12 = uVar7;
              goto LAB_005c4590;
            }
            if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(__s), iVar6 != 0)) {
              pcVar9 = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar11 = 0xdd;
              goto LAB_005c4818;
            }
            break;
          }
          if (sVar10 == 2) {
            if (iVar4 == 0) {
              uVar3 = (uint)*(ushort *)(param_1 + 6);
            }
            else if (capwap_warning_switch == 0) {
              uVar3 = (uint)*(ushort *)(param_1 + 6);
            }
            else {
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                uVar3 = (uint)*(ushort *)(param_1 + 6);
              }
              else {
                printf("[CW_WARNING]%32s():%4d Uncorrect sub ele len(%d)\n",
                       "cw_priv_sta_assoc_rslt_new_parse",0xfc,(uint)*(ushort *)((int)__s_00 + 0xe))
                ;
                uVar3 = (uint)*(ushort *)(param_1 + 6);
              }
            }
            goto LAB_005c4594;
          }
          if (capwap_warning_switch == 0) {
            sVar10 = *(short *)((int)__s_00 + 0xe);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              sVar10 = *(short *)((int)__s_00 + 0xe);
            }
            else {
              printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                     "cw_priv_sta_assoc_rslt_new_parse",0x100,(uint)*(ushort *)((int)__s_00 + 0xc));
              sVar10 = *(short *)((int)__s_00 + 0xe);
            }
          }
          if (sVar10 == 0) {
            uVar3 = (uint)*(ushort *)(param_1 + 6);
            goto LAB_005c4594;
          }
          iVar4 = cw_protocol_retrieve_raw_bytes(param_1);
          *(int *)((int)__s_00 + 0x10) = iVar4;
        } while (iVar4 != 0);
      }
      goto LAB_005c445c;
    }
    if ((capwap_err_switch == 0) || (iVar6 = is_target_debug_ap(__s), iVar6 == 0))
    goto LAB_005c445c;
    uVar3 = (uint)__s[1];
    pcVar9 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar11 = 0xa0;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar6 = is_target_debug_ap(__s), iVar6 == 0))
    goto LAB_005c445c;
    uVar3 = (uint)*__s;
    pcVar9 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar11 = 0x98;
  }
LAB_005c4690:
  printf(pcVar9,"cw_priv_sta_assoc_rslt_new_parse",uVar11,uVar3);
LAB_005c445c:
  cw_sta_assoc_rslt_sub_ele_free(__s);
  FUN_00407df0(__s);
  return 0xffffffff;
}

