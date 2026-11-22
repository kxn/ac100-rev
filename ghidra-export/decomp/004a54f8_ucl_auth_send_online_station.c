// func ucl_auth_send_online_station @ 004a54f8 size=1308

undefined4 ucl_auth_send_online_station(int param_1,undefined1 *param_2,int *param_3)

{
  void *__s;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int local_180;
  undefined4 local_17c;
  undefined1 auStack_178 [4];
  undefined1 auStack_174 [4];
  undefined1 auStack_170 [4];
  undefined1 auStack_16c [4];
  undefined1 auStack_168 [4];
  char *local_164;
  int local_160;
  void *local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  char acStack_148 [31];
  undefined1 local_129;
  undefined4 local_128 [64];
  
  local_164 = (char *)0x0;
  local_160 = 0;
  local_15c = (void *)0x0;
  local_158 = 0;
  local_154 = 0;
  local_150 = 0;
  local_14c = 0;
  local_180 = 0;
  memset(local_128,0,0x100);
  memset(acStack_148,0,0x20);
  if (((param_1 == 0) || (param_2 == (undefined1 *)0x0)) || (param_3 == (int *)0x0)) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar9 = 0x208;
    pcVar7 = "[UCL_AUTH_ERR]%s()/%d Para is invalid.\n";
  }
  else {
    if (ucl_info_switch != 0) {
      printf("[UCL_AUTH_INFO]%s()/%d Online station request message: %s\n",
             "ucl_auth_send_online_station",0x20c,param_1);
    }
    __s = (void *)uac_mem_malloc_my(0xc80,0x20e);
    if (__s != (void *)0x0) {
      memset(__s,0,0xc80);
      local_154 = 0;
      local_164 = "/tums/ucl/v1/addUclAuthTerminal";
      local_158 = 0xc80;
      local_160 = param_1;
      local_15c = __s;
      iVar1 = sendto_business_by_short_link(&local_164,&local_180);
      if ((iVar1 != 0) || (local_180 != 0)) {
        if (ucl_warn_switch != 0) {
          printf("[UCL_AUTH_WARN]%s()/%d Report online station to NMS failed.\n",
                 "ucl_auth_send_online_station",0x21e);
        }
        if (ucl_warn_switch != 0) {
          printf("[UCL_AUTH_WARN]%s()/%d Error code is %d.\n","ucl_auth_send_online_station",0x21f,
                 local_180);
        }
        uac_mem_free_my(__s);
        return 0xffffffff;
      }
      iVar1 = json_tokener_parse(__s);
      if (((iVar1 != 0) && (iVar2 = json_object_object_get(iVar1,"result"), iVar2 != 0)) &&
         (iVar2 = json_object_object_get(iVar2,"deleteList"), iVar2 != 0)) {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 5) {
          puVar10 = local_128;
          puVar8 = puVar10;
          for (iVar3 = 0; iVar4 = json_object_array_length(iVar2), iVar3 < iVar4; iVar3 = iVar3 + 1)
          {
            if (iVar3 == 0x40) goto LAB_004a58c4;
            uVar9 = json_object_array_get_idx(iVar2,iVar3);
            *puVar8 = uVar9;
            puVar8 = puVar8 + 1;
          }
          if (0 < iVar3) {
LAB_004a58c4:
            iVar2 = 0;
            do {
              iVar4 = json_object_object_get(*puVar10,"mac");
              if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"ucl_auth_send_online_station",0x235);
                }
                pcVar7 = "";
              }
              else {
                pcVar7 = (char *)json_object_get_string(iVar4);
              }
              strncpy(acStack_148,pcVar7,0x1f);
              local_129 = 0;
              sscanf(acStack_148,"%2X-%2X-%2X-%2X-%2X-%2X",&local_17c,auStack_178,auStack_174,
                     auStack_170,auStack_16c,auStack_168);
              iVar4 = 0;
              puVar6 = param_2;
              do {
                puVar8 = (undefined4 *)((int)&local_17c + iVar4);
                iVar4 = iVar4 + 4;
                *puVar6 = (char)*puVar8;
                puVar6 = puVar6 + 1;
              } while (iVar4 != 0x18);
              iVar2 = iVar2 + 1;
              puVar10 = puVar10 + 1;
              param_2 = param_2 + 6;
            } while (iVar2 < iVar3);
            *param_3 = iVar3;
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (((iVar3 != 4) || (iVar2 = json_object_object_length(iVar2), iVar2 != 0)) &&
             (jcs_err_switch != 0)) {
            printf("[JCS_ERR]%s()/%d Warning: Get objectArray with error obj or value type is unmatch.\n"
                   ,"ucl_auth_send_online_station",0x22e);
          }
        }
      }
      if (ucl_info_switch != 0) {
        printf("[UCL_AUTH_INFO]%s()/%d Receive online station message: %s\n",
               "ucl_auth_send_online_station",0x242,__s);
      }
      if (iVar1 != 0) {
        json_object_put(iVar1);
      }
      uac_mem_free_my(__s);
      return 0;
    }
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar9 = 0x211;
    pcVar7 = "[UCL_AUTH_ERR]%s()/%d Memory is not enough.\n";
  }
  printf(pcVar7,"ucl_auth_send_online_station",uVar9);
  return 0xffffffff;
}

