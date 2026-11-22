// func mac_auth_db_mac_entry_del_in_group @ 00453e04 size=256

void mac_auth_db_mac_entry_del_in_group(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  FUN_004082d0(DAT_00766ff4,0xffffffff);
  uVar1 = 0;
  while (uVar1 < DAT_00766fe8) {
    iVar3 = 0;
    puVar4 = param_1;
    if (*(int *)(DAT_00767024 + uVar1 * 0x188 + 0xc) == -1) {
      uVar1 = uVar1 + 1;
    }
    else {
      for (; iVar3 < param_2; iVar3 = iVar3 + 1) {
        uVar2 = *puVar4;
        if ((-1 < (int)uVar2) && (uVar2 < g_mac_auth_profile)) {
          puVar5 = (uint *)(*(int *)(DAT_00767024 + uVar1 * 0x188 + 0x180) + (uVar2 >> 5) * 4);
          *puVar5 = *puVar5 & ~(1 << (uVar2 & 0x1f));
        }
        puVar4 = puVar4 + 1;
      }
      uVar1 = uVar1 + 1;
    }
  }
  FUN_00407f30(DAT_00766ff4);
  return;
}

