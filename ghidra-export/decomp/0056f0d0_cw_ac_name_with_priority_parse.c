// func cw_ac_name_with_priority_parse @ 0056f0d0 size=320

undefined4 cw_ac_name_with_priority_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(8,0x66);
  if (__s == (undefined1 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ac_name_with_priority_parse",0x69);
    }
  }
  else {
    memset(__s,0,8);
    uVar4 = cw_protocol_retrieve8(param_1);
    *__s = uVar4;
    *(short *)(__s + 2) = *(short *)(param_2 + 0xe) + -1;
    iVar2 = cw_protocol_retrieve_str(param_1);
    *(int *)(__s + 4) = iVar2;
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read ac name\n","cw_ac_name_with_priority_parse",0x74
              );
      }
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
    else {
      *(undefined1 **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

