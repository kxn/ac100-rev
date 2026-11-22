// func _bind_entries_foreach @ 00461ca8 size=572

undefined4 _bind_entries_foreach(int param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  if (g_dhcpdef_info == 0) {
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x3c);
    }
    else {
      printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_bind_entries_foreach",0x52b,
             "_bind_entries_foreach");
      iVar1 = *(int *)(param_1 + 0x3c);
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_set_bind_entries_arg",0x502,
           "_set_bind_entries_arg");
  }
  if (param_2 == (int *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = "arg";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar4 = 0x503;
  }
  else {
    if (param_2[5] == 0) {
      iVar1 = param_2[4];
    }
    else if ((code *)param_2[6] == (code *)0x0) {
      iVar1 = param_2[4];
    }
    else {
      iVar1 = (*(code *)param_2[6])(*(undefined2 *)(param_1 + 0x10));
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = param_2[4];
    }
    param_2[4] = iVar1 + 1;
    if (*param_2 < param_2[1]) {
      if (g_dhcpdef_info == 0) {
        iVar1 = *param_2;
      }
      else {
        iVar3 = is_target_debug_ap();
        iVar1 = *param_2;
        if (iVar3 != 0) {
          printf("[%s]<%s():%d> current p_arg->offset_cnt[%d] do NOT reach p_arg->offset[%d] yet!\r\n"
                 ,"dhcp_defend","_set_bind_entries_arg",0x517,iVar1,param_2[1]);
          iVar1 = *param_2;
        }
      }
      *param_2 = iVar1 + 1;
      return 0;
    }
    iVar1 = param_2[3];
    param_2[3] = iVar1 + 1;
    if (iVar1 + 1 <= param_2[2]) {
      _get_bind_entry_json(param_1,param_2);
      return 0;
    }
    if (g_dhcpdef_info == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = (char *)param_2[2];
    __format = "[%s]<%s():%d> reach limit[%d], do NOT call _get_bind_entry_json() anymore!\r\n";
    uVar4 = 0x51f;
  }
  printf(__format,"dhcp_defend","_set_bind_entries_arg",uVar4,pcVar2);
  return 0;
}

