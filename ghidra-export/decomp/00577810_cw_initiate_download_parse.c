// func cw_initiate_download_parse @ 00577810 size=176

undefined4 cw_initiate_download_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (undefined1 *)FUN_00408450(1,0x68);
  if (puVar2 == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_initiate_download_parse",0x6b);
    }
  }
  else {
    *puVar2 = 0;
    *(undefined1 **)(param_2 + 0x10) = puVar2;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

