// func wsta_main_test @ 0063dd54 size=1

undefined4 wsta_main_test(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined2 auStack_b4 [16];
  int iStack_94;
  undefined1 uStack_90;
  undefined1 uStack_8f;
  uint uStack_4c;
  undefined2 uStack_48;
  uint uStack_30;
  
  iVar10 = 0x10;
  wsta_db_init();
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  if (param_1 == 2) {
    iVar10 = atoi(*(char **)(param_2 + 4));
  }
  iVar2 = wsta_calloc(l_wsta_profile,0xc,0,0);
  if (iVar2 == 0) {
    uVar9 = 0xffffffff;
    if ((g_wsta_error != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
      printf("<wsta>[error]%s(): %d  -> no memory!\r\n","wsta_main_test",0xe5a);
    }
  }
  else {
    iVar11 = 0;
    for (iVar8 = 0; iVar8 < iVar10; iVar8 = iVar8 + 1) {
      memset(auStack_b4,0,0x80);
      uStack_30 = iVar8 << 0x10;
      iStack_94 = iVar8;
      for (uVar1 = 1; uVar3 = rdmngr_profile_get_max_rd_per_ap(), uVar1 <= uVar3; uVar1 = uVar1 + 1)
      {
        uVar3 = 1;
        uVar12 = uVar1 << 8 | uStack_30;
        uStack_90 = (char)uVar1;
        while (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar3 <= uVar4) {
          uStack_4c = uVar3 | uVar12;
          uStack_48 = auStack_b4[0];
          uStack_8f = (char)uVar3;
          iVar5 = wsta_db_sta_assoc(auStack_b4,0,0,0,0,0,0);
          if (iVar5 == 0) {
            iVar5 = iVar11 * 0xc;
            iVar11 = iVar11 + 1;
            piVar7 = (int *)(iVar2 + iVar5);
            *piVar7 = iVar8;
            *(char *)(piVar7 + 1) = (char)uVar1;
            *(char *)((int)piVar7 + 5) = (char)uVar3;
            memcpy((void *)((int)piVar7 + 6),&uStack_4c,6);
            uVar3 = uVar3 + 1;
          }
          else {
            uVar3 = uVar3 + 1;
          }
        }
      }
    }
    iVar8 = iVar10;
    iVar5 = 2;
    if (iVar10 < 3) {
      iVar5 = iVar10;
    }
    for (; iVar5 < iVar8; iVar8 = iVar8 - (uint)(iVar6 == 0)) {
      iVar6 = rand();
      if (iVar10 == 0) {
        trap(7);
      }
      iVar6 = wsta_db_free_ap_sta(iVar6 % iVar10,0,0);
    }
    wsta_entry_print_hash(0,iVar11);
    uVar9 = 0;
    wsta_db_print_ap_all();
    wsta_db_print_list(0);
    wsta_db_uninit();
    wsta_free(iVar2);
    wsta_print_event_stat();
  }
  return uVar9;
}

