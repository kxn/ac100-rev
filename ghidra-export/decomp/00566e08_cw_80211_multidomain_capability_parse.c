// func cw_80211_multidomain_capability_parse @ 00566e08 size=412

undefined4 cw_80211_multidomain_capability_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  char *__format;
  undefined4 uVar6;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x67);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_multidomain_capability_parse",0x6a);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    iVar4 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar4;
    if (iVar4 == 0) {
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 2) = uVar5;
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 4) = uVar5;
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 6) = uVar5;
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00566f28;
    bVar1 = __s[1];
    __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
    uVar6 = 0x7c;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00566f28;
    bVar1 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x73;
  }
  printf(__format,"cw_80211_multidomain_capability_parse",uVar6,(uint)bVar1);
LAB_00566f28:
  FUN_00407df0(__s);
  return 0xffffffff;
}

