// func apmngr_hdap_postfix_get @ 00548358 size=140

undefined1 * apmngr_hdap_postfix_get(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == 1) {
    puVar2 = &DAT_006cd69c;
  }
  else if (param_1 == 2) {
    puVar2 = &DAT_006cd6a0;
  }
  else {
    puVar2 = &DAT_00688af8;
    if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_WARNING]%s()/%d direction is void, return null suffix.\n",
             "apmngr_hdap_postfix_get",0x5a);
    }
  }
  return puVar2;
}

