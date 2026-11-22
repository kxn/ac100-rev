// func cw_80211_update_station_qos_parse @ 0056a6cc size=536

undefined4 cw_80211_update_station_qos_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  int iVar5;
  byte *pbVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0xf,0x6e);
  if (__s == (byte *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_update_station_qos_parse",0x71);
    }
  }
  else {
    memset(__s,0,0xf);
    uVar2 = cw_protocol_retrieve8(param_1);
    *__s = (byte)uVar2;
    if (uVar2 < 0x20) {
      iVar5 = 0;
      cw_protocol_retrieve_bytes(param_1,__s + 1,6);
      pbVar6 = __s;
      do {
        uVar2 = cw_protocol_retrieve8(param_1);
        pbVar6[7] = (byte)uVar2;
        if ((uVar2 & 7) != uVar2) {
          if (capwap_err_switch == 0) goto LAB_0056a820;
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) goto LAB_0056a820;
          __format = "[CW_ERROR]%32s():%4d 8021p(0x%02x) is wrong\n";
          uVar2 = (uint)__s[iVar5 * 2 + 7];
          uVar3 = 0x89;
          goto LAB_0056a8d4;
        }
        uVar2 = cw_protocol_retrieve8(param_1);
        pbVar6[8] = (byte)uVar2;
        if ((uVar2 & 0x3f) != uVar2) {
          if (capwap_err_switch == 0) goto LAB_0056a820;
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) goto LAB_0056a820;
          __format = "[CW_ERROR]%32s():%4d dscp(0x%02x) is wrong\n";
          uVar2 = (uint)__s[iVar5 * 2 + 8];
          uVar3 = 0x92;
          goto LAB_0056a8d4;
        }
        iVar5 = iVar5 + 1;
        pbVar6 = pbVar6 + 2;
      } while (iVar5 != 4);
      *(byte **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        uVar2 = (uint)*__s;
        __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
        uVar3 = 0x7a;
LAB_0056a8d4:
        printf(__format,"cw_80211_update_station_qos_parse",uVar3,uVar2);
      }
LAB_0056a820:
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

