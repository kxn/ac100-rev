// func _wportal_update_to_ap @ 00411914 size=592

undefined4 _wportal_update_to_ap(void *param_1,size_t param_2,int param_3,undefined4 param_4)

{
  void *__s;
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = 0;
  if (*(int *)(param_3 + 8) != 0) {
    __s = (void *)FUN_00408450(0x14,0x247);
    if (__s == (void *)0x0) {
      uVar3 = 0xffffffff;
      if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_to_ap",0x24a);
      }
    }
    else {
      memset(__s,0,0x14);
      *(undefined4 *)((int)__s + 0xc) = 3;
      pvVar1 = (void *)FUN_00408450(0x1c,0x250);
      *(void **)((int)__s + 0x10) = pvVar1;
      if (pvVar1 == (void *)0x0) {
        if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_to_ap",0x253);
        }
      }
      else {
        memset(pvVar1,0,0x1c);
        puVar4 = *(undefined4 **)((int)__s + 0x10);
        pvVar1 = (void *)FUN_00408450(param_2,0x25a);
        *puVar4 = pvVar1;
        if (pvVar1 != (void *)0x0) {
          memcpy(pvVar1,param_1,param_2);
          puVar4[1] = param_2;
          puVar4[6] = param_4;
          serv_wtp_address_arg_init(puVar4 + 2);
          serv_wtp_address_arg_move(puVar4 + 2,param_3);
          if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d update rdt ftt list WPORTAL_MSG_TYPE_UPDATE_TO_AP\n",
                   "_wportal_update_to_ap",0x26a);
          }
          FUN_004082d0(wportal_update_rdt_ftt_mutex,0xffffffff);
          FUN_004086b0(&g_wportal_update_rdt_ftt_list,__s);
          FUN_004084b0(wportal_update_rdt_ftt_cond);
          FUN_00407f30(wportal_update_rdt_ftt_mutex);
          return 0;
        }
        if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_to_ap",0x25d);
        }
        FUN_00407df0(*(undefined4 *)((int)__s + 0x10));
      }
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

