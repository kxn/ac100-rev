// func wportal_jcs_backup_callback @ 0040e6ac size=484

void wportal_jcs_backup_callback(undefined4 param_1,undefined4 param_2)

{
  FILE *__s;
  int iVar1;
  undefined4 uVar2;
  undefined *__ptr;
  char *__format;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d wportal_jcs_backup_callback() begin.\n",
           "wportal_jcs_backup_callback",0x25cf);
  }
  __s = fopen("/tmp/authedUser.csv","a+");
  if (__s == (FILE *)0x0) {
    if (wportal_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[WPORTAL_ERR]%s()/%d open get file[%s] fail!\n","wportal_jcs_backup_callback",0x25d3,
           "/tmp/authedUser.csv");
    return;
  }
  if (g_portal_auth_mode == 1) {
    __ptr = &DAT_00676ff4;
  }
  else {
    __ptr = &DAT_0067703c;
  }
  fwrite(__ptr,0x47,1,__s);
  iVar1 = wportal_db_authed_list_range_handle
                    (0,g_max_session,_wportal_authed_user_json_backup_callback,__s,0,0,0,local_20);
  if (iVar1 == -1) {
    if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0040e78c;
    __format = "[WPORTAL_ERR]%s()/%d get authed list failed\n";
    uVar2 = 0x25e1;
  }
  else {
    uVar2 = json_object_new_string("/tmp/authedUser.csv");
    json_object_object_add(param_2,"file_name",uVar2);
    if ((wportal_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_0040e78c;
    __format = "[WPORTAL_DBG]%s()/%d wportal_jcs_backup_callback() success.\n";
    uVar2 = 0x25e6;
  }
  printf(__format,"wportal_jcs_backup_callback",uVar2);
LAB_0040e78c:
  fclose(__s);
  return;
}

