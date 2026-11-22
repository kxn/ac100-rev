// func apmngr_db_specify_entry_cloud_config_id_reset @ 0053b61c size=344

void apmngr_db_specify_entry_cloud_config_id_reset(ushort *param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != (char *)0x0) {
    iVar2 = 0;
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    while (iVar2 < param_2) {
      iVar1 = g_apmngr_entry_array + (uint)*param_1 * 0x2d8;
      if (*(int *)(iVar1 + 0x1c) == 1) {
        strncpy((char *)(iVar1 + 0x1c5),param_3,0x40);
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 1;
      }
      else {
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 1;
      }
    }
    FUN_00407f30(apmngr_db_mutex);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Cloud_config_id is NULL.\n",
           "apmngr_db_specify_entry_cloud_config_id_reset",0x843);
    return;
  }
  return;
}

