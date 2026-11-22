// func uac_wservice_callback_proc @ 005e1188 size=560

undefined4 uac_wservice_callback_proc(int param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  code *pcVar13;
  undefined4 local_428 [126];
  char local_230 [532];
  
  puVar7 = &g_wserv_callback_list;
  pcVar10 = param_2;
  puVar3 = (undefined *)FUN_004081b0(&g_wserv_callback_list);
  do {
    puVar8 = puVar3;
    if (puVar8 == (undefined *)0x0) {
      return 0;
    }
    if (param_1 == 2) {
      pcVar13 = *(code **)(puVar8 + 0x18);
      uVar4 = 0;
      if (pcVar13 != (code *)0x0) {
        for (; uVar4 < 0x205; uVar4 = uVar4 + 1) {
          local_230[uVar4] = param_2[uVar4 + 0x205];
        }
        uVar4 = (uint)param_2 & 3;
        iVar5 = *(int *)(param_2 + -uVar4);
        uVar6 = (uint)(param_2 + 4) & 3;
        uVar11 = *(undefined4 *)(param_2 + 8);
        uVar12 = *(undefined4 *)(param_2 + 0xc);
        uVar1 = (uint)(param_2 + 3) & 3;
        uVar2 = *(uint *)(param_2 + 3 + -uVar1);
        uVar9 = (uint)(param_2 + 7) & 3;
        pcVar10 = (char *)(*(int *)(param_2 + 4 + -uVar6) << uVar6 * 8 & -1 << (uVar9 + 1) * 8 |
                          *(uint *)(param_2 + 7 + -uVar9) >> (3 - uVar9) * 8);
        for (uVar6 = 0; uVar6 < 0x1f5; uVar6 = uVar6 + 1) {
          *(char *)((int)local_428 + uVar6) = param_2[uVar6 + 0x10];
        }
        iVar5 = (*pcVar13)((iVar5 << uVar4 * 8 | (uint)local_230 & 0xffffffffU >> (4 - uVar4) * 8) &
                           -1 << (uVar1 + 1) * 8 | uVar2 >> (3 - uVar1) * 8,pcVar10,uVar11,uVar12);
LAB_005e131c:
        if (((iVar5 != 0) && (g_wserv_error != 0)) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          local_428[0] = *(undefined4 *)(puVar8 + 0xc);
          pcVar10 = "uac_wservice_callback_proc";
          printf("<wserv>[error]%s(): %d  -> Failed to proc %d callback of [%s].\r\n",
                 "uac_wservice_callback_proc",0x1866,param_1);
        }
      }
    }
    else if (param_1 == 3) {
      pcVar13 = *(code **)(puVar8 + 0x1c);
      uVar4 = 0;
      if (pcVar13 != (code *)0x0) {
        uVar6 = (uint)param_2 & 3;
        uVar1 = (uint)(param_2 + 4) & 3;
        uVar11 = *(undefined4 *)(param_2 + 8);
        uVar12 = *(undefined4 *)(param_2 + 0xc);
        uVar9 = (uint)(param_2 + 3) & 3;
        uVar9 = (*(int *)(param_2 + -uVar6) << uVar6 * 8 |
                (uint)puVar7 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)(param_2 + 3 + -uVar9) >> (3 - uVar9) * 8;
        uVar6 = (uint)(param_2 + 7) & 3;
        pcVar10 = (char *)((*(int *)(param_2 + 4 + -uVar1) << uVar1 * 8 |
                           (uint)pcVar10 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar6 + 1) * 8 |
                          *(uint *)(param_2 + 7 + -uVar6) >> (3 - uVar6) * 8);
        for (; uVar4 < 0x1f5; uVar4 = uVar4 + 1) {
          *(char *)((int)local_428 + uVar4) = param_2[uVar4 + 0x10];
        }
LAB_005e1314:
        iVar5 = (*pcVar13)(uVar9,pcVar10,uVar11,uVar12);
        goto LAB_005e131c;
      }
    }
    else if (param_1 == 1) {
      pcVar13 = *(code **)(puVar8 + 0x14);
      uVar4 = 0;
      if (pcVar13 != (code *)0x0) {
        uVar6 = (uint)param_2 & 3;
        uVar1 = (uint)(param_2 + 4) & 3;
        uVar11 = *(undefined4 *)(param_2 + 8);
        uVar12 = *(undefined4 *)(param_2 + 0xc);
        uVar9 = (uint)(param_2 + 3) & 3;
        uVar9 = (*(int *)(param_2 + -uVar6) << uVar6 * 8 |
                (uint)puVar7 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)(param_2 + 3 + -uVar9) >> (3 - uVar9) * 8;
        uVar6 = (uint)(param_2 + 7) & 3;
        pcVar10 = (char *)((*(int *)(param_2 + 4 + -uVar1) << uVar1 * 8 |
                           (uint)pcVar10 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar6 + 1) * 8 |
                          *(uint *)(param_2 + 7 + -uVar6) >> (3 - uVar6) * 8);
        for (; uVar4 < 0x1f5; uVar4 = uVar4 + 1) {
          *(char *)((int)local_428 + uVar4) = param_2[uVar4 + 0x10];
        }
        goto LAB_005e1314;
      }
    }
    puVar3 = (undefined *)FUN_00408680();
    puVar7 = puVar8;
  } while( true );
}

