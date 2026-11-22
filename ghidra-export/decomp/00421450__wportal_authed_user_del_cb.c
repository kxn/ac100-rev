// func _wportal_authed_user_del_cb @ 00421450 size=1420

void _wportal_authed_user_del_cb(byte *param_1,int *param_2)

{
  char *__s;
  size_t sVar1;
  FILE *__s_00;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char local_238 [20];
  char acStack_224 [132];
  undefined1 auStack_1a0 [12];
  undefined1 auStack_194 [8];
  undefined4 local_18c;
  undefined1 auStack_16c [36];
  undefined1 auStack_148 [40];
  byte local_120;
  byte local_11f;
  undefined1 auStack_fd [225];
  
  memset(acStack_224,0,0x80);
  local_238[0] = '\0';
  local_238[1] = '\0';
  local_238[2] = '\0';
  local_238[3] = '\0';
  local_238[4] = '\0';
  local_238[5] = '\0';
  local_238[6] = '\0';
  local_238[7] = '\0';
  local_238[8] = '\0';
  local_238[9] = '\0';
  local_238[10] = '\0';
  local_238[0xb] = '\0';
  local_238[0xc] = '\0';
  local_238[0xd] = '\0';
  local_238[0xe] = '\0';
  local_238[0xf] = '\0';
  local_238[0x10] = '\0';
  local_238[0x11] = '\0';
  memset(auStack_1a0,0,0x180);
  snprintf(local_238,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  memset(auStack_1a0,0,0x180);
  local_18c = *(undefined4 *)(param_1 + 8);
  local_120 = param_1[0x93];
  local_11f = param_1[0xbc];
  memcpy(auStack_194,param_1,6);
  memcpy(auStack_16c,param_1 + 0x8d,6);
  memcpy(auStack_148,param_1 + 0x94,0x28);
  memcpy(auStack_fd,param_1 + 0x28,100);
  wportal_db_foreach_event_list(1,auStack_1a0,0);
  if (param_2 == (int *)0x0) {
    iVar2 = json_object_new_object();
    if (iVar2 != 0) {
      uVar4 = json_object_new_int(1);
      json_object_object_add(iVar2,"type",uVar4);
      uVar4 = json_object_new_string(local_238);
      json_object_object_add(iVar2,"mac",uVar4);
      uVar4 = json_object_new_int(6);
      json_object_object_add(iVar2,"terminate_type",uVar4);
      wportal_send_to_nginx(iVar2);
      json_object_put(iVar2);
      return;
    }
    if (wportal_err_switch == 0) {
      return;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return;
    }
    uVar4 = 0xd8e;
  }
  else if (param_2[1] < 10000) {
    iVar2 = json_object_new_object();
    if (iVar2 != 0) {
      uVar4 = json_object_new_string(local_238);
      json_object_object_add(iVar2,"mac",uVar4);
      uVar4 = json_object_new_int(6);
      json_object_object_add(iVar2,"terminate_type",uVar4);
      iVar3 = *param_2;
LAB_004215d0:
      json_object_array_add(iVar3,iVar2);
      param_2[1] = param_2[1] + 1;
      return;
    }
    if (wportal_err_switch == 0) {
      return;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return;
    }
    uVar4 = 0xda4;
  }
  else {
    __s = (char *)json_object_to_json_string_ext(*param_2,0);
    if (__s == (char *)0x0) {
      if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n","_wportal_authed_user_del_cb",
               0xdb3);
      }
    }
    else {
      sVar1 = strlen(__s);
      sprintf(acStack_224,"%s_%d_%d","/tmp/wportal_authed_list_by_mode_id",del_id,param_2[2]);
      __s_00 = fopen(acStack_224,"w");
      if (__s_00 == (FILE *)0x0) {
        if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n","_wportal_authed_user_del_cb",
                 0xdbc,acStack_224);
        }
      }
      else {
        sVar1 = fwrite(__s,sVar1,1,__s_00);
        if (sVar1 == 1) {
          fclose(__s_00);
          iVar2 = json_object_new_object();
          uVar4 = json_object_new_int(2);
          json_object_object_add(iVar2,"type",uVar4);
          uVar4 = json_object_new_int(param_2[1]);
          json_object_object_add(iVar2,"count",uVar4);
          uVar4 = json_object_new_string(acStack_224);
          json_object_object_add(iVar2,"filename",uVar4);
          wportal_send_to_nginx(iVar2);
          if (iVar2 != 0) {
            json_object_put(iVar2);
          }
        }
        else {
          if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d write result to file fail!\n","_wportal_authed_user_del_cb"
                   ,0xdc2);
          }
          fclose(__s_00);
        }
      }
    }
    json_object_put(*param_2);
    *param_2 = 0;
    iVar2 = json_object_new_array();
    if (iVar2 == 0) {
      if (wportal_err_switch == 0) {
        return;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return;
      }
      uVar4 = 0xddb;
    }
    else {
      *param_2 = iVar2;
      param_2[1] = 0;
      param_2[2] = param_2[2] + 1;
      iVar2 = json_object_new_object();
      if (iVar2 != 0) {
        uVar4 = json_object_new_string(local_238);
        json_object_object_add(iVar2,"mac",uVar4);
        uVar4 = json_object_new_int(*(undefined4 *)(param_1 + 8));
        json_object_object_add(iVar2,"vlan_id",uVar4);
        if (g_portal_auth_mode == 0) {
          uVar4 = json_object_new_int(*(undefined4 *)(param_1 + 8));
          json_object_object_add(iVar2,"serv_id",uVar4);
          iVar3 = *param_2;
        }
        else {
          iVar3 = *param_2;
        }
        goto LAB_004215d0;
      }
      if (wportal_err_switch == 0) {
        return;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return;
      }
      uVar4 = 0xde5;
    }
  }
  printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n","_wportal_authed_user_del_cb",uVar4);
  return;
}

