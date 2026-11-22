// func rrm_add_co_chnl_itf @ 004b2be4 size=764

undefined4
rrm_add_co_chnl_itf(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,uint param_6
                   ,undefined4 param_7,int param_8)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_resc = param_4;
  local_res8 = param_3;
  if ((((param_1 == 0) || (param_2 < 0)) || (param_5 < 0)) || (param_8 < 1)) {
    uVar13 = 0xffffffff;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_add_co_chnl_itf",0x2f3);
    }
  }
  else {
    piVar14 = &local_38;
    pcVar6 = (char *)((int)&local_res8 + 1);
    local_38 = -1;
    local_34 = 0xffffffff;
    local_30 = 0xffffffff;
    local_2c = 0xffffffff;
    for (iVar4 = 0; iVar4 < (int)(param_3 >> 0x18); iVar4 = iVar4 + 1) {
      pcVar8 = (char *)((int)&param_6 + 1);
      for (iVar2 = 0; iVar2 < (int)(param_6 >> 0x18); iVar2 = iVar2 + 1) {
        if (*pcVar6 == *pcVar8) {
          *piVar14 = iVar2;
          break;
        }
        pcVar8 = pcVar8 + 1;
      }
      piVar14 = piVar14 + 1;
      pcVar6 = pcVar6 + 1;
    }
    piVar14 = (int *)(param_1 + param_5 * 4);
    iVar4 = 0;
    FUN_004082d0(rrm_mutex,0xffffffff);
    while (iVar2 = *(int *)(param_1 + param_2 * 4), iVar4 < *(int *)(iVar2 + 4)) {
      puVar5 = (ushort *)(*(int *)(iVar2 + 0x18) + iVar4 * 0x2a);
      cVar1 = *(char *)((int)puVar5 + 3);
      iVar12 = *(int *)(*piVar14 + 0x24) +
               (uint)*(byte *)(*(int *)(*piVar14 + 0x14) + (uint)*puVar5 * 2 + 1) * 0xc;
      iVar2 = FUN_00407fe0(iVar12);
      if (iVar2 == 0) {
        iVar4 = iVar4 + 1;
      }
      else {
        iVar2 = FUN_004081b0(iVar12);
        for (; iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
          iVar7 = (int)*(char *)((int)&local_38 + cVar1 * 4 + 3);
          iVar3 = 0;
          iVar12 = iVar2;
          if (iVar7 == -1) {
            if (rrm_debug_switch != '\0') {
              printf("[RRM_DEBUG]%s()/%d target channel no exist\n","rrm_add_co_chnl_itf",0x31a);
            }
          }
          else {
            while (iVar9 = *(int *)(*piVar14 + 0x18) + (uint)*(ushort *)(iVar2 + 0xc) * 0x2a,
                  iVar3 < (int)(uint)*(byte *)(iVar9 + 2)) {
              iVar11 = (iVar3 * 4 + iVar7 + 8) * 2;
              iVar9 = iVar9 + iVar11;
              *(short *)(iVar9 + 2) = *(short *)(iVar12 + 0x12) + *(short *)(iVar9 + 2);
              iVar9 = *(int *)(*piVar14 + 0x18) + (uint)*(ushort *)(iVar2 + 0xc) * 0x2a;
              *(short *)(iVar9 + 10) = *(short *)(iVar12 + 0x12) + *(short *)(iVar9 + 10);
              iVar9 = *(int *)(*piVar14 + 0x18) + (uint)*(ushort *)(iVar2 + 0xc) * 0x2a;
              iVar10 = iVar3 + 4;
              if (*(char *)(iVar9 + iVar3 + 3) == iVar7) {
                iVar3 = iVar3 + 1;
                *(undefined2 *)(iVar9 + iVar10 * 2 + 4) = *(undefined2 *)(iVar9 + iVar11 + 2);
                iVar12 = iVar12 + 2;
              }
              else {
                iVar3 = iVar3 + 1;
                iVar12 = iVar12 + 2;
              }
            }
          }
        }
        iVar4 = iVar4 + 1;
      }
    }
    uVar13 = 0;
    FUN_00407f30(rrm_mutex);
  }
  return uVar13;
}

