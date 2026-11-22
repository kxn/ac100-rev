// func print_passthrough_response_get @ 00510184 size=1

undefined4 print_passthrough_response_get(char *param_1,int param_2)

{
  int iVar1;
  int *__s;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uStack_308;
  undefined2 uStack_304;
  undefined1 auStack_300 [728];
  
  if (ac_passthrough_debug_switch != '\0') {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d ............._ac_passthrough_response_get begin............\n"
           ,"print_passthrough_response_get",0x9cd);
  }
  uStack_308 = 0;
  uStack_304 = 0;
  memset(auStack_300,0,0x2d8);
  if ((param_1 == (char *)0x0) || (param_2 < 1)) {
    uVar5 = 0xffffffff;
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d invalid params\n","print_passthrough_response_get",0x9d9
            );
    }
  }
  else {
    iVar1 = FUN_0050c8a0(param_1);
    if (iVar1 < 1) {
      uVar5 = 0xffffffff;
      if (ac_passthrough_err_switch != '\0') {
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d _uac_nms_report_util_str_split() fail, str: %s!\n",
               "print_passthrough_response_get",0x9e1,param_1);
      }
    }
    else {
      __s = (int *)FUN_00408450(iVar1 << 2,0x9e4);
      uVar5 = 0xffffffff;
      if (__s != (int *)0x0) {
        memset(__s,0,iVar1 << 2);
        pcVar2 = strtok(param_1,",");
        piVar6 = __s;
        for (iVar4 = 0; (pcVar2 != (char *)0x0 && (iVar4 != iVar1)); iVar4 = iVar4 + 1) {
          *piVar6 = (int)pcVar2;
          pcVar2 = strtok((char *)0x0,",");
          piVar6 = piVar6 + 1;
        }
        __s[iVar4] = 0;
        iVar4 = 0;
        piVar6 = __s;
        do {
          uStack_308 = 0;
          uStack_304 = 0;
          ac_passthrough_str2mac(*piVar6,&uStack_308);
          iVar3 = apmngr_db_entry_get_by_mac(&uStack_308,auStack_300);
          if (iVar3 == 0) {
            if (ac_passthrough_info_switch != '\0') {
              printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
                     "print_passthrough_response_get",0x9f6);
            }
            FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
            iVar3 = FUN_00407fa0(ac_passthrough_response_result_hash,&uStack_308);
            if (iVar3 == 0) {
              if (ac_passthrough_info_switch != '\0') {
                uVar5 = 0x9f9;
code_r0x005103d4:
                printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                       "print_passthrough_response_get",uVar5);
              }
            }
            else {
              printf("going to print mac:%s id:%d \r\n",*piVar6,param_2);
              print_passthrough_response_get_from_one_ap(iVar3,param_2);
              if (ac_passthrough_info_switch != '\0') {
                uVar5 = 0x9fe;
                goto code_r0x005103d4;
              }
            }
            FUN_00407f30(ac_passthrough_get_reponse_mutex);
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar4 != iVar1);
        FUN_00407df0(__s);
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}

