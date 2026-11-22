// func write_snapshot_thread_callback @ 0058f610 size=660

void write_snapshot_thread_callback(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_30;
  
  iVar8 = 0;
  iVar6 = 0;
  iVar5 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  FUN_0051ad88(&local_40);
  uVar4 = 1;
  do {
    uVar7 = uVar4;
    if (iVar5 == *(int *)(l_profile + 0x28)) {
      iVar5 = 0;
      FUN_004082d0(g_write_snapshot_data[2],0xffffffff);
      piVar1 = g_write_snapshot_data + 4;
      piVar2 = g_write_snapshot_data + 2;
      g_write_snapshot_data[3] = g_write_snapshot_data[3] - iVar6;
      iVar6 = 0;
      FUN_004086c0(*piVar1,*piVar2,0xffffffff);
      FUN_00407f30(g_write_snapshot_data[2]);
    }
    iVar9 = (uVar7 - 1) * 4;
    FUN_004082d0(*(undefined4 *)(g_write_snapshot_data[1] + iVar9),0xffffffff);
    local_30 = (uVar7 - 1) * 0xc;
    do {
      iVar3 = FUN_004081b0(*g_write_snapshot_data + local_30);
      if (iVar3 == 0) goto LAB_0058f6e8;
      FUN_00408500(iVar3);
      FUN_004086b0(&local_40,iVar3);
      iVar8 = iVar8 + 1;
    } while (iVar8 != 10);
    iVar8 = 0;
LAB_0058f6e8:
    FUN_00407f30(*(undefined4 *)(g_write_snapshot_data[1] + iVar9));
    while (iVar9 = FUN_004081b0(&local_40), iVar9 != 0) {
      open_snapshot_file(&DAT_00676fc0,0);
      iVar3 = write_snapshot(g_write_snapshot_data[5] + 1,g_write_snapshot_data[7],iVar9);
      if (iVar3 == 0) {
        FUN_00408500(iVar9);
        snapshot_destroy(iVar9);
        g_write_snapshot_data[5] = g_write_snapshot_data[5] + 1;
        if (tftp_server_enable == 0) {
          uVar4 = 400;
          iVar9 = *(int *)(l_profile + 0x144);
        }
        else {
          uVar4 = 200;
          iVar9 = *(int *)(l_profile + 0x144);
        }
        if (uVar4 == 0) {
          trap(7);
        }
        uVar4 = (uint)(iVar9 << 0x14) / uVar4;
        if (snapshot_store_debug_switch != 0) {
          printf("[SNAPSHOT_STORE_DEBUG]%s()/%d max entry count %d \n","snapshot_handle",0x2a0,uVar4
                );
        }
        if ((uint)g_write_snapshot_data[5] < uVar4) {
          iVar6 = iVar6 + 1;
        }
        else {
          fflush((FILE *)g_write_snapshot_data[7]);
          iVar9 = write_out_snapshot_if_full
                            (g_write_snapshot_data + 5,g_write_snapshot_data[6],
                             (g_write_snapshot_data[5] + 1) - uVar4);
          if (iVar9 != 0) goto LAB_0058f740;
          iVar6 = iVar6 + 1;
        }
      }
      else {
LAB_0058f740:
        if ((FILE *)g_write_snapshot_data[7] != (FILE *)0x0) {
          fclose((FILE *)g_write_snapshot_data[7]);
        }
      }
    }
    iVar5 = iVar5 + 1;
    uVar4 = uVar7 + 1;
    if (*(uint *)(l_profile + 0x28) < uVar7 + 1) {
      uVar4 = (uVar7 - *(uint *)(l_profile + 0x28)) + 1;
    }
  } while( true );
}

