// func cw_wtp_board_data_assemble @ 00583744 size=412

undefined4 cw_wtp_board_data_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar5);
  iVar2 = FUN_004081b0(puVar5 + 1);
  do {
    if (iVar2 == 0) {
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
      return uVar4;
    }
    if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) <
        (int)(*(ushort *)(iVar2 + 0xe) + 4)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
      uVar4 = 0xf3;
LAB_0058385c:
      printf(__format,"cw_wtp_board_data_assemble",uVar4);
      return 0xffffffff;
    }
    cw_protocol_restore16(param_1,*(undefined2 *)(iVar2 + 0xc));
    if (0x3ff < *(ushort *)(iVar2 + 0xe) - 1) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d subelement length(%d) is wrong\n","cw_wtp_board_data_assemble",
             0xfd,(uint)*(ushort *)(iVar2 + 0xe));
      return 0xffffffff;
    }
    cw_protocol_restore16(param_1);
    if (*(int *)(iVar2 + 0x10) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d subelement data is null\n";
      uVar4 = 0x105;
      goto LAB_0058385c;
    }
    cw_protocol_restore_raw_bytes(param_1,*(int *)(iVar2 + 0x10),*(undefined2 *)(iVar2 + 0xe));
    iVar2 = FUN_00408680(iVar2);
  } while( true );
}

