// func cw_ac_ipv6_list_assemble @ 0056e648 size=268

undefined4 cw_ac_ipv6_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*(ushort *)(param_2 + 0xe) & 0xf) == 0) {
    if ((**(ushort **)(param_2 + 0x10) == *(ushort *)(param_2 + 0xe) >> 4) &&
       (*(int *)(*(ushort **)(param_2 + 0x10) + 2) != 0)) {
      cw_protocol_restore_raw_bytes();
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to write ipv6 list\n","cw_ac_ipv6_list_assemble",0xa4);
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d length of message eleemnt(%d) is wrong\n",
             "cw_ac_ipv6_list_assemble",0x9c,(uint)*(ushort *)(param_2 + 0xe));
    }
  }
  return uVar3;
}

