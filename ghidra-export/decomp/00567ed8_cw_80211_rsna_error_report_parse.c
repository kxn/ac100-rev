// func cw_80211_rsna_error_report_parse @ 00567ed8 size=556

undefined4 cw_80211_rsna_error_report_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x28,0x78);
  if (__s == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_rsna_error_report_parse",0x7b);
    return 0xffffffff;
  }
  memset(__s,0,0x28);
  cw_protocol_retrieve_bytes(param_1,__s,6);
  cw_protocol_retrieve_bytes(param_1,(int)__s + 6,6);
  uVar2 = cw_protocol_retrieve8(param_1);
  *(char *)((int)__s + 0xc) = (char)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    *(char *)((int)__s + 0xd) = (char)uVar2;
    if (uVar2 < 0x11) {
      iVar3 = cw_protocol_retrieve16(param_1);
      *(short *)((int)__s + 0xe) = (short)iVar3;
      if (iVar3 == 0) {
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)__s + 0x10) = uVar4;
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)__s + 0x14) = uVar4;
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)__s + 0x18) = uVar4;
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)__s + 0x1c) = uVar4;
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)__s + 0x20) = uVar4;
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)__s + 0x24) = uVar4;
        *(void **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00568054;
      uVar2 = (uint)*(ushort *)((int)__s + 0xe);
      __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zerod\n";
      uVar4 = 0x9a;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00568054;
      uVar2 = (uint)*(byte *)((int)__s + 0xd);
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar4 = 0x91;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00568054;
    uVar2 = (uint)*(byte *)((int)__s + 0xc);
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x88;
  }
  printf(__format,"cw_80211_rsna_error_report_parse",uVar4,uVar2);
LAB_00568054:
  FUN_00407df0(__s);
  return 0xffffffff;
}

