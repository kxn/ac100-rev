// func cw_priv_sta_assoc_req_new_parse @ 005c282c size=1456

undefined4 cw_priv_sta_assoc_req_new_parse(int param_1,int param_2)

{
  byte *__s;
  uint uVar1;
  byte bVar6;
  void *__s_00;
  undefined2 uVar5;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined1 uVar7;
  char *pcVar8;
  short sVar9;
  undefined4 uVar10;
  uint *puVar11;
  int iVar12;
  
  __s = (byte *)FUN_00408450(0x20,0x8c);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_assoc_req_new_parse",0x8f);
    return 0xffffffff;
  }
  memset(__s,0,0x20);
  FUN_0051ad88(__s + 0x14);
  uVar1 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar1;
  if (uVar1 < 0x20) {
    uVar1 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar1;
    if (uVar1 < 0x11) {
      cw_protocol_retrieve_bytes(param_1,__s + 2,6);
      uVar10 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 8) = uVar10;
      bVar6 = cw_protocol_retrieve8(param_1);
      __s[0xc] = bVar6;
      iVar4 = cw_protocol_retrieve32(param_1);
      *(int *)(__s + 0x10) = iVar4;
      if ((uint)*(ushort *)(param_2 + 0xe) == iVar4 + 0x11U) {
        iVar4 = iVar4 + (uint)*(ushort *)(param_1 + 6);
LAB_005c29dc:
        do {
          uVar1 = (uint)*(ushort *)(param_1 + 6);
LAB_005c29e0:
          if (iVar4 <= (int)uVar1) {
            *(byte **)(param_2 + 0x10) = __s;
            return 0;
          }
          __s_00 = (void *)FUN_00408450(0x14,0xb4);
          if (__s_00 == (void *)0x0) {
            if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
              pcVar8 = "[CW_ERROR]%32s():%4d out of memory\n";
              uVar10 = 0xb7;
LAB_005c2c40:
              printf(pcVar8,"cw_priv_sta_assoc_req_new_parse",uVar10);
            }
            break;
          }
          memset(__s_00,0,0x14);
          FUN_004086b0(__s + 0x14,__s_00);
          if ((int)(iVar4 - (uint)*(ushort *)(param_1 + 6)) < 4) {
            if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
              pcVar8 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
              uVar10 = 0xc0;
              goto LAB_005c2c40;
            }
            break;
          }
          uVar5 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)((int)__s_00 + 0xc) = uVar5;
          iVar2 = cw_protocol_retrieve16(param_1);
          *(short *)((int)__s_00 + 0xe) = (short)iVar2;
          if ((0x3ff < iVar2 - 1U) || ((int)(iVar4 - (uint)*(ushort *)(param_1 + 6)) < iVar2)) {
            if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(__s), iVar4 == 0)) break;
            uVar1 = (uint)*(ushort *)((int)__s_00 + 0xe);
            pcVar8 = "[CW_ERROR]%32s():%4d length of subelement(%d) is wrong\n";
            uVar10 = 0xcc;
            goto LAB_005c2adc;
          }
          if (*(short *)((int)__s_00 + 0xc) == 0) {
            pvVar3 = (void *)FUN_00408450(8,0xd7);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 != (void *)0x0) {
              memset(pvVar3,0,8);
              puVar11 = *(uint **)((int)__s_00 + 0x10);
              *puVar11 = (uint)*(ushort *)((int)__s_00 + 0xe);
              uVar1 = cw_protocol_retrieve_raw_bytes(param_1);
              puVar11[1] = uVar1;
              goto LAB_005c29dc;
            }
            if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
              pcVar8 = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar10 = 0xda;
              goto LAB_005c2c40;
            }
            break;
          }
          if (*(short *)((int)__s_00 + 0xc) == 1) {
            pvVar3 = (void *)FUN_00408450(iVar2,0xea);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
                pcVar8 = "[CW_ERROR]%32s():%4d Malloc failed\n";
                uVar10 = 0xed;
                goto LAB_005c2c40;
              }
              break;
            }
            memset(pvVar3,0,(uint)*(ushort *)((int)__s_00 + 0xe));
            puVar11 = *(uint **)((int)__s_00 + 0x10);
            *puVar11 = (uint)*(ushort *)((int)__s_00 + 0xe);
            if ((capwap_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_WARNING]%32s():%4d sub ele len:%d\n","cw_priv_sta_assoc_req_new_parse",
                     0xf4,(uint)*(ushort *)((int)__s_00 + 0xe));
            }
            cw_protocol_retrieve_bytes(param_1,puVar11 + 1,6);
            iVar2 = cw_protocol_retrieve8(param_1);
            *(char *)((int)puVar11 + 10) = (char)iVar2;
            if (iVar2 != 0) {
              uVar1 = FUN_00408450(iVar2 * 0xc,0xf9);
              puVar11[3] = uVar1;
              if (uVar1 == 0) {
                if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
                  pcVar8 = "[CW_ERROR]%32s():%4d Malloc failed\n";
                  uVar10 = 0xfc;
                  goto LAB_005c2c40;
                }
                break;
              }
            }
            for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)((int)puVar11 + 10); iVar2 = iVar2 + 1) {
              uVar1 = puVar11[3];
              iVar12 = iVar2 * 0xc;
              uVar7 = cw_protocol_retrieve8(param_1);
              *(undefined1 *)(uVar1 + iVar12) = uVar7;
              uVar1 = puVar11[3];
              uVar7 = cw_protocol_retrieve8(param_1);
              *(undefined1 *)(uVar1 + iVar12 + 1) = uVar7;
              cw_protocol_retrieve_bytes(param_1,puVar11[3] + iVar12 + 2,6);
              uVar1 = puVar11[3];
              uVar10 = cw_protocol_retrieve32(param_1);
              *(undefined4 *)(uVar1 + iVar12 + 8) = uVar10;
            }
            uVar1 = (uint)*(ushort *)(param_1 + 6);
            goto LAB_005c29e0;
          }
          if (capwap_warning_switch == 0) {
            sVar9 = *(short *)((int)__s_00 + 0xe);
          }
          else {
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              sVar9 = *(short *)((int)__s_00 + 0xe);
            }
            else {
              printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                     "cw_priv_sta_assoc_req_new_parse",0x10a,(uint)*(ushort *)((int)__s_00 + 0xc));
              sVar9 = *(short *)((int)__s_00 + 0xe);
            }
          }
          if (sVar9 == 0) {
            uVar1 = (uint)*(ushort *)(param_1 + 6);
            goto LAB_005c29e0;
          }
          iVar2 = cw_protocol_retrieve_raw_bytes(param_1);
          *(int *)((int)__s_00 + 0x10) = iVar2;
        } while (iVar2 != 0);
      }
      goto LAB_005c28b4;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(__s), iVar4 == 0))
    goto LAB_005c28b4;
    uVar1 = (uint)__s[1];
    pcVar8 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar10 = 0xa0;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(__s), iVar4 == 0))
    goto LAB_005c28b4;
    uVar1 = (uint)*__s;
    pcVar8 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar10 = 0x98;
  }
LAB_005c2adc:
  printf(pcVar8,"cw_priv_sta_assoc_req_new_parse",uVar10,uVar1);
LAB_005c28b4:
  cw_sta_assoc_req_sub_ele_free(__s);
  FUN_00407df0(__s);
  return 0xffffffff;
}

