// func clean_tdcp_response_from_ap @ 0050fd64 size=1

undefined4 clean_tdcp_response_from_ap(char *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uStack_308;
  undefined2 uStack_304;
  undefined1 auStack_300 [728];
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    if (ac_passthrough_info_switch != '\0') {
      printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
             "_ac_passthrough_response_clean_all_aps",0x5eb);
    }
    FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
    FUN_00408570(ac_passthrough_response_result_hash,
                 _ac_passthrough_response_clean_all_aps_one_hash_node,&stack0xffffffe8);
    if (ac_passthrough_info_switch != '\0') {
      printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
             "_ac_passthrough_response_clean_all_aps",0x5ee);
    }
    FUN_00407f30(ac_passthrough_get_reponse_mutex);
    return 0;
  }
  if (ac_passthrough_debug_switch != '\0') {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d ............._ac_passthrough_response_clean begin............\n"
           ,"_ac_passthrough_response_clean",0x593);
  }
  uStack_308 = 0;
  uStack_304 = 0;
  memset(auStack_300,0,0x2d8);
  if ((param_1 == (char *)0x0) || (param_2 < 1)) {
    uVar3 = 0xffffffff;
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d invalid params\n","_ac_passthrough_response_clean",0x59d
            );
    }
  }
  else {
    iVar4 = 0;
    do {
      memcpy(&uStack_308,param_1,6);
      iVar2 = apmngr_db_entry_get_by_mac(&uStack_308,auStack_300);
      if (iVar2 == 0) {
        if (ac_passthrough_info_switch != '\0') {
          printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
                 "_ac_passthrough_response_clean",0x5a8);
        }
        FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
        piVar1 = (int *)FUN_00407fa0(ac_passthrough_response_result_hash,&uStack_308);
        if (piVar1 == (int *)0x0) {
          if (ac_passthrough_info_switch != '\0') {
            uVar3 = 0x5b0;
            goto code_r0x0050d0a0;
          }
        }
        else {
          if (ac_passthrough_debug_switch != '\0') {
            printf("[AC_PASSTHROUGH_DEBUG]%s()/%d param timeout:%02x-%02x-%02x-%02x-%02x -%02x \n",
                   "_ac_passthrough_response_clean",0x5ac,uStack_308 >> 0x18,
                   uStack_308 >> 0x10 & 0xff,uStack_308 >> 8 & 0xff,uStack_308 & 0xff,
                   (uint)uStack_304._0_1_,(uint)(byte)uStack_304);
          }
          if (param_3 == -1) {
            free_reponse_from_list(piVar1);
            *piVar1 = 0;
          }
          else {
            iVar2 = get_reponse_by_id_from_list(piVar1,param_3);
            if (iVar2 != 0) {
              FUN_00408500(iVar2);
              if (*(int *)(iVar2 + 0x18) != 0) {
                FUN_00407df0();
                *(undefined4 *)(iVar2 + 0x18) = 0;
              }
              FUN_00407df0(iVar2);
              *piVar1 = *piVar1 + -1;
            }
          }
          uVar3 = 0x5c1;
          if (ac_passthrough_info_switch != '\0') {
code_r0x0050d0a0:
            printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                   "_ac_passthrough_response_clean",uVar3);
          }
        }
        FUN_00407f30(ac_passthrough_get_reponse_mutex);
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 6;
    } while (iVar4 != param_2);
    uVar3 = 0;
  }
  return uVar3;
}

