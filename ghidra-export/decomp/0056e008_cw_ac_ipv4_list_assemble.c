// func cw_ac_ipv4_list_assemble @ 0056e008 size=324

undefined4 cw_ac_ipv4_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*(ushort *)(param_2 + 0xe) & 3) == 0) {
    puVar4 = *(ushort **)(param_2 + 0x10);
    if ((*puVar4 == *(ushort *)(param_2 + 0xe) >> 2) && (iVar2 = 0, *(int *)(puVar4 + 2) != 0)) {
      for (; iVar2 < (int)(uint)*puVar4; iVar2 = iVar2 + 1) {
        cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar4 + 2) + iVar2 * 4));
      }
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to write ac ipv4 list\n","cw_ac_ipv4_list_assemble",0xa5
              );
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d length of message eleemnt(%d) is wrong\n",
             "cw_ac_ipv4_list_assemble",0x9d,(uint)*(ushort *)(param_2 + 0xe));
    }
  }
  return uVar3;
}

