// func cw_returned_message_element_parse @ 00580630 size=472

undefined4 cw_returned_message_element_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x6f);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_returned_message_element_parse",0x72);
    return 0xffffffff;
  }
  memset(__s,0,8);
  iVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)iVar3;
  if (iVar3 - 1U < 4) {
    iVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar3;
    if ((iVar3 != 0) && (*(ushort *)(param_2 + 0xe) - 2 == iVar3)) {
      iVar3 = cw_protocol_retrieve_raw_bytes(param_1);
      *(int *)(__s + 4) = iVar3;
      if (iVar3 != 0) {
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read message\n","cw_returned_message_element_parse",
               0x8e);
      }
      goto LAB_00580754;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00580754;
    bVar1 = __s[1];
    __format = "[CW_ERROR]%32s():%4d length of message(%d) is wrong\n";
    uVar4 = 0x85;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00580754;
    bVar1 = *__s;
    __format = "[CW_ERROR]%32s():%4d reason(%d) is wrong\n";
    uVar4 = 0x7c;
  }
  printf(__format,"cw_returned_message_element_parse",uVar4,(uint)bVar1);
LAB_00580754:
  FUN_00407df0(__s);
  return 0xffffffff;
}

