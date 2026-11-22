// func wsta_db_wlan_sta_foreach @ 00638e1c size=684

int wsta_db_wlan_sta_foreach
              (uint param_1,uint param_2,uint param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xff;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if (((int)param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= (int)param_1)) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
    uVar6 = 0xa15;
    param_3 = param_1;
  }
  else if ((param_2 == 0) || (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar2 < param_2)) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
    uVar6 = 0xa1a;
    param_3 = param_2;
  }
  else {
    if ((param_3 != 0) && (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), param_3 <= uVar2)) {
      FUN_0051ad88(&local_38);
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      iVar1 = 0;
      if (*(int *)(*(int *)(*(int *)(DAT_007cc6e4 + param_1 * 4) + (param_2 - 1) * 4) +
                   (param_3 - 1) * 0xc + 8) != 0) {
        iVar3 = FUN_004081b0();
        while (iVar3 != 0) {
          iVar4 = FUN_00408680(iVar3);
          iVar5 = wsta_calloc(1,0x80,"wsta_db_wlan_sta_foreach",0xa2d);
          if (iVar5 != 0) {
            memcpy((void *)(iVar5 + 0x18),(void *)(iVar3 + 0x18),0x68);
            FUN_004086b0(&local_38,iVar5 + 0xc);
          }
          iVar1 = iVar1 + 1;
          iVar3 = iVar4;
        }
      }
      FUN_00407f30(DAT_007cc6bc);
      iVar3 = FUN_004081b0(&local_38);
      while (iVar3 != 0) {
        iVar4 = FUN_00408680(iVar3);
        if (param_4 != (code *)0x0) {
          (*param_4)(iVar3 + -0xc,param_5);
        }
        FUN_00408500(iVar3);
        wsta_free(iVar3 + -0xc);
        iVar3 = iVar4;
      }
      return iVar1;
    }
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid wlan_id[%d]!\r\n";
    uVar6 = 0xa1f;
  }
  printf(__format,"wsta_db_wlan_sta_foreach",uVar6,param_3);
  return -1;
}

