// func check_snapshot_list @ 0058f4bc size=140

/* WARNING: Removing unreachable block (ram,0x0058f4f8) */

void check_snapshot_list(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00407fe0(param_1 + 0x94);
    if (*(uint *)(l_profile + 0x28) == 0) {
      trap(7);
    }
    if (((uint)(*(int *)(l_profile + 0x144) << 0x14) / 0x60) / *(uint *)(l_profile + 0x28) <= uVar1)
    {
      move_all_pkt_snapshot(param_1 + 0x94,*(undefined4 *)(param_1 + 4));
      return;
    }
  }
  return;
}

