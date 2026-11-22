// func cw_image_data_parse @ 00576bb8 size=580

undefined4 cw_image_data_parse(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  byte *__s;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  ushort uVar6;
  uint uVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  sVar2 = *(short *)(param_2 + 0xe);
  __s = (byte *)FUN_00408450(8,0x66);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_image_data_parse",0x69);
    return 0xffffffff;
  }
  memset(__s,0,8);
  iVar3 = cw_protocol_retrieve8(param_1);
  uVar6 = sVar2 - 1;
  *__s = (byte)iVar3;
  uVar5 = (uint)uVar6;
  if (iVar3 - 1U < 2) {
    if (uVar5 == 0) goto LAB_00576d50;
    if (uVar5 < 0x401) {
      iVar3 = cw_protocol_retrieve_raw_bytes(param_1,uVar5);
      *(int *)(__s + 4) = iVar3;
      if (iVar3 != 0) {
        *(ushort *)(__s + 2) = uVar6;
        goto LAB_00576c44;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read data\n","cw_image_data_parse",0x92);
      }
      goto LAB_00576d04;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00576d04;
    __format = "[CW_ERROR]%32s():%4d length of data(%d) is wrong\n";
    uVar4 = 0x82;
  }
  else {
    if (iVar3 == 5) {
      if (uVar5 == 0) {
        __s[2] = 0;
        __s[3] = 0;
        __s[4] = 0;
        __s[5] = 0;
        __s[6] = 0;
        __s[7] = 0;
LAB_00576c44:
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
LAB_00576d50:
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d length of message element(%d) doesn\'t match type(%d)\n",
               "cw_image_data_parse",0x7a,(uint)*(ushort *)(param_2 + 0xe),(uint)*__s);
      }
      goto LAB_00576d04;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00576d04;
    uVar5 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
    uVar4 = 0x72;
  }
  printf(__format,"cw_image_data_parse",uVar4,uVar5);
LAB_00576d04:
  FUN_00407df0(__s);
  return 0xffffffff;
}

