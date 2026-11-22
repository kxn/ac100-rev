// func wportal_send_to_nginx_for_return @ 00422d74 size=920

undefined4 wportal_send_to_nginx_for_return(int param_1,int *param_2,int param_3)

{
  int iVar1;
  long lVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  ssize_t sVar7;
  int *piVar8;
  socklen_t local_500;
  int local_4fc [2];
  char acStack_4f4 [100];
  sockaddr local_490 [7];
  undefined1 auStack_420 [1028];
  
  memset(auStack_420,0,0x400);
  local_500 = 0;
  memset(acStack_4f4,0,100);
  local_4fc[0] = 0;
  local_4fc[1] = 0;
  if (param_1 == 0) {
    if (wportal_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[WPORTAL_ERR]%s()/%d Para null\n";
      uVar5 = 0x36d7;
      goto LAB_00422ff0;
    }
  }
  else {
    iVar1 = socket(1,1,0);
    if (-1 < iVar1) {
      memset(local_490,0,0x6e);
      local_490[0].sa_family = 1;
      lVar2 = syscall(0x107e);
      sprintf(acStack_4f4,"%s_%lu","/tmp/nginx_to_uac",lVar2);
      unlink(acStack_4f4);
      strcpy(local_490[0].sa_data,acStack_4f4);
      sVar3 = strlen(local_490[0].sa_data);
      local_500 = sVar3 + 2;
      iVar4 = bind(iVar1,local_490,local_500);
      if (iVar4 < 0) {
        if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[WPORTAL_ERR]%s()/%d Bind send socket failed.\n",
                 "wportal_send_to_nginx_for_return",0x36ea);
        }
      }
      else {
        if (param_3 != 0) {
          local_4fc[1] = 0;
          local_4fc[0] = param_3;
          setsockopt(iVar1,0xffff,0x1006,local_4fc,8);
        }
        memset(local_490,0,0x6e);
        local_490[0].sa_family = 1;
        strcpy(local_490[0].sa_data,"/tmp/uac_to_nginx");
        sVar3 = strlen(local_490[0].sa_data);
        local_500 = sVar3 + 2;
        uVar5 = json_object_new_string(acStack_4f4);
        json_object_object_add(param_1,"clnt_path",uVar5);
        pcVar6 = (char *)json_object_to_json_string_ext(param_1,0);
        do {
          sVar3 = strlen(pcVar6);
          sVar7 = sendto(iVar1,pcVar6,sVar3,0,local_490,local_500);
          if (0 < sVar7) {
            sVar7 = recvfrom(iVar1,auStack_420,0x3ff,0,local_490,&local_500);
            if (sVar7 < 1) {
              if (wportal_debug_switch == 0) {
                *param_2 = 0;
              }
              else {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  *param_2 = 0;
                }
                else {
                  printf("[WPORTAL_DBG]%s()/%d Receive failed.\n","wportal_send_to_nginx_for_return"
                         ,0x3717);
                  *param_2 = 0;
                }
              }
            }
            else {
              auStack_420[sVar7] = 0;
              iVar4 = json_tokener_parse(auStack_420);
              *param_2 = iVar4;
              if (iVar4 != 0) {
                close(iVar1);
                return 0;
              }
            }
            goto LAB_00422f40;
          }
          if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d Send failed.\n","wportal_send_to_nginx_for_return",0x3709);
          }
          piVar8 = __errno_location();
        } while ((*piVar8 == 0xb) || (*piVar8 == 4));
        *param_2 = 0;
      }
LAB_00422f40:
      close(iVar1);
      return 0xffffffff;
    }
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar6 = "[WPORTAL_ERR]%s()/%d Create send socket failed.\n";
      uVar5 = 0x36df;
LAB_00422ff0:
      printf(pcVar6,"wportal_send_to_nginx_for_return",uVar5);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

