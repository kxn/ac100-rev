// func _sso_notify_sangfor_server @ 0043a490 size=980

void _sso_notify_sangfor_server(int param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *__dest;
  int iVar4;
  char acStack_c68 [68];
  char local_c24 [512];
  char local_a24 [512];
  char acStack_824 [512];
  char acStack_624 [512];
  char acStack_424 [1028];
  
  memcpy(acStack_c68,"http://%s:%d/cgi-bin/caauth.cgi?ui=web&opr=%s&chk_cookie=0&info=%s",0x43);
  memset(acStack_624,0,0x200);
  memset(acStack_824,0,0x200);
  memset(local_a24,0,0x200);
  memset(local_c24,0,0x200);
  memset(acStack_424,0,0x400);
  if ((param_2 == 0) || (param_3 == 0)) {
    if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d _sso_notify_sangfor_server para invalid return\n",
             "_sso_notify_sangfor_server",0xc1);
    }
  }
  else {
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      if (param_1 == 0) {
        pcVar2 = "logout";
      }
      else {
        pcVar2 = "logon";
      }
      printf("[WPORTAL_INFO]%s()/%d sso notify sangfor. opr: %s, username: %s, ip: %s\n",
             "_sso_notify_sangfor_server",0xc4,pcVar2,param_2,param_3);
    }
    memset(acStack_624,0,0x200);
    memset(acStack_824,0,0x200);
    memset(local_a24,0,0x200);
    memset(local_c24,0,0x200);
    memset(acStack_424,0,0x400);
    sprintf(acStack_824,"%s/%s//",param_3,param_2);
    iVar4 = 0;
    _sso_notify_base64_encode(acStack_824,local_a24);
    iVar3 = 0;
    while (cVar1 = local_a24[iVar4], cVar1 != '\0') {
      if (cVar1 == '+') {
        __dest = local_c24 + iVar3;
        pcVar2 = "%2B";
LAB_0043a61c:
        strcpy(__dest,pcVar2);
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 3;
      }
      else {
        if (cVar1 == '/') {
          __dest = local_c24 + iVar3;
          pcVar2 = "%2F";
          goto LAB_0043a61c;
        }
        if (cVar1 == '=') {
          __dest = local_c24 + iVar3;
          pcVar2 = "%3D";
          goto LAB_0043a61c;
        }
        iVar4 = iVar4 + 1;
        local_c24[iVar3] = cVar1;
        iVar3 = iVar3 + 1;
      }
    }
    local_c24[iVar3] = '\0';
    FUN_004082d0(wportal_sso_notify_config_mutex,0xffffffff);
    if (param_1 == 0) {
      pcVar2 = "logout";
    }
    else {
      pcVar2 = "logon";
    }
    sprintf(acStack_624,acStack_c68,&g_sangfor_sso_config,DAT_0075a2d0,pcVar2,local_c24);
    FUN_00407f30(wportal_sso_notify_config_mutex);
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d info: %s\n","_sso_notify_sangfor_server",0xdd,acStack_824);
    }
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d base64_info: %s\n","_sso_notify_sangfor_server",0xde,local_a24);
    }
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d uri_info: %s\n","_sso_notify_sangfor_server",0xdf,local_c24);
    }
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d url: %s\n","_sso_notify_sangfor_server",0xe0,acStack_624);
    }
    sprintf(acStack_424,"/lib/wportal/sso_do_http.sh \'%s\'",acStack_624);
    system(acStack_424);
  }
  return;
}

