// func cw_80211_update_wlan_parse @ 0056b174 size=668

undefined4 cw_80211_update_wlan_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined2 uVar4;
  byte bVar5;
  int iVar3;
  char *__format;
  undefined4 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0xc,0x6f);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_update_wlan_parse",0x72);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 0x11) {
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 2) = uVar4;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[4] = bVar5;
      uVar2 = cw_protocol_retrieve8(param_1);
      __s[5] = (byte)uVar2;
      if (uVar2 < 4) {
        iVar3 = cw_protocol_retrieve16(param_1);
        *(short *)(__s + 6) = (short)iVar3;
        if ((iVar3 <= (int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6))) &&
           (*(ushort *)(param_2 + 0xe) - 8 == iVar3)) {
          if (*(ushort *)(param_2 + 0xe) != 8) {
            iVar3 = cw_protocol_retrieve_raw_bytes(param_1);
            *(int *)(__s + 8) = iVar3;
            if (iVar3 == 0) {
              if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[CW_ERROR]%32s():%4d failed to read key\n","cw_80211_update_wlan_parse",0xa5
                      );
              }
              goto LAB_0056b2e4;
            }
          }
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0056b2e4;
        uVar2 = (uint)*(ushort *)(__s + 6);
        __format = "[CW_ERROR]%32s():%4d key length(%d) is wrong\n";
        uVar6 = 0x9a;
      }
      else {
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0056b2e4;
        uVar2 = (uint)__s[5];
        __format = "[CW_ERROR]%32s():%4d key status(%d) is wrong\n";
        uVar6 = 0x92;
      }
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056b2e4;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar6 = 0x84;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056b2e4;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x7b;
  }
  printf(__format,"cw_80211_update_wlan_parse",uVar6,uVar2);
LAB_0056b2e4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

