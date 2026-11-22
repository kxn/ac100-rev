// func wsta_db_sta_for_each_range_usr @ 00638564 size=1

int wsta_db_sta_for_each_range_usr
              (uint param_1,int param_2,code *param_3,undefined4 param_4,code *param_5,
              undefined4 param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 *puStack_30;
  
  iVar5 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  if ((param_2 != 0) && (param_5 != (code *)0x0)) {
    puStack_30 = &uStack_40;
    FUN_0051ad88(puStack_30);
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    if (DAT_007cc6e0 < param_1) {
      iVar5 = -1;
      if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wsta>[error]%s(): %d  -> offset[%d] is out of range, wsta size[%d]!\r\n",
               "wsta_db_sta_for_each_range_usr",0x5d6,param_1,DAT_007cc6e0);
      }
    }
    else {
      iVar1 = 0;
      if (DAT_007cc6e0 != 0) {
        iVar4 = 0;
        iVar2 = FUN_004081b0(&DAT_007cc6d8);
        iVar6 = 0;
        iVar5 = -1;
        while (iVar2 != 0) {
          if (((param_3 == (code *)0x0) || (iVar3 = (*param_3)(iVar2 + -0xc,param_4), iVar3 == 0))
             && (iVar1 = iVar1 + 1, iVar4 < param_2)) {
            if (iVar6 < (int)param_1) {
              iVar2 = FUN_00408680(iVar2);
              iVar6 = iVar6 + 1;
            }
            else {
              iVar3 = wsta_calloc(1,0x8c,"wsta_db_sta_for_each_range_usr",0x5fe);
              if (iVar3 == 0) {
                if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  printf("<wsta>[error]%s(): %d  -> no memory!!\r\n",
                         "wsta_db_sta_for_each_range_usr",0x601);
                }
                goto code_r0x00638604;
              }
              iVar4 = iVar4 + 1;
              memcpy((void *)(iVar3 + 0x24),(void *)(iVar2 + 0xc),0x68);
              FUN_004086b0(&uStack_40,iVar3);
              iVar2 = FUN_00408680(iVar2);
              iVar5 = iVar4;
            }
          }
          else {
            iVar2 = FUN_00408680(iVar2);
          }
        }
      }
      if (param_7 != (int *)0x0) {
        *param_7 = iVar1;
      }
    }
code_r0x00638604:
    FUN_00407f30(DAT_007cc6bc);
    iVar1 = FUN_004081b0(&uStack_40);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      (*param_5)(iVar1 + 0xc,param_6);
      wsta_free(iVar1);
      iVar1 = iVar2;
    }
  }
  return iVar5;
}

