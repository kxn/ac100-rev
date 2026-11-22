// func clear_uac_lldp_list @ 004a36f0 size=220

void clear_uac_lldp_list(void)

{
  int iVar1;
  
  g_uac_lldp_timer = 0xffffffff;
  FUN_004082d0(uac_lldp_mutex,0xffffffff);
  iVar1 = FUN_004081b0(&g_uac_lldp_list);
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d clear_uac_lldp_list.\n","clear_uac_lldp_list",0x6e);
  }
  while (iVar1 != 0) {
    FUN_00408500(iVar1);
    if (*(int *)(iVar1 + 0x14) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
    iVar1 = FUN_004081b0(&g_uac_lldp_list);
  }
  g_total_cnt = 0;
  g_is_continue = 0;
  FUN_00407f30(uac_lldp_mutex);
  return;
}

