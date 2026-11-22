// func cw_wtp_fallback_parse @ 00585244 size=292

undefined4 cw_wtp_fallback_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  pbVar2 = (byte *)FUN_00408450(1,0x6f);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_wtp_fallback_parse",0x72);
    }
  }
  else {
    *pbVar2 = 0;
    iVar3 = cw_protocol_retrieve8(param_1);
    *pbVar2 = (byte)iVar3;
    if (iVar3 - 1U < 2) {
      *(byte **)(param_2 + 0x10) = pbVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d mode(%d) is wrong\n","cw_wtp_fallback_parse",0x7b,(uint)*pbVar2
              );
      }
      FUN_00407df0(pbVar2);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

