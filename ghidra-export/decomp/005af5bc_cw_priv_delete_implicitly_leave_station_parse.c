// func cw_priv_delete_implicitly_leave_station_parse @ 005af5bc size=536

undefined4 cw_priv_delete_implicitly_leave_station_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x66);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_delete_implicitly_leave_station_parse",
           0x69);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    iVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar3;
    if ((iVar3 == 6) || (iVar3 == 8)) {
      if (*(ushort *)(param_2 + 0xe) - 2 == iVar3) {
        iVar3 = cw_protocol_retrieve_raw_bytes(param_1,iVar3);
        *(int *)(__s + 4) = iVar3;
        if (iVar3 != 0) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read mac address\n",
                 "cw_priv_delete_implicitly_leave_station_parse",0x8a);
        }
        goto LAB_005af6ec;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005af6ec;
      uVar2 = (uint)*(ushort *)(param_2 + 0xe);
      __format = "[CW_ERROR]%32s():%4d length of message element(%d) is wrong\n";
      uVar4 = 0x83;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005af6ec;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
      uVar4 = 0x7b;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005af6ec;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x72;
  }
  printf(__format,"cw_priv_delete_implicitly_leave_station_parse",uVar4,uVar2);
LAB_005af6ec:
  FUN_00407df0(__s);
  return 0xffffffff;
}

