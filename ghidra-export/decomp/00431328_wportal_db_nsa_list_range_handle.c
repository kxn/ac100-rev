// func wportal_db_nsa_list_range_handle @ 00431328 size=696

undefined4
wportal_db_nsa_list_range_handle
          (uint param_1,uint param_2,code *param_3,undefined4 param_4,int param_5,code *param_6,
          undefined4 param_7,int *param_8)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *__format;
  undefined4 uVar7;
  uint uVar8;
  
  bVar1 = nsa_list == 0;
  *param_8 = 0;
  if (bVar1) {
    uVar6 = 0xffffffff;
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d inputs error.\n";
    uVar7 = 0x15d7;
  }
  else {
    if (((param_2 != 0) && (param_3 != (code *)0x0)) && ((param_5 == 0 || (param_6 != (code *)0x0)))
       ) {
      FUN_004082d0(wportal_nsa_mutex,0xffffffff);
      iVar2 = FUN_00407fe0(nsa_list);
      iVar4 = nsa_list;
      *param_8 = iVar2;
      uVar3 = FUN_00407fe0(iVar4);
      if (uVar3 < param_1) {
        if ((wportal_debug_switch != 0) &&
           (iVar4 = is_target_debug_ap(wportal_nsa_mutex), iVar4 != 0)) {
          uVar6 = FUN_00407fe0(nsa_list);
          printf("[WPORTAL_DBG]%s()/%d offset[%d] is out of range, nsalist size[%d]!\n",
                 "wportal_db_nsa_list_range_handle",0x15e9,param_1,uVar6);
        }
        FUN_00407f30(wportal_nsa_mutex);
        return 0xffffffff;
      }
      uVar3 = 0;
      uVar8 = 0;
      iVar4 = FUN_004081b0(nsa_list);
      while (iVar2 = iVar4, iVar2 != 0) {
        iVar4 = FUN_00408680(iVar2);
        if (uVar8 < param_1) {
          if ((param_5 == 0) || (iVar2 = (*param_6)(iVar2,param_7), iVar2 != 0)) {
            uVar8 = uVar8 + 1;
          }
        }
        else {
          if ((param_5 == 0) && (param_2 <= uVar3)) goto LAB_00431438;
          if (param_2 <= uVar3) {
            iVar5 = (*param_6)(iVar2,param_7);
            uVar3 = uVar3 + (iVar5 != 0);
          }
          if ((uVar3 < param_2) &&
             ((param_5 == 0 || (iVar5 = (*param_6)(iVar2,param_7), iVar5 != 0)))) {
            uVar3 = uVar3 + 1;
            (*param_3)(iVar2,param_4);
          }
        }
      }
      if (param_5 != 0) {
        *param_8 = uVar3 + param_1;
      }
LAB_00431438:
      FUN_00407f30(wportal_nsa_mutex);
      return 0;
    }
    uVar6 = 0;
    if (wportal_debug_switch == 0) {
      return 0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0;
    }
    __format = "[WPORTAL_DBG]%s()/%d nothing need be done.\n";
    uVar7 = 0x15de;
  }
  printf(__format,"wportal_db_nsa_list_range_handle",uVar7);
  return uVar6;
}

