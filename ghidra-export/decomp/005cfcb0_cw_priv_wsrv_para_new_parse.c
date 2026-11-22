// func cw_priv_wsrv_para_new_parse @ 005cfcb0 size=1356

undefined4 cw_priv_wsrv_para_new_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined2 uVar6;
  byte bVar7;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 uVar8;
  int iVar5;
  char *__format;
  int iVar9;
  undefined1 *puVar10;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0xd,0x8d);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_para_new_parse",0x90);
    return 0xffffffff;
  }
  memset(__s,0,0xd);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 0x11) {
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
      uVar3 = cw_protocol_retrieve8(param_1);
      __s[8] = (byte)uVar3;
      switch(uVar3) {
      case 0:
        goto switchD_005cfdc4_caseD_0;
      case 1:
      case 4:
        puVar4 = (undefined1 *)FUN_00408450(0xc,0xb6);
        if (puVar4 != (undefined1 *)0x0) {
          memset(puVar4,0,0xc);
          uVar8 = cw_protocol_retrieve8(param_1);
          *puVar4 = uVar8;
          uVar8 = cw_protocol_retrieve8(param_1);
          puVar4[1] = uVar8;
          uVar3 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(puVar4 + 2) = uVar3;
          uVar3 = cw_protocol_retrieve16(param_1);
          puVar4[7] = (char)uVar3;
          puVar4[6] = (char)((uint)uVar3 >> 8);
          iVar5 = cw_protocol_retrieve_raw_bytes(param_1,uVar3);
          *(int *)(puVar4 + 8) = iVar5;
          if (iVar5 != 0) {
LAB_005cfea4:
            *(undefined1 **)(__s + 9) = puVar4;
switchD_005cfdc4_caseD_0:
            *(byte **)(param_2 + 0x10) = __s;
            uVar3 = 0xffffffff;
            if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
              uVar3 = 0;
            }
            return uVar3;
          }
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            uVar3 = 0xc5;
LAB_005d00f8:
            printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_para_new_parse",uVar3);
          }
LAB_005cffc8:
          FUN_00407df0(puVar4);
          goto LAB_005cfda0;
        }
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_005cfda0;
        uVar3 = 0xb9;
        break;
      case 2:
        puVar4 = (undefined1 *)FUN_00408450(0x4e,0xcf);
        if (puVar4 != (undefined1 *)0x0) {
          memset(puVar4,0,0x4e);
          uVar8 = cw_protocol_retrieve8(param_1);
          *puVar4 = uVar8;
          uVar8 = cw_protocol_retrieve8(param_1);
          puVar4[1] = uVar8;
          uVar3 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(puVar4 + 2) = uVar3;
          cw_protocol_retrieve_ip(param_1,puVar4 + 6);
          cw_protocol_retrieve_ip(param_1,puVar4 + 0x1a);
          cw_protocol_retrieve_ip(param_1,puVar4 + 0x2e);
          uVar6 = cw_protocol_retrieve16(param_1);
          puVar4[0x43] = (char)uVar6;
          puVar4[0x42] = (char)((ushort)uVar6 >> 8);
          uVar6 = cw_protocol_retrieve16(param_1);
          puVar4[0x45] = (char)uVar6;
          puVar4[0x44] = (char)((ushort)uVar6 >> 8);
          uVar6 = cw_protocol_retrieve16(param_1);
          puVar4[0x47] = (char)uVar6;
          puVar4[0x46] = (char)((ushort)uVar6 >> 8);
          uVar3 = cw_protocol_retrieve16(param_1);
          puVar4[0x49] = (char)uVar3;
          puVar4[0x48] = (char)((uint)uVar3 >> 8);
          iVar5 = cw_protocol_retrieve_raw_bytes(param_1,uVar3);
          *(int *)(puVar4 + 0x4a) = iVar5;
          if (iVar5 != 0) goto LAB_005cfea4;
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            uVar3 = 0xe7;
            goto LAB_005d00f8;
          }
          goto LAB_005cffc8;
        }
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_005cfda0;
        uVar3 = 0xd2;
        break;
      case 3:
        puVar4 = (undefined1 *)FUN_00408450(0x86,0xf1);
        if (puVar4 != (undefined1 *)0x0) {
          uVar8 = cw_protocol_retrieve8(param_1);
          *puVar4 = uVar8;
          iVar5 = 0;
          uVar8 = cw_protocol_retrieve8(param_1);
          puVar4[1] = uVar8;
          puVar10 = puVar4;
          do {
            uVar8 = cw_protocol_retrieve8(param_1);
            iVar9 = iVar5 * 0x21;
            puVar10[2] = uVar8;
            iVar5 = iVar5 + 1;
            puVar10 = puVar10 + 0x21;
            cw_protocol_retrieve_bytes(param_1,puVar4 + iVar9 + 3,0x20);
          } while (iVar5 != 4);
          *(undefined1 **)(__s + 9) = puVar4;
          goto switchD_005cfdc4_caseD_0;
        }
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_005cfda0;
        uVar3 = 0xf5;
        break;
      default:
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_005cfda0;
        uVar2 = (uint)__s[8];
        __format = "[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n";
        uVar3 = 0x105;
        goto LAB_005d0084;
      }
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wsrv_para_new_parse",uVar3);
      goto LAB_005cfda0;
    }
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_005cfda0;
    uVar2 = (uint)__s[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar3 = 0xa1;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_005cfda0;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0x99;
  }
LAB_005d0084:
  printf(__format,"cw_priv_wsrv_para_new_parse",uVar3,uVar2);
LAB_005cfda0:
  FUN_00407df0(__s);
  return 0xffffffff;
}

