// func cw_priv_ap_log_report_para_assemble @ 005a63b4 size=256

undefined4 cw_priv_ap_log_report_para_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  puVar3 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar3);
  cw_protocol_restore8(param_1,puVar3[1]);
  cw_protocol_restore8(param_1,puVar3[2]);
  cw_protocol_restore8(param_1,puVar3[3]);
  if ((byte)(puVar3[4] - 1) < 2) {
    cw_protocol_restore_ip(param_1,puVar3 + 4);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar3 + 0x18));
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d Illegal remote servert type:%d\n",
             "cw_priv_ap_log_report_para_assemble",0xa4,(uint)(byte)puVar3[4]);
    }
  }
  return uVar4;
}

