// func _apmngr_collect_reboot_ap_ids @ 0052a720 size=204

undefined4 _apmngr_collect_reboot_ap_ids(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar2 = 1;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input ap_entry or data invalid.\n",
             "_apmngr_collect_reboot_ap_ids",0x276);
    }
  }
  else {
    uVar2 = 0;
    if ((*(int *)(param_1 + 0x2ac) - 2U < 2) && (*(int *)(param_1 + 0x24) == 0)) {
      if (*(char *)(param_2 + 2) == '\0') {
        iVar1 = param_2[1];
      }
      else {
        if (*(char *)(param_1 + 0x26c) != *(char *)(param_2 + 2)) {
          return 0;
        }
        iVar1 = param_2[1];
      }
      uVar2 = 0;
      *(undefined2 *)(*param_2 + iVar1 * 2) = *(undefined2 *)(param_1 + 0x10);
      param_2[1] = iVar1 + 1;
    }
  }
  return uVar2;
}

