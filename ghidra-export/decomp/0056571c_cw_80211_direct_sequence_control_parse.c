// func cw_80211_direct_sequence_control_parse @ 0056571c size=616

undefined4 cw_80211_direct_sequence_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  byte bVar6;
  undefined4 uVar4;
  undefined2 uVar5;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x14,0x67);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_direct_sequence_control_parse",0x6a);
    return 0xffffffff;
  }
  memset(__s,0,0x14);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    iVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar3;
    if (iVar3 == 0) {
      bVar6 = cw_protocol_retrieve8(param_1);
      __s[2] = bVar6;
      uVar2 = cw_protocol_retrieve8(param_1);
      __s[3] = (byte)uVar2;
      if ((uVar2 & 0x1f) == uVar2) {
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(__s + 4) = uVar4;
        if (*(short *)(param_2 + 0xe) == 0x13) {
          bVar6 = cw_protocol_retrieve8(param_1);
          __s[8] = bVar6;
          uVar5 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(__s + 10) = uVar5;
          uVar5 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(__s + 0xc) = uVar5;
          uVar5 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(__s + 0xe) = uVar5;
          uVar5 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(__s + 0x10) = uVar5;
          bVar6 = cw_protocol_retrieve8(param_1);
          __s[0x12] = bVar6;
          bVar6 = cw_protocol_retrieve8(param_1);
          __s[0x13] = bVar6;
        }
        else {
          __s[8] = 0xff;
          __s[10] = 0xff;
          __s[0xb] = 0xff;
          __s[0xc] = 0xff;
          __s[0xd] = 0xff;
          __s[0xe] = 0xff;
          __s[0xf] = 0xff;
          __s[0x10] = 0xff;
          __s[0x11] = 0xff;
          __s[0x12] = 0xff;
          __s[0x13] = 0xff;
        }
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056587c;
      uVar2 = (uint)__s[3];
      __format = "[CW_ERROR]%32s():%4d current cca(0x%02x) is wrong\n";
      uVar4 = 0x88;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056587c;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
      uVar4 = 0x7c;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056587c;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x73;
  }
  printf(__format,"cw_80211_direct_sequence_control_parse",uVar4,uVar2);
LAB_0056587c:
  FUN_00407df0(__s);
  return 0xffffffff;
}

