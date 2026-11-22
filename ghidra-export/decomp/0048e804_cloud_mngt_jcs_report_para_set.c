// func cloud_mngt_jcs_report_para_set @ 0048e804 size=284

void cloud_mngt_jcs_report_para_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = json_object_object_get(param_1,"time_interval");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
      goto LAB_0048e864;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar3 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
      goto LAB_0048e864;
    }
  }
  iVar1 = -1;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_report_para_set",0x1dc9);
  }
LAB_0048e864:
  if ((client_report_interval != iVar1) &&
     (client_report_interval = iVar1, g_cloud_mngt_client_report_timer_id != -1)) {
    FUN_00408060();
    g_cloud_mngt_client_report_timer_id =
         FUN_00408340(client_report_interval,0,cloud_mngt_client_update_report_timer_cb,0,0,
                      "cloud_mngt_jcs_report_para_set",0x1dd0);
  }
  return;
}

