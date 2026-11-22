// func cw_priv_fail_station_create @ 005b127c size=524

int cw_priv_fail_station_create(uint *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (200 < *param_1) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_fail_station_create",0xf9,
           *param_1);
    return 0;
  }
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap(param_1,8);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d sta_list list is null\n";
    uVar3 = 0xff;
LAB_005b140c:
    printf(pcVar4,"cw_priv_fail_station_create",uVar3);
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
    uVar3 = 0x107;
    goto LAB_005b140c;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if ((*param_1 == 0) || (param_1[1] == 0)) {
LAB_005b1330:
    uVar3 = cw_priv_fail_station_length(iVar1);
    iVar2 = cw_protocol_msg_ele_create(0x56,uVar3,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005b1364;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005b1364;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
    uVar3 = 0x11b;
  }
  else {
    iVar2 = cw_protocol_clone(param_1[1],*param_1 * 0x14 & 0xfffc);
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 != 0) goto LAB_005b1330;
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005b1364;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 4);
      goto LAB_005b1364;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d failed to clone sta_list list\n";
    uVar3 = 0x112;
  }
  printf(pcVar4,"cw_priv_fail_station_create",uVar3);
  iVar2 = *(int *)(iVar1 + 4);
LAB_005b1364:
  if (iVar2 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(iVar1);
  return 0;
}

