// func cw_priv_sniffing_statistics_create @ 005c0acc size=524

int cw_priv_sniffing_statistics_create(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (500 < *param_1) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_sniffing_statistics_create",
           0xf8,*param_1);
    return 0;
  }
  if ((0 < *param_1) && (param_1[1] == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap(param_1,8);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d sta_list list is null\n";
    uVar3 = 0xfe;
LAB_005c0c5c:
    printf(pcVar4,"cw_priv_sniffing_statistics_create",uVar3);
    return 0;
  }
  iVar1 = cw_protocol_clone(param_1);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar3 = 0x106;
    goto LAB_005c0c5c;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if ((*param_1 < 1) || (param_1[1] == 0)) {
LAB_005c0b80:
    uVar3 = cw_priv_sniffing_statistics_length(iVar1);
    iVar2 = cw_protocol_msg_ele_create(0x6e,uVar3,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005c0bb4;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005c0bb4;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
    uVar3 = 0x11a;
  }
  else {
    iVar2 = cw_protocol_clone(param_1[1],*param_1 * 0x14 & 0xfffc);
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 != 0) goto LAB_005c0b80;
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005c0bb4;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005c0bb4;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d failed to clone sta_list list\n";
    uVar3 = 0x111;
  }
  printf(pcVar4,"cw_priv_sniffing_statistics_create",uVar3);
  iVar2 = *(int *)(iVar1 + 4);
LAB_005c0bb4:
  if (iVar2 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(iVar1);
  return 0;
}

