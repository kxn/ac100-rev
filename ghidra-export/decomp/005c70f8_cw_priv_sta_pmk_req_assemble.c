// func cw_priv_sta_pmk_req_assemble @ 005c70f8 size=400

undefined4 cw_priv_sta_pmk_req_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  puVar5 = *(undefined1 **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar5);
  cw_protocol_restore8(param_1,puVar5[1]);
  if ((byte)puVar5[2] < 0x20) {
    cw_protocol_restore8(param_1);
    if ((byte)puVar5[3] < 0x11) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore32(param_1,*(undefined4 *)(puVar5 + 4));
      cw_protocol_restore_raw_bytes(param_1,puVar5 + 8,0x11);
      cw_protocol_restore_raw_bytes(param_1,puVar5 + 0x19,0x10);
      cw_protocol_restore_raw_bytes(param_1,puVar5 + 0x29,6);
      cw_protocol_restore_raw_bytes(param_1,puVar5 + 0x2f,6);
      cw_protocol_restore_raw_bytes(param_1,puVar5 + 0x35,0x20);
      cw_protocol_restore_raw_bytes(param_1,puVar5 + 0x55,0x10);
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = puVar5[3];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar4 = 200;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = puVar5[2];
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0xc0;
  }
  printf(__format,"cw_priv_sta_pmk_req_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

