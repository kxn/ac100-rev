// func _wportal_url_parser @ 0040b330 size=1560

int * _wportal_url_parser(char *param_1)

{
  bool bVar1;
  int *__s;
  int *__s_00;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  int *__dest;
  int local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  char local_b4 [16];
  char local_a4 [136];
  
  local_b8 = 0;
  local_bc = 0;
  local_c0 = 0;
  local_c4 = 0;
  local_c8 = -1;
  memset(local_a4,0,0x80);
  __s = (int *)FUN_00408450(0x9c,0x1a00);
  if (__s == (int *)0x0) {
    if (wportal_err_switch == 0) {
      return (int *)0x0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return (int *)0x0;
    }
    printf("[WPORTAL_ERR]%s()/%d Malloc url protocol failed.\n","_wportal_url_parser",0x1a03);
    return (int *)0x0;
  }
  memset(__s,0,0x9c);
  __s_00 = (int *)FUN_00408450(0x80,0x1a08);
  if (__s_00 == (int *)0x0) {
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(__s), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Malloc url protocol failed.\n","_wportal_url_parser",0x1a0b);
    }
  }
  else {
    *(char *)__s_00 = '\0';
    *(char *)((int)__s_00 + 1) = '\0';
    *(char *)((int)__s_00 + 2) = '\0';
    *(char *)((int)__s_00 + 3) = '\0';
    if ((((*param_1 == 'h') && (param_1[1] == 't')) && (param_1[2] == 't')) && (param_1[3] == 'p'))
    {
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d url : %s\n","_wportal_url_parser",0x1a13,param_1);
      }
      sscanf(param_1,"%[^://]",__s_00);
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d protocol : %s\n","_wportal_url_parser",0x1a1d,__s_00);
      }
      sVar3 = strlen((char *)__s_00);
      bVar1 = true;
      sscanf(param_1 + sVar3 + 3,"%d.%d.%d.%d",&local_b8,&local_bc,&local_c0,&local_c4);
    }
    else {
      bVar1 = false;
      sscanf(param_1,"%d.%d.%d.%d",&local_b8,&local_bc,&local_c0,&local_c4);
    }
    sprintf(local_b4,"%d.%d.%d.%d",local_b8,local_bc,local_c0,local_c4);
    if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d url parse ip_string : %s.\n","_wportal_url_parser",0x1a29,
             local_b4);
    }
    iVar2 = strcmp(local_b4,"0.0.0.0");
    if (iVar2 != 0) {
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d host ip : %s\n","_wportal_url_parser",0x1a2c,local_b4);
      }
      sVar3 = strlen((char *)__s_00);
      sVar4 = strlen(local_b4);
      sscanf(param_1 + sVar3 + sVar4 + 3,":%d/",&local_c8);
      if (local_c8 == -1) {
        local_c8 = 0;
      }
      if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(local_b4), iVar2 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d url parse port : %d.\n","_wportal_url_parser",0x1a32,local_c8);
      }
      FUN_0051a7a8(local_b4,__s + 1);
      *__s = 0;
LAB_0040b4ac:
      __s[6] = local_c8;
      FUN_00407df0(__s_00);
      return __s;
    }
    pcVar5 = strchr(param_1,0x5b);
    if (pcVar5 != (char *)0x0) {
      pcVar5 = param_1 + 1;
      if (bVar1) {
        sVar3 = strlen((char *)__s_00);
        pcVar5 = param_1 + sVar3 + 4;
      }
      sscanf(pcVar5,"%[^]]",local_b4);
      if (local_b4[0] != '\0') {
        if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d host ipv6 : %s\n","_wportal_url_parser",0x1a48,local_b4);
        }
        if (bVar1) {
          sVar3 = strlen((char *)__s_00);
          sVar4 = strlen(local_b4);
          sVar3 = sVar3 + sVar4 + 3;
        }
        else {
          sVar3 = strlen(local_b4);
        }
        sscanf(param_1 + sVar3,":%d/",&local_c8);
        if (local_c8 == -1) {
          local_c8 = 0;
        }
        FUN_0051a7a8(local_b4,__s + 1);
        *__s = 1;
        goto LAB_0040b4ac;
      }
    }
    if (bVar1) {
      sVar3 = strlen((char *)__s_00);
      param_1 = param_1 + sVar3 + 3;
    }
    sscanf(param_1,"%[^/]",local_a4);
    if (local_a4[0] != '\0') {
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d host url : %s\n","_wportal_url_parser",0x1a6a,local_a4);
      }
      __dest = __s + 7;
      *__s = 2;
      strcpy((char *)__dest,local_a4);
      FUN_00407df0(__s_00);
      if (*__s == 2) {
        sVar3 = strlen((char *)__dest);
        iVar2 = 0;
        while( true ) {
          if (((int)sVar3 <= iVar2) || (iVar2 == 0x80)) goto LAB_0040b58c;
          if (*(char *)((int)__s + iVar2 + 0x1c) == ':') break;
          iVar2 = iVar2 + 1;
        }
        *(char *)((int)__s + iVar2 + 0x1c) = '\0';
      }
LAB_0040b58c:
      if (wportal_info_switch == 0) {
        return __s;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return __s;
      }
      printf("[WPORTAL_INFO]%s()/%d para url : %s\n","_wportal_url_parser",0x1a71,__dest);
      return __s;
    }
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d invalid url!\n","_wportal_url_parser",0x1a75);
    }
    FUN_00407df0(__s);
    __s = __s_00;
  }
  FUN_00407df0(__s);
  return (int *)0x0;
}

