// func cw_priv_capwap_retrans_para_parse @ 005acf74 size=328

undefined4 cw_priv_capwap_retrans_para_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  undefined2 uVar5;
  byte bVar6;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  pbVar2 = (byte *)FUN_00408450(6,0x6e);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_capwap_retrans_para_parse",0x71);
    }
  }
  else {
    *pbVar2 = 0;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
    pbVar2[4] = 0;
    pbVar2[5] = 0;
    iVar3 = cw_protocol_retrieve8(param_1);
    *pbVar2 = (byte)iVar3;
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d Illegal retransmit times %d\n",
               "cw_priv_capwap_retrans_para_parse",0x7a,(uint)*pbVar2);
      }
      FUN_00407df0(pbVar2);
      uVar4 = 0xffffffff;
    }
    else {
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(pbVar2 + 2) = uVar5;
      bVar6 = cw_protocol_retrieve8(param_1);
      pbVar2[4] = bVar6;
      *(byte **)(param_2 + 0x10) = pbVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

