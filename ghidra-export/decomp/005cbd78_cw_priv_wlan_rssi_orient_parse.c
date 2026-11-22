// func cw_priv_wlan_rssi_orient_parse @ 005cbd78 size=300

undefined4 cw_priv_wlan_rssi_orient_parse(undefined4 param_1,int param_2)

{
  undefined4 *__s;
  undefined4 uVar1;
  uint uVar2;
  undefined1 uVar4;
  int iVar3;
  
  __s = (undefined4 *)FUN_00408450(8,0x6c);
  if (__s == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wlan_rssi_orient_parse",0x6f);
    }
  }
  else {
    memset(__s,0,8);
    uVar1 = cw_protocol_retrieve32(param_1);
    *__s = uVar1;
    uVar2 = cw_protocol_retrieve16(param_1);
    *(short *)(__s + 1) = (short)uVar2;
    if (uVar2 < 0x20) {
      uVar4 = cw_protocol_retrieve8(param_1);
      *(undefined1 *)((int)__s + 6) = uVar4;
      uVar4 = cw_protocol_retrieve8(param_1);
      *(undefined1 *)((int)__s + 7) = uVar4;
      *(undefined4 **)(param_2 + 0x10) = __s;
      uVar1 = 0;
    }
    else {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_wlan_rssi_orient_parse",0x7b,
               (uint)*(ushort *)(__s + 1));
      }
      FUN_00407df0(__s);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

