// func apupd_status_get @ 006497c0 size=1

undefined4 apupd_status_get(undefined4 *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  bool bVar8;
  
  if (param_1 == (undefined4 *)0x0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_status_get_by_state",0x1c19);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  if (apupd_model_list == 0) {
    if ((g_apupd_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar7 = 0x1ba7;
LAB_00652ef4:
      printf(__format,"apudp_status_get_by_config_state",uVar7);
    }
LAB_00652dc0:
    uVar7 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: apupd get status failed.\r\n","apupd_db_status_get_by_state"
             ,0x1c23);
    }
    goto LAB_00652dd0;
  }
  iVar5 = FUN_004081b0();
  bVar4 = true;
  bVar3 = false;
  bVar1 = false;
  bVar2 = false;
  bVar8 = false;
  for (; iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
    switch(*(undefined4 *)(iVar5 + 0x140)) {
    case 0:
      break;
    case 1:
      bVar8 = true;
      break;
    case 2:
      bVar2 = true;
      break;
    case 3:
      bVar1 = true;
      if (*apupd_config == 0) {
        for (iVar6 = FUN_004081b0(iVar5 + 0x7f4); iVar6 != 0; iVar6 = FUN_00408680(iVar6)) {
          if (*(int *)(iVar6 + 0x48) - 6U < 2) {
            bVar4 = false;
            bVar1 = true;
            goto switchD_00652e14_caseD_0;
          }
        }
        bVar1 = true;
      }
      break;
    case 4:
      bVar3 = true;
      break;
    default:
      if ((g_apupd_error == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00652dc0;
      __format = "[APUPD_ERROR]%32s() %05d: model state is invalib.\r\n";
      uVar7 = 0x1bdc;
      goto LAB_00652ef4;
    }
switchD_00652e14_caseD_0:
  }
  if (bVar1) {
    uVar7 = 3;
    if (*apupd_config == 0) {
      if (bVar4) {
        uVar7 = 5;
      }
      *param_1 = uVar7;
    }
    else {
      *param_1 = 3;
    }
  }
  else if (bVar2) {
    *param_1 = 2;
  }
  else {
    if (bVar8) {
      *param_1 = 1;
      uVar7 = 0;
      goto LAB_00652dd0;
    }
    if (!bVar3) {
      *param_1 = 0;
      uVar7 = 0;
      goto LAB_00652dd0;
    }
    *param_1 = 4;
  }
  uVar7 = 0;
LAB_00652dd0:
  FUN_00407f30(apupd_db_mutex);
  return uVar7;
}

