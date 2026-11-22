// func _set_bind_svrs_arg @ 00461780 size=512

undefined4 _set_bind_svrs_arg(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_set_bind_svrs_arg",0x6a6,
           "_set_bind_svrs_arg");
  }
  if (g_dhcpdef_info == 0) {
    iVar2 = param_3[6];
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = param_3[6];
    }
    else {
      printf("[%s]<%s():%d> p_arg->offset_cnt[%d], p_arg->offset[%d], p_arg->total_size[%d]\r\n",
             "dhcp_defend","_set_bind_svrs_arg",0x6a8,param_3[1],param_3[2],param_3[5]);
      iVar2 = param_3[6];
    }
  }
  if (iVar2 == 0) {
    iVar2 = param_3[5];
  }
  else if ((code *)param_3[7] == (code *)0x0) {
    iVar2 = param_3[5];
  }
  else {
    iVar2 = (*(code *)param_3[7])(*param_3,*param_2);
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = param_3[5];
  }
  param_3[5] = iVar2 + 1;
  if ((int)param_3[1] < (int)param_3[2]) {
    if (g_dhcpdef_warn == 0) {
      iVar2 = param_3[1];
    }
    else {
      iVar1 = is_target_debug_ap();
      iVar2 = param_3[1];
      if (iVar1 != 0) {
        printf("\x1b[33;49m[%s]<%s():%d> current p_arg->offset_cnt[%d] exceeds p_arg->offset[%d]\x1b[0m\r\n"
               ,"dhcp_defend","_set_bind_svrs_arg",0x6bc,iVar2,param_3[2]);
        iVar2 = param_3[1];
      }
    }
    param_3[1] = iVar2 + 1;
  }
  else {
    iVar2 = param_3[4];
    param_3[4] = iVar2 + 1;
    if ((int)param_3[3] < iVar2 + 1) {
      if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[%s]<%s():%d> reach limit[%d], do NOT call _get_bind_svr_json() anymore!\r\n",
               "dhcp_defend","_set_bind_svrs_arg",0x6c4,param_3[4]);
      }
    }
    else {
      _get_bind_svr_json(param_2,param_3);
    }
  }
  return 0;
}

