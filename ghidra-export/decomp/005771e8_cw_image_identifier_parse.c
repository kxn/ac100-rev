// func cw_image_identifier_parse @ 005771e8 size=320

undefined4 cw_image_identifier_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0xc,0x67);
  if (__s == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_image_identifier_parse",0x6a);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar2 = cw_protocol_retrieve32(param_1);
    *__s = uVar2;
    *(short *)(__s + 1) = *(short *)(param_2 + 0xe) + -4;
    iVar3 = cw_protocol_retrieve_str(param_1);
    __s[2] = iVar3;
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read data\n","cw_image_identifier_parse",0x77);
      }
      FUN_00407df0(__s);
      uVar2 = 0xffffffff;
    }
    else {
      *(undefined4 **)(param_2 + 0x10) = __s;
      uVar2 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

