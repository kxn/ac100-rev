// func _wportal_authed_user_del_by_mode_id @ 00420e30 size=1176

undefined4 _wportal_authed_user_del_by_mode_id(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__s;
  size_t sVar3;
  FILE *__s_00;
  undefined1 uVar5;
  undefined4 uVar4;
  undefined8 uVar6;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  char acStack_94 [132];
  
  memset(acStack_94,0,0x80);
  local_a0 = json_object_new_array();
  if (local_a0 == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n","_wportal_authed_user_del_by_mode_id",
           0xe18);
    return 0xffffffff;
  }
  local_9c = 0;
  local_98 = 0;
  iVar2 = json_object_object_get(param_1,"auth_type");
  if (iVar2 == 0) {
LAB_00420eb4:
    uVar5 = 0xff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_del_by_mode_id",0xe20);
    }
  }
  else {
    iVar1 = json_object_get_type(iVar2);
    if (iVar1 == 3) {
      uVar5 = json_object_get_int(iVar2);
    }
    else {
      iVar1 = json_object_get_type();
      if (iVar1 != 2) goto LAB_00420eb4;
      uVar6 = json_object_get_double(iVar2);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
  }
  if (g_portal_auth_mode == 1) {
    iVar2 = json_object_object_get(param_1,"vlan_id");
    if (iVar2 != 0) {
      iVar1 = json_object_get_type(iVar2);
      if (iVar1 == 3) {
        iVar2 = json_object_get_int(iVar2);
        if (iVar2 == 0) {
          iVar2 = 0xfff;
        }
        goto LAB_00420f28;
      }
      iVar1 = json_object_get_type();
      if (iVar1 == 2) {
        uVar6 = json_object_get_double(iVar2);
        iVar2 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          iVar2 = 0xfff;
        }
        goto LAB_00420f28;
      }
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_del_by_mode_id",0xe25);
    }
    iVar2 = -1;
    goto LAB_00420f28;
  }
  iVar2 = json_object_object_get(param_1,"serv_id");
  if (iVar2 != 0) {
    iVar1 = json_object_get_type(iVar2);
    if (iVar1 == 3) {
      iVar2 = json_object_get_int(iVar2);
      goto LAB_00420f28;
    }
    iVar1 = json_object_get_type();
    if (iVar1 == 2) {
      uVar6 = json_object_get_double(iVar2);
      iVar2 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      goto LAB_00420f28;
    }
  }
  iVar2 = -1;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_authed_user_del_by_mode_id",0xe2c);
    iVar2 = -1;
  }
LAB_00420f28:
  wportal_db_aut_del_by_mode_id(iVar2,uVar5,_wportal_authed_user_del_cb,&local_a0);
  if (local_9c != 0) {
    __s = (char *)json_object_to_json_string_ext(local_a0,0);
    if (__s == (char *)0x0) {
      if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n",
               "_wportal_authed_user_del_by_mode_id",0xe36);
      }
    }
    else {
      sVar3 = strlen(__s);
      sprintf(acStack_94,"%s_%d_%d","/tmp/wportal_authed_list_by_mode_id",del_id,local_98);
      __s_00 = fopen(acStack_94,"w");
      if (__s_00 == (FILE *)0x0) {
        if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n",
                 "_wportal_authed_user_del_by_mode_id",0xe3f,acStack_94);
        }
      }
      else {
        sVar3 = fwrite(__s,sVar3,1,__s_00);
        if (sVar3 == 1) {
          fclose(__s_00);
          iVar2 = json_object_new_object();
          uVar4 = json_object_new_int(2);
          json_object_object_add(iVar2,"type",uVar4);
          uVar4 = json_object_new_int(local_9c);
          json_object_object_add(iVar2,"count",uVar4);
          uVar4 = json_object_new_string(acStack_94);
          json_object_object_add(iVar2,"filename",uVar4);
          wportal_send_to_nginx(iVar2);
          if (iVar2 != 0) {
            json_object_put(iVar2);
          }
        }
        else {
          if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d write result to file fail!\n",
                   "_wportal_authed_user_del_by_mode_id",0xe45);
          }
          fclose(__s_00);
        }
      }
    }
  }
  if (local_a0 != 0) {
    json_object_put();
  }
  return 0;
}

