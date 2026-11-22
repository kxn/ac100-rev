// func rrm_ap_para_neighbor_add @ 004b21b8 size=1300

undefined4
rrm_ap_para_neighbor_add
          (int param_1,uint param_2,uint param_3,uint param_4,int param_5,short *param_6,int param_7
          ,uint param_8)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  void *__s;
  void *pvVar5;
  uint uVar6;
  void *__s_00;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  void *pvVar14;
  int iVar15;
  
  param_2 = param_2 & 0xffff;
  if (((param_1 == 0) || (*(int *)(param_1 + 0xc) <= (int)param_2)) || (param_7 < 1)) {
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_ap_para_neighbor_add",0x1cd);
    return 0xffffffff;
  }
  FUN_004082d0(rrm_mutex,0xffffffff);
  sVar1 = *(short *)(*(int *)(param_1 + 0x14) + param_2 * 2);
  iVar12 = (int)sVar1;
  sVar2 = *(short *)(*(int *)(param_1 + 0x14) + (param_4 & 0xffff) * 2);
  uVar11 = (uint)sVar2;
  if ((iVar12 < 0) || ((int)uVar11 < 0)) {
    if (rrm_err_switch == '\0') goto LAB_004b25b4;
    pcVar8 = "[RRM_ERROR]%s()/%d ap[%d] is not calculated by rrm\n";
    uVar10 = 0x1d5;
  }
  else {
    iVar13 = (int)*(char *)(*(int *)(param_1 + 0x1c) + iVar12 * 0xf + (param_3 & 0xff) + 2);
    if (iVar13 < 0) {
LAB_004b2324:
      FUN_00407f30(rrm_mutex);
      return 0;
    }
    iVar15 = iVar12 * 0xc;
    for (__s = (void *)FUN_004081b0(*(int *)(param_1 + 0x20) + iVar15); __s != (void *)0x0;
        __s = (void *)FUN_00408680(__s)) {
      if (*(ushort *)((int)__s + 0xc) == uVar11) {
        __s_00 = *(void **)((int)__s + 0x24);
        bVar3 = false;
        if (__s_00 != (void *)0x0) goto LAB_004b2360;
        if (rrm_err_switch == '\0') goto LAB_004b25b4;
        pcVar8 = "[RRM_ERROR]%s()/%d malloc failed\n";
        uVar10 = 0x210;
        goto LAB_004b263c;
      }
    }
    uVar6 = FUN_00407fe0(*(int *)(param_1 + 0x20) + iVar15);
    if (uVar6 < param_8) {
      __s = (void *)FUN_00408450(0x28,0x1f1);
      if (__s == (void *)0x0) {
        if (rrm_err_switch == '\0') goto LAB_004b25b4;
        pcVar8 = "[RRM_ERROR]%s()/%d malloc failed\n";
        uVar10 = 500;
      }
      else {
        memset(__s,0,0x28);
        *(short *)((int)__s + 0xc) = sVar2;
        *(undefined1 *)((int)__s + 0xe) =
             *(undefined1 *)(*(int *)(param_1 + 0x18) + uVar11 * 0x2a + 2);
        __s_00 = (void *)FUN_00408450(0x28,0x1fc);
        if (__s_00 == (void *)0x0) {
          FUN_00407df0(__s);
          if (rrm_err_switch == '\0') goto LAB_004b25b4;
          pcVar8 = "[RRM_ERROR]%s()/%d malloc failed\n";
          uVar10 = 0x200;
        }
        else {
          memset(__s_00,0,0x28);
          *(short *)((int)__s_00 + 0xc) = sVar1;
          bVar3 = true;
          *(undefined1 *)((int)__s_00 + 0xe) =
               *(undefined1 *)(*(int *)(param_1 + 0x18) + iVar12 * 0x2a + 2);
          *(void **)((int)__s + 0x24) = __s_00;
          *(void **)((int)__s_00 + 0x24) = __s;
LAB_004b2360:
          iVar12 = iVar12 * 0x2a;
          bVar4 = false;
          iVar7 = 0;
          do {
            iVar9 = (int)*(char *)(*(int *)(param_1 + 0x1c) + uVar11 * 0xf +
                                   (uint)*(byte *)(param_5 + iVar7) + 2);
            if (-1 < iVar9) {
              *(short *)((int)__s + 0x10) = *param_6 + *(short *)((int)__s + 0x10);
              *(short *)((int)__s_00 + 0x10) = *param_6 + *(short *)((int)__s_00 + 0x10);
              iVar9 = (iVar9 * 3 + iVar13 + 8) * 2;
              *(short *)((int)__s + iVar9 + 2) = *param_6 + *(short *)((int)__s + iVar9 + 2);
              *(short *)((int)__s_00 + iVar9 + 2) = *param_6 + *(short *)((int)__s_00 + iVar9 + 2);
              iVar9 = *(int *)(param_1 + 0x18) + iVar12;
              *(short *)(iVar9 + 10) = *param_6 + *(short *)(iVar9 + 10);
              iVar9 = *(int *)(param_1 + 0x18) + iVar12 + (iVar13 + 4) * 2;
              *(short *)(iVar9 + 4) = *param_6 + *(short *)(iVar9 + 4);
              iVar9 = *(int *)(param_1 + 0x18) + iVar12 + (iVar13 + 2) * 8;
              *(short *)(iVar9 + 2) = *param_6 + *(short *)(iVar9 + 2);
              bVar4 = true;
            }
            iVar7 = iVar7 + 1;
            param_6 = param_6 + 1;
          } while (iVar7 != param_7);
          if ((!bVar3) || (bVar4)) {
            pvVar14 = (void *)0x0;
            if (!bVar3) {
              pvVar14 = __s;
            }
            for (pvVar5 = (void *)FUN_004081b0(*(int *)(param_1 + 0x20) + iVar15); pvVar5 != pvVar14
                ; pvVar5 = (void *)FUN_00408680(pvVar5)) {
              if (*(ushort *)((int)pvVar5 + 0x10) <= *(ushort *)((int)__s + 0x10))
              goto joined_r0x004b22e4;
            }
            pvVar5 = (void *)0x0;
joined_r0x004b22e4:
            if (bVar3) {
              FUN_004086b0(*(int *)(param_1 + 0x24) + uVar11 * 0xc,__s_00);
            }
            if (pvVar5 == (void *)0x0) {
              if (bVar3) {
                FUN_004086b0(*(int *)(param_1 + 0x20) + iVar15,__s);
              }
            }
            else {
              if (!bVar3) {
                FUN_00408500(__s);
              }
              FUN_00408170(pvVar5,__s);
            }
            goto LAB_004b2324;
          }
          FUN_00407df0(__s);
          FUN_00407df0(__s_00);
          if (rrm_err_switch == '\0') goto LAB_004b25b4;
          pcVar8 = "[RRM_ERROR]%s()/%d Input error\n";
          uVar10 = 0x228;
        }
      }
LAB_004b263c:
      printf(pcVar8,"rrm_ap_para_neighbor_add",uVar10);
      goto LAB_004b25b4;
    }
    if (rrm_err_switch == '\0') goto LAB_004b25b4;
    pcVar8 = "[RRM_ERROR]%s()/%d ap[%d] is not full\n";
    uVar10 = 0x1ed;
  }
  printf(pcVar8,"rrm_ap_para_neighbor_add",uVar10,param_2);
LAB_004b25b4:
  FUN_00407f30(rrm_mutex);
  return 0xffffffff;
}

