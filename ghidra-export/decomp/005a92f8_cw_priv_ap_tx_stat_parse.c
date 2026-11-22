// func cw_priv_ap_tx_stat_parse @ 005a92f8 size=656

undefined4 cw_priv_ap_tx_stat_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  undefined4 uVar2;
  int iVar3;
  int iVar5;
  undefined8 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0x210,0x9e);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_tx_stat_parse",0xa1);
    }
  }
  else {
    memset(__s,0,0x210);
    uVar4 = cw_protocol_retrieve8(param_1);
    *__s = uVar4;
    cw_protocol_retrieve_bytes(param_1,__s + 1,3);
    uVar6 = cw_protocol_retrieve64(param_1);
    *(undefined8 *)(__s + 8) = uVar6;
    uVar6 = cw_protocol_retrieve64(param_1);
    *(undefined8 *)(__s + 0x10) = uVar6;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x18) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x1c) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x20) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x24) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x28) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x2c) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x30) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x34) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x38) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x3c) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x40) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x44) = uVar2;
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0x48) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x88) = uVar2;
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0x8c) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0xcc) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0x10c) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0x14c) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0x18c) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    iVar3 = 0;
    do {
      uVar2 = cw_protocol_retrieve32(param_1);
      iVar5 = iVar3 + 4;
      *(undefined4 *)(__s + iVar3 + 0x1cc) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x40);
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

