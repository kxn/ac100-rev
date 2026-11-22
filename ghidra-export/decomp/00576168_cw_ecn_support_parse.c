// func cw_ecn_support_parse @ 00576168 size=288

undefined4 cw_ecn_support_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  pbVar2 = (byte *)FUN_00408450(1,0x6b);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ecn_support_parse",0x6e);
    }
  }
  else {
    *pbVar2 = 0;
    uVar3 = cw_protocol_retrieve8(param_1);
    *pbVar2 = (byte)uVar3;
    if (uVar3 < 2) {
      *(byte **)(param_2 + 0x10) = pbVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[CW_ERROR]%32s():%4d ecn support(%d) is wrong\n","cw_ecn_support_parse",0x77,
               (uint)*pbVar2);
      }
      FUN_00407df0(pbVar2);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

