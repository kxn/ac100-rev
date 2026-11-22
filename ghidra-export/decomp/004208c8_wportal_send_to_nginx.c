// func wportal_send_to_nginx @ 004208c8 size=396

undefined4 wportal_send_to_nginx(int param_1)

{
  size_t sVar1;
  char *__s;
  size_t __n;
  ssize_t sVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  sockaddr local_98 [7];
  
  if (param_1 == 0) {
    uVar5 = 0xffffffff;
    if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Para null\n","wportal_send_to_nginx",0x369b);
    }
  }
  else {
    memset(local_98,0,0x6e);
    local_98[0].sa_family = 1;
    strcpy(local_98[0].sa_data,"/tmp/uac_to_nginx");
    sVar1 = strlen(local_98[0].sa_data);
    __s = (char *)json_object_to_json_string_ext(param_1,0);
    do {
      __n = strlen(__s);
      sVar2 = sendto(nginx_fd,__s,__n,0,local_98,sVar1 + 2);
      if (0 < sVar2) break;
      if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Send failed.\n","wportal_send_to_nginx",13999);
      }
      g_send_to_nginx_fail_count = g_send_to_nginx_fail_count + 1;
      piVar3 = __errno_location();
    } while ((*piVar3 == 0xb) || (*piVar3 == 4));
    uVar5 = 0;
  }
  return uVar5;
}

