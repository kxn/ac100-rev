// func wportal_print_cloud_url @ 0042add4 size=1

void wportal_print_cloud_url(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  FUN_004082d0(wportal_cloud_server_update_mutex,0xffffffff);
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d g_cloud_portal_host_name is %s\n","wportal_print_cloud_url",0x38bb,
           &g_cloud_portal_host_name);
  }
  pcVar2 = &cloud_server_ip;
  iVar3 = 0;
  while (iVar3 < cloud_server_num) {
    if (((*pcVar2 == '\0') || (wportal_debug_switch == 0)) ||
       (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x28;
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d cloud_server_ip[%d] is [%s]\n","wportal_print_cloud_url",0x38c1,
             iVar3,pcVar2);
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x28;
    }
  }
  pcVar2 = &cloud_server_old_ip;
  iVar3 = 0;
  while (iVar3 < old_cloud_server_num) {
    if (((*pcVar2 == '\0') || (wportal_debug_switch == 0)) ||
       (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x28;
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d cloud_server_old_ip[%d] is [%s]\n","wportal_print_cloud_url",
             0x38c9,iVar3,pcVar2);
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x28;
    }
  }
  uac_mutex_give(wportal_cloud_server_update_mutex);
  return;
}

