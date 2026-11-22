// func cw_priv_mesh_public_control_dump @ 005b5e50 size=624

undefined4 cw_priv_mesh_public_control_dump(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  ushort *puVar4;
  
  puVar4 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private mesh public control \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private mesh public control(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x.. \r\n",(uint)*puVar4);
  printf("\t\t\t\tAP count: %d \r\n",(uint)*puVar4);
  if (*puVar4 != 0) {
    puts("\t\t\t\tmac list: ");
    for (iVar1 = 0; iVar1 < (int)(uint)*puVar4; iVar1 = iVar1 + 1) {
      pbVar3 = (byte *)(*(int *)(puVar4 + 2) + iVar1 * 6);
      printf("\t\t\t\t\tmac:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)*pbVar3,(uint)pbVar3[1],
             (uint)pbVar3[2],(uint)pbVar3[3],(uint)pbVar3[4],(uint)pbVar3[5]);
    }
  }
  printf("\t\t*****Sub Message Element of mesh control public(%d)*****\n",
         (uint)*(ushort *)(param_1 + 0xc));
  iVar1 = FUN_004081b0(puVar4 + 6);
  while( true ) {
    if (iVar1 == 0) {
      printf("\t\t***Sub Message Element of Mesh Control Public(%d) End***\n",
             (uint)*(ushort *)(param_1 + 0xc));
      return 0;
    }
    puVar4 = (ushort *)cw_msg_ele_mngr_get(*(undefined2 *)(iVar1 + 0xc));
    if (puVar4 == (ushort *)0x0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
             "cw_priv_mesh_public_control_dump",0x1c2,(uint)*(ushort *)(iVar1 + 0xc));
      return 0xffffffff;
    }
    if (*(int *)(iVar1 + 0x10) == 0) break;
    iVar2 = (**(code **)(puVar4 + 0xe))(iVar1);
    if (((iVar2 == -1) && (capwap_err_switch != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to dump %s(%d)\n","cw_priv_mesh_public_control_dump",0x1cf
             ,*(undefined4 *)(puVar4 + 2),(uint)*puVar4);
    }
    iVar1 = FUN_00408680(iVar1);
  }
  if (capwap_err_switch == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  printf("[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value\n","cw_priv_mesh_public_control_dump",
         0x1c8,*(undefined4 *)(puVar4 + 2),(uint)*puVar4);
  return 0xffffffff;
}

