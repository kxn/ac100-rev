// func rdmngr_db_for_each_proc @ 0061cac8 size=1

int rdmngr_db_for_each_proc
              (uint param_1,int param_2,code *param_3,undefined4 param_4,code *param_5,
              undefined4 param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *__src;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 uStack_318;
  undefined4 uStack_314;
  undefined4 uStack_310;
  undefined1 auStack_308 [728];
  undefined4 *puStack_30;
  uint uStack_2c;
  
  iVar8 = 0;
  memset(auStack_308,0,0x2d8);
  uStack_318 = 0;
  uStack_314 = 0;
  uStack_310 = 0;
  if ((param_2 != 0) && (param_5 != (code *)0x0)) {
    if ((rdmngr_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d global search begins, offset:%d, size:%d\n",
             "rdmngr_db_for_each_proc",0xe0f,param_1,param_2);
    }
    puStack_30 = &uStack_318;
    FUN_0051ad88(puStack_30);
    FUN_004082d0(DAT_007cc64c,0xffffffff);
    iVar8 = DAT_007cc65c;
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    iVar3 = apmngr_db_get_sensor_max();
    if ((uint)((iVar1 + iVar2 + iVar3) * iVar8) < param_1) {
      iVar8 = -1;
      if ((rdmngr_warning_switch != 0) &&
         (iVar2 = is_target_debug_ap(), iVar1 = DAT_007cc65c, iVar2 != 0)) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar10 = apmngr_db_get_sensor_max();
        printf("[RDMNGR_WARNING]%s()/%d offset[%d] is out of range, radio size[%d]!\n",
               "rdmngr_db_for_each_proc",0xe15,param_1,(iVar2 + iVar3 + iVar10) * iVar1);
      }
    }
    else {
      iVar2 = 0;
      iVar10 = 0;
      iVar1 = 0;
      iVar3 = 0;
      iVar8 = -1;
      uVar9 = 1;
      do {
        __src = *(int **)(DAT_007cc650 + iVar2 + 4);
        if ((((__src != (int *)0x0) && (*__src != -1)) &&
            ((param_3 == (code *)0x0 || (iVar4 = (*param_3)(__src,param_4), iVar4 == 0)))) &&
           (iVar10 = iVar10 + 1, iVar1 < param_2)) {
          if (iVar3 < (int)param_1) {
            iVar3 = iVar3 + 1;
          }
          else {
            iVar4 = FUN_004082a0(1,0x60,0xe39);
            if (iVar4 == 0) {
              if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[RDMNGR_ERROR]%s()/%d no memory!!\n","rdmngr_db_for_each_proc",0xe3c);
              }
              goto code_r0x0061cc64;
            }
            memcpy((void *)(iVar4 + 0xc),__src,0x54);
            iVar1 = iVar1 + 1;
            FUN_004086b0(&uStack_318,iVar4);
            iVar8 = iVar1;
          }
        }
        iVar4 = DAT_007cc65c;
        iVar2 = iVar2 + 8;
        uStack_2c = uVar9;
        iVar5 = apmngr_db_get_ap_max();
        iVar6 = apmngr_db_get_template_max();
        iVar7 = apmngr_db_get_sensor_max();
        uVar9 = uVar9 + 1;
      } while (uStack_2c < (uint)((iVar5 + iVar6 + iVar7) * iVar4));
      if (param_7 != (int *)0x0) {
        *param_7 = iVar10;
      }
    }
code_r0x0061cc64:
    FUN_00407f30(DAT_007cc64c);
    iVar1 = FUN_004081b0(&uStack_318);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      iVar3 = apmngr_db_entry_get_by_id((uint)(*(int *)(iVar1 + 0xc) << 0xc) >> 0x10,auStack_308);
      if (iVar3 == 0) {
        (*param_5)(auStack_308,iVar1 + 0xc,param_6);
      }
      FUN_00407df0(iVar1);
      iVar1 = iVar2;
    }
  }
  return iVar8;
}

