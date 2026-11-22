// func cw_data_transfer_data_parse @ 00572db8 size=552

undefined4 cw_data_transfer_data_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x67);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_data_transfer_data_parse",0x6a);
    return 0xffffffff;
  }
  memset(__s,0,8);
  iVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)iVar2;
  if ((iVar2 - 1U < 2) || (iVar2 == 5)) {
    iVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar2;
    if (iVar2 - 1U < 2) {
      iVar2 = cw_protocol_retrieve16(param_1);
      *(short *)(__s + 2) = (short)iVar2;
      if (*(ushort *)(param_2 + 0xe) - 4 == iVar2) {
        iVar2 = cw_protocol_retrieve_raw_bytes(param_1);
        *(int *)(__s + 4) = iVar2;
        if (iVar2 != 0) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read data\n","cw_data_transfer_data_parse",0x8e);
        }
        goto LAB_00572ef8;
      }
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00572ef8;
      uVar4 = (uint)*(ushort *)(__s + 2);
      __format = "[CW_ERROR]%32s():%4d length of data(%d) is wrong\n";
      uVar3 = 0x85;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00572ef8;
      uVar4 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d mode(%d) is wrong\n";
      uVar3 = 0x7c;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00572ef8;
    uVar4 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
    uVar3 = 0x73;
  }
  printf(__format,"cw_data_transfer_data_parse",uVar3,uVar4);
LAB_00572ef8:
  FUN_00407df0(__s);
  return 0xffffffff;
}

