// func cw_priv_set_silence_params_parse @ 005bfb40 size=308

undefined4 cw_priv_set_silence_params_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  undefined2 uVar5;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  pbVar2 = (byte *)FUN_00408450(4,0x6d);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_set_silence_params_parse",0x70);
    }
  }
  else {
    *pbVar2 = 0;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
    iVar3 = cw_protocol_retrieve8(param_1);
    *pbVar2 = (byte)iVar3;
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d roma_cnt:%d error\n","cw_priv_set_silence_params_parse",0x78,
               (uint)*pbVar2);
      }
      FUN_00407df0(pbVar2);
      uVar4 = 0xffffffff;
    }
    else {
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(pbVar2 + 2) = uVar5;
      *(byte **)(param_2 + 0x10) = pbVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

