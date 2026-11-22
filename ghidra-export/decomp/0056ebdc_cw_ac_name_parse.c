// func cw_ac_name_parse @ 0056ebdc size=304

undefined4 cw_ac_name_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(8,0x65);
  if (__s == (undefined2 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ac_name_parse",0x68);
    }
  }
  else {
    memset(__s,0,8);
    *__s = *(undefined2 *)(param_2 + 0xe);
    iVar2 = cw_protocol_retrieve_str(param_1,*(undefined2 *)(param_2 + 0xe));
    *(int *)(__s + 2) = iVar2;
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read ac name\n","cw_ac_name_parse",0x72);
      }
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
    else {
      *(undefined2 **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

