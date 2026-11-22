// func cw_priv_pwr_state_parse @ 005b92f4 size=304

undefined4 cw_priv_pwr_state_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar6;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  pbVar2 = (byte *)FUN_00408450(2,0x6e);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_pwr_state_parse",0x71);
    }
  }
  else {
    *pbVar2 = 0;
    pbVar2[1] = 0;
    uVar3 = cw_protocol_retrieve8(param_1);
    *pbVar2 = (byte)uVar3;
    if (uVar3 < 0x20) {
      bVar6 = cw_protocol_retrieve8(param_1);
      pbVar2[1] = bVar6;
      *(byte **)(param_2 + 0x10) = pbVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_pwr_state_parse",0x7a,
               (uint)*pbVar2);
      }
      FUN_00407df0(pbVar2);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

