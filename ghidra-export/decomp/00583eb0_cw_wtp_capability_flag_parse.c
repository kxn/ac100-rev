// func cw_wtp_capability_flag_parse @ 00583eb0 size=248

undefined4 cw_wtp_capability_flag_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x10,0x71);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_wtp_capability_flag_parse",0x74);
    }
  }
  else {
    iVar4 = 0;
    memset(__s,0,0x10);
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      puVar3 = (undefined4 *)((int)__s + iVar4);
      iVar4 = iVar4 + 4;
      *puVar3 = uVar2;
    } while (iVar4 != 0x10);
    *(void **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

