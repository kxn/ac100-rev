// func cw_priv_sta_statistics_create @ 005c7858 size=436

int cw_priv_sta_statistics_create(uint *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 == 0) || ((iVar3 = 0, param_1[1] != 0 && (*param_1 < 0xc9)))) {
    piVar1 = (int *)cw_protocol_clone(param_1,8);
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sta_statistics_create",0x119)
        ;
      }
    }
    else {
      piVar1[1] = 0;
      if (*param_1 == 0) {
        iVar3 = *piVar1;
      }
      else if (param_1[1] == 0) {
        iVar3 = *piVar1;
      }
      else {
        iVar3 = cw_protocol_clone(param_1[1],*param_1 * 0x28 & 0xfff8);
        piVar1[1] = iVar3;
        if (iVar3 == 0) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to clone sta_list\n","cw_priv_sta_statistics_create"
                   ,0x124);
          }
          FUN_00407df0(piVar1);
          return 0;
        }
        iVar3 = *piVar1;
      }
      iVar3 = cw_protocol_msg_ele_create(0x52,iVar3 * 0x26 + 4U & 0xfffe,piVar1);
      if (iVar3 == 0) {
        if (capwap_err_switch == 0) {
          iVar2 = piVar1[1];
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = piVar1[1];
          }
          else {
            printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                   "cw_priv_sta_statistics_create",0x12e);
            iVar2 = piVar1[1];
          }
        }
        if (iVar2 != 0) {
          FUN_00407df0();
        }
        FUN_00407df0(piVar1);
      }
    }
  }
  return iVar3;
}

