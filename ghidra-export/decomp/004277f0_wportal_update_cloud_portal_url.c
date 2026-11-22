// func wportal_update_cloud_portal_url @ 004277f0 size=268

void wportal_update_cloud_portal_url(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d cloud_portal_url is %s \n","wportal_update_cloud_portal_url",0x38a4
           ,param_1);
  }
  piVar1 = (int *)_wportal_url_parser(param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
  if (*piVar1 == 2) {
    memset(&g_cloud_portal_host_name,0,0x100);
    strncpy(&g_cloud_portal_host_name,(char *)(piVar1 + 7),0xff);
    if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(piVar1), iVar2 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d g_cloud_portal_host_name now is %s \n",
             "wportal_update_cloud_portal_url",0x38aa,&g_cloud_portal_host_name);
    }
  }
  FUN_00407df0(piVar1);
  return;
}

