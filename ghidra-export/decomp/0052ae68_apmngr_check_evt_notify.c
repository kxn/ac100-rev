// func apmngr_check_evt_notify @ 0052ae68 size=456

undefined4 apmngr_check_evt_notify(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Triger a %s check event.\n","apmngr_check_evt_notify",0x1e6,
           (&apmngr_check_evt_str)[param_1]);
  }
  iVar1 = FUN_004081b0(&g_apmngr_check_callback_list);
  do {
    if (iVar1 == 0) {
      return 1;
    }
    if (param_1 == 0) {
      if ((*(code **)(iVar1 + 0x14) != (code *)0x0) &&
         (iVar2 = (**(code **)(iVar1 + 0x14))(), iVar2 == 0)) {
        if (apmngr_warning_switch == '\0') {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        __format = "[APMNGR_WARNING]%s()/%d Auto reboot check failed of [%s].\n";
        uVar3 = 0x1f1;
LAB_0052af6c:
        printf(__format,"apmngr_check_evt_notify",uVar3,*(undefined4 *)(iVar1 + 0xc));
        return 0;
      }
    }
    else if ((param_1 == 1) && (*(code **)(iVar1 + 0x18) != (code *)0x0)) {
      if (param_2 == 0) {
        if (apmngr_err_switch == '\0') {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        printf("[APMNGR_ERROR]%s()/%d Illegal join check para.\n","apmngr_check_evt_notify",0x1fb);
        return 0;
      }
      iVar2 = (**(code **)(iVar1 + 0x18))(param_2,*(undefined4 *)(param_2 + 0x2d8));
      if (iVar2 == 0) {
        if (apmngr_warning_switch == '\0') {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        __format = "[APMNGR_WARNING]%s()/%d Join check failed of [%s].\n";
        uVar3 = 0x200;
        goto LAB_0052af6c;
      }
    }
    iVar1 = FUN_00408680(iVar1);
  } while( true );
}

