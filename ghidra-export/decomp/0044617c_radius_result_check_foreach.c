// func radius_result_check_foreach @ 0044617c size=820

undefined4 radius_result_check_foreach(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (radius_err_switch != 0) {
      printf("[RADIUS_ERR]%s()/%d Para is invalid.\n","radius_result_check_foreach",0x13d2);
    }
  }
  else {
    uac_list_init(&local_2c);
    uac_list_init(&local_38);
    uac_mutex_take(*(undefined4 *)(param_1 + 0xc),0xffffffff);
    while (iVar1 = uac_list_first(*(undefined4 *)(param_1 + 0x1c)), iVar1 != 0) {
      uac_list_remove(iVar1);
      uac_list_insert_last(&local_2c,iVar1);
    }
    uac_mutex_give(*(undefined4 *)(param_1 + 0xc));
    for (iVar1 = uac_list_first(&g_radius_result_check_list); iVar1 != 0;
        iVar1 = uac_list_next(iVar1)) {
      if (radius_info_switch == 0) {
        pcVar3 = *(code **)(iVar1 + 0x2c);
      }
      else {
        printf("[RADIUS_INFO]%s()/%d g_check_list reg.cb\n","radius_result_check_foreach",0x13ea);
        pcVar3 = *(code **)(iVar1 + 0x2c);
      }
      (*pcVar3)(&local_2c,&local_38);
    }
    uac_mutex_take(*(undefined4 *)(param_1 + 0xc),0xffffffff);
    iVar1 = uac_list_first(&local_2c);
    while (iVar1 != 0) {
      if (radius_debug_switch != 0) {
        printf("[RADIUS_DEBUG]%s()/%d check list _radius_send_result_to_ngx timer_node->result is %d\n"
               ,"radius_result_check_foreach",0x13f6,*(undefined4 *)(iVar1 + 0x48));
      }
      _radius_send_result_to_ngx(iVar1 + -0x570,iVar1 + 0x40);
      uac_list_remove(iVar1);
      uac_list_insert_last(*(undefined4 *)(param_1 + 0x14),iVar1);
      iVar1 = uac_list_first(&local_2c);
    }
    iVar1 = uac_list_first(&local_38);
    while (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x48) = 0xffffffff;
      if (radius_debug_switch != 0) {
        printf("[RADIUS_DEBUG]%s()/%d _radius_send_result_to_ngx timer_node->result is UAC_ERROR\n",
               "radius_result_check_foreach",0x1404);
      }
      _radius_send_result_to_ngx(iVar1 + -0x570,iVar1 + 0x40);
      uac_list_remove(iVar1);
      uac_list_insert_last(*(undefined4 *)(param_1 + 0x14),iVar1);
      iVar1 = uac_list_first(&local_38);
    }
    uVar2 = 0;
    uac_mutex_give(*(undefined4 *)(param_1 + 0xc));
  }
  return uVar2;
}

