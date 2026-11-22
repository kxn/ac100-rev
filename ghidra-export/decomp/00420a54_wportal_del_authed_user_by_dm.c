// func wportal_del_authed_user_by_dm @ 00420a54 size=988

undefined4 wportal_del_authed_user_by_dm(char *param_1)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char local_1d0 [20];
  undefined1 auStack_1bc [44];
  undefined1 auStack_190 [12];
  byte local_184;
  byte local_183;
  byte local_182;
  byte local_181;
  byte local_180;
  byte local_17f;
  
  local_1d0[0] = '\0';
  local_1d0[1] = '\0';
  local_1d0[2] = '\0';
  local_1d0[3] = '\0';
  local_1d0[4] = '\0';
  local_1d0[5] = '\0';
  local_1d0[6] = '\0';
  local_1d0[7] = '\0';
  local_1d0[8] = '\0';
  local_1d0[9] = '\0';
  local_1d0[10] = '\0';
  local_1d0[0xb] = '\0';
  local_1d0[0xc] = '\0';
  local_1d0[0xd] = '\0';
  local_1d0[0xe] = '\0';
  local_1d0[0xf] = '\0';
  local_1d0[0x10] = '\0';
  local_1d0[0x11] = '\0';
  memset(auStack_1bc,0,0x28);
  if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d wportal_del_authed_user_by_dm\n","wportal_del_authed_user_by_dm",
           0x3634);
  }
  memset(auStack_190,0,0x180);
  if (param_1[0x82] == '\0') {
    if (g_portal_auth_mode == 1) {
      if (*(int *)(param_1 + 0x180) != -1) {
LAB_00420afc:
        uVar3 = wportal_db_dae_nas_port_for_aut_del_do
                          (*(undefined4 *)(param_1 + 0x180),_wportal_aut_dae_check,param_1);
        return uVar3;
      }
      iVar2 = *(int *)(param_1 + 0x7c);
    }
    else if (g_portal_auth_mode == 0) {
      if (*(int *)(param_1 + 0x180) < 0) {
        iVar2 = *(int *)(param_1 + 0x7c);
      }
      else {
        uVar1 = wserv_profile_get_max_wservice();
        if (*(uint *)(param_1 + 0x180) < uVar1) goto LAB_00420afc;
        iVar2 = *(int *)(param_1 + 0x7c);
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x7c);
    }
    if ((iVar2 != 0) || ((*(uint *)(param_1 + 0x80) & 0xffff0000) != 0)) {
      uVar3 = wportal_db_dae_calling_station_for_aut_del_do
                        (param_1 + 0x7c,_wportal_aut_dae_check,param_1);
      return uVar3;
    }
    if (*param_1 != '\0') {
      uVar3 = wportal_db_dae_username_for_aut_del_do(param_1,_wportal_aut_dae_check,param_1);
      return uVar3;
    }
    iVar2 = FUN_00407eb0(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                         *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74),
                         *(undefined4 *)(param_1 + 0x78));
    if (iVar2 != 0) {
      FUN_00408190(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                   *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74),
                   *(undefined4 *)(param_1 + 0x78),auStack_1bc,0x28,"0.0.0.0");
      if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d ip is %s \n","wportal_del_authed_user_by_dm",0x3653,auStack_1bc
              );
      }
      uVar3 = wportal_db_dae_framed_ip_for_aut_del_do(auStack_1bc,_wportal_aut_dae_check,param_1);
      return uVar3;
    }
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_DBG]%s()/%d No attr\n";
    uVar3 = 0x3659;
  }
  else {
    iVar2 = wportal_db_dae_sessid_get(param_1,auStack_190);
    if (iVar2 == 0) {
      iVar2 = _wportal_aut_dae_check(auStack_190,param_1);
      if (iVar2 == 0) {
        uVar1 = (uint)local_183;
        if (wportal_debug_switch != 0) {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            uVar1 = (uint)local_183;
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d _wportal_aut_dae_check OK\n",
                   "wportal_del_authed_user_by_dm",0x3660);
            uVar1 = (uint)local_183;
          }
        }
        snprintf(local_1d0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_184,uVar1,
                 (uint)local_182,(uint)local_181,(uint)local_180,(uint)local_17f);
        iVar2 = json_object_new_object();
        uVar3 = json_object_new_int(1);
        json_object_object_add(iVar2,"type",uVar3);
        uVar3 = json_object_new_string(local_1d0);
        json_object_object_add(iVar2,"mac",uVar3);
        uVar3 = json_object_new_int(6);
        json_object_object_add(iVar2,"terminate_type",uVar3);
        wportal_send_to_nginx(iVar2);
        if (iVar2 == 0) {
          return 0;
        }
        json_object_put(iVar2);
        return 0;
      }
      if (wportal_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[WPORTAL_DBG]%s()/%d _wportal_aut_dae_check failed\n";
      uVar3 = 0x367a;
    }
    else {
      if (wportal_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[WPORTAL_DBG]%s()/%d Not found aut entry\n";
      uVar3 = 0x363c;
    }
  }
  printf(__format,"wportal_del_authed_user_by_dm",uVar3);
  return 0xffffffff;
}

