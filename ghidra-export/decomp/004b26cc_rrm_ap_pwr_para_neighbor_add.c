// func rrm_ap_pwr_para_neighbor_add @ 004b26cc size=852

undefined4
rrm_ap_pwr_para_neighbor_add
          (int param_1,ushort param_2,byte param_3,uint param_4,int param_5,short *param_6,
          int param_7,uint param_8)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  void *__s;
  undefined4 uVar9;
  uint uVar10;
  
  uVar10 = (uint)param_2;
  if (((param_1 == 0) || (*(int *)(param_1 + 0xc) <= (int)uVar10)) || (param_7 < 1)) {
    uVar9 = 0xffffffff;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_ap_pwr_para_neighbor_add",0x256);
    }
  }
  else {
    FUN_004082d0(rrm_mutex,0xffffffff);
    iVar7 = (int)*(short *)(*(int *)(param_1 + 0x14) + uVar10 * 2);
    iVar2 = (int)*(short *)(*(int *)(param_1 + 0x14) + (param_4 & 0xffff) * 2);
    if ((iVar7 < 0) || (iVar2 < 0)) {
      if (rrm_err_switch != '\0') {
        printf("[RRM_ERROR]%s()/%d ap[%d] is not calculated by rrm\n","rrm_ap_pwr_para_neighbor_add"
               ,0x25e,uVar10);
      }
LAB_004b2994:
      uVar9 = 0xffffffff;
      FUN_00407f30(rrm_mutex);
    }
    else {
      if (-1 < *(char *)(*(int *)(param_1 + 0x1c) + iVar7 * 0xf + (uint)param_3 + 2)) {
        iVar7 = 0;
        do {
          iVar3 = (int)*(char *)(*(int *)(param_1 + 0x1c) + iVar2 * 0xf +
                                 (uint)*(byte *)(param_5 + iVar7) + 2);
          if (-1 < iVar3) {
            iVar3 = *(int *)(param_1 + (iVar3 + 8) * 4) + iVar2 * 0xc;
            pvVar4 = (void *)FUN_004081b0(iVar3);
            __s = (void *)0x0;
            if (pvVar4 != (void *)0x0) {
              uVar1 = *(ushort *)((int)pvVar4 + 0xc);
              while( true ) {
                if ((uVar1 == uVar10) &&
                   (__s = pvVar4, (uint)*(byte *)((int)pvVar4 + 0xe) == (uint)param_3))
                goto LAB_004b2808;
                pvVar4 = (void *)FUN_00408680(pvVar4);
                if (pvVar4 == (void *)0x0) break;
                uVar1 = *(ushort *)((int)pvVar4 + 0xc);
              }
              __s = (void *)0x0;
            }
LAB_004b2808:
            uVar5 = FUN_00407fe0(iVar3);
            if (__s == (void *)0x0) {
              if (uVar5 < param_8) {
                __s = (void *)FUN_00408450(0x14,0x27d);
                if (__s != (void *)0x0) {
LAB_004b2924:
                  memset(__s,0,0x14);
                  *(ushort *)((int)__s + 0xc) = param_2;
                  goto LAB_004b2824;
                }
                if (rrm_err_switch == '\0') goto LAB_004b2994;
                uVar9 = 0x280;
              }
              else {
                iVar6 = FUN_00408610(iVar3);
                if (*param_6 <= *(short *)(iVar6 + 0x10)) goto LAB_004b2874;
                FUN_00408500(iVar6);
                FUN_00407df0(iVar6);
                __s = (void *)FUN_00408450(0x14,0x28d);
                if (__s != (void *)0x0) goto LAB_004b2924;
                if (rrm_err_switch == '\0') goto LAB_004b2994;
                uVar9 = 0x290;
              }
              printf("[RRM_ERROR]%s()/%d malloc failed\n","rrm_ap_pwr_para_neighbor_add",uVar9);
              goto LAB_004b2994;
            }
            FUN_00408500(__s);
            *(ushort *)((int)__s + 0xc) = param_2;
LAB_004b2824:
            *(byte *)((int)__s + 0xe) = param_3;
            *(short *)((int)__s + 0x10) = *param_6;
            iVar6 = FUN_004081b0(iVar3);
            if (iVar6 == 0) {
LAB_004b2868:
              FUN_004086b0(iVar3,__s);
            }
            else {
              sVar8 = *param_6;
              while (sVar8 < *(short *)(iVar6 + 0x10)) {
                iVar6 = FUN_00408680();
                if (iVar6 == 0) goto LAB_004b2868;
                sVar8 = *param_6;
              }
              FUN_00408170(iVar6,__s);
            }
          }
LAB_004b2874:
          iVar7 = iVar7 + 1;
          param_6 = param_6 + 1;
        } while (iVar7 != param_7);
      }
      uVar9 = 0;
      FUN_00407f30(rrm_mutex);
    }
  }
  return uVar9;
}

