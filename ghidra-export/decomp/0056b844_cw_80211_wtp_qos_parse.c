// func cw_80211_wtp_qos_parse @ 0056b844 size=652

undefined4 cw_80211_wtp_qos_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  byte bVar5;
  undefined2 uVar4;
  int iVar3;
  char *__format;
  undefined4 uVar6;
  byte *pbVar7;
  int iVar8;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x2a,0x6e);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_wtp_qos_parse",0x71);
    return 0xffffffff;
  }
  memset(__s,0,0x2a);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if ((uVar2 & 0x1f) == uVar2) {
      iVar8 = 0;
      pbVar7 = __s;
      while( true ) {
        bVar5 = cw_protocol_retrieve8(param_1);
        pbVar7[2] = bVar5;
        uVar4 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(pbVar7 + 4) = uVar4;
        uVar4 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(pbVar7 + 6) = uVar4;
        bVar5 = cw_protocol_retrieve8(param_1);
        pbVar7[8] = bVar5;
        uVar2 = cw_protocol_retrieve8(param_1);
        pbVar7[9] = (byte)uVar2;
        if ((uVar2 & 7) != uVar2) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0056b9cc;
          __format = "[CW_ERROR]%32s():%4d 8021p(0x%02x) is wrong\n";
          uVar6 = 0x95;
          uVar2 = (uint)__s[iVar8 * 10 + 9];
          goto LAB_0056bac0;
        }
        uVar2 = cw_protocol_retrieve8(param_1);
        pbVar7[10] = (byte)uVar2;
        if ((uVar2 & 0x3f) != uVar2) break;
        iVar8 = iVar8 + 1;
        pbVar7 = pbVar7 + 10;
        if (iVar8 == 4) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056b9cc;
      __format = "[CW_ERROR]%32s():%4d dscp(0x%02x) is wrong\n";
      uVar6 = 0x9e;
      uVar2 = (uint)__s[iVar8 * 10 + 10];
    }
    else {
      if ((capwap_err_switch == 0) || (iVar8 = is_target_debug_ap(), iVar8 == 0)) goto LAB_0056b9cc;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d tagging policy(0x%02x) is wrong\n";
      uVar6 = 0x83;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar8 = is_target_debug_ap(), iVar8 == 0)) goto LAB_0056b9cc;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x7a;
  }
LAB_0056bac0:
  printf(__format,"cw_80211_wtp_qos_parse",uVar6,uVar2);
LAB_0056b9cc:
  FUN_00407df0(__s);
  return 0xffffffff;
}

