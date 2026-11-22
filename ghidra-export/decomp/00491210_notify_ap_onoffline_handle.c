// func notify_ap_onoffline_handle @ 00491210 size=124

undefined4 notify_ap_onoffline_handle(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 0xffffffff;
  if ((((param_1 != 0) && (uVar3 = 0, uVar2 = uVar3, *(int *)(param_1 + 0xc) != 0)) &&
      (iVar1 = _cloud_mngt_role_match(*(undefined4 *)(param_1 + 0x14)), iVar1 != 0)) &&
     (((ap_report_switch != 0 && (uVar2 = 0, *(char *)(param_1 + 0x1c5) != '\0')) &&
      (uVar2 = uVar3, *(int *)(param_1 + 0x3c) != 0)))) {
    ap_offline_or_online = 1;
  }
  return uVar2;
}

