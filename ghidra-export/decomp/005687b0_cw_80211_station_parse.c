// func cw_80211_station_parse @ 005687b0 size=584

undefined4 cw_80211_station_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined2 uVar4;
  int iVar3;
  char *__format;
  undefined4 uVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x14,0x6b);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_station_parse",0x6e);
    return 0xffffffff;
  }
  memset(__s,0,0x14);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar4 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(__s + 2) = uVar4;
    iVar3 = cw_protocol_retrieve8(param_1);
    __s[4] = (byte)iVar3;
    if (iVar3 == 0) {
      cw_protocol_retrieve_bytes(param_1,__s + 5,6);
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0xc) = uVar4;
      uVar2 = cw_protocol_retrieve8(param_1);
      __s[0xe] = (byte)uVar2;
      if (uVar2 < 0x11) {
        __s[0xf] = *(char *)(param_2 + 0xf) - 0xd;
        iVar3 = cw_protocol_retrieve_raw_bytes(param_1);
        *(int *)(__s + 0x10) = iVar3;
        if (iVar3 != 0) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read supported rates\n","cw_80211_station_parse",
                 0x9a);
        }
        goto LAB_0056890c;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056890c;
      uVar2 = (uint)__s[0xe];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar5 = 0x90;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056890c;
      uVar2 = (uint)__s[4];
      __format = "[CW_ERROR]%32s():%4d flags(%d) isn\'t zeroed\n";
      uVar5 = 0x83;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056890c;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0x77;
  }
  printf(__format,"cw_80211_station_parse",uVar5,uVar2);
LAB_0056890c:
  FUN_00407df0(__s);
  return 0xffffffff;
}

