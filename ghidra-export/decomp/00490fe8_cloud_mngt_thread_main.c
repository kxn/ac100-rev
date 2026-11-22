// func cloud_mngt_thread_main @ 00490fe8 size=552

void cloud_mngt_thread_main(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0051ad88(&local_38);
  do {
    FUN_004082d0(cloud_mngt_msg_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_cloud_mngt_msg_list), iVar1 == 0) {
      FUN_004086c0(cloud_mngt_msg_cond,cloud_mngt_msg_mutex,0xffffffff);
    }
    FUN_004082c0(&local_38,&g_cloud_mngt_msg_list);
    FUN_00407f30(cloud_mngt_msg_mutex);
    while (iVar1 = FUN_004081b0(&local_38), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (*(int *)(iVar1 + 0x10) == 0) {
LAB_004910f0:
        iVar3 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar3 = *(int *)(iVar1 + 0xc);
        if (iVar3 == 2) {
          if (((ap_report_switch == 0) || (client_report_switch == 0)) ||
             (iVar3 = FUN_00408290(client_container), iVar3 != 0)) {
            cloud_mngt_client_data_free(*(undefined4 *)(iVar1 + 0x10));
            if (cloud_mngt_debug_switch == '\0') {
              *(undefined4 *)(iVar1 + 0x10) = 0;
            }
            else {
              uVar2 = 0xccf;
              __format = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_msg_client_proc failed\n";
LAB_0049115c:
              printf(__format,"cloud_mngt_msg_proc",uVar2);
              *(undefined4 *)(iVar1 + 0x10) = 0;
            }
          }
          else {
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
          goto LAB_004910f0;
        }
        if (iVar3 == 0x14) {
          if ((ap_report_switch == 0) || (iVar3 = FUN_00408290(bssid_info_changed_sc), iVar3 != 0))
          {
            cloud_mngt_bssid_data_free(*(undefined4 *)(iVar1 + 0x10));
            if (cloud_mngt_debug_switch != '\0') {
              uVar2 = 0xcd7;
              __format = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_msg_bssid_proc failed\n";
              goto LAB_0049115c;
            }
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
          else {
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
          goto LAB_004910f0;
        }
        if (iVar3 == 1) {
          if ((ap_report_switch == 0) || (iVar3 = FUN_00408290(ap_container), iVar3 != 0)) {
            cloud_mngt_ap_data_free(*(undefined4 *)(iVar1 + 0x10));
            if (cloud_mngt_debug_switch != '\0') {
              uVar2 = 0xcc6;
              __format = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_msg_ap_proc failed\n";
              goto LAB_0049115c;
            }
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
          else {
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
          goto LAB_004910f0;
        }
        if (cloud_mngt_err_switch == '\0') goto LAB_004910f0;
        printf("[CLOUD_MNGT_ERROR]%s()/%d Unknown msg op[%d]\n","cloud_mngt_msg_proc",0xcdc);
        iVar3 = *(int *)(iVar1 + 0x10);
      }
      if (iVar3 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      FUN_00407df0(iVar1);
    }
  } while( true );
}

