// func _autorrm_config_set @ 004a8c84 size=620

undefined4 _autorrm_config_set(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [3];
  
  local_38 = g_autorrm_time;
  local_34 = DAT_00767bc4;
  local_30[0] = DAT_00767bc8;
  iVar4 = g_autorrm_date;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar1 = 8;
    iVar4 = 0;
    do {
      iVar3 = strcmp(param_2,(&PTR_DAT_006a14c4)[iVar4]);
      iVar1 = iVar1 + -1;
      if (iVar3 == 0) break;
      iVar4 = iVar4 + 1;
    } while (iVar1 != 0);
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    sscanf(param_3,"%2u:%2u:%2u",&local_38,&local_34,local_30);
  }
  if (((param_1 == 0) || (iVar4 != g_autorrm_date)) ||
     (iVar1 = memcmp(&local_38,&g_autorrm_time,0xc), iVar1 != 0)) {
    if (g_autorrm_timer != -1) {
      if (rrm_debug_switch != '\0') {
        printf("[RRM_DEBUG]%s()/%d stop timer for rrm.\n\n","_autorrm_config_set",0x91d);
      }
      FUN_00408060(g_autorrm_timer);
      g_autorrm_timer = -1;
    }
    if (param_1 == 0) {
      g_autorrm_date = iVar4;
      g_autorrm_time = local_38;
      DAT_00767bc4 = local_34;
      DAT_00767bc8 = local_30[0];
      g_autorrm_enable = param_1;
      return 0;
    }
  }
  if (g_autorrm_timer == -1) {
    uVar2 = _autorrm_tmo_caculate(0,iVar4,&local_38);
    g_autorrm_timer = FUN_00408340(uVar2,0,_autorrm_tmo_handle,0,0,"_autorrm_config_set",0x927);
    if (g_autorrm_timer == -1) {
      if (rrm_err_switch != '\0') {
        printf("[RRM_ERROR]%s()/%d Failed to start a timer to rrm.\n","_autorrm_config_set",0x92a);
        return 0xffffffff;
      }
      return 0xffffffff;
    }
    if (rrm_debug_switch != '\0') {
      printf("[RRM_DEBUG]%s()/%d start a timer waiting %ld seconds to timeout.\n",
             "_autorrm_config_set",0x92d,uVar2);
    }
  }
  g_autorrm_enable = param_1;
  DAT_00767bc8 = local_30[0];
  DAT_00767bc4 = local_34;
  g_autorrm_time = local_38;
  g_autorrm_date = iVar4;
  return 0;
}

