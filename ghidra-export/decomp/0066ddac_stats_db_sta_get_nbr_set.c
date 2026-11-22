// func stats_db_sta_get_nbr_set @ 0066ddac size=896

undefined4 stats_db_sta_get_nbr_set(int param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int extraout_v1;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  void *__dest;
  int iVar10;
  
  FUN_00407e70();
  uVar3 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar4 = FUN_004081b0(param_1);
    if (iVar4 != 0) {
      uVar2 = *(ushort *)(iVar4 + 0x12);
      do {
        *(undefined1 *)(iVar4 + 0x1c) = 0;
        *(undefined1 *)(iVar4 + 0x1d) = 0;
        pbVar5 = *(byte **)(*(int *)(DAT_007cc8ec + (uint)uVar2 * 0x1e0 + 0x1d8) +
                            (*(byte *)(iVar4 + 0x14) - 1) * 8 + 4);
        if (pbVar5 != (byte *)0x0) {
          if ((*pbVar5 & 2) != 0) {
            *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(pbVar5 + 4);
          }
          iVar6 = FUN_00407fa0(DAT_007cc8e0,iVar4 + 0xc);
          if ((iVar6 != 0) && (iVar10 = 0, iVar8 = iVar6, (*(byte *)(iVar6 + 0x1b9) & 2) != 0)) {
            while (iVar10 < (int)(uint)*(byte *)(iVar6 + 0x1b8)) {
              if ((uint)(extraout_v1 - *(int *)(iVar8 + 0x128)) < stats_nbr_expire_time) {
                if (((uint)*(ushort *)(iVar4 + 0x12) != (uint)*(ushort *)(iVar8 + 300)) ||
                   (*(char *)(iVar8 + 0x12e) != *(char *)(iVar4 + 0x14))) {
                  pbVar7 = (byte *)(DAT_007cc8ec + (uint)*(ushort *)(iVar8 + 300) * 0x1e0);
                  pbVar5 = *(byte **)(*(int *)(pbVar7 + 0x1d8) + (*(byte *)(iVar8 + 0x12e) - 1) * 8
                                     + 4);
                  if ((pbVar5 != (byte *)0x0) &&
                     ((((*pbVar7 & 2) != 0 && ((*pbVar5 & 2) != 0)) &&
                      ((*(byte *)(*(int *)(pbVar5 + 0x160) + (*(byte *)(iVar8 + 0x12f) - 1) * 0x100
                                 + 8) & 2) != 0)))) {
                    if (*(int *)(pbVar5 + 4) == 1) {
                      bVar1 = *(byte *)(iVar4 + 0x1d);
                      *(byte *)(iVar4 + 0x1d) = bVar1 + 1;
                      iVar9 = (uint)bVar1 * 0x18 + 0x140;
                    }
                    else {
                      bVar1 = *(byte *)(iVar4 + 0x1c);
                      *(byte *)(iVar4 + 0x1c) = bVar1 + 1;
                      iVar9 = (uint)bVar1 * 0x18 + 0x20;
                    }
                    __dest = (void *)(iVar4 + iVar9);
                    *(undefined2 *)((int)__dest + 6) = *(undefined2 *)(iVar8 + 300);
                    memcpy(__dest,(void *)(DAT_007cc8ec + (uint)*(ushort *)(iVar8 + 300) * 0x1e0 +
                                          0x10),6);
                    *(undefined1 *)((int)__dest + 8) = *(undefined1 *)(iVar8 + 0x12e);
                    *(undefined1 *)((int)__dest + 10) =
                         *(undefined1 *)
                          (*(int *)(*(int *)(DAT_007cc8ec + (uint)*(ushort *)(iVar8 + 300) * 0x1e0 +
                                            0x1d8) + (*(byte *)(iVar8 + 0x12e) - 1) * 8 + 4) + 8);
                    *(undefined1 *)((int)__dest + 9) =
                         *(undefined1 *)
                          (*(int *)(*(int *)(DAT_007cc8ec + (uint)*(ushort *)(iVar8 + 300) * 0x1e0 +
                                            0x1d8) + (*(byte *)(iVar8 + 0x12e) - 1) * 8 + 4) + 0x11)
                    ;
                    *(undefined1 *)((int)__dest + 0xb) =
                         *(undefined1 *)
                          (*(int *)(*(int *)(DAT_007cc8ec + (uint)*(ushort *)(iVar8 + 300) * 0x1e0 +
                                            0x1d8) + (*(byte *)(iVar8 + 0x12e) - 1) * 8 + 4) + 0x10)
                    ;
                    *(undefined1 *)((int)__dest + 0xc) = *(undefined1 *)(iVar8 + 0x130);
                    *(undefined1 *)((int)__dest + 0xd) = *(undefined1 *)(iVar8 + 0x12f);
                    *(undefined4 *)((int)__dest + 0x14) = 0xffffffff;
                    memcpy((void *)((int)__dest + 0xe),
                           (void *)(*(int *)(*(int *)(*(int *)(DAT_007cc8ec +
                                                               (uint)*(ushort *)(iVar8 + 300) *
                                                               0x1e0 + 0x1d8) +
                                                      (*(byte *)(iVar8 + 0x12e) - 1) * 8 + 4) +
                                            0x160) + (*(byte *)(iVar8 + 0x12f) - 1) * 0x100 + 9),6);
                  }
                  goto LAB_0066e0a0;
                }
                iVar10 = iVar10 + 1;
                iVar8 = iVar8 + 0xc;
              }
              else {
LAB_0066e0a0:
                iVar10 = iVar10 + 1;
                iVar8 = iVar8 + 0xc;
              }
            }
          }
        }
        iVar4 = FUN_00408680(iVar4);
        if (iVar4 == 0) break;
        uVar2 = *(ushort *)(iVar4 + 0x12);
      } while( true );
    }
    FUN_00407f30(l_stats_data);
    uVar3 = 0;
  }
  return uVar3;
}

