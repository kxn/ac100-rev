// func move_all_pkt_snapshot @ 00589180 size=256

void move_all_pkt_snapshot(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return;
  }
  iVar3 = (param_2 + -1) * 4;
  FUN_004082d0(*(undefined4 *)(g_write_snapshot_data[1] + iVar3),0xffffffff);
  iVar2 = FUN_00407fe0(param_1);
  FUN_004082c0(*g_write_snapshot_data + (param_2 + -1) * 0xc,param_1);
  FUN_00407f30(*(undefined4 *)(g_write_snapshot_data[1] + iVar3));
  FUN_004082d0(g_write_snapshot_data[2],0xffffffff);
  piVar1 = g_write_snapshot_data;
  iVar3 = g_write_snapshot_data[3];
  g_write_snapshot_data[3] = iVar2 + iVar3;
  if (iVar2 + iVar3 != 0) {
    FUN_004084b0(piVar1[4]);
  }
  FUN_00407f30(g_write_snapshot_data[2]);
  return;
}

