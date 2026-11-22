// func apupd_timer_thread_callback @ 0064bd14 size=300

void apupd_timer_thread_callback(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  FUN_0051ad88(&local_30);
  do {
    FUN_004082d0(apupd_msg_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_apupd_timer_list), iVar1 == 0) {
      FUN_004086c0(apupd_msg_cond,apupd_msg_mutex,0xffffffff);
    }
    FUN_004082c0(&local_30,&g_apupd_timer_list);
    FUN_00407f30(apupd_msg_mutex);
    while (iVar1 = FUN_004081b0(&local_30), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (*(int *)(iVar1 + 0xc) == 0) {
        apupd_report_hw_fw_to_cloud_callback(*(undefined4 *)(iVar1 + 0x10));
LAB_0064bde4:
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else if (g_apupd_error == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 != 0) {
          printf("[APUPD_ERROR]%32s() %05d: Unknown msg op[%d]\r\n","apupd_timer_proc",0xd65,
                 *(undefined4 *)(iVar1 + 0xc));
          goto LAB_0064bde4;
        }
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      if (iVar2 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      FUN_00407df0(iVar1);
    }
  } while( true );
}

