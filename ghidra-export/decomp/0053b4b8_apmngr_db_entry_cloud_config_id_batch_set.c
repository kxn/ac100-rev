// func apmngr_db_entry_cloud_config_id_batch_set @ 0053b4b8 size=356

void apmngr_db_entry_cloud_config_id_batch_set(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (char *)0x0) {
    iVar2 = 0;
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    while (iVar2 < apmngr_ap_num_max + apmngr_template_num_max + apmngr_sensor_num_max) {
      iVar1 = g_apmngr_entry_array + iVar2 * 0x2d8;
      if (*(int *)(iVar1 + 0x1c) == 1) {
        strncpy((char *)(iVar1 + 0x1c5),param_1,0x40);
        iVar2 = iVar2 + 1;
      }
      else {
        iVar2 = iVar2 + 1;
      }
    }
    FUN_00407f30(apmngr_db_mutex);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Cloud_config_id is NULL.\n",
           "apmngr_db_entry_cloud_config_id_batch_set",0x825);
    return;
  }
  return;
}

