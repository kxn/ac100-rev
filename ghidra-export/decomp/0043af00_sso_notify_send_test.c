// func sso_notify_send_test @ 0043af00 size=1

/* WARNING: Removing unreachable block (ram,0x0043a66c) */
/* WARNING: Removing unreachable block (ram,0x0043a754) */
/* WARNING: Removing unreachable block (ram,0x0043a708) */
/* WARNING: Removing unreachable block (ram,0x0043a70c) */
/* WARNING: Removing unreachable block (ram,0x0043a714) */
/* WARNING: Removing unreachable block (ram,0x0043a724) */

void sso_notify_send_test(void)

{
  char cVar1;
  int iVar2;
  char *__dest;
  char *__src;
  int iVar3;
  char acStack_c68 [68];
  char acStack_c24 [512];
  char acStack_a24 [512];
  char acStack_824 [512];
  char acStack_624 [512];
  char acStack_424 [1028];
  
  memcpy(acStack_c68,"http://%s:%d/cgi-bin/caauth.cgi?ui=web&opr=%s&chk_cookie=0&info=%s",0x43);
  memset(acStack_624,0,0x200);
  memset(acStack_824,0,0x200);
  memset(acStack_a24,0,0x200);
  memset(acStack_c24,0,0x200);
  memset(acStack_424,0,0x400);
  if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d sso notify sangfor. opr: %s, username: %s, ip: %s\n",
           "_sso_notify_sangfor_server",0xc4,"logon",&UNK_00681180,&UNK_00681188);
  }
  memset(acStack_624,0,0x200);
  memset(acStack_824,0,0x200);
  memset(acStack_a24,0,0x200);
  memset(acStack_c24,0,0x200);
  memset(acStack_424,0,0x400);
  sprintf(acStack_824,"%s/%s//",&UNK_00681188,&UNK_00681180);
  iVar3 = 0;
  _sso_notify_base64_encode(acStack_824,acStack_a24);
  iVar2 = 0;
  do {
    while( true ) {
      cVar1 = acStack_a24[iVar3];
      if (cVar1 == '\0') {
        acStack_c24[iVar2] = '\0';
        FUN_004082d0(wportal_sso_notify_config_mutex,0xffffffff);
        sprintf(acStack_624,acStack_c68,&g_sangfor_sso_config,DAT_0075a2d0,"logon",acStack_c24);
        FUN_00407f30(wportal_sso_notify_config_mutex);
        if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d info: %s\n","_sso_notify_sangfor_server",0xdd,acStack_824);
        }
        if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d base64_info: %s\n","_sso_notify_sangfor_server",0xde,
                 acStack_a24);
        }
        if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d uri_info: %s\n","_sso_notify_sangfor_server",0xdf,
                 acStack_c24);
        }
        if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d url: %s\n","_sso_notify_sangfor_server",0xe0,acStack_624);
        }
        sprintf(acStack_424,"/lib/wportal/sso_do_http.sh \'%s\'",acStack_624);
        system(acStack_424);
        return;
      }
      if (cVar1 != '+') break;
      __dest = acStack_c24 + iVar2;
      __src = "%2B";
LAB_0043a61c:
      strcpy(__dest,__src);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 3;
    }
    if (cVar1 == '/') {
      __dest = acStack_c24 + iVar2;
      __src = "%2F";
      goto LAB_0043a61c;
    }
    if (cVar1 == '=') {
      __dest = acStack_c24 + iVar2;
      __src = "%3D";
      goto LAB_0043a61c;
    }
    iVar3 = iVar3 + 1;
    acStack_c24[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while( true );
}

