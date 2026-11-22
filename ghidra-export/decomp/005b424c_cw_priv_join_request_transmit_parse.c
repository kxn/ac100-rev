// func cw_priv_join_request_transmit_parse @ 005b424c size=224

undefined4 cw_priv_join_request_transmit_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined2 uVar5;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (undefined2 *)FUN_00408450(4,0x6e);
  if (puVar2 == (undefined2 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_join_request_transmit_parse",0x71);
    }
  }
  else {
    *(undefined1 *)puVar2 = 0;
    *(undefined1 *)((int)puVar2 + 1) = 0;
    *(undefined1 *)(puVar2 + 1) = 0;
    *(undefined1 *)((int)puVar2 + 3) = 0;
    uVar5 = cw_protocol_retrieve16(param_1);
    *puVar2 = uVar5;
    uVar5 = cw_protocol_retrieve16(param_1);
    puVar2[1] = uVar5;
    *(undefined2 **)(param_2 + 0x10) = puVar2;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

