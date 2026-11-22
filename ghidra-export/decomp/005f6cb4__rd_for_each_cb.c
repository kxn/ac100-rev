// func _rd_for_each_cb @ 005f6cb4 size=1084

undefined4 _rd_for_each_cb(void *param_1,int param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int local_2a0;
  void *local_29c;
  char local_298 [100];
  undefined1 auStack_234 [524];
  
  memset(local_298 + 0x10,0,0x54);
  memset(auStack_234,0,0x205);
  local_298[8] = '\0';
  local_298[9] = '\0';
  local_298[10] = '\0';
  local_298[0xb] = '\0';
  local_298[0xc] = '\0';
  local_298[0xd] = '\0';
  local_298[0xe] = '\0';
  local_298[0xf] = '\0';
  local_298[0] = '\0';
  local_298[1] = '\0';
  local_298[2] = '\0';
  local_298[3] = '\0';
  local_298[4] = '\0';
  local_298[5] = '\0';
  local_298[6] = '\0';
  local_298[7] = '\0';
  uVar3 = rdmngr_profile_get_max_wlan_per_rd();
  if ((uint)(param_2 + -1 >> 1) < uVar3) {
    uVar9 = 1;
    if ((g_wserv_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      pcVar7 = "<wserv>[error]%s(): %d  -> n_column[%d] invalid!\r\n";
      uVar8 = 0x16c;
LAB_005f6da0:
      uVar9 = 1;
      printf(pcVar7,"_rd_for_each_cb",uVar8,param_2);
    }
  }
  else {
    local_2a0 = 0;
    uVar3 = 0;
    local_29c = param_1;
    iVar4 = rdmngr_profile_get_max_wlan_per_rd();
    memset(param_1,0,iVar4 * 6);
    local_2a0 = -1;
    iVar4 = 0;
    while( true ) {
      uVar5 = rdmngr_profile_get_max_wlan_per_rd();
      bVar1 = uVar5 <= uVar3;
      uVar3 = uVar3 + 1;
      if (bVar1) break;
      *(undefined1 *)((int)local_29c + iVar4) = 0;
      *(char *)((int)local_29c + iVar4 + 1) = (char)uVar3;
      *(undefined2 *)((int)local_29c + iVar4 + 2) = 0xffff;
      *(undefined2 *)((int)local_29c + iVar4 + 4) = 0xffff;
      iVar4 = iVar4 + 6;
    }
    bVar1 = false;
    for (iVar4 = 0; iVar4 < param_2; iVar4 = iVar4 + 1) {
      if (((char *)*param_4 == (char *)0x0) || (pcVar7 = (char *)*param_3, pcVar7 == (char *)0x0)) {
        if (g_wserv_error == 0) {
          return 1;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 1;
        }
        pcVar7 = "<wserv>[error]%s(): %d  -> column_name or column_value is null!\r\n";
        uVar8 = 0x178;
        goto LAB_005f70c0;
      }
      iVar6 = strcmp((char *)*param_4,"radio_id");
      if (iVar6 == 0) {
        local_2a0 = atoi(pcVar7);
        iVar6 = rdmngr_db_rd_entry_get(local_2a0,local_298 + 0x10);
        if (((iVar6 != 0) && (bVar1 = true, g_wserv_error != 0)) &&
           (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          pcVar7 = "<wserv>[debug]%s(): %d  -> rdmngr_db_rd_entry_get failed.\r\n";
          uVar8 = 0x181;
LAB_005f7030:
          bVar1 = true;
          printf(pcVar7,"_rd_for_each_cb",uVar8);
        }
      }
      else {
        iVar10 = iVar4 + 1 >> 1;
        snprintf(local_298 + 8,8,"wserv%d",iVar10);
        snprintf(local_298,8,"vlan%d",iVar10);
        pcVar7 = (char *)*param_4;
        iVar6 = strcmp(pcVar7,local_298 + 8);
        pvVar2 = local_29c;
        if (iVar6 == 0) {
          iVar10 = (iVar10 + -1) * 6;
          iVar6 = atoi((char *)*param_3);
          *(short *)((int)pvVar2 + iVar10 + 2) = (short)iVar6;
          iVar6 = (int)*(short *)((int)local_29c + iVar10 + 2);
          if (((iVar6 != -1) && (iVar6 = wserv_db_get_entry_by_id(iVar6,auStack_234), iVar6 != 0))
             && ((bVar1 = true, g_wserv_error != 0 && (iVar6 = is_target_debug_ap(), iVar6 != 0))))
          {
            pcVar7 = "<wserv>[debug]%s(): %d  -> wserv_id is invalid.\r\n";
            uVar8 = 399;
            goto LAB_005f7030;
          }
        }
        else {
          iVar6 = strcmp(pcVar7,local_298);
          pvVar2 = local_29c;
          if (iVar6 == 0) {
            iVar6 = atoi((char *)*param_3);
            *(short *)((int)pvVar2 + (iVar10 + -1) * 6 + 4) = (short)iVar6;
          }
          else {
            iVar6 = strcmp(pcVar7,"priv_key");
            if (iVar6 != 0) {
              if (g_wserv_error == 0) {
                return 1;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                return 1;
              }
              param_2 = *param_4;
              pcVar7 = "<wserv>[error]%s(): %d  -> invalid column_name[%s]!\r\n";
              uVar8 = 0x19b;
              goto LAB_005f6da0;
            }
          }
        }
      }
      param_3 = param_3 + 1;
      param_4 = param_4 + 1;
    }
    if (bVar1) {
      uVar9 = 0;
      FUN_00407ec0(local_2a0,g_invalid_rf_id,&g_invalid_rf_id_pos);
    }
    else {
      uVar9 = 0;
      iVar4 = wserv_db_rd_load(&local_2a0);
      if (((iVar4 != 0) && (uVar9 = 1, g_wserv_error != 0)) &&
         (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        pcVar7 = "<wserv>[error]%s(): %d  -> wserv_db_entry_load() fail!\r\n";
        uVar8 = 0x1a9;
LAB_005f70c0:
        uVar9 = 1;
        printf(pcVar7,"_rd_for_each_cb",uVar8);
      }
    }
  }
  return uVar9;
}

