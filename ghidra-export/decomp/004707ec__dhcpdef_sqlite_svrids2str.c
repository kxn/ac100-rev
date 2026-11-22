// func _dhcpdef_sqlite_svrids2str @ 004707ec size=568

int _dhcpdef_sqlite_svrids2str(uint *param_1,char *param_2,char *param_3,char *param_4)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char local_30 [16];
  
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_30[4] = '\0';
  local_30[5] = '\0';
  local_30[6] = '\0';
  local_30[7] = '\0';
  local_30[8] = '\0';
  local_30[9] = '\0';
  if ((param_1 == (uint *)0x0) || (param_3 == (char *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","_dhcpdef_sqlite_svrids2str",0x1ed,
           "id_list && id_str");
    return -1;
  }
  pcVar4 = param_4;
  pcVar1 = (char *)dhcpdef_db_get_max_svr_per_ap();
  if (pcVar1 < param_2) {
    iVar7 = -1;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      return -1;
    }
    pcVar4 = "\x1b[31;49m[%s]<%s():%d> Invalid list_len[%d]!\x1b[0m\r\n";
    uVar5 = 0x1f1;
    param_3 = param_2;
  }
  else {
    iVar7 = dhcpdef_db_get_max_svr_per_ap();
    if (param_4 < (char *)(iVar7 * 6)) {
      iVar7 = -1;
      if (g_dhcpdef_error == 0) {
        return -1;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return -1;
      }
      dhcpdef_db_get_max_svr_per_ap();
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> Invalid str_len[%d], less than %d!\x1b[0m\r\n";
      uVar5 = 0x1f7;
      param_3 = param_4;
    }
    else {
      iVar7 = 0;
      pcVar1 = (char *)0x0;
      memset(param_3,0,(size_t)(param_4 + 1));
      while (pcVar1 != param_2) {
        uVar6 = *param_1;
        if (((int)uVar6 < 0) || (uVar3 = dhcpdef_db_get_max_server(), uVar3 <= uVar6)) {
          pcVar1 = pcVar1 + 1;
          param_1 = param_1 + 1;
        }
        else {
          uVar6 = (uint)param_1 & 3;
          iVar7 = iVar7 + 1;
          uVar3 = (int)param_1 + 3U & 3;
          pcVar4 = (char *)((*(int *)((int)param_1 - uVar6) << uVar6 * 8 |
                            (uint)pcVar4 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar3 + 1) * 8 |
                           *(uint *)(((int)param_1 + 3U) - uVar3) >> (3 - uVar3) * 8);
          pcVar1 = pcVar1 + 1;
          param_1 = param_1 + 1;
          snprintf(local_30,10,"%d,",pcVar4);
          strcat(param_3,local_30);
        }
      }
      if (g_dhcpdef_info == 0) {
        return iVar7;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return iVar7;
      }
      pcVar4 = "[%s]<%s():%d> id_str: %s, id_num: %d\r\n";
      uVar5 = 0x208;
    }
  }
  printf(pcVar4,"dhcp_defend","_dhcpdef_sqlite_svrids2str",uVar5,param_3);
  return iVar7;
}

