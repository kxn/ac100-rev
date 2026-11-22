// func cw_80211_supported_rates_parse @ 005696c0 size=328

undefined4 cw_80211_supported_rates_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(10,0x65);
  if (__s == (byte *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_supported_rates_parse",0x68);
    }
  }
  else {
    memset(__s,0,10);
    uVar2 = cw_protocol_retrieve8(param_1);
    *__s = (byte)uVar2;
    if (uVar2 < 0x20) {
      __s[1] = *(char *)(param_2 + 0xf) - 1;
      cw_protocol_retrieve_bytes(param_1,__s + 2);
      *(byte **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_80211_supported_rates_parse",0x71,
               (uint)*__s);
      }
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

