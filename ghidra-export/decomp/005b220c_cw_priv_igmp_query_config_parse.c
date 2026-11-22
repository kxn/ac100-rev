// func cw_priv_igmp_query_config_parse @ 005b220c size=188

undefined4 cw_priv_igmp_query_config_parse(undefined4 param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 uVar3;
  undefined1 uVar4;
  int iVar2;
  undefined4 uVar5;
  
  puVar1 = (undefined2 *)FUN_00408450(4,0x70);
  if (puVar1 == (undefined2 *)0x0) {
    uVar5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_igmp_query_config_parse",0x73);
    }
  }
  else {
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
    *(undefined1 *)(puVar1 + 1) = 0;
    *(undefined1 *)((int)puVar1 + 3) = 0;
    uVar3 = cw_protocol_retrieve16(param_1);
    *puVar1 = uVar3;
    uVar4 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)(puVar1 + 1) = uVar4;
    *(undefined2 **)(param_2 + 0x10) = puVar1;
    uVar5 = 0;
  }
  return uVar5;
}

