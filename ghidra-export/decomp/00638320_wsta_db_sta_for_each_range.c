// func wsta_db_sta_for_each_range @ 00638320 size=580

int wsta_db_sta_for_each_range(uint param_1,int param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *local_30;
  
  iVar4 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if ((param_2 != 0) && (param_3 != (code *)0x0)) {
    local_30 = &local_40;
    FUN_0051ad88(local_30);
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    if (DAT_007cc6e0 < param_1) {
      iVar4 = -1;
      if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wsta>[error]%s(): %d  -> offset[%d] is out of range, wsta size[%d]!\r\n",
               "wsta_db_sta_for_each_range",0x575,param_1,DAT_007cc6e0);
      }
    }
    else if (DAT_007cc6e0 != 0) {
      iVar2 = 0;
      iVar1 = FUN_004081b0(&DAT_007cc6d8);
      iVar5 = 0;
      iVar4 = -1;
      while (iVar1 != 0) {
        if (iVar5 < (int)param_1) {
          iVar1 = FUN_00408680(iVar1);
          iVar5 = iVar5 + 1;
        }
        else {
          iVar3 = wsta_calloc(1,0x8c,"wsta_db_sta_for_each_range",0x585);
          if (iVar3 == 0) {
            if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("<wsta>[error]%s(): %d  -> no memory!!\r\n","wsta_db_sta_for_each_range",0x588)
              ;
            }
            break;
          }
          iVar2 = iVar2 + 1;
          memcpy((void *)(iVar3 + 0x24),(void *)(iVar1 + 0xc),0x68);
          FUN_004086b0(&local_40,iVar3);
          iVar1 = FUN_00408680(iVar1);
          iVar4 = iVar2;
          if (param_2 <= iVar2) break;
        }
      }
    }
    FUN_00407f30(DAT_007cc6bc);
    iVar1 = FUN_004081b0(&local_40);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      (*param_3)(iVar1 + 0xc,param_4);
      wsta_free(iVar1);
      iVar1 = iVar2;
    }
  }
  return iVar4;
}

