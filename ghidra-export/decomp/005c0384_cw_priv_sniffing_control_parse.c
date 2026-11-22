// func cw_priv_sniffing_control_parse @ 005c0384 size=244

undefined4 cw_priv_sniffing_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 uVar6;
  undefined2 uVar5;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (undefined1 *)FUN_00408450(6,0x7a);
  if (puVar2 == (undefined1 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sniffing_control_parse",0x7d);
    }
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    uVar6 = cw_protocol_retrieve8(param_1);
    *puVar2 = uVar6;
    uVar5 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(puVar2 + 2) = uVar5;
    uVar5 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(puVar2 + 4) = uVar5;
    *(undefined1 **)(param_2 + 0x10) = puVar2;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

