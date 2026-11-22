// func cw_add_mac_acl_entry_parse @ 0056fab8 size=552

undefined4 cw_add_mac_acl_entry_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x66);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_add_mac_acl_entry_parse",0x69);
    return 0xffffffff;
  }
  memset(__s,0,8);
  iVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)iVar2;
  if (iVar2 == 0) {
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0056fbf4;
    uVar4 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d num of entries(%d) is wrong\n";
    uVar3 = 0x72;
  }
  else {
    iVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar2;
    if ((iVar2 == 6) || (iVar2 == 8)) {
      uVar4 = *(ushort *)(param_2 + 0xe) - 2 & 0xffff;
      if (uVar4 == (uint)*__s * iVar2) {
        iVar2 = cw_protocol_retrieve_raw_bytes(param_1,uVar4);
        *(int *)(__s + 4) = iVar2;
        if (iVar2 != 0) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read mac address\n","cw_add_mac_acl_entry_parse",
                 0x8b);
        }
        goto LAB_0056fbf4;
      }
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0056fbf4;
      __format = "[CW_ERROR]%32s():%4d length of mac address list(%d) is wrong\n";
      uVar3 = 0x84;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0056fbf4;
      uVar4 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
      uVar3 = 0x7b;
    }
  }
  printf(__format,"cw_add_mac_acl_entry_parse",uVar3,uVar4);
LAB_0056fbf4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

