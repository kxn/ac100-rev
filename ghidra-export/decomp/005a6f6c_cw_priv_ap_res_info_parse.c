// func cw_priv_ap_res_info_parse @ 005a6f6c size=296

undefined4 cw_priv_ap_res_info_parse(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte bVar5;
  undefined2 uVar4;
  undefined4 uVar6;
  
  pbVar1 = (byte *)FUN_00408450(6,0x71);
  if (pbVar1 == (byte *)0x0) {
    uVar6 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_res_info_parse",0x74);
    }
  }
  else {
    *pbVar1 = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    uVar2 = cw_protocol_retrieve8(param_1);
    *pbVar1 = (byte)uVar2;
    if (uVar2 < 0x20) {
      bVar5 = cw_protocol_retrieve8(param_1);
      pbVar1[1] = bVar5;
      bVar5 = cw_protocol_retrieve8(param_1);
      pbVar1[2] = bVar5;
      uVar6 = 0;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(pbVar1 + 4) = uVar4;
      *(byte **)(param_2 + 0x10) = pbVar1;
    }
    else {
      uVar6 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_ap_res_info_parse",0x7d,
               (uint)*pbVar1);
      }
    }
  }
  return uVar6;
}

