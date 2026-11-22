// func reset_ap_rd_sample @ 0066b118 size=292

void reset_ap_rd_sample(int param_1,int param_2,int param_3,undefined1 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = (param_3 + -1) * 8;
  if (param_1 == 0) {
    uVar3 = *(undefined4 *)(param_4 + 0x24);
    uVar2 = *(undefined4 *)(param_4 + 0x20);
    uVar5 = *(undefined4 *)(param_4 + 0x2c);
    uVar4 = *(undefined4 *)(param_4 + 0x28);
    memset(param_4,0,0x160);
    reset_stats_db_rd_sample(param_4);
    *(undefined4 *)(param_4 + 0x24) = uVar3;
    *(undefined4 *)(param_4 + 0x20) = uVar2;
    *(undefined4 *)(param_4 + 0x2c) = uVar5;
    *(undefined4 *)(param_4 + 0x28) = uVar4;
    *(undefined4 *)(param_4 + 0x34) = 0;
    *param_4 = 0;
  }
  else {
    if (*(char *)(*(int *)(DAT_007cc8ec + param_2 * 0x1e0 + 0x1d8) + iVar1) != '\0') {
      memset(param_4,0,0x160);
      return;
    }
    if (*(int *)(param_4 + 0x160) != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_4 + 0x160) = 0;
    }
    FUN_00407df0(param_4);
    *(undefined4 *)(*(int *)(DAT_007cc8ec + param_2 * 0x1e0 + 0x1d8) + iVar1 + 4) = 0;
  }
  return;
}

