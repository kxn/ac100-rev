// func cw_priv_bw_ctrl_parse @ 005ac66c size=848

undefined4 cw_priv_bw_ctrl_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  uint *puVar7;
  char *__format;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x10,0x7a);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_bw_ctrl_parse",0x7d);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 5) {
    uVar4 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 4) = uVar4;
    uVar4 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 8) = uVar4;
    if ((*__s == 0) || (*__s == 4)) {
      uVar3 = cw_protocol_retrieve32(param_1);
      if (uVar3 < 0x81) {
        puVar7 = (uint *)FUN_00408450(uVar3 * 6 + 4,0x96);
        if (puVar7 != (uint *)0x0) {
          *puVar7 = uVar3;
          if (uVar3 != 0) {
            cw_protocol_retrieve_bytes(param_1,puVar7 + 1,uVar3 * 6 & 0xfffe);
          }
          *(uint **)(__s + 0xc) = puVar7;
LAB_005ac8fc:
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          uVar4 = 0x99;
          goto LAB_005ac950;
        }
      }
      else if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("[CW_ERROR]%32s():%4d mac_num(%d) is too big, shouldn\'t bigger then %d\n",
               "cw_priv_bw_ctrl_parse",0x93,uVar3,0x80);
      }
    }
    else {
      pbVar5 = (byte *)FUN_00408450(2,0xa5);
      if (pbVar5 != (byte *)0x0) {
        uVar3 = cw_protocol_retrieve8(param_1);
        *pbVar5 = (byte)uVar3;
        if (uVar3 < 0x20) {
          uVar3 = cw_protocol_retrieve8(param_1);
          pbVar5[1] = (byte)uVar3;
          if (uVar3 < 0x11) {
            *(byte **)(__s + 0xc) = pbVar5;
            goto LAB_005ac8fc;
          }
          if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
            bVar1 = pbVar5[1];
            __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
            uVar4 = 0xb7;
            goto LAB_005ac8b4;
          }
        }
        else if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          bVar1 = *pbVar5;
          __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
          uVar4 = 0xaf;
LAB_005ac8b4:
          printf(__format,"cw_priv_bw_ctrl_parse",uVar4,(uint)bVar1);
        }
        FUN_00407df0(pbVar5);
        goto LAB_005ac6ec;
      }
      if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        uVar4 = 0xa8;
LAB_005ac950:
        printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_bw_ctrl_parse",uVar4);
      }
    }
  }
  else if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("[CW_ERROR]%32s():%4d bw_type(%d) is wrong\n","cw_priv_bw_ctrl_parse",0x86,(uint)*__s);
  }
  if (__s == (byte *)0x0) {
    return 0xffffffff;
  }
LAB_005ac6ec:
  FUN_00407df0(__s);
  return 0xffffffff;
}

