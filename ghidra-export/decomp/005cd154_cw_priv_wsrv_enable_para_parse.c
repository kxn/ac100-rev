// func cw_priv_wsrv_enable_para_parse @ 005cd154 size=1544

undefined4 cw_priv_wsrv_enable_para_parse(uint param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  byte *__s;
  uint uVar3;
  undefined2 uVar6;
  byte bVar7;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar8;
  undefined1 *puVar9;
  char *__format;
  int iVar10;
  undefined1 *puVar11;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x14,0x66);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_enable_para_parse",0x69);
    return 0xffffffff;
  }
  memset(__s,0,0x14);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar3;
    if (uVar3 < 0x11) {
      uVar6 = cw_protocol_retrieve16(param_1);
      __s[3] = (byte)uVar6;
      __s[2] = (byte)((ushort)uVar6 >> 8);
      uVar6 = cw_protocol_retrieve16(param_1);
      __s[5] = (byte)uVar6;
      __s[4] = (byte)((ushort)uVar6 >> 8);
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[6] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[7] = bVar7;
      iVar4 = cw_protocol_retrieve16(param_1);
      __s[9] = (byte)iVar4;
      __s[8] = (byte)((uint)iVar4 >> 8);
      if (iVar4 != 0) {
        iVar4 = cw_protocol_retrieve_raw_bytes(param_1,iVar4);
        *(int *)(__s + 10) = iVar4;
        if (iVar4 == 0) {
          if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to read ssid_id\n","cw_priv_wsrv_enable_para_parse",
                   0x89);
          }
          goto LAB_005cd290;
        }
      }
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[0xe] = bVar7;
      uVar3 = param_1;
      uVar5 = cw_protocol_retrieve8(param_1);
      __s[0xf] = (byte)uVar5;
      switch(uVar5) {
      case 0:
        goto switchD_005cd2b4_caseD_0;
      case 1:
      case 4:
        uVar3 = 0xc;
        puVar9 = (undefined1 *)FUN_00408450(0xc,0x9b);
        if (puVar9 == (undefined1 *)0x0) {
          if (capwap_err_switch == 0) {
            uVar2 = (uint)(__s + 10) & 3;
            puVar9 = (undefined1 *)
                     (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                     uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              uVar2 = (uint)(__s + 10) & 3;
              puVar9 = (undefined1 *)
                       (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                       uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
            }
            else {
              uVar5 = 0x9e;
LAB_005cd680:
              printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_enable_para_parse",uVar5);
              puVar9 = *(undefined1 **)(__s + 10);
            }
          }
        }
        else {
          memset(puVar9,0,0xc);
          uVar8 = cw_protocol_retrieve8(param_1);
          *puVar9 = uVar8;
          uVar8 = cw_protocol_retrieve8(param_1);
          puVar9[1] = uVar8;
          uVar5 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(puVar9 + 2) = uVar5;
          uVar5 = cw_protocol_retrieve16(param_1);
          puVar9[7] = (char)uVar5;
          puVar9[6] = (char)((uint)uVar5 >> 8);
          iVar4 = cw_protocol_retrieve_raw_bytes(param_1,uVar5);
          *(int *)(puVar9 + 8) = iVar4;
          if (iVar4 != 0) {
LAB_005cd394:
            *(undefined1 **)(__s + 0x10) = puVar9;
switchD_005cd2b4_caseD_0:
            *(byte **)(param_2 + 0x10) = __s;
            if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
              return 0xffffffff;
            }
            return 0;
          }
          if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_enable_para_parse",0xab);
          }
          FUN_00407df0(puVar9);
          puVar9 = *(undefined1 **)(__s + 10);
        }
        break;
      case 2:
        uVar3 = 0x4e;
        puVar9 = (undefined1 *)FUN_00408450(0x4e,0xb6);
        if (puVar9 == (undefined1 *)0x0) {
          if (capwap_err_switch == 0) {
            uVar2 = (uint)(__s + 10) & 3;
            puVar9 = (undefined1 *)
                     (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                     uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 != 0) {
              uVar5 = 0xb9;
              goto LAB_005cd680;
            }
            uVar2 = (uint)(__s + 10) & 3;
            puVar9 = (undefined1 *)
                     (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                     uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
          }
        }
        else {
          memset(puVar9,0,0x4e);
          uVar8 = cw_protocol_retrieve8(param_1);
          *puVar9 = uVar8;
          uVar8 = cw_protocol_retrieve8(param_1);
          puVar9[1] = uVar8;
          uVar5 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(puVar9 + 2) = uVar5;
          cw_protocol_retrieve_ip(param_1,puVar9 + 6);
          cw_protocol_retrieve_ip(param_1,puVar9 + 0x1a);
          cw_protocol_retrieve_ip(param_1,puVar9 + 0x2e);
          uVar6 = cw_protocol_retrieve16(param_1);
          puVar9[0x43] = (char)uVar6;
          puVar9[0x42] = (char)((ushort)uVar6 >> 8);
          uVar6 = cw_protocol_retrieve16(param_1);
          puVar9[0x45] = (char)uVar6;
          puVar9[0x44] = (char)((ushort)uVar6 >> 8);
          uVar6 = cw_protocol_retrieve16(param_1);
          puVar9[0x47] = (char)uVar6;
          puVar9[0x46] = (char)((ushort)uVar6 >> 8);
          uVar5 = cw_protocol_retrieve16(param_1);
          puVar9[0x49] = (char)uVar5;
          puVar9[0x48] = (char)((uint)uVar5 >> 8);
          uVar3 = param_1;
          iVar4 = cw_protocol_retrieve_raw_bytes(param_1,uVar5);
          *(int *)(puVar9 + 0x4a) = iVar4;
          if (iVar4 != 0) goto LAB_005cd394;
          if (capwap_err_switch == 0) {
            uVar3 = *(uint *)(__s + 10);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              uVar2 = (uint)(__s + 10) & 3;
              uVar3 = *(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                      uVar3 & 0xffffffffU >> (4 - uVar2) * 8;
            }
            else {
              printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_enable_para_parse",0xcf);
              uVar3 = *(uint *)(__s + 10);
            }
          }
          FUN_00407df0(uVar3);
        }
        break;
      case 3:
        uVar3 = 0x86;
        puVar9 = (undefined1 *)FUN_00408450(0x86,0xda);
        if (puVar9 != (undefined1 *)0x0) {
          uVar8 = cw_protocol_retrieve8(param_1);
          *puVar9 = uVar8;
          iVar4 = 0;
          uVar8 = cw_protocol_retrieve8(param_1);
          puVar9[1] = uVar8;
          puVar11 = puVar9;
          do {
            uVar8 = cw_protocol_retrieve8(param_1);
            iVar10 = iVar4 * 0x21;
            puVar11[2] = uVar8;
            iVar4 = iVar4 + 1;
            puVar11 = puVar11 + 0x21;
            cw_protocol_retrieve_bytes(param_1,puVar9 + iVar10 + 3,0x20);
          } while (iVar4 != 4);
          *(undefined1 **)(__s + 0x10) = puVar9;
          goto switchD_005cd2b4_caseD_0;
        }
        if (capwap_err_switch == 0) {
          uVar2 = (uint)(__s + 10) & 3;
          puVar9 = (undefined1 *)
                   (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                   uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
        }
        else {
          iVar4 = is_target_debug_ap();
          if (iVar4 != 0) {
            uVar5 = 0xde;
            goto LAB_005cd680;
          }
          uVar2 = (uint)(__s + 10) & 3;
          puVar9 = (undefined1 *)
                   (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                   uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
        }
        break;
      default:
        if (capwap_err_switch == 0) {
          puVar9 = *(undefined1 **)(__s + 10);
        }
        else {
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            uVar2 = (uint)(__s + 10) & 3;
            puVar9 = (undefined1 *)
                     (*(int *)(__s + 10 + -uVar2) << uVar2 * 8 |
                     uVar3 & 0xffffffffU >> (4 - uVar2) * 8);
          }
          else {
            printf("[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n",
                   "cw_priv_wsrv_enable_para_parse",0xef,(uint)__s[0xf]);
            puVar9 = *(undefined1 **)(__s + 10);
          }
        }
      }
      FUN_00407df0(puVar9);
      goto LAB_005cd290;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005cd290;
    bVar7 = __s[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar5 = 0x7a;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005cd290;
    bVar7 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0x72;
  }
  printf(__format,"cw_priv_wsrv_enable_para_parse",uVar5,(uint)bVar7);
LAB_005cd290:
  FUN_00407df0(__s);
  return 0xffffffff;
}

