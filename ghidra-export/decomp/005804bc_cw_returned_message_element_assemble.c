// func cw_returned_message_element_assemble @ 005804bc size=372

undefined4 cw_returned_message_element_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*pbVar5 - 1 < 4) {
    cw_protocol_restore8();
    if ((pbVar5[1] != 0) && (*(ushort *)(param_2 + 0xe) - 2 == (uint)pbVar5[1])) {
      cw_protocol_restore8(param_1);
      if (*(int *)(pbVar5 + 4) != 0) {
        cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar5 + 4),pbVar5[1]);
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
      printf("[CW_ERROR]%32s():%4d failed to write message\n","cw_returned_message_element_assemble"
             ,0xba);
      return 0xffffffff;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = pbVar5[1];
    __format = "[CW_ERROR]%32s():%4d length of message(%d) is wrong\n";
    uVar4 = 0xb2;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *pbVar5;
    __format = "[CW_ERROR]%32s():%4d reason(%d) is wrong\n";
    uVar4 = 0xaa;
  }
  printf(__format,"cw_returned_message_element_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

