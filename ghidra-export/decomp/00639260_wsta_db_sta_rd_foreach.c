// func wsta_db_sta_rd_foreach @ 00639260 size=688

int wsta_db_sta_rd_foreach(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_30;
  int local_2c;
  
  param_2 = param_2 & 0xff;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if (((int)param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= (int)param_1)) {
    if (g_wsta_warning == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
    uVar6 = 0xb9f;
    param_2 = param_1;
  }
  else {
    if ((param_2 != 0) && (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
      FUN_0051ad88(&local_40);
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      iVar1 = 0;
      iVar7 = 0;
      uVar2 = 1;
      local_30 = param_1 << 2;
      local_2c = (param_2 - 1) * 4;
      do {
        uVar3 = rdmngr_profile_get_max_wlan_per_rd();
        if (uVar3 < uVar2) {
LAB_006394c4:
          FUN_00407f30(DAT_007cc6bc);
          iVar1 = FUN_004081b0(&local_40);
          while (iVar1 != 0) {
            iVar5 = FUN_00408680(iVar1);
            if (param_3 != (code *)0x0) {
              (*param_3)(iVar1 + 0xc,param_4);
            }
            wsta_free(iVar1);
            iVar1 = iVar5;
          }
          return iVar7;
        }
        if (*(int *)(*(int *)(*(int *)(DAT_007cc6e4 + local_30) + local_2c) + iVar1 + 8) != 0) {
          for (iVar5 = FUN_004081b0(); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
            iVar4 = wsta_calloc(1,0x8c,"wsta_db_sta_rd_foreach",0xbb1);
            if (iVar4 == 0) {
              if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("<wsta>[error]%s(): %d  -> no memory!!\r\n","wsta_db_sta_rd_foreach",0xbb4);
              }
              goto LAB_006394c4;
            }
            iVar7 = iVar7 + 1;
            memcpy((void *)(iVar4 + 0x24),(void *)(iVar5 + 0x18),0x68);
            FUN_004086b0(&local_40,iVar4);
          }
        }
        uVar2 = uVar2 + 1;
        iVar1 = iVar1 + 0xc;
      } while( true );
    }
    if (g_wsta_warning == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
    uVar6 = 0xba4;
  }
  printf(__format,"wsta_db_sta_rd_foreach",uVar6,param_2);
  return 0;
}

