// func wips_entry_clear @ 004cab78 size=492

void wips_entry_clear(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 in_a3;
  
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d trigger wips entry clear\n","wips_entry_clear",0xca2);
  }
  iVar3 = wips_local_time_get();
  FUN_004082d0(wips_global_mutex,0xffffffff);
  iVar4 = FUN_004081b0(&g_wips_list);
  while (iVar1 = iVar4, iVar1 != 0) {
    iVar4 = FUN_00408680(iVar1);
    if (*(int *)(iVar1 + 0xac) != 1) {
      iVar5 = FUN_004081b0(iVar1 + 0x9c);
      while (iVar2 = iVar5, iVar2 != 0) {
        iVar5 = FUN_00408680(iVar2);
        if (sensor_debug_switch == '\0') {
          iVar6 = *(int *)(iVar2 + 0x24);
        }
        else {
          printf("[SENSOR_DEBUG]%s()/%d local_time: %llu last_time: %llu\n","wips_entry_clear",0xcc2
                 ,in_a3,iVar3 >> 0x1f,iVar3,*(int *)(iVar2 + 0x24) >> 0x1f,*(int *)(iVar2 + 0x24));
          iVar6 = *(int *)(iVar2 + 0x24);
        }
        if ((0x15180 < iVar3 - iVar6) || (iVar3 < *(int *)(iVar2 + 0x20))) {
          FUN_00408500(iVar2);
          FUN_00407df0(iVar2);
        }
      }
      iVar5 = FUN_00407fe0(iVar1 + 0x9c);
      if (iVar5 == 0) {
        *(undefined4 *)(g_wips_id2entry + *(int *)(iVar1 + 0xc) * 4) = 0;
        FUN_004080f0(g_wips_id_allocator,*(undefined4 *)(iVar1 + 0xc));
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
      }
    }
  }
  FUN_00407f30(wips_global_mutex);
  return;
}

