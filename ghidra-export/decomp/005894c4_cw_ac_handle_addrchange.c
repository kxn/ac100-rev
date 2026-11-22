// func cw_ac_handle_addrchange @ 005894c4 size=264

void cw_ac_handle_addrchange(int *param_1,undefined4 param_2)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 4) == '\n') {
    iVar3 = *param_1 + -0x18;
    for (puVar2 = (ushort *)(param_1 + 6);
        ((3 < iVar3 && (3 < *puVar2)) && ((int)(uint)*puVar2 <= iVar3));
        puVar2 = (ushort *)((int)puVar2 + uVar1)) {
      if ((ushort)(puVar2[1] - 1) < 2) {
        if (((*(byte *)(puVar2 + 2) & 0xf0) == 0x20) || ((*(byte *)(puVar2 + 2) & 0xf0) == 0x30)) {
          capwap_ipv6_socket_join_or_leave_group(*(undefined4 *)(ac + 0x10),param_1[5],param_2);
          uVar1 = (uint)*puVar2;
        }
        else {
          uVar1 = (uint)*puVar2;
        }
      }
      else {
        uVar1 = (uint)*puVar2;
      }
      uVar1 = uVar1 + 3 & 0xfffffffc;
      iVar3 = iVar3 - uVar1;
    }
  }
  return;
}

