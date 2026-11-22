// func apupd_apmngr_callback_apupd_group_join @ 0064516c size=152

undefined4 apupd_apmngr_callback_apupd_group_join(short param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_a8 [164];
  
  if (((param_1 != -1) && (param_2 != 0)) && (*(int *)(param_2 + 0xc) != 0)) {
    iVar1 = apupd_db_wtp_get_by_mac(param_2 + 0x48,auStack_a8);
    if (iVar1 == -1) {
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: get wtp by mac error.\r\n",
               "apupd_apmngr_callback_apupd_group_join",0xf4f);
      }
    }
    else {
      apupd_db_wtp_set(auStack_a8);
    }
  }
  return 0;
}

