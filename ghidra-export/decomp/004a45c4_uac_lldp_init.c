// func uac_lldp_init @ 004a45c4 size=320

undefined4 uac_lldp_init(void)

{
  int iVar1;
  
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d .............uac_lldp_init............\n","uac_lldp_init",0x237)
    ;
  }
  uac_lldp_mutex = FUN_00407f00("uac_lldp_mutex",0);
  if (uac_lldp_mutex == 0) {
    if (uac_lldp_err_switch != '\0') {
      printf("[UAC_LLDP_ERROR]%s()/%d Create cloud mngt msg mutex failed.\n","uac_lldp_init",0x23c);
    }
  }
  else {
    g_total_cnt = 0;
    FUN_0051ad88(&g_uac_lldp_list);
    if (uac_lldp_debug_switch != '\0') {
      printf("[UAC_LLDP_DEBUG]%s()/%d .............uac_lldp_jcs_init............\n",
             "uac_lldp_jcs_init",0x1b8);
    }
    iVar1 = FUN_004084d0("uac_lldp",2,_uac_lldp_jcs_set);
    if ((((iVar1 == 0) && (iVar1 = FUN_004084d0("uac_lldp",3,_uac_lldp_jcs_get), iVar1 == 0)) &&
        (iVar1 = apmngr_support_capacity_register(0x25), iVar1 == 0)) &&
       (iVar1 = uac_lldp_pkt_init(), iVar1 == 0)) {
      uac_lldp_debug_init();
      return 0;
    }
  }
  uac_lldp_fini();
  return 0xffffffff;
}

